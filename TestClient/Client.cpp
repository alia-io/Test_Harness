/////////////////////////////////////////////////////////////////////////
// Client.cpp - Demonstrates simple one-way string messaging           //
//                                                                     //
// Jim Fawcett, CSE687 - Object Oriented Design, Spring 2016           //
// Application: OOD Project #4                                         //
// Platform:    Visual Studio 2015, Dell XPS 8900, Windows 10 pro      //
/////////////////////////////////////////////////////////////////////////
/*
 * This package implements a client that sends string messages
 * to a server that simply displays them.
 *
 * It's purpose is to provide a very simple illustration of how to use
 * the Socket Package provided for Project #4.
 */
 /*
  * Required Files:
  *   StringClient.cpp, StringServer.cpp
  *   Sockets.h, Sockets.cpp
  *   Logger.h, Logger.cpp, Cpp11-BlockingQueue.h
  *   Utilities.h, Utilities.cpp
  */
#include "Client.h"
#include "Sockets.h"
#include "StaticLogger.h"
#include "TestResultCounter.h"
#include <string>
#include <iostream>
#include <thread>

const IP_VERSION Client::ipVersion = IP_VERSION::IPv6;      // create initial connection parameters
const std::string Client::ipAddress = "localhost";
const size_t Client::portNumber = 9090;

using namespace Sockets;

class ConnectionHandler {
private:
    TestResultCounter counter{};    // Counts the number of tests of each category
public:
    void operator()(Socket& socket_);
    void setTotalTests(int count);
    void sendTimer(Timer* t);
};

/* This method increments the counter for each result message that comes back as passed, failed, and exception */
void ConnectionHandler::operator()(Socket& socket_) {

    int numberOfTests = counter.getTestsTotal();
    while (true) {  // Incoming messages from server received here
        if (numberOfTests <= 0) break;
        std::string msg = Socket::removeTerminator(socket_.recvString());
        Message resultMsg{ msg };
        if (resultMsg.getResultMessageBody().testResult == TEST_RESULT::pass) {
            StaticLogger<1>::write(LogMsg{ OUTPUT_TYPE::positive, resultMsg.getResultMessageBody().testMessage });
            counter.incrementTestPassed();
        }
        else if (resultMsg.getResultMessageBody().testResult == TEST_RESULT::fail) {
            StaticLogger<1>::write(LogMsg{ OUTPUT_TYPE::negative, resultMsg.getResultMessageBody().testMessage });
            counter.incrementTestFailed();
        }
        else if (resultMsg.getResultMessageBody().testResult == TEST_RESULT::exception) {
            StaticLogger<1>::write(LogMsg{ OUTPUT_TYPE::neutral, resultMsg.getResultMessageBody().testMessage });
            counter.incrementTestFailed();
        }
        numberOfTests--;
    }
    counter.getTimer()->endTimer();
    StaticLogger<1>::write(LogMsg{ OUTPUT_TYPE::summary, counter.testResultSummary() });
}

void ConnectionHandler::setTotalTests(int count) { counter.setTotalTests(count); }
void ConnectionHandler::sendTimer(Timer* t) { counter.setTimer(t); }

/* Run each test inside of testList for a specified log level */ 
void Client::runTests(LOG_LEVEL logLevel, std::list<std::string> testList) {
    init();
    try {
        SocketSystem ss;
        Timer timer{};
        std::thread listenThread([=] { startListener(testList.size(), timer); });  // create threads to handle incoming results messages 
        ::Sleep(1000);   // wait to make sure server listener is started
        sendRequest(logLevel, testList, timer); // calls method that sends the test list to be processed by TestHarness on the server side
        listenThread.join();
    }
    catch (std::exception& exc) {
        StaticLogger<1>::write(LogMsg{ OUTPUT_TYPE::system, "Exeception caught: " + std::string(exc.what()) }); //Log a msg when excpt is caught
    }
}

void Client::init() {
    StaticLogger<1>::attach(&std::cout);
    StaticLogger<1>::start();
    StaticLogger<1>::write(LogMsg{ OUTPUT_TYPE::system, "Client started" });    // Indicate to the console that Client has started
}

void Client::startListener(int numTests, Timer timer) {  // Communication from server to client
    SocketListener sl(Client::portNumber, Client::ipVersion);
    ConnectionHandler cp;
    cp.setTotalTests(numTests);
    cp.sendTimer(&timer);
    sl.start(cp);
    std::cout.flush();
    std::cin.get();
}

// Communication from client to server
void Client::sendRequest(LOG_LEVEL logLevel, std::list<std::string> testList, Timer timer) {

    SocketConnecter si;
    while (!si.connect("localhost", 8080)) {    // connect to server
        StaticLogger<1>::write(LogMsg{ OUTPUT_TYPE::system, "Client waiting to connect" });
        ::Sleep(100);
    }

    Message request{ Client::ipVersion, Client::ipAddress, Client::portNumber,
        IP_VERSION::IPv6, "localhost", 8080, logLevel, testList };
    std::string jsonRequest = request.getJsonFormattedMessage();

    timer.startTimer();
    si.sendString(jsonRequest);   // send request to server

    StaticLogger<1>::write(LogMsg{ OUTPUT_TYPE::system, "Client sent test request message" });
    StaticLogger<1>::write(LogMsg{ OUTPUT_TYPE::system, "Server processing results..." });
}
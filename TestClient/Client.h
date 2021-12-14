#pragma once
#include "Message.h"
#include "Timer.h"

//////////////////////////////////////////////////////
// Client.h											//
// CSE 681: Object Oriented Design					//
// Santhosh Srinivasan, Jiawen Zhen, Alifa Stith	//
//////////////////////////////////////////////////////

/* This is the header file for the Client class. The Client class utilizes the socket class to enable
* the client to send messages to a server with the matching connection. This class also enables the 
* client to recieves messages back from the server with test results
*
*/

using namespace TestMessenger;

class Client {
public:
	static const IP_VERSION ipVersion;
	static const std::string ipAddress;
	static const size_t portNumber;
	void runTests(LOG_LEVEL logLevel, std::list<std::string> testList); // run each test inside of testList for a specified log level
private:
	void init();
	void startListener(int numTests, Timer timer);	// Handle connection from server to client  
	void sendRequest(LOG_LEVEL logLevel, std::list<std::string> testList, Timer timer);	// Set up connection from client to server
};
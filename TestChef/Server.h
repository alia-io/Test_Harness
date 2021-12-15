#pragma once
#include "Message.h"

//////////////////////////////////////////////////////
// Message.h										//
// CSE 681: Object Oriented Design					//
// Santhosh Srinivasan, Jiawen Zhen, Alifa Stith	//
//////////////////////////////////////////////////////

/* This is the header file for the Server class. The Server class utilizes the socket class to recieve 
* messages sent over from a client with the matching connection. This class also enables the
* server to send messages back to the client with test results
*
*/

using namespace TestMessenger;

static class Server {
public:
	static const IP_VERSION ipVersion;
	static const std::string ipAddress;
	static const size_t portNumber;
	static void runServer();
	static void runTestHarness(Message requestMsg);	//run test harnesss for all tests outlined in the body of the Message object
private:
	static void init();
	static void startListener();	// Handle connection from client to server 
};
#pragma once
#include <chrono>
#include <string>
#include <thread>

using std::chrono::time_point;
using std::chrono::system_clock;

/*
*	--------------------
*	MESSAGETYPE options:
*	--------------------
* 
*	request - message containing a single DLL/TEST function pointer to be tested
*		source: parent process ID (TestHarness)
*		destination: child process ID (TestRunner)
* 
*	response - message containing the result of a single DLL/TEST function pointer
*		source: child process ID (TestRunner)
*		destination: parent process ID (TestHarness)
* 
*	request_list - message containing a list of DLLs to be tested
*		source: client IP address & port
*		destination: server IP address & port
* 
*	response_list - message containing a list of the TEST results
*		source: server IP address & port
*		destination: client IP address & port
*/

enum THREAD_TYPE { parent, child };
enum IP_VERSION { IPV4 = 4, IPV6 = 6 };
enum class MESSAGE_TYPE { request, response, request_list, response_list };
struct Address {};

struct ThreadAddress : Address {
	const THREAD_TYPE type;
	const std::thread::id id;
};

struct ServerAddress : Address {
	const IP_VERSION version;
	const std::string ip;
	const size_t port;
};

class TestMessage {
private:
	const Address source;
	const Address destination;
	const MESSAGE_TYPE type;
	const std::string author;		// this could be a client user name or "TestHarness" server
	const time_point<system_clock> timestamp;
	const std::string body;
public:
	//TestMessage(Address sourceAddress, Address destinationAddress, MESSAGE_TYPE messageType,
	//	std::string messageAuthor, std::string messageBody);
	Address getSourceAddress();
	Address getDestinationAddress();
	MESSAGE_TYPE getMessageType();
	std::string getMessage();
};
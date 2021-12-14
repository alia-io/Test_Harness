#pragma once
#include "Message.h"
#include "Timer.h"

using namespace TestMessenger;

class Client {
public:
	static const IP_VERSION ipVersion;
	static const std::string ipAddress;
	static const size_t portNumber;
	void runTests(LOG_LEVEL logLevel, std::list<std::string> testList);
private:
	void init();
	void startListener(int numTests, Timer timer);
	void sendRequest(LOG_LEVEL logLevel, std::list<std::string> testList, Timer timer);
};
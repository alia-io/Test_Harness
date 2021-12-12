#include "TestMessageParser.h"

#include <iostream>
#include <stack>

using namespace TestSuite;

std::string TestMessageParser::convertMessageToJSONString(TestMessage message) {
	
	std::string str = "{ \"source\": { \"address\": ";
	if (typeid(*(message.source)) == typeid(ThreadAddress)) {
		ThreadAddress* src = dynamic_cast<ThreadAddress*>(message.source);
		str += "\"thread\", \"type\": ";
		if (src->getType() == THREAD_TYPE::parent) str += "\"parent\", ";
		else if (src->getType() == THREAD_TYPE::child) str += "\"child\", ";
		std::stringstream ss;
		ss << src->getId();
		str += "\"id\": " + ss.str();
	}
	else if (typeid(*(message.source)) == typeid(ServerAddress)) {
		ServerAddress* src = dynamic_cast<ServerAddress*>(message.source);
		str += "\"server\", \"version\": ";
		if (src->getVersion() == IP_VERSION::IPV4) str += "\"IPV4\", ";
		else if (src->getVersion() == IP_VERSION::IPV6) str += "\"IPV6\", ";
		str += "\"ip\": \"" + src->getIp() + "\", \"port\": " + std::to_string(src->getPort());
	}

	str += " }, \"destination\": { \"address\": ";
	if (typeid(*(message.destination)) == typeid(ThreadAddress)) {
		ThreadAddress* dest = dynamic_cast<ThreadAddress*>(message.destination);
		str += "\"thread\", \"type\": ";
		if (dest->getType() == THREAD_TYPE::parent) str += "\"parent\", ";
		else if (dest->getType() == THREAD_TYPE::child) str += "\"child\", ";
		std::stringstream ss;
		ss << dest->getId();
		str += "\"id\": " + ss.str();
	}
	else if (typeid(*(message.destination)) == typeid(ServerAddress)) {
		ServerAddress* dest = dynamic_cast<ServerAddress*>(message.destination);
		str += "\"server\", \"version\": ";
		if (dest->getVersion() == IP_VERSION::IPV4) str += "\"IPV4\", ";
		else if (dest->getVersion() == IP_VERSION::IPV6) str += "\"IPV6\", ";
		str += "\"ip\": \"" + dest->getIp() + "\", \"port\": " + std::to_string(dest->getPort());
	}

	str += " }, \"type\": ";
	if (message.type == MESSAGE_TYPE::request) str += "\"request\"";
	else if (message.type == MESSAGE_TYPE::result) str += "\"result\"";
	else if (message.type == MESSAGE_TYPE::request_list) str += "\"request_list\"";
	else if (message.type == MESSAGE_TYPE::result_list) str += "\"result_list\"";

	str += ", \"author\": \"" + message.author;
	str += "\", \"timestamp\": " + TestTimer::epochTimeFromTimePoint(message.timestamp);
	str += ", \"body\": " + message.body + " }";

	return str;
}

TestMessage TestMessageParser::convertJSONStringToMessage(std::string messageString) {

	Address* source;
	Address* destination;
	MESSAGE_TYPE messageType;
	std::string author;
	time_point<system_clock> timestamp;
	std::string body;

	enum MESSAGE_STEP { none, source, destination, type, author, timestamp, body };
	enum THREAD_STEP { none, address, type, id };
	enum SERVER_STEP { none, address, version, ip, port };

	std::stack<char> stk{};
	int stackSize = stk.size();
	MESSAGE_STEP messageStep = MESSAGE_STEP::none;
	std::string word = "";
	//THREAD_STEP threadStep = THREAD_STEP::none;
	//SERVER_STEP serverStep = SERVER_STEP::none;

	for (char ch : messageString) {




		/*if (ch == '{') {
			stk.push(ch);
			continue;
		}

		if (ch == '}') {
			if (stk.top() == '{') {
				stk.pop();
				continue;
			}
		}

		if (ch == '"') {
			if (stk.top() == '"') {

				continue;
			} else {
				stk.push(ch);
				word = "";
				continue;
			}
		}*/

	}
}

std::string TestMessageParser::convertTestResultToJSONBody(TEST_RESULT result, std::string messageText) {
	if (result == TEST_RESULT::pass)
		return "{ \"result\": \"pass\", \"message\": \"" + messageText + "\" }";
	else if (result == TEST_RESULT::fail)
		return "{ \"result\": \"fail\", \"message\": \"" + messageText + "\" }";
	else if (result == TEST_RESULT::exception)
		return "{ \"result\": \"exception\", \"message\": \"" + messageText + "\" }";
	return "";
}

TEST_RESULT TestMessageParser::getTestResultFromBody(TestMessage message) {

	bool result = false;
	std::string str = "";

	for (char ch : message.body) {
		if (result) {
			if (ch == '\"') {
				str.erase(std::remove_if(str.begin(), str.end(), ::isspace), str.end());
				if (str.compare("pass") == 0) return TEST_RESULT::pass;
				if (str.compare("fail") == 0) return TEST_RESULT::fail;
				if (str.compare("exception") == 0) return TEST_RESULT::exception;
				break;
			}
			else str += ch;
		}
		else {
			str.erase(std::remove_if(str.begin(), str.end(), ::isspace), str.end());
			if (str.compare("{\"result\":\"") == 0) {
				result = true;
				str = ch;
			}
			else str += ch;
		}
	}

	return TEST_RESULT::invalid;
}

std::string TestMessageParser::getTestResultMessageFromBody(TestMessage message) {

	bool startMsg = false;
	bool resultMsg = false;
	std::string str = "";

	for (char ch : message.body) {
		if (resultMsg) {
			if (ch == '\"') return str;
			else str += ch;
		}
		else if (startMsg) {
			str.erase(std::remove_if(str.begin(), str.end(), ::isspace), str.end());
			if (str.compare("\"message\":\"") == 0) {
				resultMsg = true;
				str = ch;
			}
			else str += ch;
		}
		else if (ch == ',') startMsg = true;
	}

	return "";
}
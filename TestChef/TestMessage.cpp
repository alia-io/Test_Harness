#include "TestMessage.h"

Address TestMessage::getSourceAddress() { return source; }
Address TestMessage::getDestinationAddress() { return destination; }
MESSAGE_TYPE TestMessage::getMessageType() { return type; }
std::string TestMessage::getMessage() { return body; }
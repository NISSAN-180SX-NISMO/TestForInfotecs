#include "StringHandlerExceptions.h"

StringHandlerExceptions::StringHandlerExceptions(std::string msg) :
	std::exception(msg.c_str()) 
{
}

SizeOverflow::SizeOverflow(std::string msg, int maxSize, int currentSize) :
	StringHandlerExceptions(msg)
{
	this->maxSize = maxSize;
	this->currentSize = currentSize;
}

std::string SizeOverflow::getMore() const noexcept
{
	return "Max size = " + std::to_string(this->maxSize) + 
		". Current size = " + std::to_string(this->currentSize) + ".";
}

InvalidChar::InvalidChar(std::string msg, char current) :
	StringHandlerExceptions(msg)
{
	this->current = current;
}

std::string InvalidChar::getMore() const noexcept
{
	const char ch[2]{this->current};
	return std::string(ch);
}

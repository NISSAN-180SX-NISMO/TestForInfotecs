#pragma once
#include <stdexcept>
#include <string>

class StringHandlerExceptions : public std::exception
{
public:
	StringHandlerExceptions(std::string msg);
	virtual std::string getMore() const noexcept = 0;
	virtual ~StringHandlerExceptions() = default;
};

class SizeOverflow : public StringHandlerExceptions 
{
private:
	int maxSize = 0;
	int currentSize = 0;
public: 
	SizeOverflow(std::string msg, int maxSize, int currentSize);
	virtual std::string getMore() const noexcept override;
};

class InvalidChar : public StringHandlerExceptions
{
private:
	char current = '\0';
public:
	InvalidChar(std::string msg, char current);
	virtual std::string getMore() const noexcept override;
};


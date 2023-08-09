#pragma once
#include "../../../Debug.h"
#include <string>

class StringHandler {
private:
	virtual void debugInfo(std::string functionName) = 0;
protected:
	static std::string buffer;
	virtual void updateBuffer() = 0;
public:
	virtual std::string get() = 0;
};
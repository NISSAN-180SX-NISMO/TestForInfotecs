#include "CalculatedShow.h"

std::string to_string(std::vector<int> vector) {
	std::string str;
	for (auto i : vector)
		str += std::to_string(i).c_str();
	return str;
}

void CalculatedShow::debugInfo(std::string functionName)
{
#ifdef DEBUG
	DEBUG << "================================================" << ENDEBUG;
	DEBUG << "Debug info:" << ENDEBUG;
	DEBUG << "Name of function:\t\t" << functionName << ENDEBUG;
	DEBUG << "Thread id:\t\t\t" << std::this_thread::get_id() << ENDEBUG;
	DEBUG << "Current state of buff:\t\t" << (this->buffer.empty() ? "empty" : "\"" + this->buffer + "\"") << ENDEBUG;
	DEBUG << "Current state of input string:\t" << "\"" + this->current + "\"" << ENDEBUG;
	DEBUG << "================================================" << ENDEBUG;
#endif // DEBUG
}

void CalculatedShow::updateBuffer()
{
	std::unique_lock<std::mutex> mutex;
	buffer.clear();
	debugInfo("updateBuffer");
}

int CalculatedShow::calculateSum()
{
	int sum = 0;
	for (const char ch : current)
		sum += std::atoi(&ch);
	current = std::to_string(sum);
	debugInfo("calculateSum");
	return sum;
}

void CalculatedShow::print()
{
	std::cout << "Result = " << current << std::endl;
}

CalculatedShow::CalculatedShow(std::string input)
{
	current = input;
	debugInfo("Constructor");
	this->current = buffer;
	updateBuffer();
	print();
	this->sum = calculateSum();
}

std::string CalculatedShow::get()
{
	return std::to_string(this->sum);
}

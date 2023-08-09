#include "Converter.h"

int Converter::maxSize = 64;

void Converter::replaceEven(std::string& str)
{
    for (int i = 0; i < str.size(); ++i) {
        if (!((str[i] - '0') % 2)) {
            str.replace(i, 1, "ÊÂ");
            ++i;
        }

    }
    current = str;
    debugInfo("replaceEven");
}

void Converter::sort(std::string& str)
{
    std::sort(str.begin(), str.end(), 
        [](char a, char b) {
            return a > b; 
        });
    current = str;
    debugInfo("sort");
}

bool Converter::checkStringFormat(const std::string& str)
{
    if (str.size() > this->maxSize) 
        throw SizeOverflow("Size overflow!", this->maxSize, str.size());
    for (char ch : str) 
        if (int(ch) < 48 || int(ch) > 57) 
            throw InvalidChar("Invalid char!", ch);
    
}

void Converter::updateBuffer()
{
    std::unique_lock<std::mutex> mutex;
    buffer = this->current;
    debugInfo("updateBuffer");
}

Converter::Converter(std::string& input)
{
    current = input;
    debugInfo("Constructor");
    checkStringFormat(current);
    sort(current);
    replaceEven(current);
    updateBuffer();
}

std::string Converter::get()
{
    return this->buffer;
}

void Converter::debugInfo(std::string functionName)
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

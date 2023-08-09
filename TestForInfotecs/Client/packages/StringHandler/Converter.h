#pragma once
#include "StringHandlerExceptions.h"
#include <algorithm>
#include <string>
#include <mutex>

#include "../../../Debug.h"
#include "StringHandlerABS.h"

class Converter : public StringHandler
{
private:
    virtual void debugInfo(std::string functionName) override;
    std::string current;
    static int maxSize;
    void replaceEven(std::string& str);
    void sort(std::string& str);
    bool checkStringFormat(const std::string& str);
    virtual void updateBuffer() override;
public:
    Converter(std::string& input);
    virtual std::string get() override;
};


#pragma once
#include "StringHandlerExceptions.h"
#include <algorithm>
#include <string>
#include <mutex>
#include <vector>
#include <iostream>

#include "../../../Debug.h"
#include "StringHandlerABS.h"

class CalculatedShow : public StringHandler {
private:
	virtual void debugInfo(std::string functionName) override;
    virtual void updateBuffer() override;
    std::string current;
    std::thread* calc;
    int sum;
    int calculateSum();
    void print();
public:
    CalculatedShow(std::string input);
    virtual std::string get() override;
};
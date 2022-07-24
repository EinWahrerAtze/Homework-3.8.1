#pragma once
#include <iostream>
#include <string>
#include <exception>

class Bad_length : public std::domain_error
{
public:
	Bad_length(const std::string & what);
};
#pragma once
#include <iostream>; 

class Bad_length
{
public:
	Bad_length(int n = 0) : m_n(n) { }
	void msg();
private:
	int m_n;
};

void Bad_length::msg()
{
	std::wcout << L"Вы ввели слово запретной длины (" << m_n << L" символов)!\n";
}
#include <string>
#include <Windows.h>
#include "Bad_length.h"

int function(const std::wstring & str, int forbidden_length)
{
	if (str.length() > forbidden_length)
	{
		throw Bad_length(str.length());
	}
	else
	{
		return str.length();
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::wstring str;
	int forbidden_length = 0;
	
	std::wcout << L"Введите запретную длину: ";
	
	while (!(std::wcin >> forbidden_length) || (forbidden_length < 0))
	{
		std::wcin.clear();
		while (std::wcin.get() != L'\n')
			continue;
		std::wcout << L"Пожалуйста, введите положительное число: ";
	}
	
	std::wcin.get();

	while (true)
	{
		std::wcout << L"Введите слово не длиннее " << forbidden_length << L" символов: ";
		getline(std::wcin, str);
	
		int length = 0;

		try
		{
			length = function(str, forbidden_length);
		}
		catch (Bad_length & bl)
		{
			bl.msg();
			std::wcout << L"Завершение программы.\n";
			break;
		}

		std::wcout << L"Длина слова \"" << str << L"\" составляет " << length << L" символа(ов).\n";
	}

	std::wcout << L"Пока!\n";
	return 0;
}
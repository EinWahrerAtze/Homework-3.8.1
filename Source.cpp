#include "Bad_length.h"

size_t function(const std::string & str, int forbidden_length)
{
	if (str.length() > forbidden_length)
	{
		throw Bad_length("You entered more than allowed!\n");
	}
	else
	{
		return str.length();
	}
}

int main()
{
	std::string str;
	int forbidden_length = 0;
	std::cout << "Enter the forbidden length: ";
	
	while (!(std::cin >> forbidden_length) || (forbidden_length < 0))
	{
		std::cin.clear();
		while (std::cin.get() != '\n')
			continue;
		std::cout << "Please, enter a positive value: ";
	}
	
	std::cin.get();

	while (true)
	{
		std::cout << "Enter a word less than " << forbidden_length << " characters: ";
		getline(std::cin, str);
	
		size_t length = 0;

		try
		{
			length = function(str, forbidden_length);
		}
		catch (Bad_length & bl)
		{
			std::cout << bl.what();
			std::cout << "Program terminating.\n";
			break;
		}

		std::cout << "The lenght of \"" << str << "\" is " << length << " characters.\n";
	}

	std::cout << "Bye!\n";
	return 0;
}
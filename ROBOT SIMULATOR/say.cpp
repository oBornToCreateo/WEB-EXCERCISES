#include "say.h"



	std::vector<std::string> ones{ "","one", "two", "three", "four", "five", "six","seven", "eight", "nine" };
	std::vector<std::string> teens{ "ten", "eleven", "twelve", "thirteen","fourteen", "fifteen","sixteen", "seventeen","eighteen", "nineteen" };
	std::vector<std::string> tens{ "", "", "twenty", "thirty", "forty", "fifty","sixty", "seventy", "eighty", "ninety" };

	std::string in_english(long long in)
	{
		std::string answer = "";

		if (in == 0)
		{
			return "zero";
		}
		else if (in < 0)
		{
			throw std::domain_error("Your domain is in error!");
		}
		else if (in >= 1000000000000)
		{
			throw std::domain_error("Your domain is in error!");
		}
		else 
		{
			if (in >= 1000000000 && in < 999999999999) {
				answer += in_english(in / 1000000000) + " billion" + ((in % 1000000000 != 0) ? " " + in_english(in % 1000000000) : "");
			}
			else if (in >= 1000000 && in < 1000000000) {
				answer += in_english(in / 1000000) + " million" + ((in % 1000000 != 0) ? " " + in_english(in % 1000000) : "");
			}
			else if (in >= 1000 && in < 1000000) {
				answer += in_english(in / 1000) + " thousand" + ((in % 1000 != 0) ? " " + in_english(in % 1000) : "");
			}
			else if (in >= 100 && in < 1000) {
				answer += in_english(in / 100) + " hundred" + ((in % 100 != 0) ? " " + in_english(in % 100) : "");
			}
			else if (in >= 20 && in < 100) {
				answer += tens.at(in / 10) + ((in % 10 != 0) ? "-" + in_english(in % 10) : "");
			}
			else if (in >= 10 && in < 20) {
				answer += teens.at(in - 10);
			}
			else if (in < 10) {
				answer += ones.at(in);
			}
			return answer;
			
		}

	}



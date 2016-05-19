#pragma once
#include <vector>
#include <algorithm>

template <typename T, typename Less>
bool FindMax(std::vector<T> const& arr, T& maxValue, Less const &less)
{
	if (arr.size() == 0)
	{
		return false;
	}
	maxValue = *std::max_element(arr.begin(), arr.end(), less);

	return true;
}


struct SportsMan
{
	SportsMan() = default;
	SportsMan(std::string const &firstName, std::string const &middleName
			, std::string const &lastName, double height, double weight)
		: firstName(firstName)
		, middleName(middleName)
		, lastName(lastName)
		, height(height)
		, weight(weight)
	{
	}
	std::string firstName;
	std::string middleName;
	std::string lastName;
	double height;
	double weight;
};
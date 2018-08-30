#pragma once
#include <iostream>
#include <string>
#include <array>
#include <vector>

void remove(std::string& str, const char& toRemove) 
{
	// Removes the content of toRemove from str. for example, if str = "dog" and toRemove = 'o', str becomes dg and is returned;
	for (unsigned int i = str.find(toRemove) + 1; i <= str.size(); i++) {
		if (i == str.size())
			str[i - 1] = '\0';
		str[i - 1] = str[i];
	}
	str.resize(str.size() - 1);
}

bool coExists(std::string s1, std::string s2) {
	// Tests if s2 is exactly there in s1. For example, if s1 = codder and s2 = dcoder, then it returns true as dcoder is jumbled form of codder..
	// If s1 = code, s2 = dcoder, it returns false;

	for (std::size_t i = 0; i < s1.size(); i++) {
		bool exist = true;
		for (std::size_t j = 0; j < s2.size(); j++)
		{
			if (s1[i] == s2[j]) {
				remove(s2, s2[j]);
				exist = true;
				break;
			}
			else exist = false;
		}
		if (!exist) break;
	}
	return s2.empty();
}

template<int T>
int majorityNum(std::array<int, T>& arr) {
	// Finds the number which is present in majority in the array. "Majority" means, the number is present more than sizeOfArr/2 times..
	for (std::size_t i = 0; i < arr.size(); i++)
	{
		std::size_t count = 0;
		for (std::size_t j = 0; j < arr.size(); j++)
		{
			if (arr[i] == arr[j])
			{
				count++;
			}
		}
		if (count >= arr.size() / 2)
		{
			return arr[i];
		}
		else return -1;
	}
}

int majorityNum(int arr[], int size) {
	// Overloaded function of above for C-arrays
	int result;
	for (int i = 0; i < size; i++)
	{
		int count = 0;
		for (int j = 0; j < size; j++)
		{
			if (arr[i] == arr[j])
			{
				count++;
			}
		}
		if (count >= size / 2)
		{
			result = arr[i];
			break;
		}
		else result = -1;
	}
	return result;
}

std::vector<bool> SieveOfEratosthenes(int n) {
	std::vector<bool> prime;
	for (int i = 0; i <= n; i++) {
		prime.push_back(true);
	}
	for (int p = 2; p*p <= n; p++) {
		if (prime[p] == true) {
			for (int i = p * 2; i <= n; i += p) {
				prime[i] = false;
			}
		}
	}
	return prime;
}

std::string sortString(std::string& str) {
	// Sorts a string on the basis of ASCII values; For example "dcoDer" returns "Dcdeor"

	std::vector<int> ascii;
	for (int i = 0; i < str.size(); i++) {
		ascii.push_back((int)str[i]);
	}
	std::sort(ascii.begin(), ascii.end());
	str.clear();
	for (int i = 0; i < ascii.size(); i++) {
		str += (char)ascii[i];
	}
	return str;
}

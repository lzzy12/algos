#pragma once
#include <iostream>
#include <string>
#include <array>
#include <vector>
namespace slib{
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

	bool coExists(const std::string& s1, std::string s2) {
		// Tests if s2 is exactly there in s1. For example, if s1 = codder and s2 = dcoder, then it returns true as dcoder is jumbled form of codder..
		// If s1 = code, s2 = dcoder, it returns false;
		if (s1 == s2) {
			return true;
		}
		if(s2 != ""){
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
		return false;
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

	std::vector<bool> sieveOfEratosthenes(int n) {
		// Implementation of Sieve Of Eratosthenes algorithm for finding first prime numbers until n;
		/* Sample use case:
		 *	int main()
		 *{
		 * std::vector<bool> x = sieveOfEratosthenes(30);
		 * for(std::size_t i = 0; i < x.size(); i++)
		 *	{
		 *	    if(x[i]) // if x[i] is true
		 *		   std::cout << i;
		 *	}
		 *}
		*/
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

	std::string sortString(std::string str) {
		// Sorts a string on the basis of ASCII values; For example "dcoDer" returns "Dcdeor".

		std::vector<int> ascii;
		for (std::size_t i = 0; i < str.size(); i++) {
			ascii.push_back((int)str[i]);
		}
		std::sort(ascii.begin(), ascii.end());
		str.clear();
		for (std::size_t i = 0; i < ascii.size(); i++) {
			str += (char)ascii[i];
		}
		return str;
	}

	int integerMultiplyCalc(float input) {
		// Returns the smallest number which when multiplied by input, makes the input an integer. 
		// For eg. if input = 1.5, 1.5 * 2 = 3, 3 is an integer, so 2 is returned;
		int n = 0;
		while (input != (int)input) {
			n++;
			input *= n;
		}
		return n;
	}

	int* reverseArray(int input[], int size) 
	{
		int i = 0;
		while (i != size / 2) {
			int temp = input[i];
			input[i] = input[size - i - 1];
			input[size - i - 1] = temp;
			i++;
		}
		return input;
	}
	template<int T>
	std::array<int, T> reverseArray(std::array<int, T>& input) {
		int i = 0;
		while (i != input.size() / 2) {
			int temp = input[i];
			input[i] = input[input.size() - i - 1];
			input[input.size() - i - 1] = temp;
			i++;
		}
		return input;
	}
	std::string encrypt(std::string s)
	{
		/**
		*
		* @param s String to be encrypted
		* Each Character of the String is XOR'd with the length of the String
		* @return String with each character XOR'd with length
		*/
		std::string encryptedStr = "";
		for (size_t i = 0; i < s.length(); i++)
		{
			int t = (int)s[i];
			t = t ^ s.length();
			encryptedStr += (char) t;
		}
		return encryptedStr;
	}
}

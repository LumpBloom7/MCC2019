#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <filesystem>
#include "../_include/getExePath.h"

int main() {
	std::filesystem::path inputDir = std::filesystem::path(getExePath()) / "Input" / "Bakery";
	for (auto& file : std::filesystem::directory_iterator(inputDir)) {
		std::vector<int> prices{};

		std::ifstream input(file);
		while (true) {
			size_t tmp;
			input >> tmp;
			prices.emplace_back(tmp);
			if (input.eof()) break;
		}

		std::sort(prices.begin(), prices.end()); // Sort the array once.
		std::cout << std::endl;

		// We don't want to modify the array in any way for efficiency purposes, so we keep iterators to the smallest and largest values in it.
		auto left = 0;
		auto right = prices.size() - 1;

		size_t maxCost = 0;

		// It's pretty straight forward. We add the current smallest value, and the first and second largest, then ignore the third largest. Make sure to move the iterators.
		while (left != right) {
			maxCost += prices[left++];
			maxCost += prices[right--];
			maxCost += prices[right--];
			--right;
		}

		std::cout << maxCost << std::endl;
	}
}
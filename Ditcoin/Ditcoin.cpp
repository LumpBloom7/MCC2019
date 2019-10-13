#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <filesystem>
#include "../_include/getExePath.h"

int main() {
	std::filesystem::path inputDir = std::filesystem::path(getExePath()) / "Input" / "Ditcoin";
	for (auto& file : std::filesystem::directory_iterator(inputDir)) {
		std::vector<size_t> prices{};

		// Using this special input method because the input length could be problematic for some compilers, we're gonna read from file instead.
		std::ifstream fin(file);
		while (true) {
			size_t value;
			fin >> value;
			prices.emplace_back(value);
			if (fin.eof()) break;
		}

		auto highest = std::max_element(prices.begin(), prices.end()); // Get the highest possible value in the foreseeable future
		size_t currentDitcoinBalance = 0;
		size_t moneyEarned = 0;

		for (auto today = prices.begin(); today < prices.end(); ++today) {
			++currentDitcoinBalance; // We get a coin every day.

			// In order to maximize profits, we only cash in if the current day has the highest ditcoin we are going to see.
			if (*today == *highest) {
				moneyEarned += currentDitcoinBalance * (*today);
				highest = std::max_element(today + 1, prices.end()); // Don't forget to reevaluate a new highest value day since the previous day has passed and that we may have more days remaining.
				currentDitcoinBalance = 0;
			}
		}

		std::cout << moneyEarned << std::endl;
	}
}
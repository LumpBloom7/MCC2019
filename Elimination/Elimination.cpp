#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>
#include <filesystem>
#include "../_include/getExePath.h"

int main() {
	std::filesystem::path inputDir = std::filesystem::path(getExePath()) / "Input" / "Elimination";
	for (auto& file : std::filesystem::directory_iterator(inputDir)) {
		size_t oCount = 0;

		std::string string{};
		size_t k;

		std::ifstream input(file);
		input >> string >> k;

		size_t longest = 0;

		// Use two pointer method
		auto leftIt = string.begin(), rightIt = string.begin();
		while (rightIt < string.end()) {
			if (*(rightIt++) == '0') ++oCount; // Count every 0 encountered

			while (oCount > k) // If we exceed the 0 limit, we'll need to shift the left pointer
				if (*(leftIt++) == '0') // If the left pointer happens to be a 0, decrement the 0 counter
					--oCount;

			// Check the current distance between two pointers minus the counted 0s, this will give us exactly the amount of 1s in the substring
			longest = (std::distance(leftIt, rightIt - 1) + 1 - oCount > longest) ? std::distance(leftIt, rightIt - 1) + 1 - oCount : longest;
		}

		std::cout << longest << std::endl;
	}
}
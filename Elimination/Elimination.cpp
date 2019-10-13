#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>

int main() {
	size_t oCount = 0;

	std::string string{};
	size_t k = 200366;

	// Using this special input method because the input length could be problematic for some compilers, we're gonna read from file instead.
	std::ifstream fin("input.txt");
	fin >> string;

	size_t longest = 0;

	// Use two pointer method
	auto leftIt = string.begin(), rightIt = string.begin();
	while(rightIt < string.end()) {
		if (*(rightIt++) == '0') ++oCount; // Count every 0 encountered

		while (oCount > k) // If we exceed the 0 limit, we'll need to shift the left pointer
			if (*(leftIt++) == '0') // If the left pointer happens to be a 0, decrement the 0 counter
				--oCount;

		// Check the current distance between two pointers minus the counted 0s, this will give us exactly the amount of 1s in the substring
		longest = (std::distance(leftIt, rightIt-1) + 1 - oCount > longest) ? std::distance(leftIt, rightIt-1) + 1 - oCount : longest;
	}

	std::cout << longest << std::endl;
}
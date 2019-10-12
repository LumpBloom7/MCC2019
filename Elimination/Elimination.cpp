#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>

int main() {
	// This is a pure brute force method, so not ideal, please share if you have a better algo.
	size_t maxI = 0;
	size_t iCount = 0;
	size_t oCount = 0;

	std::vector<bool> string{}; // Using bool vector since this is a binary string, and we'll save on a bit of RAM

	// Using this special input method because the input length could be problematic for some compilers, we're gonna read from file instead.
	std::ifstream fin("input.txt");
	while (true) {
		int tmp = fin.get() - '0';
		string.emplace_back(static_cast<bool>(tmp));
		if (fin.eof()) break;
	}
	size_t k = 200366;

	// This is basically just running measuring the largest possible contiguous length of 1, on every single element. O(N^2)
	for (int i = 0; i < string.size(); ++i) {
		if (string[i] == 1) {
			iCount = 1;
			oCount = 0;
			for (int j = i + 1; j < string.size(); ++j) {
				if (string[j] == 1) ++iCount;
				else if (string[j] == 0) ++oCount;
				if (oCount > k) break;
			}
			maxI = iCount > maxI ? iCount : maxI;
		}
	}
	std::cout << maxI << std::endl;
}
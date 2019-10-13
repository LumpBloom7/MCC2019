#include <iostream>
#include <vector>
#include <numeric>
#include <fstream>
#include <filesystem>
#include "../_include/getExePath.h"

int main() {
	std::filesystem::path inputDir = std::filesystem::path(getExePath()) / "Input" / "Ascending";
	for (auto& file : std::filesystem::directory_iterator(inputDir)) {
		std::vector<int> numbers{};

		std::ifstream input(file);
		while (true) {
			size_t tmp;
			input >> tmp;
			numbers.emplace_back(tmp);
			if (input.eof()) break;
		}

		size_t smallest = std::numeric_limits<size_t>::max(); // This will be initialized to be the biggest number.

		// It's always ascending, so we don't need to sort
		// We also don't have to compare a value with every other values, we only need to compare adjacent values
		for (auto i = numbers.begin() + 1; i < numbers.end(); ++i) {
			int tmp = *i - *(i - 1);
			smallest = (*i - *(i - 1) < smallest ? *i - *(i - 1) : smallest);
		}

		std::cout << smallest << std::endl;
	}
}
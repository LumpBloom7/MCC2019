#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <filesystem>
#include "../_include/getExePath.h"

int main() {
	std::filesystem::path inputDir = std::filesystem::path(getExePath()) / "Input" / "Candy";
	for (auto& file : std::filesystem::directory_iterator(inputDir)) {
		std::vector<std::string> shouts{};

		std::ifstream input(file);
		while (true) {
			std::string tmp;
			input >> tmp;
			shouts.emplace_back(tmp);
			if (input.eof()) break;
		}

		size_t currentPosition = 1; // We end at one.

		// We are simply gonna reverse the process
		for (auto i = shouts.rbegin(); i < shouts.rend(); ++i) {
			if (*i == "odd") // If odd is shouted, our current position is guaranteed to double
				currentPosition += currentPosition;
			else if (*i == "even" && currentPosition > 0) // If even is shouted and we aren't in the first spot, the people in front of us is doubled.
				currentPosition += currentPosition - 1;
		}
		std::cout << currentPosition << std::endl;
	}
}

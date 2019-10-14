#include <iostream>
#include <fstream>
#include <filesystem>
#include "../_include/getExePath.h"

using namespace std;

int main() {
	filesystem::path inputDir = filesystem::path(getExePath()) / "Input" / "Ascending";
	for (auto& file : filesystem::directory_iterator(inputDir)) {
		ifstream input(file);

		size_t previous, minDiff = numeric_limits<size_t>::max();
		input >> previous;

		while (!input.eof()) {
			size_t current;
			input >> current;
			if (current - previous < minDiff)
				minDiff = current - previous;
			previous = current;
		}

		cout << minDiff << endl;
	}
}
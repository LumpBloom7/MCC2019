#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include "../_include/getExePath.h"

using namespace std;

int main() {
	filesystem::path inputDir = filesystem::path(getExePath()) / "Input" / "Candy";
	for (auto& file : filesystem::directory_iterator(inputDir)) {		
		uint64_t currentPosition = 0, currentBit = 0;
		ifstream input(file);
		while (!input.eof()) {
			string tmp;
			input >> tmp;
			if (tmp == "odd")
				currentPosition |= 1ULL << currentBit;
			++currentBit;
		}

		cout << ++currentPosition << endl;
	}
}

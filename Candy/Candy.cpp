#include <iostream>
#include <string>
#include <vector>

int main() {
	std::vector<std::string> shouts = { "odd", "odd", "odd", "odd", "even", "odd", "even", "even", "odd", "odd", "even", "even", "odd", "odd", "even", "odd", "odd", "odd", "odd", "odd", "even", "odd", "even", "even", "odd", "odd", "even", "odd", "even", "odd", "odd", "odd", "even", "odd", "even", "odd", "even", "odd", "even", "even", "odd", "even", "odd", "even", "even", "even", "odd", "odd", "even", "odd", "even", "odd", "even", "even", "even", "even", "odd", "even", "even", "even" };

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

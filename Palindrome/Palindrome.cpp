#include <iostream>
#include <vector>

int main() {
	// Somewhat brute force?

	// Start out with a width of 1;
	std::vector<int> palindrome{ 0 };  // This will be half the palindrome
	size_t width = 1;

	size_t n = 139292, k = 2;
	size_t count = 1;

	// Cut down later calculation by precalculating the potential length of palindrome
	size_t j = 1;
	while (true) {
		size_t tmp = std::pow(k, j);
		if (count + tmp <= n) {
			if (width % 2 == 0) {
				palindrome.emplace_back(0);
				++width;
				++j;
			}
			else {
				++width;
			}
		}
		else {
			break;
		}
		count += tmp;
	}

	// Brute force generator starts here
	while (count != n) {
		auto it = palindrome.begin(); // Make sure we are modifying the first digit
		count++; // Add to the counter
		++(*it); // Add first value

		// Check if current digit is maxed
		while (*it == k) {
			*it = 0; // Set current digit to 0
			++(*(it + 1)); // Increment next digit
			++it; // Move to next digit to perform the same checks
		}
	}


	// Start by printing the elements of this "half a palindrome" in reverse
	for (auto it = palindrome.rbegin(); it < palindrome.rend(); ++it)
		std::cout << *it;

	// If width is odd, we omit the first digit of this palindrome, before printing the half as normal; If the width is even, we print the half in full.
	for (auto it = palindrome.begin() + ((width % 2 == 1) ? 1 : 0); it < palindrome.end(); ++it)
		std::cout << *it;
}
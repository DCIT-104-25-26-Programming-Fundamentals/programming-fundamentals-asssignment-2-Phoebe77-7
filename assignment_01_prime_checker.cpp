// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 1
// =============================================================================
//
// TASK: Prime Number Checker
//
// Write a C++ program that checks whether a given number is prime.
//
// A prime number is a whole number greater than 1 that has no divisors
// other than 1 and itself (e.g., 2, 3, 5, 7, 11, 13 ...).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT / OUTPUT EXAMPLES
// -----------------------------------------------------------------------------
//
//   Enter a number: 7
//   7 is a prime number.
//
//   Enter a number: 10
//   10 is NOT a prime number.
//
//   Enter a number: 1
//   1 is NOT a prime number.
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - You MUST implement the logic inside a function (see scaffold below).
// - Numbers less than 2 are NOT prime — handle this inside the function.
// - The main() function must call isPrime() and print the result.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;

bool is prime(int number) {
    if (number < 2) {
        return false;
    }
    for (int i = 2; i < number, i++)
}
        if (number % i == 0) {
            return false;
        }
        return true;
        int main() {
            while (true) {
                int number;
                std::cout << "Enter any number:";
                std::cin >> number;
            }
        }
        if (is_prime(number)) {
            std::cout << number <<" is a prime number"<< stdL::endl;}
            else {
                std::cout << number << "is NOT a prime number" < std::endl;
            }
            return 0;
        
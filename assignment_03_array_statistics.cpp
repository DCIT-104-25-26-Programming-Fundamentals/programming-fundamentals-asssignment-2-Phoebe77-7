// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 3
// =============================================================================
//
// TASK: Array Statistics Calculator
//
// Write a C++ program that reads a collection of numbers from the user
// and computes key statistical values using separate functions.
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT / OUTPUT EXAMPLE
// -----------------------------------------------------------------------------
//
//   How many numbers? 5
//   Enter number 1: 4
//   Enter number 2: 7
//   Enter number 3: 2
//   Enter number 4: 9
//   Enter number 5: 1
//
//   Results:
//   Sum:     23
//   Average: 4.6
//   Maximum: 9
//   Minimum: 1
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - You MUST implement each calculation in its own function (see scaffold).
// - You may NOT use any standard library functions like accumulate(), max(),
//   or min(). Implement the logic yourself using loops.
// - N must be a positive integer. If the user enters 0 or a negative number,
//   print an error message and stop.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;

int calculateSum(vector<int> numbers)
{
    int sum = 0;

    for (int i = 0; i < numbers.size(); i++)
    {
        sum += numbers[i];
    }

    return sum;
}

// Function to calculate average
double calculateAverage(vector<int> numbers)
{
    int sum = calculateSum(numbers);

    return (double)sum / numbers.size();
}

// Function to find maximum value
int calculateMaximum(vector<int> numbers)
{
    int maximum = numbers[0];

    for (int i = 1; i < numbers.size(); i++)
    {
        if (numbers[i] > maximum)
        {
            maximum = numbers[i];
        }
    }

    return maximum;
}

// Function to find minimum value
int calculateMinimum(vector<int> numbers)
{
    int minimum = numbers[0];

    for (int i = 1; i < numbers.size(); i++)
    {
        if (numbers[i] < minimum)
        {
            minimum = numbers[i];
        }
    }

    return minimum;
}

int main()
{
    int n;

    cout << "How many numbers? ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Error: Please enter a positive integer." << endl;
        return 0;
    }

    vector<int> numbers;

    for (int i = 0; i < n; i++)
    {
        int number;

        cout << "Enter number " << i + 1 << ": ";
        cin >> number;

        numbers.push_back(number);
    }

    cout << "\nResults:" << endl;

    cout << "Sum:     " << calculateSum(numbers) << endl;
    cout << "Average: " << calculateAverage(numbers) << endl;
    cout << "Maximum: " << calculateMaximum(numbers) << endl;
    cout << "Minimum: " << calculateMinimum(numbers) << endl;

    return 0;
}
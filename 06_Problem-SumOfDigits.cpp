#include <iostream>   // Include the iostream library for input/output operations.
#include <string>     // Include the string library to work with std::string.
using namespace std;  // Use the standard namespace to simplify usage of standard library functions.

// Function: ReadPositiveNumber
// Purpose: Prompts the user with a custom message to enter a positive number.
//          Continues to prompt until the user enters a number greater than zero.
// Parameter: Message - a string containing the prompt message.
// Returns: An integer representing the positive number input by the user.
int ReadPositiveNumber(string Message)
{
    int Number = 0;  // Initialize a variable to store the user's input.

    // Use a do-while loop to ensure the prompt is displayed at least once.
    do
    {
        cout << Message << endl; // Display the prompt message to the user.
        cin >> Number;           // Read the user's input.
    } while (Number <= 0);       // Repeat if the entered number is not positive (<= 0).

    return Number;  // Return the valid positive number.
}

// Function: SumOfDigits
// Purpose: Calculates the sum of all digits of a given number.
//          It does so by repeatedly extracting the last digit and adding it to a cumulative sum.
// Parameter: Number - the positive integer whose digits will be summed.
// Returns: The sum of the digits of the given number.
int SumOfDigits(int Number)
{
    int Sum = 0;        // Initialize the sum of digits to zero.
    int Remainder = 0;  // Variable to store the last digit (remainder) during extraction.

    // Process each digit of the number until the number becomes zero.
    while (Number > 0)
    {
        Remainder = Number % 10; // Extract the last digit of Number.
        Number = Number / 10;    // Remove the last digit from Number.
        Sum = Sum + Remainder;   // Add the extracted digit to the cumulative sum.
    }

    return Sum;  // Return the calculated sum of digits.
}

// Main function: Entry point of the program.
int main()
{
    // Prompt the user to enter a positive number and then calculate the sum of its digits.
    // The result is then printed to the console with an explanatory message.
    cout << "\nSum Of Digits = "
        << SumOfDigits(ReadPositiveNumber("Please enter a positive number?"))
        << "\n";

    return 0;  // Return 0 to indicate that the program executed successfully.
}

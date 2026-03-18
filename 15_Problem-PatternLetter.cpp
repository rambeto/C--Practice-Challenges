#include <iostream>   // Include iostream for input/output operations.
#include <string>     // Include string to work with std::string.
using namespace std;  // Use the standard namespace to avoid having to prepend std:: to standard functions.

// Function: ReadPositiveNumber
// Purpose: Prompts the user with a custom message to enter a positive number.
//          It continues to prompt until the user enters a number greater than zero.
// Parameter: Message - a string containing the prompt message to display.
// Returns: A positive integer entered by the user.
int ReadPositiveNumber(string Message)
{
    int Number = 0;  // Variable to store the user's input.
    do
    {
        cout << Message << endl;  // Display the prompt message.
        cin >> Number;            // Read the user's input.
    } while (Number <= 0);        // Repeat if the number is not positive.
    
    return Number;  // Return the validated positive number.
}

// Function: PrintLetterPattern
// Purpose: Prints a letter pattern using uppercase letters.
//          It starts from 'A' and prints as many letters as specified by the input Number.
//          Each row prints a letter repeated a number of times equal to its position in the alphabet.
//          For example, if Number is 3, the pattern will be:
//              A
//              BB
//              CCC
// Parameter: Number - a positive integer determining the number of rows in the pattern.
void PrintLetterPattern(int Number)
{
    cout << "\n";  // Print an empty line for formatting.
   
    // Outer loop: Iterates from ASCII value 65 ('A') to (65 + Number - 1).
    // Each iteration corresponds to a row in the pattern.
    for (int i = 65; i <= 65 + Number - 1; i++)
    {
        // Inner loop: Determines the number of times to print the current letter.
        // The expression (i - 65 + 1) calculates the position of the letter in the alphabet,
        // which is also the number of times it should be repeated in the current row.
        for (int j = 1; j <= i - 65 + 1; j++)
        {
            cout << char(i);  // Convert the ASCII value to its corresponding character and print it.
        }
       
        cout << "\n";  // Move to the next line after printing the current row.
    }
}

// Main function: Program entry point.
int main()
{
    // Read a positive number from the user and then print the letter pattern based on that number.
    PrintLetterPattern(ReadPositiveNumber("Please enter a positive number?"));
    
    return 0;  // Return 0 to indicate that the program executed successfully.
}

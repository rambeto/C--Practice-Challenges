#include <iostream>   // Include iostream for input/output operations.
using namespace std;  // Use the standard namespace to simplify usage of standard functions.

// Function: GetFractionPart
// Purpose: Extracts the fractional part of a floating-point number.
// Parameters:
//   - Number: A floating-point number.
// Returns: The fractional part of the input number.
float GetFractionPart(float Number)
{
    // Subtract the integer part of the number from the original number to get the fractional part.
    return Number - int(Number);
}

// Function: MyRound
// Purpose: Rounds a floating-point number to the nearest integer.
// Parameters:
//   - Number: A floating-point number to be rounded.
// Returns: The rounded integer value of the input number.
int MyRound(float Number)
{
    int IntPart;  // Variable to store the integer part of the number.
    IntPart = int(Number);  // Extract the integer part.

    // Compute the fractional part using the GetFractionPart function.
    float FractionsPart = GetFractionPart(Number);

    // If the absolute value of the fractional part is 0.5 or more, round the number accordingly.
    if (abs(FractionsPart) >= 0.5)
    {
        // If the number is positive, round up.
        if (Number > 0)
            return ++IntPart;  
        // If the number is negative, round down.
        else
            return --IntPart;
    }
    else
    {
        // If the fractional part is less than 0.5, keep the integer part as is.
        return IntPart;
    }
}

// Function: ReadNumber
// Purpose: Reads a floating-point number from the user.
// Returns: The number entered by the user.
float ReadNumber()
{
    float Number;  // Variable to store user input.

    // Prompt the user to enter a floating-point number.
    cout << "Please enter a float number? ";
    cin >> Number;  // Read input from the user.

    return Number;  // Return the input number.
}

// Main function: Entry point of the program.
int main()
{
    float Number = ReadNumber();  // Read a number from the user.

    // Print the rounded value using the custom MyRound function.
    cout << "My Round Result : " << MyRound(Number) << endl;

    // Print the rounded value using the built-in round function for comparison.
    cout << "C++ Round Result: " << round(Number) << endl;

    return 0;  // Return 0 to indicate successful program execution.
}

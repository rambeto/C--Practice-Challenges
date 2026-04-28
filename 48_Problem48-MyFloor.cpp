#include <iostream>   // Include iostream for input/output operations.
using namespace std;  // Use the standard namespace to simplify usage of standard functions.

// Function: MyFloor
// Purpose: Computes the floor value of a floating-point number.
// Parameters:
//   - Number: A floating-point number whose floor value is to be determined.
// Returns: The greatest integer less than or equal to the input number.
int MyFloor(float Number)
{
    // If the number is positive or zero, return its integer part.
    if (Number > 0)
        return int(Number);
    else
        // If the number is negative and has a fractional part, subtract 1 to get the floor value.
        return int(Number) - 1;
}

// Function: ReadNumber
// Purpose: Reads a floating-point number from the user.
// Returns: The number entered by the user.
float ReadNumber()
{
    float Number;  // Variable to store user input.

    // Prompt the user to enter a floating-point number.
    cout << "Please enter a number? ";
    cin >> Number;  // Read input from the user.

    return Number;  // Return the input number.
}

// Main function: Entry point of the program.
int main()
{
    float Number = ReadNumber();  // Read a number from the user.

    // Print the floor value using the custom MyFloor function.
    cout << "My MyFloor Result : " << MyFloor(Number) << endl;

    // Print the floor value using the built-in floor function for comparison.
    cout << "C++ floor Result  : " << floor(Number) << endl;

    return 0;  // Return 0 to indicate successful program execution.
}

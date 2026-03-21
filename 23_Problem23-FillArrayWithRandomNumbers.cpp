#include <iostream>   // Include iostream for input/output operations.
using namespace std;  // Use the standard namespace to avoid prefixing std:: to standard functions.

// Function: RandomNumber
// Purpose: Generates a random integer between two specified values (inclusive).
// Parameters:
//   From - the lower bound of the random range.
//   To   - the upper bound of the random range.
// Returns: A random integer between From and To.
int RandomNumber(int From, int To)
{
    // Generate a random number in the range [From, To]:
    // rand() % (To - From + 1) yields a number between 0 and (To - From), then adding From shifts the range.
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

// Function: FillArrayWithRandomNumbers
// Purpose: Fills an array with a specified number of random numbers between 1 and 100.
// Parameters:
//   arr      - an integer array with a capacity of 100 elements.
//   arrLength - a reference variable that will hold the number of elements to fill.
//             The user specifies this number.
void FillArrayWithRandomNumbers(int arr[100], int &arrLength)
{
    cout << "\nEnter number of elements:\n";
    cin >> arrLength;  // Read the desired number of elements from the user.

    // Fill the array with random numbers between 1 and 100.
    for (int i = 0; i < arrLength; i++)
        arr[i] = RandomNumber(1, 100);
}

// Function: PrintArray
// Purpose: Prints the elements of an integer array separated by spaces.
// Parameters:
//   arr      - the array to print.
//   arrLength - the number of elements in the array.
void PrintArray(int arr[100], int arrLength)
{
    // Loop through the array and print each element followed by a space.
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";
    
    cout << "\n";  // Print a newline after printing all elements.
}

// Main function: Program entry point.
int main() {
    // Seed the random number generator with the current time.
    // This ensures that different sequences of random numbers are produced on each run.
    srand((unsigned)time(NULL));

    int arr[100];   // Declare an array to hold up to 100 integers.
    int arrLength;  // Variable to store the number of elements to be filled in the array.

    // Fill the array with random numbers.
    FillArrayWithRandomNumbers(arr, arrLength);

    // Print the array elements.
    cout << "\nArray Elements: ";
    PrintArray(arr, arrLength);

    return 0;  // Return 0 to indicate successful program execution.
}

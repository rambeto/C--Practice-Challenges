#include <iostream>   // Include iostream for input/output operations.
using namespace std;  // Use the standard namespace to simplify standard functions.

// Function: RandomNumber
// Purpose: Generates a random integer within the inclusive range [From, To].
// Parameters:
//   - From: The lower bound of the range.
//   - To:   The upper bound of the range.
// Returns: A random integer between From and To.
int RandomNumber(int From, int To)
{
    // Generate a random number:
    // rand() % (To - From + 1) gives a number between 0 and (To - From).
    // Adding From shifts it into the range [From, To].
    int randNum = rand() % (To - From + 1) + From;
    return randNum;  // Return the generated random number.
}

// Function: FillArrayWithRandomNumbers
// Purpose: Fills an array with random integers between -100 and 100.
// Parameters:
//   - arr: An integer array (with capacity 100) that will be filled with random numbers.
//   - arrLength: A reference variable to store the number of elements the user wants to fill.
void FillArrayWithRandomNumbers(int arr[100], int &arrLength)
{
    cout << "\nEnter number of elements:\n";
    cin >> arrLength;  // Read the desired number of elements.

    // Loop over each index from 0 to arrLength - 1 and fill the array with a random number.
    // In this case, the random numbers range from -100 to 100.
    for (int i = 0; i < arrLength; i++)
        arr[i] = RandomNumber(-100, 100);
}

// Function: PrintArray
// Purpose: Prints the elements of an integer array separated by spaces.
// Parameters:
//   - arr: The array to print.
//   - arrLength: The number of elements in the array.
void PrintArray(int arr[100], int arrLength)
{
    // Loop through the array and print each element with a space after it.
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";
    cout << "\n";  // Print a newline after all elements.
}

// Function: NegativeCount
// Purpose: Counts how many elements in the array are negative.
// Parameters:
//   - arr: The array to check.
//   - arrLength: The number of elements in the array.
// Returns: The count of elements that are less than 0.
int NegativeCount(int arr[100], int arrLength)
{
    int Counter = 0;  // Initialize a counter for negative numbers.
    
    // Loop through each element of the array.
    for (int i = 0; i < arrLength; i++)
    {
        // Check if the current element is negative.
        if (arr[i] < 0)
        {
            Counter++;  // Increment the counter if the condition is met.
        }
    }
    
    return Counter;  // Return the total count of negative numbers.
}

// Main function: Entry point of the program.
int main() {
    // Seed the random number generator with the current time.
    // This ensures that a different sequence of random numbers is generated each run.
    srand((unsigned)time(NULL));

    int arr[100];      // Declare an array to hold up to 100 integers.
    int arrLength;     // Variable to store the number of elements in the array.

    // Fill the array with random numbers in the range [-100, 100].
    FillArrayWithRandomNumbers(arr, arrLength);

    // Print the elements of the array.
    cout << "\nArray Elements: ";
    PrintArray(arr, arrLength);

    // Count and print the number of negative numbers in the array.
    cout << "\nNegative Numbers count is: ";
    cout << NegativeCount(arr, arrLength) << endl;

    return 0;  // Return 0 to indicate successful program execution.
}

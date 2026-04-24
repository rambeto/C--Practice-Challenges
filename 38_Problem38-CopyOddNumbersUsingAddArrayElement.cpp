#include <iostream>   // Include iostream for input/output operations.
using namespace std;  // Use the standard namespace to avoid prefixing std:: to standard library functions.

// Function: RandomNumber
// Purpose: Generates a random integer within the inclusive range [From, To].
// Parameters:
//   - From: The lower bound of the range.
//   - To:   The upper bound of the range.
// Returns: A random integer between From and To.
int RandomNumber(int From, int To)
{
    // Generate a random number using the modulus operator:
    // rand() % (To - From + 1) produces a number in the range 0 to (To - From),
    // and then adding From shifts the range to [From, To].
    int randNum = rand() % (To - From + 1) + From;
    return randNum;  // Return the generated random number.
}

// Function: FillArrayWithRandomNumbers
// Purpose: Fills an integer array with random numbers between 1 and 100.
// Parameters:
//   - arr: An integer array (with a capacity of 100) that will be filled with random numbers.
//   - arrLength: A reference variable that will hold the number of elements in the array.
// The function prompts the user for the number of elements and then fills each element with a random number.
void FillArrayWithRandomNumbers(int arr[100], int &arrLength)
{
    cout << "\nEnter number of elements:\n";
    cin >> arrLength;  // Read the number of elements from the user.

    // Loop through each index from 0 to arrLength - 1.
    // For each index, generate a random number between 1 and 100 and assign it to the array.
    for (int i = 0; i < arrLength; i++)
        arr[i] = RandomNumber(1, 100);
}

// Function: PrintArray
// Purpose: Prints the elements of an integer array separated by spaces.
// Parameters:
//   - arr: The array to be printed.
//   - arrLength: The number of elements in the array.
void PrintArray(int arr[100], int arrLength)
{
    // Loop through the array and print each element followed by a space.
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";
    cout << "\n";  // Print a newline after printing all elements.
}

// Function: AddArrayElement
// Purpose: Adds a new element to the end of an array and updates its length.
// Parameters:
//   - Number: The number to add to the array.
//   - arr: The array where the new element will be added.
//   - arrLength: A reference variable tracking the current number of elements in the array.
// Behavior: Increments arrLength by 1 and assigns the new element to the last position.
void AddArrayElement(int Number, int arr[100], int &arrLength)
{
    // Since it is a new element, increment the array length.
    arrLength++;
    // Place the new element at the index corresponding to the new length (using zero-based indexing).
    arr[arrLength - 1] = Number;
}

// Function: CopyOddNumbers
// Purpose: Copies only the odd numbers from a source array into a destination array.
// Parameters:
//   - arrSource: The source array from which to copy numbers.
//   - arrDestination: The destination array to store the odd numbers.
//   - arrLength: The number of elements in the source array.
//   - arrDestinationLength: A reference variable that will track the number of odd numbers copied into the destination array.
void CopyOddNumbers(int arrSource[100], int arrDestination[100], int arrLength, int &arrDestinationLength)
{
    // Loop through each element of the source array.
    for (int i = 0; i < arrLength; i++)
    {
        // Check if the current element is odd.
        if (arrSource[i] % 2 != 0)
        {
            // If odd, add it to the destination array using the AddArrayElement function.
            AddArrayElement(arrSource[i], arrDestination, arrDestinationLength);
        }
    }
}

// Main function: Entry point of the program.
int main() {
    // Seed the random number generator with the current time.
    // This ensures that a different sequence of random numbers is generated on each run.
    srand((unsigned)time(NULL));

    int arr[100];      // Declare the source array with a capacity of 100 integers.
    int arrLength = 0; // Initialize the source array length to 0.
    
    // Fill the source array with random numbers.
    FillArrayWithRandomNumbers(arr, arrLength);

    int arr2[100];     // Declare the destination array to hold the odd numbers.
    int arr2Length = 0; // Initialize the destination array length to 0.

    // Copy only the odd numbers from the source array into the destination array.
    CopyOddNumbers(arr, arr2, arrLength, arr2Length);

    // Print the elements of the source array.
    cout << "\nArray 1 elements:\n";
    PrintArray(arr, arrLength);

    // Print the elements of the destination array containing only odd numbers.
    cout << "\nArray 2 Odd numbers:\n";
    PrintArray(arr2, arr2Length);

    return 0;  // Return 0 to indicate successful program execution.
}

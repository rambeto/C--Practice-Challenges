/*
Problem #02
Check and Print Prime Numbers from 1 to N.

Concepts:
- Prime Number Logic
- Mathematical Optimization (sqrt)
- Nested Logic (Function within Loop)
*/

#include <iostream>
#include <cmath>

using namespace std;

/*
-----------------------------------------------------------
Function: IsPrimeNumber
Purpose : Determines if a given number is prime.
          Optimized by checking up to the square root.
-----------------------------------------------------------
*/
bool IsPrimeNumber(int Number)
{
    // Numbers less than or equal to 1 are not prime
    if (Number <= 1)
        return false;

    // Limit the range of checks to the square root for efficiency
    int SqrtNumber = sqrt(Number);

    for (int i = 2; i <= SqrtNumber; i++)
    {
        if (Number % i == 0) // Found a divisor -> not prime
            return false;
    }

    return true;
}

/*
-----------------------------------------------------------
Function: PrintAllPrimeNumbers
Purpose : Iterates from 1 to the given limit and prints 
          whether each number is prime or not.
-----------------------------------------------------------
*/
void PrintAllPrimeNumbers(int Limit)
{
    cout << "\nPrime status for numbers from 1 to " << Limit << ":\n";
    cout << "-------------------------------------------\n";

    for (int i = 1; i <= Limit; i++)
    {
        if (IsPrimeNumber(i))
            cout << i << ": is a Prime number.\n";
        else
            cout << i << ": is Not a prime number.\n";
    }
}

int main()
{
    // Print prime status for numbers up to 100
    PrintAllPrimeNumbers(100);

    system("pause>0");
    return 0;
}

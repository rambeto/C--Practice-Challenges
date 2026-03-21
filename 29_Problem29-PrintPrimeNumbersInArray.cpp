/*
Problem #29
Copy and Print All Prime Numbers in Array.

Concepts:
- Array Traversal (Looping through elements)
- Function Reusability (IsPrimeNumber)
- Random Number Generation for Arrays
- Building a new array from filtered data
*/

#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

// دالة لتحديد ما إذا كان الرقم أولياً أم لا
bool IsPrimeNumber(int Number)
{
    if (Number <= 1)
        return false;

    int SqrtNumber = sqrt(Number);
    for (int i = 2; i <= SqrtNumber; i++)
    {
        if (Number % i == 0)
            return false;
    }
    return true;
}

// دالة لتوليد رقم عشوائي في نطاق معين
int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

// تعبئة المصفوفة بأرقام عشوائية
void FillArrayWithRandomNumbers(int arr[100], int& arrLength)
{
    cout << "\nEnter number of elements: ";
    cin >> arrLength;

    for (int i = 0; i < arrLength; i++)
    {
        arr[i] = RandomNumber(1, 100);
    }
}

// طباعة عناصر المصفوفة
void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

/*
-----------------------------------------------------------
Function: CopyPrimeNumbers
Purpose : Checks each element in arrSource, if it's prime, 
          it copies it to arrDestination.
-----------------------------------------------------------
*/
void CopyPrimeNumbers(int arrSource[100], int arrDestination[100], int arrLength, int& arrDestinationLength)
{
    arrDestinationLength = 0; // البداية من الصفر للمصفوفة الجديدة
    for (int i = 0; i < arrLength; i++)
    {
        if (IsPrimeNumber(arrSource[i]))
        {
            arrDestination[arrDestinationLength] = arrSource[i];
            arrDestinationLength++;
        }
    }
}

int main()
{
    // Seed random generator
    srand((unsigned)time(NULL));

    int arr[100], arrLength;
    int arrPrime[100], arrPrimeLength;

    FillArrayWithRandomNumbers(arr, arrLength);

    cout << "\nArray Elements: ";
    PrintArray(arr, arrLength);

    // عملية النسخ والفلترة
    CopyPrimeNumbers(arr, arrPrime, arrLength, arrPrimeLength);

    cout << "\nPrime Numbers in Array are: ";
    PrintArray(arrPrime, arrPrimeLength);

    system("pause>0");
    return 0;
}

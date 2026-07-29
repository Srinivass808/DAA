#include <iostream>
#include <chrono>
using namespace std;

// Iterative Factorial
// Time Complexity: O(n)
// Space Complexity: O(1)
int factorialIterative(int n)
{
    int fact = 1;

    for (int i = 1; i <= n; i++)
    {
        fact = fact * i;
    }

    return fact;
}

// Recursive Factorial
// Time Complexity: O(n)
// Space Complexity: O(n)
int factorialRecursive(int n)
{
    if (n == 0 || n == 1)
        return 1;

    return n * factorialRecursive(n - 1);
}

int main()
{
    int n;

    cout << "Enter a number: ";
    cin >> n;

    // Iterative
    auto start1 = chrono::high_resolution_clock::now();
    int result1 = factorialIterative(n);
    auto end1 = chrono::high_resolution_clock::now();

    // Recursive
    auto start2 = chrono::high_resolution_clock::now();
    int result2 = factorialRecursive(n);
    auto end2 = chrono::high_resolution_clock::now();

    auto time1 = chrono::duration_cast<chrono::nanoseconds>(end1 - start1);
    auto time2 = chrono::duration_cast<chrono::nanoseconds>(end2 - start2);

    cout << "\nIterative Factorial = " << result1 << endl;
    cout << "Iterative Time = " << time1.count() << " ns" << endl;

    cout << "\nRecursive Factorial = " << result2 << endl;
    cout << "Recursive Time = " << time2.count() << " ns" << endl;

    return 0;
}
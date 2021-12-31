#include <iostream>
#include <chrono>
#include <vector>
using namespace std;
using namespace std::chrono;

void IterateFibonacci(int a)
{
    int n1 = 0, n2 = 1, res = 0;
    for (int i = 0; i < a; i++)
    {
        cout << res <<" ";
        res = n1 + n2;
        n1 = n2;
        n2 = res;
    }
}

int RecursiveFibonacci(int n)
{
    if (n == 1 || n == 0) return n;
    else return RecursiveFibonacci(n - 1) + RecursiveFibonacci(n - 2);
}

int main()
{
    int n, i = 0;
    cout <<"Enter a number to see that amount of series of fibonacci:";
    cout << "\n";
    cin >> n;

    cout <<"Fibonacci Series is: \n";
    auto a = high_resolution_clock::now();
    IterateFibonacci(n);
    auto z = high_resolution_clock::now();
    auto time1 = duration_cast<milliseconds>(z - a);
    cout <<"Iterative function takes: "<< time1.count() << " millisecond(s)." << endl;

    //-------

    auto b = high_resolution_clock::now();
    while (i < n)
    {
        cout << " " << RecursiveFibonacci(i);
        i++;
    }

    auto y = high_resolution_clock::now();
    auto time2 = duration_cast<milliseconds>(y - b);
    cout <<" Recursive function takes: "<< time2.count() << " millisecond(s)." << endl;
    return 0;
}
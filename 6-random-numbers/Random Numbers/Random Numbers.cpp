#include <iostream>
#include <time.h>
using namespace std;

int main()
{
    srand((unsigned)time(0)); 
    int r, inValue;
	float numbers[21] = {};
	int storage[10000] = {};
	float ratio;

	cout << "Here you can exercise occurance chance of random numbers between 1 and 20 when you enter amount of time you want to iterate. \n ";
	cout << "Please enter amount of time ( <10.000 ) you want to iterate the random generator. \n";
	cin >> inValue;
	cout << "\n";

	for (int i = 0; i < inValue-1; i++)
	{
		r = rand() % 20 + 1; // getting number btw 1-20
		storage[i] = r;
		numbers[storage[i]]++;
	}

	for (int i = 1; i < 21; i++)
	{
		ratio = (numbers[i] / inValue) * 100;
		cout << "Number " << i << "'s occurance = " << numbers[i] << "and occurance ratio amongs the other numbers is %" << ratio << endl;
	}
}

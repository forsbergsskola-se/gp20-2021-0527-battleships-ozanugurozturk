#include <iostream>
#include <ctime>

using namespace std;

const int rows = 10;
const int columns = 10;

int maxShips = 10;

int matrix[rows][columns];

void Clear() 
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			matrix[i][j] = 0;
		}
	}
}

void Show() 
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

int ShipsAmount()
{
	int counter = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (matrix[i][j] ==1)
			{
				counter++;
			}
		}
	}
	return counter;
}

void ShipLocator()
{
	int ships = 0;

	while (ships < maxShips)
	{
		int x = rand() % rows;
		int y = rand() % columns;

		if (matrix[x][y] != 1)
		{
			ships++;
			matrix[x][y] = 1;
		}

	}
}

bool Attack(int row, int column)
{
	if (matrix[row][column] == 1)
	{
		matrix[row][column] = 8;
		return true;
	}
	else return false;
}

int main()
{
	srand(time(NULL));
	Clear();
	
	int x, y;
	
	cout << "Welcome to BATTLESHIPS game. You have a '10 x 10 grid' and you need to give coordinates to attack a certain location." << endl;
	cout << endl;
	Show();
	cout << endl;
	ShipLocator();
	while (true)
	{
		cout << "please select a coordinate to attack" << endl;
		cout << "x: "; cin >> x;
		cout << endl;
		cout << "y: "; cin >> y;
		cout << endl;
		if (Attack(x,y))
		{
			cout << "You hit a ship." << endl;
		}
		else
		{
			cout << "Miss..." << endl;
		}
		cout << "Number of ships left on the grid: " << ShipsAmount() << endl;
	}

	system("pause");
	return 0;
}

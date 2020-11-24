
#include <iostream>
#include <iomanip>
#include <time.h>
#include <Windows.h>

using namespace std;

void Create(int** a, const int row, const int col, const int Low, const int High);
void Print(int** a, const int row, const int col);
void Change(int** a, const int row, const int col);
int IMinEven(int** a, const int row, const int colNo);
int IMaxOdd(int** a, const int row, const int colNo);

int main()
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand((unsigned)time(NULL));

	int Low = 7;
	int High = 65;

	int row;
	int col;

	cout << "Кількість рядків = "; cin >> row;
	cout << "Кількість стовпчиків = "; cin >> col;

	int** a = new int* [row];
	for (int i = 0; i < row; i++)
		a[i] = new int[col];

	cout << "Оригінальний массив" << endl;
	Create(a, row, col, Low, High);
	Print(a, row, col);

	cout << "Модифікований массив" << endl;
	Change(a, row, col);
	Print(a, row, col);

	for (int i = 0; i < row; i++)
		delete[] a[i];
	delete[] a;

	system("pause");
	return 0;
}

void Create(int** a, const int row, const int col, const int Low, const int High)
{
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int row, const int col)
{
	cout << endl;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}



int IMinEven(int** a, const int row, const int colNo)
{
	int min = a[0][colNo];
	int imin = 0;
	for (int r = 2; r < row; r++)
	{
		if (a[r][colNo] < min)
		{
			min = a[r][colNo];
			imin = r;
		}
	}
	return imin;
}

int IMaxOdd(int** a, const int row, const int colNo)
{
	int max = a[0][colNo];
	int imax = 0;
	for (int r = 2; r < row; r++)
	{
		if (a[r][colNo] > max)
		{
			max = a[r][colNo];
			imax = r;
		}
	}
	return imax;
}
void Change(int** a, const int row, const int col)
{
	int imin, imax, min, max;
	for (int j = 1; j < col; j += 2)
	{
		imin = IMinEven(a, row, j);
		min = a[imin][j];
		imax = IMaxOdd(a, row, j - 1);
		max = a[imax][j - 1];

		a[imin][j] = max;
		a[imax][j - 1] = min;
	}
}
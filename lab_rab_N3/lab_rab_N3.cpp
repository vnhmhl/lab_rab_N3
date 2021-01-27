#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

double func(double x, int n)
{
	double rez = 0;
	for (int i = 1; i <= n; i++)
	{
		rez += cos(i * x) / i;
	}
	return rez;
}

double func(double x, double eps)
{
	double an = 0;
	double prev = 0;
	double rez = cos(x);
	int i = 2;
	do
	{
		an = cos(i * x) / i;
		prev = rez;
		rez += an;
		i++;
	} while (abs(prev - rez) > eps);
	return rez;
}

double func(double x) 
{
	double rez = -log(abs(2 * sin(x / 2)));
	return rez;
}

int main()
{
	double a = M_PI / 5;
	double b = 9 * M_PI / 5;
	for (int k = 0; k < 10; k++)
	{
		double x = a + k * ((b - a) / 10);
		double sn = func(x, 40);
		double se = func(x, 0.0001);
		double y = func(x);
		cout << setw(5) << "X=" << setw(13) << fixed << setprecision(5) << x;
		cout << setw(5) << "SN=" << setw(13) << setprecision(5) << sn;
		cout << setw(5) << "SE=" << setw(13) << setprecision(5) << se;
		cout << setw(5) << "Y=" << setw(13) << setprecision(5) << y;
		cout << endl;
	}
	system("pause");
	return 0;
}

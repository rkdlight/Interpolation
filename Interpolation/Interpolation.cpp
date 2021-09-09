#include <iostream>
#include <cmath>

using namespace std;

double polinom(double* xi, double* yi, double x, int n = 3) {
	double y = 0;
	double p = 1;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			if (k != i) {
				p *= (x - xi[k]) / (xi[i] - xi[k]);
			}
		}
		y += yi[i] * p;
		p = 1;
	}

	return y;
}

double Max(double* arr, int n) {
	double max = arr[0];

	for (int i = 0; i < n; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	return max;
}

double Min(double* arr, int n) {
	double min = arr[0];

	for (int i = 0; i < n; i++) {
		if (arr[i] < min) {
			min = arr[i];
		}
	}
	return min;
}

double func(double x) {

	return pow(log(x), 10.0 / 9.0);

}

int main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	double max, min, x, y;
	cout << "Введите количество начальных точек: ";
	cin >> n;
	double* xi = new double[n];
	double* yi = new double[n];
	for (int i = 0; i < n; i++) {
		// Заполнение массива и вывод значений его элементов
		cout << "Введите координату X точки " << i << ":\n";
		cout << "X" << i << ": ";
		cin >> xi[i];
		yi[i] = func(xi[i]);
	}
	max = Max(xi, n);
	min = Min(xi, n);

	for (int i = 0; i < n; i++) {
		cout << "( " << xi[i] << ", " << yi[i] << " )\n";
	}
	do {
		cout << "Введите X для вычисления функции больше " << min << " и меньше " << max << ": ";
		cin >> x;
	} while (!(x >= min && x <= max));
	
	y = polinom(xi, yi, x, n);
	
	cout << "Y: " << y << "\n";

	system("pause");
	return 0;
}
#include <iostream>

using namespace std;

template <typename T>
void read(T [], int);

template <typename T>
void bubble_sort(T [], int);

template <typename T>
void show(T [], int);

int main(void)
{
	cout << "enter number of elements : ";
	int n;
	cin >> n;

	cout << "enter integers : ";
	int x[n];
	read<int>(x, n);

	cout << "enter floating point numbers : ";
	double y[n];
	read<double>(y, n);

	cout << "enter characters : ";
	char z[n];
	read<char>(z, n);

	bubble_sort<int>(x, n);
	bubble_sort<double>(y, n);
	bubble_sort<char>(z, n);

	show<int>(x, n);
	show<double>(y, n);
	show<char>(z, n);

	return 0;
}
template <typename T>
void read (T x[], int n)
{
	for (int i = 0; i < n; i++) {

		cin >> x[i];
	}
}
template <typename T>
void bubble_sort(T x[], int n)
{
	for(int i = 0; i < n; i++) {

		for(int j = 0; j < n - i - 1; j++) {

			if(x[j] > x[j + 1]) {
				
				swap(x[j], x[j + 1]);
			}
		}
	}
}
template <typename T>
void show(T x[], int n)
{
	for(int i = 0; i < n; i++) {

		cout << x[i] << " ";
	}
	cout << endl;
}














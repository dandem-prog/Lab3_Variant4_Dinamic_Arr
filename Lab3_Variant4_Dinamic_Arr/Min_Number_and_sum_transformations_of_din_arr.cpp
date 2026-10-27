#include <iostream>
#include <ctime>
#include <cstdint>
using std::cout;
using std::cin;
void shift(int* arr, int start, int end) {
	int temp = arr[end];
	for (int i = end; i > start; --i) {
		arr[i] = arr[i - 1];
	}
	arr[start] = temp;
}
int main() {
	int n;
	cout << "enter number of elements in arr\n";
	cin >> n;
	if (n < 0) {
		cout << "error";
		return 0;
	}
	int* arr = new int[n] {};
	cout << "enter elements of arr\n";
	for (int32_t i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	int min_n = 0;
	for (int32_t i = 0; i < n; ++i) {
		if (arr[i] <= arr[min_n]) min_n = i;
	}
	++min_n;
	int first_negative = 0;
	int first_neg_num = 0;
	int sum = 0;
	for (int32_t i = 0; i < n; ++i) {
		if (arr[i] < first_negative) {
			first_negative = arr[i];
			first_neg_num = i;
			break;
		}
	}
	int last_negative = 0;
	int last_neg_num = 0;
	for (int32_t i = 0; i < n; ++i) {
		if (arr[i] < 0) {
			last_negative = arr[i];
			last_neg_num = i;
		}
	}
	for (int32_t i = first_neg_num + 1; i < last_neg_num; ++i) sum += arr[i];
	cout << "number of min(max of all minimal) element = " << min_n << "\nsum of elements between first and last negative numbers = " << sum << "\nenter X\n";
	int X;
	cin >> X;
	int temp = -1;
	for (int32_t i = 0; i < n; ++i) {
		if (abs(arr[i]) > X && temp == -1) {
			temp = i;
		}
		if (temp != -1 && abs(arr[i]) <= X) {
			shift(arr, temp, i);
			++temp;
		}
	}
	cout << "new arr : ";
	for (int32_t i = 0; i < n; ++i) {
		cout << arr[i] << " ";
	}
	cout << '\n';
	delete[] arr;
	// second task with random elements
	int* arr_rnd = new int[n]{};
	int a, b;
	cout << "enter a,b\n";
	cin >> a >> b;
	srand(time(0));
	for (int32_t i = 0; i < n; ++i) {
		arr_rnd[i] = a + rand() % (b - a + 1);
	}
	cout << "new random arr : ";
	for (int32_t i = 0; i < n; ++i) {
		cout << arr_rnd[i] << " ";
	}
	cout << '\n';
	min_n = 0;
	for (int32_t i = 0; i < n; ++i) {
		if (arr_rnd[i] <= arr_rnd[min_n]) min_n = i;
	}
	++min_n;
	first_negative = 0;
	first_neg_num = 0;
	sum = 0;
	for (int32_t i = 0; i < n; ++i) {
		if (arr_rnd[i] < first_negative) {
			first_negative = arr_rnd[i];
			first_neg_num = i;
			break;
		}
	}
	last_negative = 0;
	last_neg_num = 0;
	for (int32_t i = 0; i < n; ++i) {
		if (arr_rnd[i] < 0) {
			last_negative = arr_rnd[i];
			last_neg_num = i;
		}
	}
	for (int32_t i = first_neg_num + 1; i < last_neg_num; ++i) sum += arr_rnd[i];
	cout << "number of min(max of all minimal) element = " << min_n << "\nsum of elements between first and last negative numbers = " << sum << "\nenter X\n";
	temp = -1;
	for (int32_t i = 0; i < n; ++i) {
		if (abs(arr_rnd[i]) > X && temp == -1) {
			temp = i;
		}
		if (temp != -1 && abs(arr_rnd[i]) <= X) {
			shift(arr_rnd, temp, i);
			++temp;
		}
	}
	cout << "new (random)arr : ";
	for (int32_t i = 0; i < n; ++i) {
		cout << arr_rnd[i] << " ";
	}
	cout << '\n';
	delete[] arr_rnd;
	return 0;
}
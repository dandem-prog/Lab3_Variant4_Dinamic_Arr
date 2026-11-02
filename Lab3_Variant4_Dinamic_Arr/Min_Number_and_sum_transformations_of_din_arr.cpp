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
int num_of_min_el_array(int* arr,int n) {
	int min_n = 0;
	for (int32_t i = 0; i < n; ++i) {
		if (arr[i] <= arr[min_n]) min_n = i;
	}
	++min_n;
	return min_n;
}
int sum_between_first_and_last_negative_el_of_arr(int *arr,int n) {
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
	return sum;
}
void enter_el_of_arr(int* arr, int n) {
	for (int32_t i = 0; i < n; ++i) {
		cin >> arr[i];
	}
}
void change_arr_lower_x(int* arr, int n, int X) {
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
}
void arr_out(int* arr, int n) {
	for (int32_t i = 0; i < n; ++i) {
		cout << arr[i] << " ";
	}
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
	enter_el_of_arr(arr,n);
	cout << "number of min(max of all minimal) element = " << num_of_min_el_array(arr,n) << "\nsum of elements between first and last negative numbers = " << sum_between_first_and_last_negative_el_of_arr(arr,n) << "\nenter X\n";
	int X;
	cin >> X;
	change_arr_lower_x(arr, n, X);
	cout << "new arr : ";
	arr_out(arr, n);
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
	arr_out(arr_rnd, n);
	cout << '\n';
	cout << "number of min(max of all minimal) element = " << num_of_min_el_array(arr_rnd,n) << "\nsum of elements between first and last negative numbers = " << sum_between_first_and_last_negative_el_of_arr(arr_rnd,n) << "\nenter X\n";
	change_arr_lower_x(arr_rnd, n, X);
	cout << "new (random)arr : ";
	arr_out(arr_rnd, n);
	cout << '\n';
	delete[] arr_rnd;
	return 0;
}
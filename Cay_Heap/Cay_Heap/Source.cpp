#include <iostream>
using namespace std;
int n = 0;
void max_heap(int a[], int i) {
	if (i < 0) return;
	if (a[i] < a[2 * i + 1] && a[i]<a[2*i+2]) {
		int inew = 0;
		if (a[2 * i + 1] > a[2 * i + 2]) {
			inew = 2 * i + 1;
		}
		else {
			inew = 2 * i + 2;
		}
		swap(a[i], a[inew]);
		max_heap(a, inew);
	}
	else if (a[i] < a[2 * i + 1] && a[i] >= a[2 * i + 2]) {
		swap(a[i], a[2 * i + 1]);
		max_heap(a, 2 * i + 1);
	}
	else if (a[i] >= a[2 * i + 1] && a[i] < a[2 * i + 2]) {
		swap(a[i], a[2 * i + 2]);
		max_heap(a, 2 * i + 2);
	}
	
	max_heap(a, i - 1);
}
void min_heap(int a[], int i) {
	if (i < 0 || (2*i+1)>=n ) return;
	if (a[i] > a[2 * i + 1] && a[i] > a[2 * i + 2]) {
		int inew = 0;
		if (a[2 * i + 1] < a[2 * i + 2]) {
			inew = 2 * i + 1;
		}
		else {
			inew = 2 * i + 2;
		}
		swap(a[i], a[inew]);
		min_heap(a, inew);
	}
	else if (a[i] > a[2 * i + 1] && a[i] <= a[2 * i + 2]) {
		swap(a[i], a[2 * i + 1]);
		min_heap(a, 2 * i + 1);
	}
	else if (a[i] <= a[2 * i + 1] && a[i] > a[2 * i + 2]) {
		swap(a[i], a[2 * i + 2]);
		min_heap(a, 2 * i + 2);
	}

	min_heap(a, i - 1);
}
int main() {

	int a[1000];
	int x = 0;

	while (cin >> x) {
		a[n++] = x;
	}
	min_heap(a, n / 2 - 1);
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	return 0;
}
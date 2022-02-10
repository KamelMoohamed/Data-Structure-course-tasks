#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int const N = 2e5;
	int arr[N];
 
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
 
	sort(arr, arr + n);
	if (arr[0] == 1 && k == 0) {
		cout << -1;
	}
	else if (arr[0] >= 1 && k == 0) {
		cout << 1;
	}
	else if (k <= n - 1) {
		if (arr[k - 1] != arr[k]) {
			cout << arr[k - 1];
		}
		else {
			cout << -1;
		}
	}
	else if (k == n) {
		cout << arr[k - 1];
	}
	return 0;
}

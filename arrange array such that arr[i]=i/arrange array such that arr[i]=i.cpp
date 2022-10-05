#include<iostream>
#include<unordered_set>
using namespace std;

// NAIVE APPROACH //

void rearrange(int arr[], int n) {
	int i, j, temp;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (arr[j] == i) {
				temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
				break;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (arr[i] != i) {
			arr[i] = -1;
		}
	}
}
// USING SET //
void fixArray(int arr[], int n)
{
	unordered_set<int> s;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] != -1)
			s.insert(arr[i]);
	}
	for (int i = 0; i < n; i++)
	{
		if (s.find(i) != s.end())
		{
			arr[i] = i;
		}
		else
		{
			arr[i] = -1;
		}
	}
}
int main() {
	int arr[] = { 2,4,3,5,8,7,6 };
	int n = sizeof(arr) / sizeof(arr[0]);
	rearrange(arr, n);
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	fixArray(arr, n);
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

}
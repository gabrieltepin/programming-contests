#include <iostream>
#include <climits>
using namespace std;

// Function to print an array arr of size n
void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";

	cout << endl;
}

// Function to find maximum value of the expression
// (A[s] - A[r] + A[q] - A[p]) where s > r > q > p
void maximizeExpression(int A[], int n)
{
	// create 4 lookup tables and initialize them to INT_MIN
	int L1[n + 1], L2[n], L3[n - 1], L4[n - 2];

	for (int i = 0; i <= n - 3; i++)
		L1[i] = L2[i] = L3[i] = L4[i] = INT_MIN;

	L1[n - 2] = L2[n - 2] = L3[n - 2] = INT_MIN;
	L1[n - 1] = L2[n - 1] = L1[n] = INT_MIN;

	// L1[] stores the maximum value of A[l]
	for (int i = n - 1; i >= 0; i--)
		L1[i] = max(L1[i + 1], A[i]);

	// L2[] stores the maximum value of A[l] - A[k]
	for (int i = n - 2; i >= 0; i--)
		L2[i] = max(L2[i + 1], L1[i + 1] - A[i]);

	// L3[] stores the maximum value of A[l] - A[k] + A[j]
	for (int i = n - 3; i >= 0; i--)
		L3[i] = max(L3[i + 1], L2[i + 1] + A[i]);

	// L4[] stores the maximum value of A[l] - A[k] + A[j] - A[i]
	for (int i = n - 4; i >= 0; i--)
		L4[i] = max(L4[i + 1], L3[i + 1] - A[i]);

	// maximum value would be present at L4[0]
	for (int i=0; i < sizeof(L1)/sizeof(L1[0]) ; i++) cout << L1[i] << " "; cout << endl;
    for (int i=0; i < sizeof(L2)/sizeof(L2[0]) ; i++) cout << L2[i] << " "; cout << endl;
    for (int i=0; i < sizeof(L3)/sizeof(L3[0]) ; i++) cout << L3[i] << " "; cout << endl;
    for (int i=0; i < sizeof(L4)/sizeof(L4[0]) ; i++) cout << L4[i] << " "; cout << endl;

}

// Maximize value of the expression
int main()
{
	int A[] = {1, 10, 1, 20, 10, 1};
	int n = sizeof(A) / sizeof(A[0]);

	// array should have atleast 4 elements
    for (int i=0;i < 6; i++) cout << A[i] << " "; cout << endl;
	if (n >= 4)
		maximizeExpression(A, n);

	return 0;
}
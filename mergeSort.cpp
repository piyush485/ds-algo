// Divide and Conquer 
// 1. keep dividing the problem into sub-problems until the solution of subproblems is trivial.
// 2. solve the subproblems.
// 3. merge the subsolutions to make the solutions of main problem.


#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    mergeSort(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
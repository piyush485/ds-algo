//binary search
//array should be sorted
/*we have to take left and right variable
then find mid = n/2
if
  data > arr[mid], we have to search in right part
  and then point left to (mid + 1)
  then again find mid

if
  data < arr[mid], we have to serch in left part
  and then point right to (mid - 1)
  then again find mid

left == right == mid

if element is found then


*********
best time = O(1)
time complexicity = log(n)
*/

#include <iostream>
using namespace std;

int binarysearch(int *arr, int n, int data)
{
  int l = 0;
  int r = n - 1;
  int flag = 0;
  while (l <= r)
  {
    int mid = (l + r) / 2;
    if (data == arr[mid])
    {
      return mid;
    }
    if (data < arr[mid])
    {
      r = mid - 1;
    }
    else
      l = mid + 1;
  }
  return -1;
}

int main()
{
  int n;
  cout << "enter limit: ";
  cin >> n;
  int arr[n];
  int i;
  cout << "enter elements: ";
  for (i = 0; i < n; i++)
    cin >> arr[i];
  int data;
  cout << "enter the element: ";
  cin >> data;
  int found;
  found = binarysearch(arr, n, data);
  /*
   (result == -1) ? cout << "Element is not present in array" : cout << "Element is present at index " << result;
*/
  if(found == -1)
    cout<<"not found!";
  else
  {
    cout<<"found at "<<found + 1<<" position";
  }

  return 0;
}
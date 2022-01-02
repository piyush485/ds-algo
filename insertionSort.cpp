// in this sort we have assume that the left side of the array is sorted and then try to sort the right side of the array by taking the split method 

#include<bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int n){
    for(int i = 0 ; i < n ; i++ ){
        int j(i-1), temp(arr[i]);
        while(j >= 0 && arr[j] > temp){
            arr[j+1] = arr[j];
            j -= 1;
        }
        arr[j+1] = temp;
    }
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0 ; i < n ; i++ )   cin >> arr[i];
    insertionSort(arr, n);

    for(int i = 0 ; i < n ; i++ )   cout << arr[i] << " ";
    return 0;   
}
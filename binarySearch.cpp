#include <bits/stdc++.h>
using namespace std; 

int binarySearch(int arr[], int l, int r, int x){
  //considering the array is sort in ascending order
  //l = left, r = right, x = element
  while(l<=r){ 
    int mid = (l+r)/2;
    if(arr[mid]==x) return mid;
    else if(arr[mid]<x){
      l=mid+1;
    }
    else r = mid-1;
  }
  return -1;
}

int main() {
  int arr[] = {0,1,2,3,4,5};
  int n=6; //size of the array

  printf("%d", binarySearch(arr, 0, n-1, 3)); //I wanna know where is the 3
}

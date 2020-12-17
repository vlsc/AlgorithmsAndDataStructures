#include <bits/stdc++.h>
using namespace std;

//asc. order
void selectionSort(int Arr[], int n){
  int min, aux, j, i;
  for(i=0;i<n-1;i++){ //i<=n-2
    min = i;
    for(j=i+1;j<n;j++){ //j<=n-1
      if (Arr[j]<Arr[min]) min = j;
    }
    //swapping the 1st with the smallest
    aux = Arr[i]; 
    Arr[i]=Arr[min];
    Arr[min]=aux;
  }
}

//des. order
void insertionSort(int Arr[], int n){
  int v, j, i;
  for(i=1;i<n;i++){
    v = Arr[i];
    j = i-1;
    while (j>=0 && Arr[j]<v){ //move the smaller to right
      Arr[j+1] = Arr[j];
      j--;
    }
    Arr[j+1] = v; //move the bigger to left
  }
}

int main() {
  int Arr[]={5,9,8,2,7,1,3,4,0,6};
  int n = 10;
  printf("Before selection sort:\n");
  for(int i=0;i<n;i++){
    printf("%d ", Arr[i]);
  }
  selectionSort(Arr, n);
  printf("\nAfter selection sort:\n");
  for(int i=0;i<n;i++){
    printf("%d ", Arr[i]);
  }
  insertionSort(Arr, n);
  printf("\nAfter insertion sort:\n");
  for(int i=0;i<n;i++){
    printf("%d ", Arr[i]);
  }
}

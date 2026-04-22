#include "merge_sort.h"

void merge(std::vector<long long>& A, int left, int mid, int right){
  int n1 = mid - left+1;
  int n2 = right - mid;

  std::vector<long long> v_left(n1), v_right(n2);

  for(int i = 0; i < n1; i++){
    v_left[i] = A[left+i];
  }

  for(int i = 0; i < n2; i++){
    v_right[i] = A[mid+1+i];
  }

  int i = 0;
  int j = 0;
  int k = left;

  while(i < n1 && j < n2){
    if(v_left[i] <= v_right[j]){
      A[k] = v_left[i];
      i++;
    }
    else{
      A[k] = v_right[j];
      j++;
    }
    k++;
  }

  while(i < n1){
    A[k] = v_left[i];
    i++;
    k++;
  }

  while(j < n2){
    A[k] = v_right[j];
    j++;
    k++;
  }
}

void mergeSort(std::vector<long long>& A, int left, int right) {
  if(left < right){
    int mid = left + (right - left)/2;
    mergeSort(A, left, mid);
    mergeSort(A, mid+1, right);
    merge(A, left, mid, right);
  }
}

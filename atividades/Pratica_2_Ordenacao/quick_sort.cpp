#include "quick_sort.h"

int partition(std::vector<long long>& A, int low, int high){
  long long pivo = A[high];
  int i = low - 1;

  for(int j = low; j <= high -1; j++){
    if(A[j] < pivo){
      i++;
      std::swap(A[i], A[j]);
    }
  }

  std::swap(A[i+1], A[high]);

  return i+1;
}

void quickSort(std::vector<long long>& A, int low, int high) {
  if(low < high){
    int aux = partition(A, low, high);

    quickSort(A, low, aux-1);
    quickSort(A, aux+1, high);
  }
}

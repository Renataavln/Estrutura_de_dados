#include <iostream>
#include <vector>

int partition(std::vector<int>& A, int low, int high){
  int pivo = A[high];
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

void quickSort(std::vector<int>& A, int low, int high) {
  if(low < high){
    int aux = partition(A, low, high);

    quickSort(A, low, aux-1);
    quickSort(A, aux+1, high);
  }
}

void imprimirVetor(const std::vector<int>& A) {
  for (int num : A) {
    std::cout << num << " ";
  }
  std::cout << "\n";
}

int main() {
  std::vector<int> meuVetor = {12, 11, 13, 5, 6, 1, 8, 20};
  int n = meuVetor.size();

  std::cout << "Vetor original: ";
  imprimirVetor(meuVetor);

  quickSort(meuVetor, 0, n-1);

  std::cout << "Vetor ordenado: ";
  imprimirVetor(meuVetor);

  return 0;
}

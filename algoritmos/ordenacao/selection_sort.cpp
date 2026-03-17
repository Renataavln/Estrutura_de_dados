#include <iostream>
#include <vector>

void selectionSort(std::vector<int>& A, int n) {
  int i_min, aux;

  for(int i = 0; i <= n-2; i++){
    i_min = i;

    for(int j = i+1; j <= n-1; j++){
      if(A[j] < A[i_min]){
        i_min = j;
      }
    }

    if(A[i] != A[i_min]){
      aux = A[i];
      A[i] = A[i_min];
      A[i_min] = aux;
    }
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

  selectionSort(meuVetor, n);

  std::cout << "Vetor ordenado: ";
  imprimirVetor(meuVetor);

  return 0;
}

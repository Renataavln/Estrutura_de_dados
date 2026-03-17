#include <iostream>
#include <vector>

void insertionSort(std::vector<int>& A, int n) {
  int pivo, j;
 
  for(int i = 1; i <= n-1; i++){
    pivo = A[i];
    j = i - 1;
    
    while((j >= 0) && (A[j] > pivo)){
      A[j+1] = A[j];
      j = j - 1;
    }

    A[j+1] = pivo;
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

  insertionSort(meuVetor, n);

  std::cout << "Vetor ordenado: ";
  imprimirVetor(meuVetor);

  return 0;
}

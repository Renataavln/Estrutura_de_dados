#include <iostream>
#include <vector>

void quickSort(std::vector<int>& A, int n) {
  
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

  quickSort(meuVetor, n);

  std::cout << "Vetor ordenado: ";
  imprimirVetor(meuVetor);

  return 0;
}

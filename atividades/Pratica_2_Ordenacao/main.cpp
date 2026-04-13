#include <iostream>
#include <vector>
#include "merge_sort.h"
#include "quick_sort.h"

void imprimirVetor(const std::vector<int>& A) {
  for (int num : A) {
    std::cout << num << " ";
  }
  std::cout << "\n";
}

int main() {
    int n;
    std::cout << "Digite o tamanho do vetor: ";
    if (!(std::cin >> n)) return 0; // Sai se não houver entrada

    std::vector<int> vetorBase(n);
    std::cout << "Digite os " << n << " elementos:\n";
    for(int i = 0; i < n; i++){
        std::cin >> vetorBase[i];
    }

    // Criar cópias para testar cada algoritmo
    std::vector<int> vetorMerge = vetorBase;
    std::vector<int> vetorQuick = vetorBase;

    std::cout << "\n--- Testando Merge Sort ---\n";
    std::cout << "Vetor original: ";
    imprimirVetor(vetorMerge);
    mergeSort(vetorMerge, 0, n - 1);
    std::cout << "Vetor ordenado: ";
    imprimirVetor(vetorMerge);

    std::cout << "\n--- Testando Quick Sort ---\n";
    std::cout << "Vetor original: ";
    imprimirVetor(vetorQuick);
    quickSort(vetorQuick, 0, n - 1);
    std::cout << "Vetor ordenado: ";
    imprimirVetor(vetorQuick);

    return 0;
}

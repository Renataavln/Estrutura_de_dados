#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <chrono>
#include "merge_sort.h"
#include "quick_sort.h"

std::vector<long long> lerInstancia(const std::string& nomeArquivo) {
    std::vector<long long> vetor;
    std::ifstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo: " << nomeArquivo << "\n";
        return vetor;
    }
    
    int n;
    if (arquivo >> n) {
        long long valor;
        for (int i = 0; i < n && arquivo >> valor; i++) {
            vetor.push_back(valor);
        }
    }
    return vetor;
}

int main(int argc, char* argv[]) { 
  std::vector<int> tamanhos = {1000, 10000, 100000}; 
  int numInstancias = 4;
  std::string pasta = "instancias-num/";
  
  if (argc > 1) {
      pasta = argv[1];
      if (pasta.back() != '/') {
          pasta += "/";
      }
  }

  std::ofstream arquivoSaida("resultados_tempo.txt");
  if (!arquivoSaida.is_open()) {
      std::cerr << "Erro ao criar o arquivo de saída\n";
      return 1;
  }

  arquivoSaida << "Resultados (Tempo em milissegundos)\n";
  arquivoSaida << "Pasta de origem: " << pasta << "\n";
  arquivoSaida << "--------------------------------------------------\n";

  double tempoTotalMerge = 0.0;
  double tempoTotalQuick = 0.0;

  for (int tamanho : tamanhos) {
      arquivoSaida << "\n=== Testando vetores de tamanho: " << tamanho << " ===\n";
      std::cout << "Processando tamanho: " << tamanho << " na pasta: " << pasta << "\n";

      for (int i = 1; i <= numInstancias; i++) {
          std::string nomeArquivo = pasta + "num." + std::to_string(tamanho) + "." + std::to_string(i) + ".in";
          
          std::vector<long long> vetorOriginal = lerInstancia(nomeArquivo);
            
          if (vetorOriginal.empty()) continue;

          std::vector<long long> vetorParaMerge = vetorOriginal;
          std::vector<long long> vetorParaQuick = vetorOriginal;
          int n = vetorOriginal.size();

          // Avaliando o Merge Sort
          auto inicioMerge = std::chrono::high_resolution_clock::now();
          mergeSort(vetorParaMerge, 0, n - 1);
          auto fimMerge = std::chrono::high_resolution_clock::now();
            
          std::chrono::duration<double, std::milli> duracaoMerge = fimMerge - inicioMerge;
          tempoTotalMerge += duracaoMerge.count();

          // Avaliando o Quick Sort
          auto inicioQuick = std::chrono::high_resolution_clock::now();
          quickSort(vetorParaQuick, 0, n - 1);
          auto fimQuick = std::chrono::high_resolution_clock::now();
            
          std::chrono::duration<double, std::milli> duracaoQuick = fimQuick - inicioQuick;
          tempoTotalQuick += duracaoQuick.count();

          arquivoSaida << "Instância " << i << ":\n";
          arquivoSaida << "  - Merge Sort: " << duracaoMerge.count() << " ms\n";
          arquivoSaida << "  - Quick Sort: " << duracaoQuick.count() << " ms\n";
      }
  }

  arquivoSaida << "\n==================================================\n";
  arquivoSaida << "TEMPO TOTAL GERAL:\n";
  arquivoSaida << "Total Merge Sort: " << tempoTotalMerge << " ms\n";
  arquivoSaida << "Total Quick Sort: " << tempoTotalQuick << " ms\n";

  arquivoSaida.close();
  std::cout << "\nProcessamento concluído. Resultado salvo no arquivo 'resultados_tempo.txt'.\n";

  return 0;
}

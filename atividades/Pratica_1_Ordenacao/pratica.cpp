#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <chrono>


void insertionSort(std::vector<long long>& A, int n) {
  long long pivo;
  int j;
 
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

void selectionSort(std::vector<long long>& A, int n) {
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

std::vector<long long> lerInstancia(const std::string& caminhoArquivo) {
  std::ifstream arquivo(caminhoArquivo);
  std::vector<long long> vetor;

  if (!arquivo.is_open()) {
      std::cerr << "Erro ao abrir o arquivo: " << caminhoArquivo << "\n";
      return vetor; 
  }

  int n;
  if (arquivo >> n) {
      vetor.reserve(n);
      long long numero; 
      while (arquivo >> numero) {
          vetor.push_back(numero);
      }
  }

  arquivo.close();
  return vetor;
}

int main() { 
  std::vector<int> tamanhos = {1000, 10000, 100000};
  int numInstancias = 4;
  std::string pasta = "instancias-num/";
 
  std::ofstream arquivoSaida("resultados_tempo.txt");
  if (!arquivoSaida.is_open()) {
      std::cerr << "Erro ao criar o arquivo de saída\n";
      return 1;
  }

  arquivoSaida << "Resultados (Tempo em milissegundos)\n";
  arquivoSaida << "--------------------------------------------------\n";

  double tempoTotalInsertion = 0.0;
  double tempoTotalSelection = 0.0;

  for (int tamanho : tamanhos) {
      arquivoSaida << "\n=== Testando vetores de tamanho: " << tamanho << " ===\n";
      std::cout << "Processando tamanho: " << tamanho << "\n";

      for (int i = 1; i <= numInstancias; i++) {
          std::string nomeArquivo = pasta + "num." + std::to_string(tamanho) + "." + std::to_string(i) + ".in";
          
          std::vector<long long> vetorOriginal = lerInstancia(nomeArquivo);
            
          if (vetorOriginal.empty()) continue;

          std::vector<long long> vetorParaInsertion = vetorOriginal;
          std::vector<long long> vetorParaSelection = vetorOriginal;
          int n = vetorOriginal.size();

          auto inicioInsertion = std::chrono::high_resolution_clock::now();
          insertionSort(vetorParaInsertion, n);
          auto fimInsertion = std::chrono::high_resolution_clock::now();
            
          std::chrono::duration<double, std::milli> duracaoInsertion = fimInsertion - inicioInsertion;
          tempoTotalInsertion += duracaoInsertion.count();

          auto inicioSelection = std::chrono::high_resolution_clock::now();
          selectionSort(vetorParaSelection, n);
          auto fimSelection = std::chrono::high_resolution_clock::now();
            
          std::chrono::duration<double, std::milli> duracaoSelection = fimSelection - inicioSelection;
          tempoTotalSelection += duracaoSelection.count();

          arquivoSaida << "Instância " << i << ":\n";
          arquivoSaida << "  - Insertion Sort: " << duracaoInsertion.count() << " ms\n";
          arquivoSaida << "  - Selection Sort: " << duracaoSelection.count() << " ms\n";
      }
  }

  arquivoSaida << "\n==================================================\n";
  arquivoSaida << "TEMPO TOTAL GERAL:\n";
  arquivoSaida << "Total Insertion Sort: " << tempoTotalInsertion << " ms\n";
  arquivoSaida << "Total Selection Sort: " << tempoTotalSelection << " ms\n";

  arquivoSaida.close();
  std::cout << "\nProcessamento concluído. Resultado salvo no arquivo 'resultados_tempo.txt'.\n";

  return 0;
}

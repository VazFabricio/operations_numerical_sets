#include "iostream"
#include <vector>
#include <chrono>

void exibeVetor(std::vector<int> vetor){
    for (int i = 0; i < vetor.size(); i++) {
        std::cout << vetor[i] << " ";
    }
    std::cout << std::endl;
}

std::vector<int> intersectionSets(std::vector<std::vector<int>> &vectors) {
    std::vector<int> result; // vetor que irá armazenar a intersecção dos vetores

    if (vectors.empty()) {
        return result; // se não houver vetores, retorna um vetor vazio
    }

    std::vector<int> firstVector = vectors[0]; // pega o primeiro vetor da lista

    // percorre todos os valores do primeiro vetor
    for (int i = 0; i < firstVector.size(); i++) {
        int currentValue = firstVector[i]; // pega o valor atual
        int count = 1; // inicializa o contador com 1, porque o valor atual já está no primeiro vetor

        // percorre os outros vetores
        for (int j = 1; j < vectors.size(); j++) {
            std::vector<int> currentVector = vectors[j]; // pega o vetor atual
            int found = 0; // inicializa a variável found como 0, porque o valor atual ainda não foi encontrado

            // procura o valor atual no vetor atual
            for (int k = 0; k < currentVector.size(); k++) {
                if (currentVector[k] == currentValue) { // se o valor atual for encontrado, marca found como 1
                    found = 1;
                    break;
                }
            }
            // se o valor atual não for encontrado no vetor atual, sai do loop interno
            if (found == 0) {
                break;
            }
            // se o valor atual for encontrado no vetor atual, incrementa o contador
            count++;
        }
        // se o contador for igual ao número total de vetores, adiciona o valor atual ao vetor de resultados, pois siguinifica que ele foi encontrado em todos os vetores
        if (count == vectors.size()) {
            result.push_back(currentValue);
        }
    }
    return result; // retorna o vetor de intersecção
}

std::vector<int> unionSets(std::vector<std::vector<int>> &vectors) {
    std::vector<int> result; // vetor que irá armazenar a união dos vetores

    if (vectors.empty()) {
        return result; // se não houver vetores, retorna um vetor vazio
    }

    std::vector<int> firstVector = vectors[0];
    result = firstVector;

    for (int j = 1; j < vectors.size(); ++j) {
        std::vector<int> currentVector = vectors[j];
        for (int k = 0; k < currentVector.size(); ++k) {
            int currentValue = currentVector[k];
            bool alreadyInResult = false;
            for (int i = 0; i < result.size(); ++i) {
                if (currentValue == result[i]) {
                    alreadyInResult = true;
                    break;
                }
            }
            if (!alreadyInResult) {
                result.push_back(currentValue);
            }
        }
    }

    return result;
}

std::vector<int> subtractionSets(std::vector<std::vector<int>> &vectors){
    //faz a subtração pela ordem dos vetores
    std::vector<int> result = vectors[0]; // inicializa o resultado com o primeiro conjunto
    for(int i=1; i<vectors.size(); i++){ // itera a partir do segundo conjunto
        std::vector<int> &vec = vectors[i];
        for(int j=0; j<vec.size(); j++){ // itera através dos elementos do conjunto atual
            //auto it = std::find(result.begin(), result.end(), vec[j]); // procura o elemento atual no resultado
            if(it != result.end()){ // se o elemento está presente no resultado
                result.erase(it); // remove o elemento do resultado
            }
        }
    }
    return result;
}

int main() {

    auto start_time = std::chrono::high_resolution_clock::now();

    std::vector<std::vector<int>> vectors = {{1, 2, 3, 4, 5},
                                             {2, 3, 5, 7},
                                             {1, 3, 4, 5, 7, 9},
                                             {3, 5, 8},
                                             {1, 3, 1, 5, 7, 9},
                                             {14, 3, 4, 10, 5, 9},
                                             {223, 3, 69, 29, 7, 9},
                                             {1, -5, 21, 3, 7, 9},
                                             {192, 3, 4, 97, 7, 9},
                                             {1, 91, 3, 43, 7, 90}};

    std::vector<int> resultIntersection = intersectionSets(vectors);

    exibeVetor(resultIntersection);

    auto end_time = std::chrono::high_resolution_clock::now();
    auto time_diff = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);

    std::cout << "Tempo de execucao: " << time_diff.count() << " microssegundos" << std::endl;

    return 0;
}


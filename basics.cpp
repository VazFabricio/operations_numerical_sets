#include "iostream"
#include <vector>

void exibeVetor(std::vector<int> vetor){
    for (int i = 0; i < vetor.size(); i++) {
        std::cout << vetor[i] << " ";
    }
    std::cout << std::endl;
}

std::vector<int> intersectionSets(std::vector<std::vector<int>> &vectors) {
    std::vector<int> result; // vetor que irá armazenar a intersecção dos vetores

    if (vectors.size() == 0) {
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

//std::vector<int> unionSets(std::vector<std::vector<int>> &vectors) {
//    return;
//}


int main() {

    std::vector<std::vector<int>> vectors = {{1, 2, 3, 4, 5},
                                             {2, 3, 5, 7},
                                             {1, 3, 4, 5, 7, 9},
                                             {3, 5, 8}};

    std::vector<int> resultIntersection = intersectionSets(vectors);

    exibeVetor(resultIntersection);

    return 0;
}

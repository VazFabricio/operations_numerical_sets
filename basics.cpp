#include "iostream"
#include <vector>

void exibeVetor(std::vector<int> vetor){
    for (int i = 0; i < vetor.size(); i++) {
        std::cout << vetor[i] << " ";
    }
    std::cout << std::endl;
}
std::vector<int> conjuntos(const std::string& posicao, std::vector<int> vetor) {

    int valores;
    std::cout << "Digite o valor de elementos do " + posicao + " conjunto: ";
    std::cin >> valores;

    for(int i=0; i<valores; i++){
        int elemento;
        std::cout << "Digite o elemento ("+ std::to_string(i+1) +")";
        std::cin >> elemento;
        vetor.push_back(elemento);
    }

    std::cout << "---------------------------";

    return vetor;
}

std::vector<int> intersection(std::vector<std::vector<int>> &vectors) {
    std::vector<int> result;

    if (vectors.size() == 0) {
        return result;
    }

    std::vector<int> firstVector = vectors[0];

    for (int i = 0; i < firstVector.size(); i++) {
        int currentValue = firstVector[i];
        int count = 1;

        for (int j = 1; j < vectors.size(); j++) {
            std::vector<int> currentVector = vectors[j];
            int found = 0;

            for (int k = 0; k < currentVector.size(); k++) {
                if (currentVector[k] == currentValue) {
                    found = 1;
                    break;
                }
            }

            if (found) {
                count++;
            } else {
                break;
            }
        }

        if (count == vectors.size()) {
            result.push_back(currentValue);
        }
    }

    return result;
}

int main() {

    std::vector<std::vector<int>> vectors = {{1, 2, 3, 4, 5},
                                             {2, 3, 5, 7},
                                             {1, 3, 4, 5, 7, 9},
                                             {3, 5, 8}};

    std::vector<int> resultIntersection = intersection(vectors);

    exibeVetor(resultIntersection);

    return 0;
}

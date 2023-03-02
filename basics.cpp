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
std::vector<int> intersection(const std::vector<int>& vetor1, const std::vector<int>& vetor2){

    std::vector<int> vetorIntersection;

    // Seleciona o vetor com o menor tamanho
    std::vector<int> vetor_menor;
    std::vector<int> vetor_maior;
    if (vetor1.size() < vetor2.size()) {
        vetor_menor = vetor1;
        vetor_maior = vetor2;
    } else {
        vetor_menor = vetor2;
        vetor_maior = vetor1;
    }

    for(int i = 0; i<vetor_menor.size();i++){
        for(int j = 0; j<vetor_maior.size(); j++){
            if(vetor_menor[i] == vetor_maior[j]){
                vetorIntersection.push_back(vetor_menor[i]);
            }
        }
    }

    return vetorIntersection;

}

int main() {
    //vetores
    std::vector<int> vetor1;
    std::vector<int> vetor2;

    vetor1 = conjuntos("primeiro", vetor1);
    vetor2 = conjuntos("segundo", vetor2);

    std::vector<int> vetorIntersection = intersection(vetor1, vetor2);

    exibeVetor(vetorIntersection);

    return 0;
}

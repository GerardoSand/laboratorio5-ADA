#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <algorithm>

bool contieneDuplicados(const std::vector<int>& v) {
    std::unordered_set<int> vistos;
    for (int num : v) {
        if (vistos.find(num) != vistos.end()) {
            return true;
        }
        vistos.insert(num);
    }
    return false;
}

std::string twoSum(const std::vector<int>& v, int t) {
    std::unordered_set<int> vistos;
    for (int num : v){
        int Buscado = t - num;
        if(vistos.find(Buscado)!= vistos.end()){
            std::vector<int> Resultado = {num, Buscado};
            return "{" + std::to_string(Resultado[0]) + ", " + std::to_string(Resultado[1]) + "}";
        }
        vistos.insert(num);
    }
    return "{}"; 
}

bool AgruparAnagramas(const std::vector<std::string>& v) {
    std::unordered_set<std::string> vistos;
    for (const std::string& letra : v) {
        if (vistos.find(letra) != vistos.end()) {
            vistos.erase(letra);
            return true;
        }

        vistos.insert(letra);
    }
    return false;
}

std::vector<std::vector<std::string>> agruparAnagramas(const std::vector<std::string>& palabras) {
    std::unordered_map<std::string, std::vector<std::string>> grupos;

    for (const std::string& palabra : palabras) {
        std::string clave = palabra;
        std::sort(clave.begin(), clave.end());
        grupos[clave].push_back(palabra);
    }

    std::vector<std::vector<std::string>> resultado;
    resultado.reserve(grupos.size());
    for (auto& par : grupos) {
        resultado.push_back(std::move(par.second));
    }

    return resultado;
}

int main() {
    std::vector<int> numeros = {4, 2, 7, 2, 9};
    std::cout << "Contiene duplicados: " << (contieneDuplicados(numeros) ? "Sí" : "No") << std::endl;

    std::vector<int> numeros2 = {2, 7, 11, 15};
    int objetivo = 9;
    std::cout << "Two Sum: " << twoSum(numeros2, objetivo) << std::endl;

    std::vector<std::string> palabras = {"ojo", "amor", "roma", "joo", "gato"};
    auto anagramas = agruparAnagramas(palabras);
    std::cout << "Grupos de anagramas:" << std::endl;
    for (const auto& grupo : anagramas) {
        std::cout << "{ ";
        for (const auto& palabra : grupo) {
            std::cout << palabra << " ";
        }
        std::cout << "}" << std::endl;
    }

    return 0;
}
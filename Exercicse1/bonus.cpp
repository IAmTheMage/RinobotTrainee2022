#include "string"
#include "iostream"
#include "unordered_map"
#include "cctype"

bool managedSequencies(char b) {
    if(b == 'X' || b == 'I') return true;
    return false;
}

int main(int argc, char** argv) {
    //A vantagem de usar uma abordagem utilizando Hash Table ( unordered_map ) 
    //é que nesse caso seria mais fácil criar um conversor universal do que usando uma abordagem com if e else ou switch por exemplo
    std::unordered_map<std::string, int> resp;
    resp["IX"] = 9;
    resp["X"] = 10;
    resp["I"] = 1;
    resp["V"] = 5;
    resp["IV"] = 4;
    resp["XL"] = 40;
    resp["L"] = 50;
    std::string data("");
    std::cout << "Digite o valor que deseja: (teoricamente vai a 89)" << std::endl;
    std::cin >> data;
    int sum = 0;
    int index = 0;
    int lastComputedNumber = 51;
    //Main Loop
    while(index < data.size()) {
        if(index < data.size() - 1) {
            std::string check1("");
            std::string check2("");
            check1 += data[index];
            check2 += data[index + 1];
            //Verificando se é um contínuo por exemplo IV ou IX
            if(resp[check1] < resp[check2] && managedSequencies(data[index]) && resp.find(check1 + check2) != resp.end()) {
                //Evitando atrocidades como XVIX, porque o próximo número tem que ser sempre menor ou igual ao atual
                if(lastComputedNumber >= resp[check1 + check2]) {
                    sum += resp[check1 + check2];
                    index += 2;
                    lastComputedNumber = resp[check1 + check2];
                }
                else {
                    std::cout << "Valor invalido" << std::endl;
                    lastComputedNumber = -1;
                    break;
                }
            }
            else {
                //Evitando atrocidades como XVIX, porque o próximo número tem que ser sempre menor ou igual ao atual
                if(lastComputedNumber >= resp[check1]) {
                    sum += resp[check1];
                    index++;
                    lastComputedNumber = resp[check1];
                }
                else {
                    std::cout << "Valor invalido" << std::endl;
                    lastComputedNumber = -1;
                    break;
                }
            }
        }
        else {
            std::string key("");
            key += data[index];
            sum += resp[key];
            index++;
        } 
    }
    if(lastComputedNumber != -1 && lastComputedNumber != 51) {
        std::cout << sum << std::endl;
    }
    return 0;
}
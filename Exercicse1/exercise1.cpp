#include "iostream"
#include "cctype"
#include "string"

int main(int argc, char** argv) {
    std::string data("");
    if(argc == 1) {
        std::cout << "Digite a sequência desejada: " << std::endl;
        std::cin >> data;
    }
    else {
        data.append(argv[1]);
    }
    int x = 0, y = 0;
    for(auto b : data) {
        switch(std::toupper(b)) {
            case 'C':
                y++;
                break;
            case 'B':
                y--;
                break;
            case 'E':
                x--;
                break;
            case 'D':
                x++;
                break;
            default:
                break;
        }
    }
    if(x == 0 && y == 0) {
        std::cout << "True" << std::endl;
    }
    else {
        std::cout << "False" << std::endl;
    }
    return 0;
}
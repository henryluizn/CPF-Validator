#include <iostream>
#include "data.cpp"

int main(){

    std::cout << "Validador de CPF" << std::endl;
    Pessoa persons[1];

    int cpf_val = getPersons(persons);

    if (cpf_val == 1){
        cout << "O CPF é valido. Imprimindo os dados inseridos\n";
        cout << "\n---------------------------------------\n";
        printData(persons);
        cout << "\n---------------------------------------\n";
    }

    return 0;
}


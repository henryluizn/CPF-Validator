#include <iostream>
#include "data.cpp"

int main(){

    std::cout << "Valida CPF" << std::endl;
    Pessoa persons[3];

    int cpf_val = getPersons(persons);

    if (cpf_val == 1){
        cout << "\nOs CPFs estao corretos. Imprimindo os dados\n";
        cout << "\n---------------------------------------\n";
        printData(persons);
        cout << "\n---------------------------------------\n";
    }

    return 0;
}


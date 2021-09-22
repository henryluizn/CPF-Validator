#include <iostream>
#include <string>
#include <sstream>
#include <string.h>

using namespace std;

typedef struct 
{
    long long cpf;
    string nome;
    int idade;
} Pessoa;


int cpfAlgorythm(string cpf)
{
    // verify -> 0 - O CPF não é válido
    // verify -> 1 - O CPF é válido
    int verify = 0;
    char dig_1 = cpf[9];
    char dig_2 = cpf[10];

    int 
        dig_verific_1 = 0, sum_dig_verific_1 = 0, 
        dig_verific_2 = 0, sum_dig_verific_2 = 0;


    // Calculo primeiro digito verificador
    for (int i = 0; i <= 8; i++)
    {
        sum_dig_verific_1 += (cpf[i] - 48) * (10 - i);
    }
    if (sum_dig_verific_1 % 11 >= 2)
    {
        dig_verific_1 = 11 - (sum_dig_verific_1 % 11);
    }
    cpf[9] = dig_verific_1 + '0';


    // Calculo segundo digito verificador
    for (int i = 0; i <= 9; i++)
    {
        sum_dig_verific_2 += (cpf[i] - 48) * (11 - i);
    }

    if (sum_dig_verific_2 % 11 >= 2)
    {
        dig_verific_2 = 11 - (sum_dig_verific_2 % 11);
    }
    cpf[10] = dig_verific_2 + '0';

    if (dig_1 == cpf[9] && dig_2 == cpf[10])
    {
        verify = 1;
    }
    
    return verify;
}


long long validarCPF(string cpf_string, long long cpf)
{
    try
    {
        int verify = cpfAlgorythm(cpf_string);
        if (verify == 1){
            return cpf;
        }
        return 0;
    }
    catch(const std::exception& e)
    {
        cout << "\nO CPF foi inserido no formato errado. Tente novamente \n";
        // std::cerr << e.what() << '\n';
        return 0;
    }
    
}


long long getCPF(int id){
    long long cpf;
    string cpf_string = "";
    
    cout << "\nInsira o CPF do " << id + 1 << " elemento:  ";
     
    try
    {
        getline(cin, cpf_string);
        cpf = stoll(cpf_string);
        if (strlen(cpf_string.c_str()) != 11){
            cout << "\nO CPF foi inserido no formato errado. Tente novamente \n";
            return 0;
        }
        return validarCPF(cpf_string, cpf);
    }
    catch(const std::exception& e)
    {
        cout << "\nO CPF foi inserido no formato errado. Tente novamente \n";
        // std::cerr << e.what() << '\n';
        return 0;
    }
    
}


string getNome(int id)
{
    string nome = "";
    cout << "\nInsira o nome do " << id + 1<< " elemento:  ";
    getline(cin, nome);
    return nome;
}


int getIdade(int id)
{
    try
    {
        string idade = "";
        cout << "\nInsira a idade do " << id + 1 << " elemento:  ";
        getline(cin, idade);
        int idade_int = stoi(idade);
        return idade_int;
    }
    catch(const std::exception& e)
    {
        cout << "\nInsira a idade no formato correto.\n";
        // std::cerr << e.what() << '\n';
        return 0;
    }
    
}


void printData(Pessoa * person)
{
    for (int i = 0; i < 3; i++)
    {
        cout << "\nCPF: " << person[i].cpf << " Nome: "<< person[i].nome 
        << " Idade: " << person[i].idade;
    }
    
}


int getPersons(Pessoa * person)
{
    int i = 0;
    long long cpf_validate = 0;
    

    while (i < 3)
    {
        cpf_validate = getCPF(i);

        if (cpf_validate != 0)
        {
            person[i].cpf = cpf_validate;
            person[i].nome = getNome(i);
            person[i].idade = getIdade(i);
            i++;
        }
    }

    return 1;
}


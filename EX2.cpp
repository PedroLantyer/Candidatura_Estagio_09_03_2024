#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <limits>

int MenuInteractionGetNum()
{
    int test_number = -1; //VALOR PADRÃO
    bool done = true;

    while(done != false)
    {
        printf("Por favor insira o numero a ser verificado: ");
        std::cin >> test_number;
        
        if(std::cin.fail()) //UTILIZADO PRA CASOS ONDE O VALOR DO INPUT É INVALIDO
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            printf("\nErro, valor invalido, por favor insira um numero inteiro\n\n");
            std::cout << std::setw(37) << std::setfill('-') << "" << std::endl << std::endl;
            continue;
        }

        break; //SAIR DO WHILE CASO O VALOR DO NUMERO SEJA OBTIDO
    }

    return test_number;
}

bool FindFibonacci(int num)
{
    if (num < 0)
    {
        return false;
    }

    if (num <= 3)
    {
        return true;
    }

    std::vector<int> Fib = {0,1}; //VECTOR PARA A SEQUENCIA
    int end = Fib.size()-1;
    int next;

    while(Fib[end] <= num)
    {
        next = Fib[end]+Fib[end-1];
        if(next == num)
        {
            return true;
        }
        Fib.push_back(next); //OPTEI POR ADICIONAR ELEMENTOS A SEQUENCIA EM VEZ DE SUBSTITUIR OS ELEMENTOS 1 E 2, ASSIM CASO DESEJEM PODEM USAR UM FOR PRA PRINTAR O VECTOR
        end = Fib.size()-1;
    }
    
    return false; //SE NEXT NUNCA FOR IGUAL A NUM, O VALOR NÃO FOI ENCONTRADO NA SEQUENCIA;
}

int main()
{   
    int test_number;
    bool found;
    printf("Bem vindo, vamos verificar se um numero faz parte da sequencia de fibonacci\n");
    test_number = MenuInteractionGetNum();

    found = FindFibonacci(test_number);
    
    if(found)
    {
        printf("Pertence a sequencia\n");
    }
    else
    {
        printf("Nao pertence a sequencia\n");
    }

    printf("Ate logo :)\n");
    return 0;
}
#include <iostream>
#include <iomanip>
#include <vector>

void SequenceOne() //P.A. COM RAZÃO 2
{
    int num = 1;
    
    for(int i = 0; i < 5; i++)
    {
        std::cout << std::setw(5) << num << " ";
        num += 2;
    }
    printf("\n");
}

void SequenceTwo() //POTENCIAS DE 2
{
    int num = 2;

    for(int i = 1; i <= 7; i++)
    {
        std::cout << std::setw(5) << num << " ";
        num *= 2;
    }
    printf("\n");
}

void SequenceThree() //QUADRADO DOS INDICES UTILIZADOS NO CICLO FOR
{
    int num;
    for(int i = 0; i <= 7; i++)
    {
        num = (i*i); //OPTEI POR NÃO UTILIZAR A FUNÇÃO POW POR QUESTÕES DE PRECISÃO, NO C++ ELA NÃO TEM OPÇÃO DE RETORNO INT E MESMO COM CASTING ALGUNS QUADRADOS PODERIAM SAIR ERRADOS
        std::cout << std::setw(5) << num << " ";
    }
    printf("\n");
}

void SequenceFour() //QUADRADO DOS MULTIPLOS DE 2
{
    int num = 2;
    for(int i = 2; i <= 10; i+=2)
    {
        num = (i*i);
        std::cout << std::setw(5) << num << " ";
    }
    printf("\n");
}

void SequenceFive() //FIBONACCI
{
    std::vector<int> Fib = {1,1};
    int temp;

    for(int i = 0; i < 2; i++) //IMPRIMIR DOIS PRIMEIROS ELEMENTOS DA SEQUENCIA
    {
        std::cout << std::setw(5) << Fib[i] << " ";
    }

    for(int i = 0; i < 5; i++) //IMPRIMIR ELEMENTOS RESTANTES DA SEQUENCIA
    {
        temp = Fib[0];
        Fib[0] = Fib[1];
        Fib[1] = (Fib[0]+temp);
        std::cout << std::setw(5) << Fib[1] << " ";
    }
    printf("\n");
}

void SequenceSix() //NUMEROS DA SEQUENCIA COMEÇAM COM D
{
    std::vector<int> vect = {2,10,12,16,17,18,19,200};
    
    for(int i = 0; i < (int)vect.size(); i++)
    {
        std::cout << std::setw(5) << vect[i] << " ";
    }
    
    printf("\n");
}

int main()
{
    SequenceOne();
    SequenceTwo();
    SequenceThree();
    SequenceFour();
    SequenceFive();
    SequenceSix();
    return 0;
}
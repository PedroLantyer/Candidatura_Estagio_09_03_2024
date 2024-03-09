#include <iostream>
#include <vector>
#include <cstdlib>

std::vector<int> GetRandVector(int rand_seed, int max_val)
{
    std::vector<int> vect;
    int num_one, num_two;

    srand(rand_seed);
    num_one = rand() % max_val;
    vect.push_back(num_one);

    do
    {
        num_two = rand() % max_val;
    }
    while(num_two == num_one);
    vect.push_back(num_two);
    
    return vect;
}

int GetRandInt (int rand_seed, int max_val)
{
    srand(rand_seed);
    int num = rand() % max_val;
    return num;
}

std::vector<int> SetOnOff(std::vector<int> positions_vect, std::vector<int> OnOff)
{
    int pos;
    for(int i = 0; i < (int)positions_vect.size(); i++)
    {
        pos = positions_vect[i];
        OnOff[pos] = 1;
    }
    return OnOff;
}

int GetFalsePos(std::vector<int> vect)
{
    for(int i = 0; i < (int)vect.size(); i++)
    {
        if (vect[i] == 0)
        {
            return i;
        }
    }
    return -1;
}

std::vector<int> SetFinalValues(int value_one, int value_two)
{
    int value_three;
    
    switch (value_one)
    {
    case 0:
        value_two ++;
        if(value_two == 1)
        {
            value_three = 2;
        }
        else
        {
            value_three = 1;
        }
        break;
    
    case 1:
        if(value_two == 0)
        {
            value_three = 2;
        }
        else
        {
            value_three = 0;
        }
        break;

    case 2:
        if(value_two == 1)
        {
            value_three = 0;
        }
        else
        {
            value_three = 1;
        }
        break;
    default:
        value_one = -1;
        value_two = -1;
        value_three = -1;
        break;
    }

    std::vector<int> vect = {value_one, value_two, value_three};
    return vect;
}

void PrintResults(std::vector<int> interruptor, std::vector<int> luz)
{
    for(int i = 0; i < (int)interruptor.size(); i++)
    {
        printf("Combinacao %d: ", i);
        printf("Interruptor %d liga a luz %d\n", interruptor[i], luz[i]);
    }
}

int main()
{
    std::vector<int> interruptores = {0,0,0};
    std::vector<int> luzes = {0,0,0};
    
    std::vector<int> luzes_acessas = GetRandVector(0,3);
    std::vector<int> interruptores_ligados = GetRandVector(1,3);

    interruptores = SetOnOff(interruptores_ligados,interruptores);
    luzes = SetOnOff(luzes_acessas, luzes);

    int interruptor_um = GetFalsePos(interruptores);
    int luz_um = GetFalsePos(luzes);

    interruptores.erase(interruptores.begin()+interruptor_um);
    luzes.erase(luzes.begin()+luz_um);

    int interruptor_dois = GetRandInt(2,2);
    int luz_dois = GetRandInt(3,2);

    std::vector<int> interruptores_final = SetFinalValues(interruptor_um, interruptor_dois);
    std::vector<int> luzes_final = SetFinalValues(luz_um, luz_dois);

    if((int)interruptores_final.size() != (int)luzes_final.size())
    {
        return 1;
    }

    PrintResults(interruptores_final, luzes_final);
    return 0;
}
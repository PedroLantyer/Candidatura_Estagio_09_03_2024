#include <iostream>

std::string reverse_str(std::string str)
{
    int end = (int)str.size()-1;
    std::string reversed = "";    
    
    for(int i = end; i >= 0; i--)
    {
        reversed += str[i];
    }
    return reversed;
}

int main()
{
    std::cout << reverse_str("PU UOY EVIG ANNOG REVEN") << std::endl;
    std::cout << reverse_str("NWOD UOY TEL ANNOG REVEN") << std::endl;
    std::cout << reverse_str("UOY TRESED DNA DNUORA NRUT ANNOG REVEN") << std::endl;
    std::cout << reverse_str("YRC UOY EKAM ANNOG REVEN") << std::endl;
    std::cout << reverse_str("EYBDOOG YAS ANNOG REVEN") << std::endl;
    std::cout << reverse_str("UOY TRUH DNA EIL A LLET ANNOG REVEN") << std::endl;

    return 0;
}
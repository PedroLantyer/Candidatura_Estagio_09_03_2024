#include <iostream>

int main()
{
    int index = 13, sum = 0;
    
    for(int i = 0; i < index; i++)
    {
        sum += i;
    }
    
    printf("%d\n", sum);
    return 0;
}
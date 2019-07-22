#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define INT32_T int;

INT32_T generateRandomNumber()
{
    srand(time(NULL));
    return rand();
}

int main()
{
    printf("Random Number: %d", generateRandomNumber());    
    return 0;
}

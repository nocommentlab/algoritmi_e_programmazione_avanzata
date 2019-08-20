#include <stdio.h>
#include <stdlib.h>
#include "TYPEDef.h"

INT32_T recursive_fibonacci(INT32_T INT32_Num);
INT32_T dynamic_programming_fibonacci(INT32_T INT32_Num);

/*
Thanks to: https://www.geeksforgeeks.org/program-for-nth-fibonacci-number/
*/



INT32_T dynamic_programming_fibonacci(INT32_T INT32_Num) 
{ 
  /* Declare an array to store Fibonacci numbers. */
  INT32_T vFibonacciHistoryResult[INT32_Num+2];   // 1 extra to handle case, n = 0 
  INT32_T INT32_Idx; 
  
  /* 0th and 1st number of the series are 0 and 1*/
  vFibonacciHistoryResult[0] = 0; 
  vFibonacciHistoryResult[1] = 1; 
  
  for (INT32_Idx = 2; INT32_Idx <= INT32_Num; INT32_Idx++) 
  { 
      /* Add the previous 2 numbers in the series 
         and store it */
      vFibonacciHistoryResult[INT32_Idx] = vFibonacciHistoryResult[INT32_Idx-1] + vFibonacciHistoryResult[INT32_Idx-2]; 
  } 
  
  return vFibonacciHistoryResult[INT32_Num]; 
} 

/* Time Complexity: T(n) = T(n-1) + T(n-2) which is exponential.
                            fib(5)   
                     /                \
               fib(4)                fib(3)   
             /        \              /       \ 
         fib(3)      fib(2)         fib(2)   fib(1)
        /    \       /    \        /      \
  fib(2)   fib(1)  fib(1) fib(0) fib(1) fib(0)
  /     \
fib(1) fib(0)

Extra Space: O(n) if we consider the function call stack size, otherwise O(1).

*/
INT32_T recursive_fibonacci(INT32_T INT32_Num) 
{ 
   if (INT32_Num <= 1) 
      return INT32_Num; 
   return fib(INT32_Num-1) + fib(INT32_Num-2); 
} 


int main()
{
    return 0;
}
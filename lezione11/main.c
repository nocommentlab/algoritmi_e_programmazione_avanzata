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

Analysis of the recursive Fibonacci program:
We know that the recursive equation for Fibonacci is T(n)=T(n-1)+T(n-2)+O(1).
What this means is, the time taken to calculate fib(n) is equal to the sum of time taken to calculate fib(n-1) and fib(n-2). This also includes the constant time to perform the previous addition.

On solving the above recursive equation we get the upper bound of Fibonacci as O(2^n) but this is not the tight upper bound. The fact that Fibonacci can be mathematically represented as a linear recursive function can be used to find the tight upper bound.
Now Fibonacci is defined as

F(n) = F(n-1)+F(n-2)

The characteristic equation for this function will be
x^2 = x+1
x^2 – x–1 = 0

Solving this by quadratic formula we can get the roots as
x = (1+\sqrt{5})/2 and x=(1 – \sqrt{5})/2

Now we know that solution of a linear recursive function is given as
F(n) = ($\alpha_1)^n + ($\alpha_2)^n

where $\alpha_1 and $\alpha_2 are the roots of the characteristic equation.
So for our Fibonacci function F(n) = F(n-1)+F(n-2) the solution will be

F(n) = ((1+$\sqrt{5})/2)^n+((1-\sqrt{5})/2)^n
Clearly T(n) and F(n) are asymptotically the same as both functions are representing the same thing.
Hence it can be said that
T(n) = O(((1+$\sqrt{5})/2)^n+((1-\sqrt{5})/2)^n)
or we can write below (using the property of Big O notation that we can drop lower order terms)
T(n) = O(((1+$\sqrt{5})/2)^n
T(n) = O(1.6180)^n
This is the tight upper bound of fibonacci

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
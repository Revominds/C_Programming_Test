#include <stdio.h>

//(iii) Input validation using scanf return value
int getValidInput(int num)
{
   while (1)
   {
      if (scanf("%d", num) == 1)
      {
         return 1;
      }
      else
      {
         printf("\n[ERR] Invalid input! Enter an integer.");

         while (getchar() != '\n')
            ;
      }
   }
}
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void header(char *hdr)
{
   printf("=======================================\n");
   printf("    %s\n", hdr);
   printf("=======================================\n\n");
}

int compareNumbers(int a, int b)
{
   if (a > b)
   {
      return 1;
   }
   else if (b > a)
   {
      return -1;
   }
   else
   {
      return 0;
   }
}

int main()
{

   system("cls");
   system("color 0b");

   header("COMPARING INTERGERS USING FUNCTION");

   int a, b;

   // calling function
   int results = compareNumbers(a, b);

   system("pause");
   return 0;
}
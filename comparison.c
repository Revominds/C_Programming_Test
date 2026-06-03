#include <stdio.h>
#include <stdlib.h>

void header(char *hdr)
{
   printf("=======================================\n");
   printf("    %s\n", hdr);
   printf("=======================================\n\n");
}

int main()
{

   system("cls");
   system("color 0b");

   header("COMPARING INTERGERS");

   int first_number;
   int second_number;

   printf("Enter first number : ");
   scanf("%d", &first_number);

   printf("Enter second number : ");
   scanf("%d", &second_number);

   if (first_number > second_number)
   {
      printf("\n[:)] First number %d is larger that second number %d\n\n", first_number, second_number);
   }
   else if (first_number < second_number)
   {
      printf("\n[:)] Second number %d is larger that first number %d\n\n", second_number, first_number);
   }
   else
   {
      printf("\n[:)] Both first # %d and second # %d are equal\n\n", first_number, second_number);
   }

   system("pause");
   return 0;
}
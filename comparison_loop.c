#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void header(char *hdr)
{
   printf("===============================================================\n");
   printf("    %s\n", hdr);
   printf("===============================================================\n\n");
}

int inputValidation(int *num)
{
   while (scanf("%d", num) != 1)
   {
      printf("\n[ERR] Invalid input! Enter a valid integer: ");
      while (getchar() != '\n')
         ;
   }
   return 1;
}

int main()
{
   system("cls");
   system("color 0b");

   int first_number, second_number;
   int choice, cont;

   do
   {
      header("COMPARING INTEGERS USING LOOPS & INPUT VALIDATION");
      printf("--------- Menu ---------\n");
      printf("[1] Compare numbers\n");
      printf("[2] Exit\n\n");

      printf("Choose option: ");
      scanf("%d", &choice);

      if (choice == 1)
      {
         printf("\nEnter first number: ");
         inputValidation(&first_number);

         printf("Enter second number: ");
         inputValidation(&second_number);

         if (first_number > second_number)
         {
            printf("[:)] First number %d is larger\n\n", first_number);
         }
         else if (first_number < second_number)
         {
            printf("[:)] Second number %d is larger\n\n", second_number);
         }
         else
         {
            printf("[:)] Both numbers are equal: %d and %d\n\n",
                   first_number, second_number);
         }
      }

      printf("[?] Do you want to continue? (1=Yes, 2=No): ");
      scanf("%d", &cont);
      system("cls");
      Sleep(200);

   } while (choice != 2 && cont == 1);

   system("pause");
   return 0;
}
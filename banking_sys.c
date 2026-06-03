#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

#define SIZE 100

void header(char *hdr)
{
   system("cls");
   printf("=======================================\n");
   printf("    %s\n", hdr);
   printf("=======================================\n\n");
}

// Account Structure
typedef struct
{
   int accountNumber;
   char accountHolderName[SIZE];
   float balance;

} Account;

// Deposit Money Function
void depositMoney(Account *acc, float amount)
{
   if (amount <= 0)
   {
      printf("[ERR] Deposit amount must be positive!\n\n");
      system("pause");
      return;
   }

   acc->balance += amount;

   printf("[SUCCESS] Deposit of %.2f GHS successful.\n", amount);
   printf("[INFO] Current Balance: %.2f GHS\n\n", acc->balance);

   system("pause");
}

// Withdraw Money Function
void withdrawMoney(Account *acc, float amount)
{
   if (amount <= 0)
   {
      printf("[ERR] Withdrawal amount must be positive!\n\n");
      system("pause");
      return;
   }

   if (amount > acc->balance)
   {
      printf("[ERR] Insufficient balance!\n");
      printf("[INFO] Current Balance: %.2f GHS\n\n", acc->balance);

      system("pause");
      return;
   }

   acc->balance -= amount;

   printf("[SUCCESS] Withdrawal of %.2f GHS successful.\n", amount);
   printf("Current Balance: %.2f GHS\n\n", acc->balance);

   system("pause");
}

// Check Balance Function
void checkBalance(Account *acc)
{
   printf("=======================================\n");
   printf("          ACCOUNT DETAILS\n");
   printf("=======================================\n");

   printf("Account Number : %d\n", acc->accountNumber);
   printf("Account Holder : %s\n", acc->accountHolderName);
   printf("Balance        : %.2f GHS\n", acc->balance);

   printf("=======================================\n\n");

   system("pause");
}

// Change Account Holder Name
void changeAccountHolderName(Account *acc)
{
   char newName[SIZE];

   while (getchar() != '\n')
      ;

   printf("Enter new account holder name: ");
   fgets(newName, SIZE, stdin);

   newName[strcspn(newName, "\n")] = '\0';

   if (strlen(newName) == 0)
   {
      printf("[ERR] Name cannot be empty!\n\n");
      system("pause");
      return;
   }

   strcpy(acc->accountHolderName, newName);

   printf("[SUCCESS] Account holder name updated successfully!\n\n");

   system("pause");
}

int main()
{
   system("color 0B");

   Account acc;

   // Create Default Account
   acc.accountNumber = 1001;
   strcpy(acc.accountHolderName, "Default User");
   acc.balance = 0.00;

   int choice;
   int cont;
   float amount;

   while (1)
   {
      header("BANKING MANAGEMENT SYSTEM");

      printf("Account Holder : %s\n", acc.accountHolderName);
      printf("Current Balance: %.2f GHS\n\n", acc.balance);

      printf("[1] Deposit Money\n");
      printf("[2] Withdraw Money\n");
      printf("[3] Check Balance\n");
      printf("[4] Change Account Holder Name\n");
      printf("[5] Exit\n\n");

      printf("Choose an option: ");
      scanf("%d", &choice);

      switch (choice)
      {
      case 1:
         header("DEPOSIT MONEY");

         printf("Enter deposit amount: ");
         scanf("%f", &amount);

         depositMoney(&acc, amount);
         break;

      case 2:
         header("WITHDRAW MONEY");

         printf("Enter withdrawal amount: ");
         scanf("%f", &amount);

         withdrawMoney(&acc, amount);
         break;

      case 3:
         checkBalance(&acc);
         break;

      case 4:
         header("CHANGE ACCOUNT HOLDER NAME");

         changeAccountHolderName(&acc);
         break;

      case 5:
         printf("\nThank you for using the Banking System.\n");
         system("pause");
         return 0;

      default:
         printf("\n[ERR] Invalid menu option!\n\n");
         system("pause");
      }

      // Ask user whether to continue
      do
      {
         system("cls");

         printf("Do you want to perform another operation?\n");
         printf("[1] Yes\n");
         printf("[2] No\n\n");

         printf("Enter choice: ");
         scanf("%d", &cont);

         if (cont != 1 && cont != 2)
         {
            printf("\n[ERR] Please enter 1 or 2 only.\n");
            system("pause");
         }

      } while (cont != 1 && cont != 2);

      if (cont == 2)
      {
         printf("\nThank you for using the Banking System.\n");
         system("pause");
         break;
      }
   }

   return 0;
}
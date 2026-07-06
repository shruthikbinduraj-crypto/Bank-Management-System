#include "../include/main.h"

BankAccount *accounts = NULL;
int accountCount = 0;

int main()
{
    int choice;

    loadFromFile();

    do
    {
        printf("\n=================================\n");
        printf("     BANK MANAGEMENT SYSTEM\n");
        printf("=================================\n");
        printf("1. Add Account\n");
        printf("2. Display Accounts\n");
        printf("3. Search Account\n");
        printf("4. Deposit Money\n");
        printf("5. Withdraw Money\n");
        printf("6. Delete Account\n");
        printf("7. Save Accounts\n");
        printf("8. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                addAccount();
                break;

            case 2:
                displayAccounts();
                break;

            case 3:
                searchAccount();
                break;

            case 4:
                depositAmount();
                break;

            case 5:
                withdrawAmount();
                break;

            case 6:
                deleteAccount();
                break;

            case 7:
                saveToFile();
                printf("Accounts saved successfully.\n");
                break;

            case 8:
                saveToFile();
                freeMemory();
                printf("Thank you for using Bank Management System.\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    } while(choice != 8);

    return 0;
}
void addAccount()
{
    printf("\nFeature Coming Soon...\n");
}

void displayAccounts()
{
    printf("\nFeature Coming Soon...\n");
}

void searchAccount()
{
    printf("\nFeature Coming Soon...\n");
}

void depositAmount()
{
    printf("\nFeature Coming Soon...\n");
}

void withdrawAmount()
{
    printf("\nFeature Coming Soon...\n");
}

void deleteAccount()
{
    printf("\nFeature Coming Soon...\n");
}

void saveToFile()
{

}

void loadFromFile()
{

}

void freeMemory()
{

}
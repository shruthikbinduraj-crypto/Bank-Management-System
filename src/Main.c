#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct
{
    int accNo;
    char name[50];
    char phone[15];
    float balance;
} Account;

Account accounts[MAX];
int count = 0;

void createAccount();
void displayAccounts();
void searchAccount();
void depositMoney();
void withdrawMoney();
void transferMoney();
void updateAccount();
void deleteAccount();
void saveToFile();
void loadFromFile();

int findAccount(int accNo)
{
    int i;
    for(i=0;i<count;i++)
    {
        if(accounts[i].accNo==accNo)
            return i;
    }
    return -1;
}

int main()
{
    int choice;

    loadFromFile();

    while(1)
    {
        printf("\n==============================\n");
        printf(" BANK MANAGEMENT SYSTEM\n");
        printf("==============================\n");
        printf("1. Create Account\n");
        printf("2. Display Accounts\n");
        printf("3. Search Account\n");
        printf("4. Deposit Money\n");
        printf("5. Withdraw Money\n");
        printf("6. Transfer Money\n");
        printf("7. Update Account\n");
        printf("8. Delete Account\n");
        printf("9. Save Accounts\n");
        printf("10. Load Accounts\n");
        printf("11. Exit\n");
        printf("Enter Choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                createAccount();
                break;

            case 2:
                displayAccounts();
                break;

            case 3:
                searchAccount();
                break;

            case 4:
                depositMoney();
                break;

            case 5:
                withdrawMoney();
                break;

            case 6:
                transferMoney();
                break;

            case 7:
                updateAccount();
                break;

            case 8:
                deleteAccount();
                break;

            case 9:
                saveToFile();
                break;

            case 10:
                loadFromFile();
                break;

            case 11:
                saveToFile();
                printf("\nThank You!\n");
                exit(0);

            default:
                printf("\nInvalid Choice\n");
        }
    }

    return 0;
}

void createAccount()
{
    printf("\nEnter Account Number : ");
    scanf("%d",&accounts[count].accNo);

    printf("Enter Name : ");
    scanf(" %[^\n]",accounts[count].name);

    printf("Enter Phone : ");
    scanf("%s",accounts[count].phone);

    printf("Enter Initial Balance : ");
    scanf("%f",&accounts[count].balance);

    count++;

    printf("\nAccount Created Successfully!\n");
}

void displayAccounts()
{
    int i;

    if(count==0)
    {
        printf("\nNo Accounts Found.\n");
        return;
    }

    printf("\n--------------- ACCOUNT LIST ---------------\n");

    for(i=0;i<count;i++)
    {
        printf("\nAccount Number : %d",accounts[i].accNo);
        printf("\nName           : %s",accounts[i].name);
        printf("\nPhone          : %s",accounts[i].phone);
        printf("\nBalance        : %.2f\n",accounts[i].balance);
    }
}

void searchAccount()
{
    int acc,index;

    printf("Enter Account Number : ");
    scanf("%d",&acc);

    index=findAccount(acc);

    if(index==-1)
    {
        printf("\nAccount Not Found.\n");
        return;
    }

    printf("\nAccount Number : %d",accounts[index].accNo);
    printf("\nName           : %s",accounts[index].name);
    printf("\nPhone          : %s",accounts[index].phone);
    printf("\nBalance        : %.2f\n",accounts[index].balance);
}
void depositMoney()
{
    int acc,index;
    float amount;

    printf("Enter Account Number : ");
    scanf("%d",&acc);

    index=findAccount(acc);

    if(index==-1)
    {
        printf("\nAccount Not Found.\n");
        return;
    }

    printf("Enter Deposit Amount : ");
    scanf("%f",&amount);

    if(amount<=0)
    {
        printf("Invalid Amount!\n");
        return;
    }

    accounts[index].balance += amount;

    printf("\nAmount Deposited Successfully!\n");
    printf("Current Balance : %.2f\n",accounts[index].balance);
}

void withdrawMoney()
{
    int acc,index;
    float amount;

    printf("Enter Account Number : ");
    scanf("%d",&acc);

    index=findAccount(acc);

    if(index==-1)
    {
        printf("\nAccount Not Found.\n");
        return;
    }

    printf("Enter Withdrawal Amount : ");
    scanf("%f",&amount);

    if(amount<=0)
    {
        printf("Invalid Amount!\n");
        return;
    }

    if(amount>accounts[index].balance)
    {
        printf("Insufficient Balance!\n");
        return;
    }

    accounts[index].balance -= amount;

    printf("\nWithdrawal Successful!\n");
    printf("Current Balance : %.2f\n",accounts[index].balance);
}

void transferMoney()
{
    int from,to;
    int i,j;
    float amount;

    printf("From Account Number : ");
    scanf("%d",&from);

    printf("To Account Number : ");
    scanf("%d",&to);

    i=findAccount(from);
    j=findAccount(to);

    if(i==-1 || j==-1)
    {
        printf("\nOne or Both Accounts Not Found.\n");
        return;
    }

    printf("Enter Amount : ");
    scanf("%f",&amount);

    if(amount<=0)
    {
        printf("Invalid Amount!\n");
        return;
    }

    if(amount>accounts[i].balance)
    {
        printf("Insufficient Balance!\n");
        return;
    }

    accounts[i].balance-=amount;
    accounts[j].balance+=amount;

    printf("\nTransfer Successful!\n");
}

void updateAccount()
{
    int acc,index;

    printf("Enter Account Number : ");
    scanf("%d",&acc);

    index=findAccount(acc);

    if(index==-1)
    {
        printf("Account Not Found!\n");
        return;
    }

    printf("Enter New Name : ");
    scanf(" %[^\n]",accounts[index].name);

    printf("Enter New Phone : ");
    scanf("%s",accounts[index].phone);

    printf("\nAccount Updated Successfully!\n");
}

void deleteAccount()
{
    int acc,index,i;

    printf("Enter Account Number : ");
    scanf("%d",&acc);

    index=findAccount(acc);

    if(index==-1)
    {
        printf("Account Not Found!\n");
        return;
    }

    for(i=index;i<count-1;i++)
    {
        accounts[i]=accounts[i+1];
    }

    count--;

    printf("\nAccount Deleted Successfully!\n");
}
void saveToFile()
{
    FILE *fp;
    int i;

    fp = fopen("accounts.dat","wb");

    if(fp==NULL)
    {
        printf("Error Saving File!\n");
        return;
    }

    fwrite(&count,sizeof(int),1,fp);

    for(i=0;i<count;i++)
    {
        fwrite(&accounts[i],sizeof(Account),1,fp);
    }

    fclose(fp);

    printf("\nAccounts Saved Successfully!\n");
}

void loadFromFile()
{
    FILE *fp;
    int i;

    fp = fopen("accounts.dat","rb");

    if(fp==NULL)
        return;

    fread(&count,sizeof(int),1,fp);

    for(i=0;i<count;i++)
    {
        fread(&accounts[i],sizeof(Account),1,fp);
    }

    fclose(fp);
}
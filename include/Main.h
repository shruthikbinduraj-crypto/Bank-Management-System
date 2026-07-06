#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int accountNumber;
    char *accountHolder;
    char *accountType;
    float balance;
} BankAccount;

extern BankAccount *accounts;
extern int accountCount;

void addAccount();
void displayAccounts();
void searchAccount();
void depositAmount();
void withdrawAmount();
void deleteAccount();

void saveToFile();
void loadFromFile();

void freeMemory();

#endif
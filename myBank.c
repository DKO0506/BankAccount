//
// Created by david on 05/12/2020.
//
#include <stdio.h>
#include "myBank.h"

enum states {
    closed = 0, opened = 1
};
enum values {
    balance = 0, state = 1
};

#define TOTAL_NUM_OF_ACCOUNTS 50
#define TWO_DIMENSIONAL 2
#define FIRST 901
#define LAST 950

double bank[TOTAL_NUM_OF_ACCOUNTS][TWO_DIMENSIONAL];


void openAccount() {
    double amount;
    printf("Please insert the initial amount of money to deposit: ");
    if (scanf("%lf", &amount) != 1) {
        printf("Failed to read the amount\n");
    } else if (amount < 1) {
        printf("Invalid Amount\n");
    } else {
        for (int i = 0; i < TOTAL_NUM_OF_ACCOUNTS; i++) {
            if (bank[i][state] == closed) {
                bank[i][balance] = amount;
                bank[i][state] = opened;
                printf("New account number is %d \n", i + FIRST);
                return;
            }
        }
    }
}

void printBalance() {
    int account;
    printf("Please insert the account number: ");
    if (scanf("%d", &account) != 1) {
        printf("Failed to read the account number \n");
    } else if (account < FIRST || account > LAST) {
        printf("Invalid input error! \n");
    } else if (bank[account - FIRST][state] == closed) {
        printf("This account is closed \n");
    } else {
        printf("Account :%d Balance :%.2lf\n", account, bank[account - FIRST][balance]);
    }

}

void deposit() {
    int account;
    double amount;
    printf("Please insert your account number\n");
    if (scanf("%d", &account) != 1) {
        printf("Failed to read the account number \n");
    } else if (account < FIRST || account > LAST) {
        printf("Invalid input error! \n");
    } else if (bank[account - FIRST][state] == closed) {
        printf("This account is closed \n");
        return;
    }
    printf("Please insert the amount you wish to deposit.\n");
    if (scanf("%lf", &amount) != 1) {
        printf("Failed to read the amount\n");
    } else if (amount < 0) {
        printf("Invalid amount value\n");
    } else {
        bank[account - FIRST][balance] += amount;
        printf("The new balance for Account number:%d is :%.2lf\n", account, bank[account - FIRST][balance]);
    }
}

void withdraw() {
    int account;
    double amount;
    printf("Please insert your account number\n");
    if (scanf("%d", &account) != 1) {
        printf("Failed to read the account number \n");
    } else if (account < FIRST || account > LAST) {
        printf("Invalid input error! \n");
    } else if (bank[account - FIRST][state] == closed) {
        printf("This account is closed \n");
        return;
    }
    printf("Please insert the amount of money you wish do withdraw\n");
    if (scanf("%lf", &amount) != 1) {
        printf("Failed to read the amount\n");
    } else if (bank[account - FIRST][balance] < amount) {
        printf("The balance in your account is:%.2lf cannot withdraw over your limit\n",
               bank[account - FIRST][balance]);
    } else {
        bank[account - FIRST][balance] -= amount;
        printf("The balance in your account after your withdrawal is :%.2lf", bank[account - FIRST][balance]);
    }
}

void closeAccount() {
    int account;
    printf("Please insert your account number\n");
    if (scanf("%d", &account) != 1) {
        printf("Failed to read the account number \n");
    } else if (account < FIRST || account > LAST) {
        printf("Invalid input error! \n");
    } else {
        bank[account - FIRST][balance] = 0;
        bank[account - FIRST][state] = closed;
        printf("The account:%d is now closed", account);
    }
}

void addInterest() {
    int interest;
    printf("Please insert interest rate: ");
    if (scanf("%d", &interest) != 1) {
        printf("Failed to read the interest rate\n");
    } else if (interest < 0 || interest > 100) {
        printf("Invalid interest rate! Interest rate should be 0 - 100\n");
    } else {
        for (int i = 0; i < TOTAL_NUM_OF_ACCOUNTS; i++) {
            if (bank[i][state] == opened) {
                bank[i][balance] += bank[i][balance] * (interest / 100.0);
            }
        }
    }
}

void printAll() {
    for (int i = 0; i < TOTAL_NUM_OF_ACCOUNTS; i++) {
        if (bank[i][state] == opened) {
            printf("Account number:%d  Balance:%.2lf\n", i + FIRST, bank[i][balance]);
        }
    }
}

void exitProgram() {
    for (int i = 0; i < TOTAL_NUM_OF_ACCOUNTS; i++) {
        if (bank[i][state] == opened) {
            bank[i][balance] = 0;
            bank[i][state] = closed;
        }
    }
}

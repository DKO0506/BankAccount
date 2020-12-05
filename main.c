#include <stdio.h>
#include "myBank.h"
void menu();
void menu(){
printf("\n Please choose a transaction type:\n");
        printf(" O-Open Account\n");
        printf(" B-Balance Inquiry\n");
        printf(" D-Deposit\n");
        printf(" W-Withdraw\n");
        printf(" C-Close Account\n");
        printf(" I-Interest\n");
        printf(" P-Print\n");
        printf(" E-Exit\n");
        }
int main() {

    char l = ' ';
    while (l != EOF) {

        menu();
        scanf("%c",&l);
        
        switch (l) {
            case 'O':
                openAccount();
                break;
            case 'B':
                printBalance();
                break;
            case 'D':
                deposit();
                break;
            case 'W':
                withdraw();
                break;
            case 'C':
                closeAccount();
                break;
            case 'I':
                addInterest();
                break;
            case 'P':
                printAll();
                break;
            case 'E':
                exitProgram();
                return 0;
                break;
            default:
                printf("Invalid transaction type\n");
                break;
        }
    }
}

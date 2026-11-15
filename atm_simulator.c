#include <stdio.h>

#define MAX_TRANSACTIONS 100

int main(void)
{
    int pin = 1234, enteredPin, choice, newPin, amount;
    int balance = 10000;
    int history[MAX_TRANSACTIONS];
    int transactions = 0;
    int i;

    printf("\n================================\n");
    printf("          WELCOME TO ATM\n");
    printf("================================\n");
    printf("Enter your ATM PIN: ");
    if (scanf("%d", &enteredPin) != 1) {
        printf("Invalid input.\n");
        return 0;
    }

    if (enteredPin != pin) {
        printf("Incorrect PIN. Access denied.\n");
        return 0;
    }

    printf("\nLogin Successful!\n");

    do {
        printf("\n========== ATM MENU ==========\n");
        printf("1. Check Balance\n");
        printf("2. Withdraw Money\n");
        printf("3. Deposit Money\n");
        printf("4. Change PIN\n");
        printf("5. Mini Statement\n");
        printf("6. Exit\n");
        printf("==============================\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please restart the program.\n");
            return 0;
        }

        switch (choice) {
            case 1:
                printf("Your Balance is: Rs. %d\n", balance);
                break;

            case 2:
                printf("Enter withdrawal amount: Rs. ");
                if (scanf("%d", &amount) != 1) return 0;

                if (amount <= 0) {
                    printf("Invalid amount!\n");
                } else if (amount > balance) {
                    printf("Insufficient Balance!\n");
                } else if (transactions >= MAX_TRANSACTIONS) {
                    printf("Transaction history is full.\n");
                } else {
                    balance -= amount;
                    history[transactions++] = -amount;
                    printf("Please collect your cash.\n");
                    printf("Remaining Balance: Rs. %d\n", balance);
                }
                break;

            case 3:
                printf("Enter deposit amount: Rs. ");
                if (scanf("%d", &amount) != 1) return 0;

                if (amount <= 0) {
                    printf("Invalid amount!\n");
                } else if (transactions >= MAX_TRANSACTIONS) {
                    printf("Transaction history is full.\n");
                } else {
                    balance += amount;
                    history[transactions++] = amount;
                    printf("Money Deposited Successfully!\n");
                    printf("Updated Balance: Rs. %d\n", balance);
                }
                break;

            case 4:
                printf("Enter New 4-digit PIN: ");
                if (scanf("%d", &newPin) != 1) return 0;

                if (newPin >= 1000 && newPin <= 9999 && newPin != pin) {
                    pin = newPin;
                    printf("PIN Changed Successfully!\n");
                } else {
                    printf("Please enter a different 4-digit PIN.\n");
                }
                break;

            case 5:
                printf("\n======= MINI STATEMENT =======\n");
                printf("Current Balance: Rs. %d\n", balance);
                if (transactions == 0) {
                    printf("No transactions yet.\n");
                }
                for (i = 0; i < transactions; i++) {
                    if (history[i] < 0)
                        printf("Withdrawn: Rs. %d\n", -history[i]);
                    else
                        printf("Deposited: Rs. %d\n", history[i]);
                }
                printf("==============================\n");
                break;

            case 6:
                printf("Thank you for using our ATM!\n");
                printf("Please visit again.\n");
                break;

            default:
                printf("Invalid Choice! Try Again.\n");
        }
    } while (choice != 6);

    return 0;
}

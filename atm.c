#include <stdio.h>

static void clearInputBuffer(void)
{
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
    }
}

int main(void)
{
    const int correctPin = 1234;
    int pin;
    int choice;
    int attempts = 0;
    double balance = 10000.0;
    double amount;

    printf("================================\n");
    printf("       WELCOME TO ATM\n");
    printf("================================\n");

    while (attempts < 3) {
        printf("\nEnter your 4-digit PIN: ");
        if (scanf("%d", &pin) != 1) {
            clearInputBuffer();
            printf("Invalid PIN. Please enter digits only.\n");
            attempts++;
            continue;
        }

        if (pin == correctPin) {
            break;
        }

        attempts++;
        printf("Incorrect PIN. %d attempt(s) remaining.\n", 3 - attempts);
    }

    if (attempts >= 3) {
        printf("\nAccount locked. Please contact customer service.\n");
        return 0;
    }

    do {
        printf("\n========== ATM MENU ==========\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");
        printf("==============================\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            clearInputBuffer();
            printf("Invalid choice. Please enter a number from 1 to 4.\n");
            continue;
        }

        switch (choice) {
        case 1:
            printf("\nYour current balance is: %.2f\n", balance);
            break;

        case 2:
            printf("\nEnter amount to deposit: ");
            if (scanf("%lf", &amount) != 1) {
                clearInputBuffer();
                printf("Invalid amount.\n");
                break;
            }
            if (amount <= 0) {
                printf("Deposit amount must be greater than zero.\n");
            } else {
                balance += amount;
                printf("Successfully deposited %.2f\n", amount);
                printf("Updated balance: %.2f\n", balance);
            }
            break;

        case 3:
            printf("\nEnter amount to withdraw: ");
            if (scanf("%lf", &amount) != 1) {
                clearInputBuffer();
                printf("Invalid amount.\n");
                break;
            }
            if (amount <= 0) {
                printf("Withdrawal amount must be greater than zero.\n");
            } else if (amount > balance) {
                printf("Insufficient balance.\n");
                printf("Your current balance is: %.2f\n", balance);
            } else {
                balance -= amount;
                printf("Please collect your cash: %.2f\n", amount);
                printf("Updated balance: %.2f\n", balance);
            }
            break;

        case 4:
            printf("\nThank you for using the ATM. Goodbye!\n");
            break;

        default:
            printf("Invalid choice. Please select 1, 2, 3, or 4.\n");
            break;
        }
    } while (choice != 4);

    return 0;
}

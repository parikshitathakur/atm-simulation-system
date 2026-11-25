/*
 * Automated Teller Machine Terminal
 * Team 2 Implementation
 */
#include <stdio.h>

static double userFunds = 8500.50;
static int accessCode = 4321;

int main(void) {
    int key, cmd;
    printf("[ATM TERMINAL B]\nEnter Security Key: ");
    if (scanf("%d", &key) != 1 || key != accessCode) {
        puts("Access Denied: Authentication Failed.");
        return 1;
    }

    while (1) {
        puts("\n[1] Check Account Funds");
        puts("[2] Credit Deposit");
        puts("[3] Cash Out");
        puts("[4] Reset PIN");
        puts("[0] Eject Session");
        printf("Select: ");
        if (scanf("%d", &cmd) != 1 || cmd == 0) {
            puts("Session closed safely.");
            break;
        }
        double amt;
        switch (cmd) {
            case 1:
                printf("Available Balance: $%.2f\n", userFunds);
                break;
            case 2:
                printf("Credit Amount: $");
                scanf("%lf", &amt);
                if (amt > 0) {
                    userFunds += amt;
                    printf("Updated Funds: $%.2f\n", userFunds);
                } else puts("Invalid deposit.");
                break;
            case 3:
                printf("Cash Out Amount: $");
                scanf("%lf", &amt);
                if (amt > userFunds) puts("Error: Exceeds available funds.");
                else if (amt <= 0) puts("Invalid cash request.");
                else {
                    userFunds -= amt;
                    printf("Dispensed: $%.2f | Balance: $%.2f\n", amt, userFunds);
                }
                break;
            case 4: {
                int p1, p2;
                printf("Enter current key: ");
                scanf("%d", &p1);
                if (p1 == accessCode) {
                    printf("New 4-digit key: ");
                    scanf("%d", &p2);
                    accessCode = p2;
                    puts("Key updated.");
                } else puts("Verification failed.");
                break;
            }
            default: puts("Unknown option.");
        }
    }
    return 0;
}

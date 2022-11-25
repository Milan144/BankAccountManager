#include <stdio.h>

int main() {
    printf("Hello, welcome on the bank app!\n Press 1 to create an account\n Press 2 to login\n Press 3 to exit\n");
    int choice;
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("You chose to create an account\n");
            break;
        case 2:
            printf("You chose to login\n");
            char username[20];
            char password[20];
            printf("Enter your username: ");
            scanf("%s", username);
            printf("Enter your password: ");
            scanf("%s", password);


        case 3:
            printf("You chose to exit\n");
            break;
        default:
            printf("You chose an invalid option\n");
            break;
    }

    return 0;
}



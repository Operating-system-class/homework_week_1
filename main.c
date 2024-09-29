#include <stdio.h>

int main() {
    int choice;
    char *menu[] = {
        "1. Add a record",
        "2. Delete a record",
        "3. Update a record",
        "4. List all records",
        "5. Quit"
    };
    for (int i = 0; i < sizeof(menu) / sizeof(menu[0]); i++) {
        printf("%s\n", menu[i]);
    }
    printf("Choose an option: ");
    scanf("%d", &choice);
    printf("You choose: %s\n", menu[choice - 1]);
    return choice;
}
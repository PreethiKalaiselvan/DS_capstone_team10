#include <stdio.h>
#include <string.h>

#define MAX_PASSENGERS 100
#define NAME_LENGTH 50

// Function declarations
void addPassenger(char passengers[][NAME_LENGTH], int *count);
void removePassenger(char passengers[][NAME_LENGTH], int *count);
void searchPassenger(char passengers[][NAME_LENGTH], int count);
void displayPassengers(char passengers[][NAME_LENGTH], int count);

int main() {
    char passengers[MAX_PASSENGERS][NAME_LENGTH];
    int count = 0;
    int choice;

    while (1) {
        printf("\nFlight Passenger Management System\n");
        printf("1. Add Passenger\n");
        printf("2. Remove Passenger\n");
        printf("3. Search Passenger\n");
        printf("4. Display Passengers\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character

        switch (choice) {
            case 1:
                addPassenger(passengers, &count);
                break;
            case 2:
                removePassenger(passengers, &count);
                break;
            case 3:
                searchPassenger(passengers, count);
                break;
            case 4:
                displayPassengers(passengers, count);
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

void addPassenger(char passengers[][NAME_LENGTH], int *count) {
    if (*count >= MAX_PASSENGERS) {
        printf("Passenger list is full!\n");
        return;
    }
    printf("Enter passenger name: ");
    fgets(passengers[*count], NAME_LENGTH, stdin);
    passengers[*count][strcspn(passengers[*count], "\n")] = 0; // Remove newline
    (*count)++;
    printf("Passenger added successfully.\n");
}

void removePassenger(char passengers[][NAME_LENGTH], int *count) {
    char name[NAME_LENGTH];
    printf("Enter passenger name to remove: ");
    fgets(name, NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0; // Remove newline

    for (int i = 0; i < *count; i++) {
        if (strcmp(passengers[i], name) == 0) {
            // Shift remaining passengers down
            for (int j = i; j < *count - 1; j++) {
                strcpy(passengers[j], passengers[j + 1]);
            }
            (*count)--;
            printf("Passenger removed successfully.\n");
            return;
        }
    }
    printf("Passenger not found.\n");
}

void searchPassenger(char passengers[][NAME_LENGTH], int count) {
    char name[NAME_LENGTH];
    printf("Enter passenger name to search: ");
    fgets(name, NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0; // Remove newline

    for (int i = 0; i < count; i++) {
        if (strcmp(passengers[i], name) == 0) {
            printf("Passenger found: %s\n", passengers[i]);
            return;
        }
    }
    printf("Passenger not found.\n");
}

void displayPassengers(char passengers[][NAME_LENGTH], int count) {
    if (count == 0) {
        printf("No passengers found.\n");
        return;
    }
    printf("Passenger List:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s\n", i + 1, passengers[i]);
    }
}

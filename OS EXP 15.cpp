#include <stdio.h>
#include <string.h>

#define MAX_USERS 10
#define MAX_FILES 10
#define MAX_NAME 20

// Structure for file
typedef struct {
    char filename[MAX_NAME];
} File;

// Structure for user directory
typedef struct {
    char username[MAX_NAME];
    File files[MAX_FILES];
    int fileCount;
} UserDirectory;

UserDirectory users[MAX_USERS];
int userCount = 0;

// Function to add user
void addUser(char name[]) {
    if (userCount < MAX_USERS) {
        strcpy(users[userCount].username, name);
        users[userCount].fileCount = 0;
        userCount++;
    } else {
        printf("User limit reached!\n");
    }
}

// Function to add file to a user
void addFile(char username[], char filename[]) {
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0) {
            if (users[i].fileCount < MAX_FILES) {
                strcpy(users[i].files[users[i].fileCount].filename, filename);
                users[i].fileCount++;
            } else {
                printf("File limit reached for user %s\n", username);
            }
            return;
        }
    }
    printf("User not found!\n");
}

// Function to display directory structure
void display() {
    printf("\nTwo-Level Directory Structure:\n");
    for (int i = 0; i < userCount; i++) {
        printf("\nUser: %s\n", users[i].username);
        printf("Files:\n");
        for (int j = 0; j < users[i].fileCount; j++) {
            printf("  - %s\n", users[i].files[j].filename);
        }
    }
}

int main() {
    int choice;
    char user[MAX_NAME], file[MAX_NAME];

    while (1) {
        printf("\n--- Two Level Directory Menu ---\n");
        printf("1. Add User\n");
        printf("2. Add File\n");
        printf("3. Display Structure\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter username: ");
                scanf("%s", user);
                addUser(user);
                break;

            case 2:
                printf("Enter username: ");
                scanf("%s", user);
                printf("Enter filename: ");
                scanf("%s", file);
                addFile(user, file);
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

// C Program to Simulate Single-Level Directory Structure

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 10
#define NAME_LEN 20

// Structure for file
typedef struct {
    char filename[NAME_LEN];
} File;

File directory[MAX];
int fileCount = 0;

// Function to create file
void createFile()
{
    if (fileCount == MAX)
    {
        printf("Directory is full!\n");
        return;
    }

    printf("Enter file name: ");
    scanf("%s", directory[fileCount].filename);

    // Check duplicate
    for (int i = 0; i < fileCount; i++)
    {
        if (strcmp(directory[i].filename, directory[fileCount].filename) == 0)
        {
            printf("File already exists!\n");
            return;
        }
    }

    fileCount++;
    printf("File created successfully.\n");
}

// Function to delete file
void deleteFile()
{
    char name[NAME_LEN];
    printf("Enter file name to delete: ");
    scanf("%s", name);

    int found = 0;

    for (int i = 0; i < fileCount; i++)
    {
        if (strcmp(directory[i].filename, name) == 0)
        {
            found = 1;

            for (int j = i; j < fileCount - 1; j++)
            {
                directory[j] = directory[j + 1];
            }

            fileCount--;
            printf("File deleted successfully.\n");
            break;
        }
    }

    if (!found)
        printf("File not found!\n");
}

// Function to display files
void displayFiles()
{
    if (fileCount == 0)
    {
        printf("Directory is empty.\n");
        return;
    }

    printf("\nFiles in Directory:\n");
    for (int i = 0; i < fileCount; i++)
    {
        printf("%s\n", directory[i].filename);
    }
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n--- Single Level Directory ---\n");
        printf("1. Create File\n");
        printf("2. Delete File\n");
        printf("3. Display Files\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                createFile();
                break;
            case 2:
                deleteFile();
                break;
            case 3:
                displayFiles();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0 ;


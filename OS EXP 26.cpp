#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char data[100];
    char ch;

    // 1. CREATE and WRITE file
    fp = fopen("file.txt", "w");

    if(fp == NULL) {
        printf("File cannot be created\n");
        exit(1);
    }

    printf("Enter text to write into file: ");
    fgets(data, sizeof(data), stdin);

    fputs(data, fp);
    fclose(fp);

    printf("File created and data written successfully.\n");

    // 2. APPEND data to file
    fp = fopen("file.txt", "a");

    if(fp == NULL) {
        printf("File cannot be opened for append\n");
        exit(1);
    }

    printf("Enter text to append: ");
    fgets(data, sizeof(data), stdin);

    fputs(data, fp);
    fclose(fp);

    printf("Data appended successfully.\n");

    // 3. READ file
    fp = fopen("file.txt", "r");

    if(fp == NULL) {
        printf("File cannot be opened for reading\n");
        exit(1);
    }

    printf("\nFile Content:\n");

    while((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }

    fclose(fp);

    // 4. FILE DELETE operation
    if(remove("file.txt") == 0) {
        printf("\nFile deleted successfully.\n");
    } else {
        printf("\nError deleting file.\n");
    }

    return 0;
}

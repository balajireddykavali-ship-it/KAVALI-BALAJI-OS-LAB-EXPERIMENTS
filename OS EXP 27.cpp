#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main() {
    DIR *dir;
    struct dirent *entry;
    char path[100];

    // Input directory path
    printf("Enter directory path (use . for current directory): ");
    scanf("%s", path);

    // Open directory
    dir = opendir(path);

    if (dir == NULL) {
        printf("Cannot open directory\n");
        exit(1);
    }

    printf("\nFiles in directory '%s':\n\n", path);

    // Read and print directory contents
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    // Close directory
    closedir(dir);

    return 0;
}

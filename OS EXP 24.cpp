#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>

int main() {
    int fd;
    char buffer[100];
    struct stat fileStat;
    DIR *dir;
    struct dirent *entry;

    // Open or create file using fcntl/open
    fd = open("demo.txt", O_CREAT | O_RDWR, 0644);

    if (fd < 0) {
        printf("Error opening file\n");
        exit(1);
    }

    printf("File opened successfully.\n");

    // Write data into file
    write(fd, "UNIX System Calls", 18);

    // Move file pointer using lseek
    lseek(fd, 0, SEEK_SET);

    // Read file data
    read(fd, buffer, 18);
    buffer[18] = '\0';

    printf("Data from file: %s\n", buffer);

    // Get file statistics using stat
    stat("demo.txt", &fileStat);

    printf("\nFile Information:\n");
    printf("File Size: %ld bytes\n", fileStat.st_size);
    printf("Inode Number: %ld\n", fileStat.st_ino);

    // Open current directory using opendir
    dir = opendir(".");

    if (dir == NULL) {
        printf("Unable to open directory\n");
        close(fd);
        exit(1);
    }

    printf("\nFiles in current directory:\n");

    // Read directory entries using readdir
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    // Close directory and file
    closedir(dir);
    close(fd);

    return 0;
}

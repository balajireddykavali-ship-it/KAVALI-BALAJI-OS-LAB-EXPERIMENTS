#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>

int main() {
    int fd, size;
    char data[50];
    struct stat sfile;
    DIR *d;
    struct dirent *dir;

    // Open file using open()
    fd = open("test.txt", O_CREAT | O_RDWR, 0777);

    if(fd == -1) {
        printf("File cannot be opened\n");
        exit(1);
    }

    printf("File opened successfully\n");

    // Write into file
    write(fd, "Operating System Lab", 20);

    // Move pointer to beginning using lseek()
    lseek(fd, 0, SEEK_SET);

    // Read file content
    size = read(fd, data, 20);
    data[size] = '\0';

    printf("File Content: %s\n", data);

    // File statistics using stat()
    stat("test.txt", &sfile);

    printf("\nFile Statistics\n");
    printf("File Size : %ld bytes\n", sfile.st_size);
    printf("File ID   : %ld\n", sfile.st_ino);

    // Open current directory
    d = opendir(".");

    if(d == NULL) {
        printf("Cannot open directory\n");
        close(fd);
        exit(1);
    }

    printf("\nDirectory Contents:\n");

    // Read directory entries
    while((dir = readdir(d)) != NULL) {
        printf("%s\n", dir->d_name);
    }

    // Close directory and file
    closedir(d);
    close(fd);

    return 0;
}

#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

int main()
{
    char filename[100];
    struct stat fileStat;

    printf("Enter file name: ");
    scanf("%s", filename);

    if (access(filename, F_OK) != 0)
    {
        printf("File does not exist.\n");
        return 1;
    }

    stat(filename, &fileStat);

    printf("\nFILE ACCESS PERMISSIONS\n\n");

    printf("Owner  : ");
    printf((fileStat.st_mode & S_IRUSR) ? "Read " : "");
    printf((fileStat.st_mode & S_IWUSR) ? "Write " : "");
    printf((fileStat.st_mode & S_IXUSR) ? "Execute " : "");
    printf("\n");

    printf("Group  : ");
    printf((fileStat.st_mode & S_IWGRP) ? "Write " : "");
    printf((fileStat.st_mode & S_IXGRP) ? "Execute " : "");
    printf("\n");

    printf("Others : ");
    printf((fileStat.st_mode & S_IROTH) ? "Read " : "");
    printf((fileStat.st_mode & S_IWOTH) ? "Write " : "");
    printf((fileStat.st_mode & S_IXOTH) ? "Execute " : "");
    printf("\n");

    printf("\nOCTAL PERMISSION FORMAT\n");
    printf("Permissions (octal): %o\n", fileStat.st_mode & 0777);

    printf("\nDIFFERENT TYPES OF USERS IN LINUX\n");
    printf("1. Root User (Superuser - full access)\n");
    printf("2. Regular User (Limited access)\n");
    printf("3. System User (Service accounts)\n");

    return 0;
}

#include <stdio.h>

struct Employee {
    int id;
    char name[20];
    float salary;
};

int main() {
    FILE *fp;
    struct Employee emp;
    int n, i, searchId;
    long pos;

    fp = fopen("employee.dat", "wb+");

    printf("Enter number of employees: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("\nEnter ID Name Salary: ");
        scanf("%d %s %f", &emp.id, emp.name, &emp.salary);

        fwrite(&emp, sizeof(emp), 1, fp);
    }

    printf("\nEnter Employee ID to search: ");
    scanf("%d", &searchId);

    rewind(fp);

    while(fread(&emp, sizeof(emp), 1, fp)) {
        if(emp.id == searchId) {
            printf("\nEmployee Found\n");
            printf("ID: %d\n", emp.id);
            printf("Name: %s\n", emp.name);
            printf("Salary: %.2f\n", emp.salary);
            break;
        }
    }

    fclose(fp);

    return 0;
}

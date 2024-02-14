#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct student
{
    char name[50];
    int ID_no;
    char intake[20];
    int year;
    int contact_no;
    char email[50];
} Student;
void add_student(Student *students, int *n)
{
    if (*n == 100)
    {
        printf("List is full.\n");
        return;
    }
    printf("Enter student name: ");
    scanf("%s", students[*n].name);
    printf("Enter student ID number: ");
    scanf("%d", &students[*n].ID_no);
    printf("Enter student intake: ");
    scanf("%s", students[*n].intake);
    printf("Enter student year: ");
    scanf("%d", &students[*n].year);
    printf("Enter student contact number: ");
    scanf("%d", &students[*n].contact_no);
    printf("Enter student email: ");
    scanf("%s", students[*n].email);
    (*n)++;
}
void display_students(Student *students, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("Student %d:\n", i + 1);
        printf("Name: %s\n", students[i].name);
        printf("ID No: %d\n", students[i].ID_no);
        printf("Intake: %s\n", students[i].intake);
        printf("Year: %d\n", students[i].year);
        printf("Contact No: %d\n", students[i].contact_no);
        printf("Email: %s\n", students[i].email);
    }
}
void search_student_by_ID_no(Student *students, int n)
{
    int ID_no;
    int found = 0;
    printf("Enter student ID number to search: ");
    scanf("%d", &ID_no);
    int i;
    for (i = 0; i < n; i++)
    {
        if (students[i].ID_no == ID_no)
        {
            found = 1;
            break;
        }
    }
    if (found)
    {
        printf("Student found:\n");
        printf("Name: %s\n", students[i].name);
        printf("ID No: %d\n", students[i].ID_no);
        printf("Intake: %s\n", students[i].intake);
        printf("Year: %d\n", students[i].year);
        printf("Contact No: %d\n", students[i].contact_no);
        printf("Email: %s\n", students[i].email);
    }
    else
    {
        printf("Student not found.\n");
    }
}
int main()
{
    Student students[100];
    int n = 0;
    printf("Student Information Management System\n");
    printf("1. Add new student\n");
    printf("2. Display all students\n");
    printf("3. Search student by ID number\n");
    printf("4. Exit\n");
    int choice;
    while (1)
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            add_student(students, &n);
            break;
        case 2:
            display_students(students, n);
            break;
        case 3:
            search_student_by_ID_no(students, n);
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Invalid choice.\n");
        }
    }
    return 0;
}

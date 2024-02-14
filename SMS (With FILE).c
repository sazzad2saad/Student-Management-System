#include <stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#define tab (printf("\t"))
#define clr (system("CLS"))
#define bold_on  "\e[3m"
#define bold_off   "\e[m"

typedef struct student{
    char name[50];
    int ID_no;
    int intake;
    int year;
    int contact_no;
    char email[50];
}Student;



void add_student(Student student_struct){
    clr;
    //  ***data input***
    tab;printf("Enter student name: ");             gets(student_struct.name);
    tab;printf("Enter student ID number: ");        scanf("%d", &student_struct.ID_no);
    tab;printf("Enter student intake: ");           scanf("%d", &student_struct.intake);
    tab;printf("Enter student year: ");             scanf("%d", &student_struct.year);
    tab;printf("Enter student contact number: ");   scanf("%d", &student_struct.contact_no);
    tab;printf("Enter student email: ");            scanf("%s", &student_struct.email);

    //  ***file input***
    FILE *file_pre;
    file_pre=fopen("data.txt","a");

    fprintf(file_pre,"%d\t%s\t%d\t%d\t%d\t%s\n",student_struct.ID_no,student_struct.name,student_struct.intake,student_struct.year,student_struct.contact_no,student_struct.email);

    fclose(file_pre);

    return;
}



void display_students(Student student_struct){

    clr;

    FILE *file_pre;
    file_pre=fopen("data.txt","r");


    //  ***checking id***
    int found=0;
    int temp_id;
    tab;printf("Enter your ID No: ");                     scanf("%d",&temp_id);
    printf("\n");


    //  ***data collecting***
    while(!feof(file_pre)){
        char name_check[50],email_check[50];
        int id_check,intake_check,year_check,contact_check;
        fscanf(file_pre,"%d",&id_check);

        //worling checking
        printf("%d %s %d %d %d %s",id_check,name_check,intake_check,year_check,contact_check,email_check);

        //finish
        int nameSize=strlen(name_check), emailSize=strlen(email_check);
        if(temp_id==id_check){
            student_struct.ID_no=temp_id;
            fgets(student_struct.name,'\t',file_pre);
            fscanf(file_pre,"%d %d %d %s", &student_struct.intake, &student_struct.year, &student_struct.contact_no, student_struct.email);

            /*fscanf(file_pre,"%d",&student_struct.ID_no);
            fgets(student_struct.name,50,file_pre);
            fscanf(file_pre,"%d %d %d %s", &student_struct.intake, &student_struct.year, &student_struct.contact_no, student_struct.email);
            */
            found=1;
            break;
        }
        else{
            fgets(name_check,50,file_pre);
            fscanf(file_pre,"%d %d %d %s", &intake_check, &year_check, &contact_check, email_check);
        }

    }
    //  ***printing***
    if(found==1){
        //clr;
        tab;printf("Name: %s\n", student_struct.name);
        tab;printf("ID No: %d\n", student_struct.ID_no);
        tab;printf("Intake: %s\n", student_struct.intake);
        tab;printf("Year: %d\n", student_struct.year);
        tab;printf("Contact No: %d\n", student_struct.contact_no);
        tab;printf("Email: %s\n", student_struct.email);

    }
    else{
        //clr;
        tab;printf("\033[31m""Invalid Id!!!"bold_off"\n");
    }

    fclose(file_pre);




    return;
}



int main(){
    //  ***struct variable***
    Student student_struct;

    //welcome();
    clr;
    //   ***Welcome and main menu***
    char welcome_text[]=" Student Information Management System\n";
    tab;
    for(int i=0;i<strlen(welcome_text);i++){
        if(welcome_text[i]==' '){
            printf("%c",welcome_text[i]);
            Sleep(200);
        }
        else {
            printf("%c",welcome_text[i]);
            Sleep(50);
        }
    }
    main_menu:
    tab;printf("1. Add new student\n");
    tab;printf("2. Display all students\n");
    tab;printf("3. Search student by ID number\n");
    tab;printf("4. Exit\n");





    //  ***main switch***
    switch(getch()){
        case '1':
            add_student(student_struct);
            break;
        case '2':
            display_students(student_struct);
            break;
        case '3':
            break;
        case '4':
            clr;
            tab;printf("Do You really want to exit?");
            tab;printf("\033[31m""Y"bold_off"es");
            tab;printf("\033[32m""N"bold_off"o");
            switch(getch()){
                case ('Y'||'y'):
                    return 0;
                case ('n'):
                    clr;
                    goto main_menu;
                case ('N'):
                    clr;
                    goto main_menu;
            }
    }


    return 0;
}

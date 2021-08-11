/*
    @description: 
    * This is the gateway to the program 
    * It has the main function
*/
#include <stdio.h>
#include<stdlib.h>
#include "h.h"

int main(int argc, char const *argv[])
{
    printf("Working ...");
    perror("Error.");
    Student s={
        .id=1
    };
    Admin a={
        .id=2
    };
    Book b={
        .id=3
    };
    addStudentToFile(s);
    addAdminToFile(a);
    addBookToFile(b);
    getAllStudents();
    return 0;
}


/*************************/
// void addStudent()
// {
//     Student s = inputStudentDetails();
//     addStudentToFile(s);
// }
// void addAdmin()
// {
//     Admin a = inputAdminDetails();
//     addAdminToFile(a);
// }

// void addBook()
// {
//     Book b = inputBookDetails();
//     addBookToFile(b);
// }


/**************** FUNCTIONS FOR FILE HANDLING *******************/

/** ADDING INTO FILES **/
void addStudentToFile(Student s)
{
    FILE *studentFile;
    studentFile = fopen("student.bin", "ab"); //adding data to the existing file : appending
    if (studentFile == NULL)
    {
        perror("\nError opening the file.\n");
        exit(1);//check this later again
    }
    fwrite(&s, sizeof(Student), 1, studentFile);
    if (fwrite != 0)
    {
        printf("\nStudent added successfully!\n");
    }
    else
        perror("\nError while adding student!\n");
    fclose(studentFile);
}
void addAdminToFile(Admin a){
    FILE *adminFile;
    adminFile=fopen("admin.bin","ab");
    if (adminFile == NULL)
    {
        perror("\nError opening the file.\n");
        exit(1);//check this later again
    }
    fwrite(&a, sizeof(Admin), 1, adminFile);
    if (fwrite != 0)
    {
        printf("\nAdmin added successfully!\n");
    }
    else
        perror("\nError while adding admin!\n");
    fclose(adminFile);
}
void addBookToFile(Book b){
    FILE *bookFile;
    bookFile=fopen("admin.bin","ab");
    if (bookFile == NULL)
    {
        perror("\nError opening the file.\n");
        exit(1);//check this later again
    }
    fwrite(&b, sizeof(Book), 1, bookFile);
    if (fwrite != 0)
    {
        printf("\nBook added successfully!\n");
    }
    else
        perror("\nError while adding book!\n");
    fclose(bookFile);
}

/** READING FROM FILES **/
void getAllStudents(){
    FILE * studentFile;
    Student s;

    //open student.bin file for reading
    studentFile=fopen("student.bin","rb");
    if(studentFile==NULL){
        perror("\nError opening the file.\n");
        exit(1);
    }

    // read file content till the end of file
    while (fread(&s,sizeof(Student),1,studentFile))
    {
        /* your code to add the data of file to a array or to print the data*/
    }
    fclose(studentFile);
}
void getAllAdmins(){
    FILE * adminFile;
    Admin s;

    //open admin.bin file for reading
    adminFile=fopen("admin.bin","rb");
    if(adminFile==NULL){
        perror("\nError opening the file.\n");
        exit(1);
    }

    // read file content till the end of file
    while (fread(&s,sizeof(Admin),1,adminFile))
    {
        /* your code to add the data of file to a array or to print the data*/
    }
    fclose(adminFile);
}
void getAllBooks(){
    FILE * bookFile;
    Book s;

    //open book.bin file for reading
    bookFile=fopen("book.bin","rb");
    if(bookFile==NULL){
        perror("\nError opening the file.\n");
        exit(1);
    }

    // read file content till the end of file
    while (fread(&s,sizeof(Book),1,bookFile))
    {
        /* your code to add the data of file to a array or to print the data*/
    }
    fclose(bookFile);
}



/*
    @description: 
    * This is the gateway to the program 
    * It has the main function
*/
#include <stdio.h>
#include <stdlib.h>
#include "h.h"

int main(int argc, char const *argv[])
{
    printf("Working ...");
    perror("Error.");
    Student s = {
        .id = 1};
    Admin a = {
        .id = 2};
    Book b = {
        .id = 3};
    addStudentToFile(s);
    addAdminToFile(a);
    addBookToFile(b);
    getAllStudents();
    return 0;
}

/*********** FUNCTION TO ADD NEW RECORD **************/
//Add a new student
void addStudent()
{
    Student s = inputStudentDetails();
    addStudentToFile(s);
}
//Add a new admin
void addAdmin()
{
    Admin a = inputAdminDetails();
    addAdminToFile(a);
}

//Add a new book
void addBook()
{
    Book b = inputBookDetails();
    addBookToFile(b);
}

void issueBook()
{
    Issue i = inputIssueDetails();
    issueBookToFile(i);
}

void returnBook()
{
    Issue i = checkReturnConditions();
    returnBookToFile(i);
}

/***************** FUNCTION TO READ NEW RECORD DETAILS *******************/
Student inputStudentDetails()
{
    Student s;
    /* your code to read the new student details */
    return s;
}

Admin inputAdminDetails()
{
    Admin a;
    /* your code to read the new admin details */
    return a;
}

Book inputBookDetails()
{
    Book b;
    /* your code to read the details of the new book */
    return b;
}

Issue inputIssueDetails()
{
    Issue i;
    /* read details of the issue and do validation*/
    return i;
}

Issue checkReturnConditions()
{
    Issue i;
    /*do all the return condition validation*/
    return i;
}

/**************** FUNCTIONS FOR FILE HANDLING *******************/

/** ADDING INTO FILES **/
void addStudentToFile(Student s)
{
    FILE *studentFile;
    studentFile = fopen("files\\student.bin", "ab"); //adding data to the existing file : appending
    if (studentFile == NULL)
    {
        perror("\nError opening the file.\n");
        exit(1); //check this later again
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
void addAdminToFile(Admin a)
{
    FILE *adminFile;
    adminFile = fopen("files\\admin.bin", "ab");
    if (adminFile == NULL)
    {
        perror("\nError opening the file.\n");
        exit(1); //check this later again
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
void addBookToFile(Book b)
{
    FILE *bookFile;
    bookFile = fopen("files\\book.bin", "ab");
    if (bookFile == NULL)
    {
        perror("\nError opening the file.\n");
        exit(1); //check this later again
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

void issueBooktoFile(Issue i)
{
    FILE *issueFile;
    issueFile = fopen("files\\issue.bin", "ab");
    if (issueFile == NULL)
    {
        perror("\nError opening the file.\n");
        exit(1); //check this later again
    }
    fwrite(&i, sizeof(Issue), 1, issueFile);
    if (fwrite != 0)
    {
        printf("\nBook added successfully!\n");
    }
    else
        perror("\nError while adding book!\n");
    fclose(issueFile);
}

void returnBookToFile(Issue i)
{
    FILE *issueFile, *temp;
    issueFile = fopen("files\\issue.bin", "rb");
    temp = fopen("files\\temp.bin", "wb");
    Issue ri;

    if (issueFile == NULL || temp == NULL)
    {
        perror("\nError opening the file.\n");
        exit(1); //check this later again
    }

    while (fread(&ri, sizeof(Issue), 1, issueFile))
    {
        if (ri.iId == i.iId)
        {
            fwrite(&i, sizeof(Issue), 1, issueFile);
        }
        else
        {
            fwrite(&ri, sizeof(Issue), 1, issueFile);
        }
    }

    int ret = remove("files\\issue.bin");

    if (ret == 0)
    {
        printf("File deleted successfully");
    }
    else
    {
        printf("Error: unable to delete the file");
    }

    ret = rename("files\\temp.bin", "files\\issue.bin");
    if (ret == 0)
    {
        printf("File renamed successfully");
    }
    else
    {
        printf("Error: unable to rename the file");
    }
    fclose(issueFile);
}

/** READING FROM FILES **/
void getAllStudents()
{
    FILE *studentFile;
    Student s;

    //open student.bin file for reading
    studentFile = fopen("student.bin", "rb");
    if (studentFile == NULL)
    {
        perror("\nError opening the file.\n");
        exit(1);
    }

    // read file content till the end of file
    while (fread(&s, sizeof(Student), 1, studentFile))
    {
        /* your code to add the data of file to a array or to print the data*/
    }
    fclose(studentFile);
}
void getAllAdmins()
{
    FILE *adminFile;
    Admin a;

    //open admin.bin file for reading
    adminFile = fopen("admin.bin", "rb");
    if (adminFile == NULL)
    {
        perror("\nError opening the file.\n");
        exit(1);
    }

    // read file content till the end of file
    while (fread(&a, sizeof(Admin), 1, adminFile))
    {
        /* your code to add the data of file to a array or to print the data*/
    }
    fclose(adminFile);
}
void getAllBooks()
{
    FILE *bookFile;
    Book b;

    //open book.bin file for reading
    bookFile = fopen("book.bin", "rb");
    if (bookFile == NULL)
    {
        perror("\nError opening the file.\n");
        exit(1);
    }

    // read file content till the end of file
    while (fread(&b, sizeof(Book), 1, bookFile))
    {
        /* your code to add the data of file to a array or to print the data*/
    }
    fclose(bookFile);
}
void getAllIssues()
{
    FILE *issueFile;
    Issue i;

    //open issue.bin file for reading
    issueFile = fopen("issue.bin", "rb");
    if (issueFile == NULL)
    {
        perror("\nError opening the file.\n");
        exit(1);
    }

    // read file content till the end of file
    while (fread(&i, sizeof(Issue), 1, issueFile))
    {
        /* your code to add the data of file to a array or to print the data*/
    }

    fclose(issueFile);
}
void getAllCurrentIssues()
{
    FILE *issueFile;
    Issue i;

    //open issue.bin file for reading
    issueFile = fopen("issue.bin", "rb");
    if (issueFile == NULL)
    {
        perror("\nError opening the file.\n");
        exit(1);
    }

    // read file content till the end of file
    while (fread(&i, sizeof(Issue), 1, issueFile))
    {
        if (i.returnedDate == NULL)
        {
            /* your code to add the data of file to a array or to print the data*/
        }
    }
    fclose(issueFile);
}

/** BOOK SEARCH FUNCTIONS **/
/*
    * get search parameter form the user 
    * search for the book info in the book.bin file
    * get the book id and search the library information of the book in library.bin 
*/
void searchBookById(int bId) {}
void searchBookByTitle(char *bookTitle) {}

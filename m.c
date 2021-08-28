/*
    @description: 
    * This is the gateway to the program 
    * It has the main function
*/
#include <stdio.h>
#include <stdlib.h>
//#include "h.h"

// int main(int argc, char const *argv[])
// {
//     printf("Working ...");
//     perror("Error.");
//     Student s = {
//         .id = 1};
//     Admin a = {
//         .id = 2};
//     Book b = {
//         .id = 3};
//     addStudentToFile(s);
//     addAdminToFile(a);
//     addBookToFile(b);
//     getAllStudents();
//     return 0;
// }

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
    /*update the status to the library*/
    LibraryBook lb = makeNewLibraryBook(b);
    addToLibraryFile(lb);
}

void issueBook()
{
    Issue i = inputIssueDetails();
    issueBookToFile(i);
    /*update the book status to the library*/
    LibraryBook lb = makeLibraryBook(i, LISSUE);
    updateLibraryFile(lb);

    /*update the student account*/
    Student s = makeStudentDetails(i, LISSUE);
    updateStudentFile(s);
}

void returnBook()
{
    Issue i = checkReturnConditions();
    returnBookToFile(i);
    /*update the book status to the library*/
    LibraryBook lb = makeLibraryBook(i, LRETURN);
    updateLibraryFile(lb);

    /*update the student account*/
    Student s = makeStudentDetails(i, LISSUE);
    updateStudentFile(s);
}

void updateBookInfo()
{
    Book b;
    //get the new info about the book being updated
    //need to decide weither to show the old data or not
    //first show the old details
    int id = inputBookId(LUPDATE);
    b = getBookInfo(id);
    //display or no the details of this book
    //then input the new details of the book
    b = inputBookDetails();
    updateBookDetailsToFile(b);
}

void deleteBookInfo()
{
    Book b;
    // get the information about the book being deleted
    int id = inputBookId(LDELETE);
    b = getBookInfo(id);
    //then display or not the details of the book
    deleteBookDetailsFromFile(b);
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
    printf("\nWe will input the book details here.");
    return b;
}

Issue inputIssueDetails()
{
    Issue i;
    /* read details of the issue and do validation*/
    printf("\nWe will input the details for issue and validate here.");
    return i;
}

Issue checkReturnConditions()
{
    Issue i;
    /*do all the return condition validation*/
    printf("\nHere is the validations while returning the book.");
    return i;
}

/**************** FUNCTIONS FOR FILE HANDLING *******************/

/** ADDING INTO FILES **/
void addStudentToFile(Student s)
{
    FILE *studentFile;
    studentFile = fopen("files/student.bin", "ab"); //adding data to the existing file : appending
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
    adminFile = fopen("files/admin.bin", "ab");
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
    bookFile = fopen("files/book.bin", "ab");
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
void issueBookToFile(Issue i)
{
    FILE *issueFile;
    issueFile = fopen("files/issue.bin", "ab");
    if (issueFile == NULL)
    {
        perror("\nError opening the file.\n");
        exit(1); //check this later again
    }
    fwrite(&i, sizeof(Issue), 1, issueFile);
    if (fwrite != 0)
    {
        printf("\nBook issued successfully!\n");
    }
    else
        perror("\nError while adding book!\n");
    fclose(issueFile);
}
void returnBookToFile(Issue i)
{
    FILE *issueFile, *temp;
    issueFile = fopen("files/issue.bin", "rb");
    temp = fopen("files/temp.bin", "wb");
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

    fclose(issueFile);
    fclose(temp);
    int ret = remove("files/issue.bin");

    if (ret == 0)
    {
        printf("File deleted successfully");
    }
    else
    {
        printf("Error: unable to delete the file");
    }

    ret = rename("files/temp.bin", "files/issue.bin");
    if (ret == 0)
    {
        printf("File renamed successfully");
    }
    else
    {
        printf("Error: unable to rename the file");
    }
}

void addToLibraryFile(LibraryBook lb)
{
    FILE *libraryFile;
    libraryFile = fopen("files/library.bin", "ab"); //adding data to the existing file : appending
    if (libraryFile == NULL)
    {
        perror("\nError opening the file.\n");
        exit(1); //check this later again
    }
    fwrite(&lb, sizeof(LibraryBook), 1, libraryFile);
    if (fwrite != 0)
    {
        printf("\nBook added to Library successfully!\n");
    }
    else
        perror("\nError while adding student!\n");
    fclose(libraryFile);
}
void updateLibraryFile(LibraryBook lb)
{

    FILE *libraryFile, *temp;
    libraryFile = fopen("files/library.bin", "rb");
    temp = fopen("files/temp.bin", "wb");
    LibraryBook ri;

    if (libraryFile == NULL || temp == NULL)
    {
        perror("\nError opening the file.\n");
        exit(1); //check this later again
    }

    while (fread(&ri, sizeof(LibraryBook), 1, libraryFile))
    {
        if (ri.bId == lb.bId)
        {
            fwrite(&lb, sizeof(LibraryBook), 1, libraryFile);
        }
        else
        {
            fwrite(&ri, sizeof(LibraryBook), 1, libraryFile);
        }
    }

    fclose(libraryFile);
    fclose(temp);
    int ret = remove("files/library.bin");

    if (ret == 0)
    {
        printf("File deleted successfully");
    }
    else
    {
        printf("Error: unable to delete the file");
    }

    ret = rename("files/temp.bin", "files/library.bin");
    if (ret == 0)
    {
        printf("File renamed successfully");
    }
    else
    {
        printf("Error: unable to rename the file");
    }
}

void updateStudentFile(Student s)
{
    FILE *studentFile, *temp;
    studentFile = fopen("files/student.bin", "rb");
    temp = fopen("files/temp.bin", "wb");
    Student st;

    if (studentFile == NULL || temp == NULL)
    {
        perror("\nError opening the file.\n");
        exit(1); //check this later again
    }

    while (fread(&st, sizeof(Student), 1, studentFile))
    {
        if (st.id == s.id)
        {
            fwrite(&s, sizeof(Student), 1, studentFile);
        }
        else
        {
            fwrite(&st, sizeof(Student), 1, studentFile);
        }
    }

    fclose(studentFile);
    fclose(temp);
    int ret = remove("files/student.bin");

    if (ret == 0)
    {
        printf("File deleted successfully");
    }
    else
    {
        printf("Error: unable to delete the file");
    }

    ret = rename("files/temp.bin", "files/student.bin");
    if (ret == 0)
    {
        printf("File renamed successfully");
    }
    else
    {
        printf("Error: unable to rename the file");
    }
}

void updateBookDetailsToFile(Book b)
{
    //replacing
    FILE *bookFile, *temp;
    bookFile = fopen("files/book.bin", "rb");
    temp = fopen("files/temp.bin", "wb");
    Book ri;

    if (bookFile == NULL || temp == NULL)
    {
        perror("\nError opening the file.\n");
        exit(1); //check this later again
    }

    while (fread(&ri, sizeof(Book), 1, bookFile))
    {
        if (ri.id == b.id)
        {
            fwrite(&b, sizeof(Book), 1, bookFile);
        }
        else
        {
            fwrite(&ri, sizeof(Book), 1, bookFile);
        }
    }
    fclose(bookFile);
    fclose(temp);
    int ret = remove("files/book.bin");

    if (ret == 0)
    {
        printf("File deleted successfully");
    }
    else
    {
        printf("Error: unable to delete the file");
    }

    ret = rename("files/temp.bin", "files/book.bin");
    if (ret == 0)
    {
        printf("File renamed successfully");
    }
    else
    {
        printf("Error: unable to rename the file");
    }
}

void deleteBookDetailsFromFile(Book b)
{
    //removing
    FILE *bookFile, *temp;
    bookFile = fopen("files/book.bin", "rb");
    temp = fopen("files/temp.bin", "wb");
    Book ri;

    if (bookFile == NULL || temp == NULL)
    {
        perror("\nError opening the file.\n");
        exit(1); //check this later again
    }

    while (fread(&ri, sizeof(Book), 1, bookFile))
    {
        if (ri.id != b.id)
        {
            fwrite(&ri, sizeof(Book), 1, bookFile);
        }
    }
    fclose(bookFile);
    fclose(temp);
    int ret = remove("files/book.bin");

    if (ret == 0)
    {
        printf("File deleted successfully");
    }
    else
    {
        printf("Error: unable to delete the file");
    }

    ret = rename("files/temp.bin", "files/book.bin");
    if (ret == 0)
    {
        printf("File renamed successfully");
    }
    else
    {
        printf("Error: unable to rename the file");
    }
}

/** READING FROM FILES **/
void getAllStudents()
{
    FILE *studentFile;
    Student s;

    //open student.bin file for reading
    studentFile = fopen("files/student.bin", "rb");
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
    adminFile = fopen("files/admin.bin", "rb");
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
    bookFile = fopen("files/book.bin", "rb");
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
    issueFile = fopen("files/issue.bin", "rb");
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
    issueFile = fopen("files/issue.bin", "rb");
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
Book getBookInfo(int id)
{
    FILE *bookFile;
    Book b;
    //open book.bin file for reading
    bookFile = fopen("files/book.bin", "rb");
    if (bookFile == NULL)
    {
        perror("\nError opening the file.\n");
        exit(1);
    }

    // read file content till the end of file
    while (fread(&b, sizeof(Book), 1, bookFile))
    {
        if (id == b.id)
            break;
    }
    fclose(bookFile);
    return b;
}
/***********************/

LibraryBook makeNewLibraryBook(Book b)
{
    LibraryBook lb = {
        .bId = b.id,
        .qty = b.qty,
        .in = b.qty,
        .out = b.qty};
    return lb;
}

LibraryBook makeLibraryBook(Issue i, int libraryTask)
{
    FILE *libraryFile;
    LibraryBook lb;

    //open library.bin file for reading
    libraryFile = fopen("files/library.bin", "rb");
    if (libraryFile == NULL)
    {
        perror("\nError opening the file.\n");
        exit(1);
    }

    // read file content till the end of file
    while (fread(&lb, sizeof(Student), 1, libraryFile))
    {
        if (i.bId == lb.bId)
            break; //we look for the book id of the book being issued in the library and store the matched info into lb
    }
    fclose(libraryFile);
    //we have the data filled into lb from library
    //now we update the info according to the libraryTask
    switch (libraryTask)
    {
    case LISSUE:
        --lb.in;
        ++lb.out;
        break;
    case LRETURN:
        ++lb.in;
        --lb.out;
        break;
    default:
        perror("ERROR!!!");
        break;
    }
    return lb;
}

Student makeStudentDetails(Issue i, int libraryTask)
{
    FILE *studentFile;
    Student s;

    //open student.bin file for reading
    studentFile = fopen("files/student.bin", "rb");
    if (studentFile == NULL)
    {
        perror("\nError opening the file.\n");
        exit(1);
    }

    // read file content till the end of file
    while (fread(&s, sizeof(Student), 1, studentFile))
    {
        if (i.uId == s.id)
            break; //we look for the id of the issuee in the student file and store the matched info into s
    }
    fclose(studentFile);
    //we have the data filled into s from student.bin
    //now we update the info according to the libraryTask
    switch (libraryTask)
    {
    case LISSUE:
        --s.quota;
        break;
    case LRETURN:
        ++s.quota;
        break;
    default:
        perror("ERROR!!!");
        break;
    }
    return s;
}
/***********************/

/*************  HELPER FUNCTIONS  ***************/
int inputBookId(int libraryTask)
{
    int id = 0;

    switch (libraryTask)
    {
    case LUPDATE:
        //get the id from the user using some interface for updating the book information
        printf("\ninput book id to update.");
        break;
    case LDELETE:
        //get the id from the user using some interface for deleting the book information
        printf("\ninput book id to delete.");
        break;

    default:
        break;
    }

    return id;
}
/*************  HELPER FUNCTIONS  ***************/

/** BOOK SEARCH FUNCTIONS **/
/*
    * get search parameter form the user 
    * search for the book info in the book.bin file
    * get the book id and search the library information of the book in library.bin 
*/
void searchBookById(int bId) {}
void searchBookByTitle(char *bookTitle) {}

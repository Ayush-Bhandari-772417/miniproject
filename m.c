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
    /*     validate the student input info and redirect to the required function */


    addStudentToFile(s);
}
//Add a new admin
void addAdmin()
{
    Admin a = inputAdminDetails();
        /*     validate the student input info and redirect to the required function */


    addAdminToFile(a);
}

//Add a new book
void addBook()
{
    Book b = inputBookDetails();
    /*     validate the student input info and redirect to the required function */


    addBookToFile(b);
    /*update the status to the library*/
    LibraryBook lb = makeNewLibraryBook(b);
    addToLibraryFile(lb);
}

void issueBook()
{
    Issue i = inputIssueDetails();
    /*     validate the student input info and redirect to the required function */

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
    /*     validate the student input info and redirect to the required function */

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
    /*     validate the student input info and redirect to the required function */

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
    Student s, *stds;

    //open student.bin file for reading
    studentFile = fopen("files/student.bin", "rb");
    if (studentFile == NULL)
    {
        perror("\nError opening the file.\n");
        exit(1);
    }

    // read file content till the end of file
    {
        stds = (Student *)calloc(0, sizeof(Student));
        int i = 0;
        size_t n = 0;
        Student *temp;
        while (fread(&s, sizeof(Student), 1, studentFile))
        {

            //storing the student details form the file to a student poiner
            //this needs some optimization, may be later
            n = (&stds)[1] - stds;
            temp = (Student *)realloc(stds, (n + 1) * sizeof(Student));
            if (!temp)
            {
                //could not allcate memory successfully
            }
            else
            {
                stds = temp;
            }
            stds[i++] = s;
        }
        displayStudents(stds); //passing all the students to print
        free(stds);
        free(temp);
    }

    fclose(studentFile);
}
void getAllAdmins()
{
    FILE *adminFile;
    Admin a, *admin;

    //open admin.bin file for reading
    adminFile = fopen("files/admin.bin", "rb");
    if (adminFile == NULL)
    {
        perror("\nError opening the file.\n");
        exit(1);
    }

    // read file content till the end of file
    {
        admin = (Admin *)calloc(0, sizeof(Admin));
        int i = 0;
        size_t n = 0;
        Admin *temp;
        while (fread(&a, sizeof(Admin), 1, adminFile))
        {

            //storing the admin details form the file to a admin poiner
            //this needs some optimization, may be later
            n = (&admin)[1] - admin;
            temp = (Admin *)realloc(admin, (n + 1) * sizeof(Admin));
            if (!temp)
            {
                //could not allcate memory successfully
            }
            else
            {
                admin = temp;
            }
            admin[i++] = a;
        }
        displayAdmins(admin); //passing all the admins to print
        free(admin);
        free(temp);
    }

    fclose(adminFile);
}
void getAllBooks()
{
    FILE *bookFile;
    Book b, *book;

    //open book.bin file for reading
    bookFile = fopen("files/book.bin", "rb");
    if (bookFile == NULL)
    {
        perror("\nError opening the file.\n");
        exit(1);
    }

    // read file content till the end of file

    {
        book = (Book *)calloc(0, sizeof(Book));
        int i = 0;
        size_t n = 0;
        Book *temp;
        while (fread(&b, sizeof(Book), 1, bookFile))
        {

            //storing the book details form the file to a admin poiner
            //this needs some optimization, may be later
            n = (&book)[1] - book;
            temp = (Book *)realloc(book, (n + 1) * sizeof(Book));
            if (!temp)
            {
                //could not allcate memory successfully
            }
            else
            {
                book = temp;
            }
            book[i++] = b;
        }
        displayBooks(book); //passing all the books to print
        free(book);
        free(temp);
    }

    fclose(bookFile);
}
void getAllIssues()
{
    FILE *issueFile;
    Issue is, *issue;

    //open issue.bin file for reading
    issueFile = fopen("files/issue.bin", "rb");
    if (issueFile == NULL)
    {
        perror("\nError opening the file.\n");
        exit(1);
    }

    // read file content till the end of file
    {
        issue = (Issue *)calloc(0, sizeof(Issue));
        int i = 0;
        size_t n = 0;
        Issue *temp;
        while (fread(&is, sizeof(Issue), 1, issueFile))
        {

            //storing the issue details form the file to a admin poiner
            //this needs some optimization, may be later
            n = (&issue)[1] - issue;
            temp = (Issue *)realloc(issue, (n + 1) * sizeof(Issue));
            if (!temp)
            {
                //could not allcate memory successfully
            }
            else
            {
                issue = temp;
            }
            issue[i++] = is;
        }
        displayIssues(issue); //passing all the issues to print
        free(issue);
        free(temp);
    }

    fclose(issueFile);
}
void getAllCurrentIssues()
{
    FILE *issueFile;
    Issue is,*issue;

    //open issue.bin file for reading
    issueFile = fopen("files/issue.bin", "rb");
    if (issueFile == NULL)
    {
        perror("\nError opening the file.\n");
        exit(1);
    }

    // read file content till the end of file
   

    {
        issue = (Issue *)calloc(0, sizeof(Issue));
        int i = 0;
        size_t n = 0;
        Issue *temp;
        while (fread(&is, sizeof(Issue), 1, issueFile))
        {

            //storing the issue details form the file to a issue poiner
            //this needs some optimization, may be later

            if (is.returnedDate == NULL)//current issues ; open issues don't have returned dates
            {
                /* your code to add the data of file to a array or to print the data*/
                n = (&issue)[1] - issue;
                temp = (Issue *)realloc(issue, (n + 1) * sizeof(Issue));
                if (!temp)
                {
                    //could not allcate memory successfully
                }
                else
                {
                    issue = temp;
                }
                issue[i++] = is;
            }
        }
        displayIssues(issue); //passing all the issues to print
        free(issue);
        free(temp);
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

Student getStudentInfo(int id)
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
        if (id == s.id)
            break;
    }
    fclose(studentFile);
    return s;
}

void getAStudent()
{
    int id = inputStudentId();
    Student s = getStudentInfo(id);
    //then display the information in the particular format
    printf("\nDisplay the member details in a format here.");
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

int inputStudentId()
{
    int id = 0;
    printf("\nWe input student id to search the information of the student.");
    return id;
}
/*************  HELPER FUNCTIONS  ***************/

/*********************  DISPLAY FUNCTIONS HERE  ********************/
void displayStudents(Student *stds)
{
    /* your code here to display the student informations */
    printf("\nWe display the information of all the members here.");
}

void displayBooks(Book *books)
{
    /* your code here to display the book informations */
    printf("\nWe display the information of the books here.");
}

void displayAdmins(Admin* admins){
    printf("\nWe display the information of the admins here.");
}
void displayIssues(Issue* issues){
printf("\nWe display all the current open issues here.");
}

/*********************  DISPLAY FUNCTIONS HERE  ********************/

/** BOOK SEARCH FUNCTIONS **/
/*
    * get search parameter form the user 
    * search for the book info in the book.bin file
    * get the book id and search the library information of the book in library.bin 
*/
void searchBookById(int bId) {}
void searchBookByTitle(char *bookTitle) {}

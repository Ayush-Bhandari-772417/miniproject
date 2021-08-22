/*
    @description :
    * modules to be used are declared as structure in this file
    * each structure represents the format of in which the data is to be stored in respective files
    * 
*/


/*************** ENUMERATION DECLARATION ***************/
enum bookCondition{
    OLD,NEW
};

enum bookStatus{
    IN,OUT
};


/****************** STRUCTURE CREATION *********************/
//a user is a registered memeber of the library
typedef struct user{
    int id; 
    char name[20];
    char issueDate[10];
    char expiryDate[10];
    int quota;
}Student;

typedef struct studentAccount{
    int uId;
    int bId;
    char issueDate[10];
    char returnDate[10];
}StudentAccount;

typedef struct admin{
    int id; 
    char name[20];
    char issueDate[10];
    char expiryDate[10];
}Admin;

typedef struct book{
    int id;
    char title[25];
    char author[25];
    float cost;
    int qty;//quantity
    int cdn;//condition
    int status;
}Book;

typedef struct library{
    int bId;//book id
    int qty;//total number of books
    int in;//number of books in
    int out;//number of books out
}Library;


typedef struct issue{
    int iId;//issue id
    int uId;//issuer/user or student id
    int bId;//issued book id
    char issueDate[10];
    char returnDate[10];
    char returnedDate[10];
}Issue;

/************** FUNCTION DECLARATION ****************/

/*
    * this is for registering a new student
    * addStudent() : it takes care of reading the new student information and adding the record to the file
    * first inputStudentDetails() takes the student details
    * the student is passed to addStudentToFile() 
    * then a student registration is completed 
*/
void addStudent();
Student inputStudentDetails();
void addStudentToFile(Student s);

/*
    * this is for registering a new admin
    * addAdmin() : it takes care of reading the new admin information and adding the record to the file
    * first inputAdminDetails() takes the admin details
    * the admin is passed to addAdminToFile() 
    * then a admin registration is completed 
*/
void addAdmin();
Admin inputAdminDetails();
void addAdminToFile(Admin a);

/*
    * this is for adding a new book
    * addBook() : it takes care of reading the new book information and adding the record to the file
    * first inputBookDetails() takes the admin details
    * the admin is passed to addBookToFile() 
    * then a new book is added 
*/
void addBook();
Book inputBookDetails();
void addBookToFile(Book b);

/*
    * these functions are for storing the information about the book issued and returned
    * new issue will be created when a book is issued 
    * while returning the book the existing issue will be updated
*/
void issueBook();
void inputIssueDetails();
void issueBookToFile(Issue i);

void returnBook();
Issue checkReturnConditions();
void returnBookToFile(Issue i);




/************* ADMIN ONLY FUNCTIONS **************/
/*
    * these functions are to be used by the admin
    * these functions will be called from the admin module only
*/
void getAllStudents();
void getAllBooks();
void getAllAdmins();
void getAllIssues();
void getAllCurrentIssues();


/** SEARCH BY FUNCTIONALITY FOR BOOK SEARCH **/
/*
    * using search by id and title for now for simplicity 
    * other search parameters can be added later
*/
void searchBookById(int bId);
void searchBookByTitle(char *title);
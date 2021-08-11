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



/************** FUNCTION DECLARATION ****************/

void addStudent();
Student inputStudentDetails();
void addStudentToFile(Student s);

void addAdmin();
Admin inputAdminDetails();
void addAdminToFile(Admin a);

void addBook();
Book inputBookDetails();
void addBookToFile(Book b);


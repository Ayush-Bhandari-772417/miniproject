/*
    @description :
    * modules to be used are declared as structure in this file
    * each structure represents the format of in which the data is to be stored in respective files
    * 
*/


/*************** ENUMERATION DECLARATION ***************/

enum bookStatus{
    BIN,BOUT
};
enum bookCondition{
    OLD,NEW
};



enum libraryTask{
    LISSUE,LRETURN,LUPDATE,LDELETE
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


//this may not be used
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
}LibraryBook;


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

Student makeStudentDetails(Issue i, int libraryTask);
void updateStudentFile(Student s);


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
Issue inputIssueDetails();
void issueBookToFile(Issue i);

void returnBook();
Issue checkReturnConditions();
void returnBookToFile(Issue i);

/***  MORE FUNCTIONS FOR BOOKS  ****/
Book getBookInfo(int id);
int inputBookId(int libraryTask);
void updateBookInfo();
void deleteBookInfo();
void updateBookDetailsToFile(Book b);
void deleteBookDetailsFromFile(Book b);

/*
    * updating the book status in the library file after issue and return
    * change book status to out, 
    * change student account , decrease student quota
*/
LibraryBook makeNewLibraryBook(Book b);
LibraryBook makeLibraryBook(Issue i,int libraryTask);
void addToLibraryFile(LibraryBook lb);
void updateLibraryFile(LibraryBook lb);

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


/**  FROM FUNCTION.H OF AAYUSH BHANDARI  **/
/*
    * these functiuon declarations are done by Aayush Bhandari
    * these are basically for the UI part and some basic functionality
    * 
*/
void printMessageCenter(const char*);	// print message at the centre
void heading(int, int);					// heading of entire program
void headMessage(const char *);			// design heading of each page
void design(int);				// design of all selection menu

void setxy (int, int);				// function to locate cursor
void set_print(int, int, const char *, char);			// function to set cursor & display
int cursor(char ch[], int, int, int);			// move the selection

void home_page();				// home page of program(First page)
void main_menu();				// The main menu of the program

					// options of main menu
void add_login();
void std_login();
void rules();
void about();

					// after loging in to respective menu
void admin_menu();
void std_menu();

					// in the menu for admin
void ad_book_handle();				// book handling menu for admin
void ad_std_handle();			// handle issuers data
void ad_cred_handle();			// handle credential of both student and admin
void keep_data();			// sets important data like fines %, no of days to issue books, ...

						// book handling menu for admin
void add_book();
void issue();
void retrn();
void mfy_book();
void dlt_book();
void disp_book();
void sch_book(int);

						// student handling menu for admin
void add_std();
void mfy_std();
void dlt_std();
void disp_std();
void sch_std();

						// credential handling menu for admin
void add_ad_cred();
void add_std_cred();
void dlt_ad_cred();
void dlt_std_cred();
void mfy_ad_cred();
void mfy_std_cred();


							// option for student menu
void change_cred();

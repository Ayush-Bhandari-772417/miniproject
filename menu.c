#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h> //contains strcmp(),strcpy(),strlen(),etc
#include <ctype.h>	//contains toupper(), tolower(),etc
#include <time.h>
#include <windows.h> // contains function to locate cursor
#include "design.h"	 // design of menu and other screen
#include "h.h"
#include "m.c"

void home_page() // home page of program(First page)
{
	char chc[2] = {16, ' '};
	int decision, x, y;
	headMessage("Home page");
	printf("\n\n\n\n\n");
	printf("\n\t**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
	printf("\n\t\t  %c`````````````````````````````````````````%c", 186, 186);
	printf("\n\t\t  %c                 WELCOME                 %c", 186, 186);
	printf("\n\t\t  %c                   TO                    %c", 186, 186);
	printf("\n\t\t  %c                 LIBRARY                 %c", 186, 186);
	printf("\n\t\t  %c               MANAGEMENT                %c", 186, 186);
	printf("\n\t\t  %c                 SYSTEM                  %c", 186, 186);
	printf("\n\t\t  %c                (LIBMAX)                 %c", 186, 186);
	printf("\n\t\t  %c_________________________________________%c", 186, 186);
	printf("\n\n\t**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n\n\n");

	design(5);
	x = 27;
	y = 35; // Position of first line to show option
	setxy(0, y - 4);
	printMessageCenter("Use cursor to move and ENTER to select");
	set_print(x, y, "1. Enter to the main menu", chc[0]);
	set_print(x, y + 1, "2. Exit from system", chc[1]);

	decision = cursor(chc, x, y, 2); // function call to know option chosen
	if (decision == 1)
		main_menu();
	else
		main(0);
}

void main_menu() // The main menu of the program
{
	int i, decision, x, y;
	char chc[6] = {16, ' ', ' ', ' ', ' ', ' '};
	headMessage("Main menu");
	printf("\n\n\n\t\t\t");
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 SELECT CATEGOIES \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

	design(11);
	x = 25;
	y = 19;
	set_print(x, y, "1. Administration login portal", chc[0]);
	// set_print(x, y+1, "2. Student login portal", chc[1]);
	// set_print(x, y+2, "3. Library rules", chc[2]);
	// set_print(x, y+3, "4. About", chc[3]);
	set_print(x, y + 4, "5. Return to home page", chc[4]);
	set_print(x, y + 5, "6. Exit", chc[5]);

	decision = cursor(chc, x, y, 6);

	//this is better with switch() statement
	if (decision == 1)
		add_login();
	else if (decision == 2)
		std_login();
	else if (decision == 3)
		rules();
	else if (decision == 4)
		about();
	else if (decision == 5)
		home_page();
	else
		main(0);
}

void add_login()
{
	int x, y;
	char chc[1] = {' '}, pwd[20];
	headMessage("Administration login portal");

	design(10);
	x = 19;
	y = 15;
	setxy(0, y);

	printMessageCenter("Enter Admin's credentials'");

	set_print(x, y + 3, "Username :- ______________________", chc[0]);
	set_print(x, y + 5, "Password :- ______________________", chc[0]);

	setxy(x + 14, y + 3);
	scanf("%[^\n]s", user);
	fseek(stdin, 0, SEEK_END);
	setxy(x + 14, y + 5);
	scanf("%[^\n]s", pwd);
	fseek(stdin, 0, SEEK_END);
	//add the admin validation code here
	admin_menu();
}

void std_login()
{
	int x, y;
	char chc[1] = {' '}, pwd[20];
	headMessage("Student login portal");

	design(10);
	x = 19;
	y = 15;
	setxy(0, y);

	printMessageCenter("Enter Student's credentials'");

	set_print(x, y + 3, "Username :- ______________________", chc[0]);
	set_print(x, y + 5, "Password :- ______________________", chc[0]);

	setxy(x + 14, y + 3);
	scanf("%[^\n]s", user);
	fseek(stdin, 0, SEEK_END);
	setxy(x + 14, y + 5);
	scanf("%[^\n]s", pwd);
	fseek(stdin, 0, SEEK_END);
	//set student validation code here
	std_menu();
}

void admin_menu()
{
	int i, decision, x, y;
	char chc[6] = {16, ' ', ' ', ' ', ' ', ' '};
	headMessage("Admin menu");
	printf("\n\n\n\t\t\t");
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 SELECT CATEGOIES \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

	design(10);
	x = 22;
	y = 19;
	set_print(x, y, "1. Book handling", chc[0]);
	set_print(x, y + 1, "2. Students handling", chc[1]);
	//set_print(x, y+2, "3. Credentials handling", chc[2]);
	//set_print(x, y+3, "4. Keep important data frequently used", chc[3]);//what is this for
	set_print(x, y + 4, "5. Return to home page", chc[4]);
	set_print(x, y + 5, "6. Exit", chc[5]);

	decision = cursor(chc, x, y, 6);

	if (decision == 1)
		ad_book_handle();
	else if (decision == 2)
		ad_std_handle();
	else if (decision == 3)
		ad_cred_handle();
	else if (decision == 4)
		keep_data();
	else if (decision == 5)
		home_page();
	else
		main(0);
}

void ad_book_handle() // book handling menu for admin
{
	int i, decision, x, y;
	char chc[10] = {16, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
	headMessage("Admin handling books");
	printf("\n\n\n\t\t\t");
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 SELECT CATEGOIES \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

	design(14);
	x = 25;
	y = 19;
	set_print(x, y, "1. Add book", chc[0]);
	set_print(x, y + 1, "2. Issue book", chc[1]);
	set_print(x, y + 2, "3. Return book", chc[2]);
	set_print(x, y + 3, "4. Modify book info", chc[3]);
	set_print(x, y + 4, "5. Delete book", chc[4]);
	set_print(x, y + 5, "6. Display books", chc[5]);
	set_print(x, y + 6, "7. Search books", chc[6]);
	set_print(x, y + 7, "8. Back", chc[7]);
	set_print(x, y + 8, "9. Return to home page", chc[8]);
	set_print(x, y + 9, "10. Exit", chc[9]);

	decision = cursor(chc, x, y, 10);

	//better use switch statement
	if (decision == 1)
		add_book();
	else if (decision == 2)
		issue();
	else if (decision == 3)
		retrn();
	else if (decision == 4)
		mfy_book();
	else if (decision == 5)
		dlt_book();
	else if (decision == 6)
		disp_book();
	else if (decision == 7)
		sch_book(1);
	else if (decision == 8)
		admin_menu();
	else if (decision == 9)
		home_page();
	else
		main(0);
}

void disp_book()
{
	int i, decision, x, y;
	char chc[10] = {16, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
	headMessage("Display books of library");
	printf("\n\n\n\t\t\t");
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 SELECT CATEGOIES \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

	design(16);
	x = 25;
	y = 19;
	set_print(x - 7, y, "Display :", chc[1]);
	set_print(x, y + 1, "1. All books", chc[0]);
	set_print(x, y + 2, "2. Issued books", chc[1]);
	set_print(x, y + 3, "3. Available books", chc[2]);
	set_print(x, y + 4, "4. Turned books", chc[3]);
	set_print(x, y + 5, "5. Lost books", chc[4]);
	set_print(x, y + 6, "6. No. of transaction", chc[5]);
	set_print(x, y + 7, "7. Issuable books", chc[6]);
	set_print(x, y + 8, "8. Back", chc[7]);
	set_print(x, y + 9, "9. Return to home page", chc[8]);
	set_print(x, y + 10, "10. Exit", chc[9]);

	decision = cursor(chc, x, y + 1, 10);
	if (decision == 8)
		ad_book_handle();
	else if (decision == 9)
		home_page();
	else if (decision == 10)
		main(0);
}

void sch_book(int a)
{
	int i, decision, x, y;
	char chc[10] = {16, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
	headMessage("Search books in the library");
	printf("\n\n\n\t\t\t");
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 SELECT CATEGOIES \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

	design(16);
	x = 30;
	y = 19;
	set_print(x - 12, y, "Search books by :", chc[1]);
	set_print(x, y + 1, "1. Book ID", chc[0]);
	set_print(x, y + 2, "2. Author", chc[1]);
	set_print(x, y + 3, "3. Publication", chc[2]);
	set_print(x, y + 4, "4. Genre", chc[3]);
	set_print(x, y + 5, "5. Subject", chc[4]);
	set_print(x, y + 6, "6. Book type", chc[5]);
	set_print(x, y + 7, "7. Pages", chc[6]);
	set_print(x, y + 8, "8. Back", chc[7]);
	set_print(x, y + 9, "9. Return to home page", chc[8]);
	set_print(x, y + 10, "10. Exit", chc[9]);

	decision = cursor(chc, x, y + 1, 10);
	if (decision == 8)
	{
		if (a == 1)
			ad_book_handle();
		else
			std_menu();
	}
	else if (decision == 9)
		home_page();
	else if (decision == 10)
		main(0);
}

void ad_std_handle() // handle issuers data
{
	int i, decision, x, y;
	char chc[8] = {16, ' ', ' ', ' ', ' ', ' ', ' ', ' '};
	headMessage("Admin handling issuers");
	printf("\n\n\n\t\t\t");
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 SELECT CATEGOIES \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

	design(12);
	x = 25;
	y = 19;
	set_print(x, y, "1. Add memeber", chc[0]);
	//set_print(x, y+1, "2. Modify issuers info", chc[1]);
	//set_print(x, y + 2, "3. Delete member info", chc[2]);
	set_print(x, y + 3, "4. Display member", chc[3]);
	//set_print(x, y + 4, "5. Search member details", chc[4]); // moved to search student/member
	set_print(x, y + 5, "6. Back", chc[5]);
	set_print(x, y + 6, "7. Return to home page", chc[6]);
	set_print(x, y + 7, "8. Exit", chc[7]);

	decision = cursor(chc, x, y, 8);

	if (decision == 1)
		add_std();
	else if (decision == 2)
		mfy_std(); //don't know about this
	else if (decision == 3)
		dlt_std(); //once a member, always a member. instead renewal status have to be checked
	else if (decision == 4)
		disp_std();
	else if (decision == 5)
		sch_std();//should be included inside display student
	else if (decision == 6)
		admin_menu();
	else if (decision == 7)
		home_page();
	else
		main(0);
}

void disp_std()
{
	int i, decision, x, y;
	char chc[10] = {16, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
	headMessage("Display members of the library");
	printf("\n\n\n\t\t\t");
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 SELECT CATEGOIES \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

	design(14);
	x = 25;
	y = 19;
	set_print(x - 7, y, "Display :", chc[1]);
	set_print(x, y + 1, "1. All members", chc[0]);
	set_print(x, y + 2, "2. A member details", chc[1]);
	//	set_print(x, y+2, "2. Students by admiited year", chc[1]);
	//	set_print(x, y+3, "3. Students by semesters", chc[2]);
	//	set_print(x, y+4, "4. Students by faculty", chc[3]);
	//	set_print(x, y+5, "5. Students by sem & faculty", chc[4]);
	//	set_print(x, y+6, "6. Black listed issuers", chc[5]);
	//	set_print(x, y+7, "7. Issuers by post", chc[6]);

	set_print(x, y + 8, "8. Back", chc[7]);
	set_print(x, y + 9, "9. Return to home page", chc[8]);
	set_print(x, y + 10, "10. Exit", chc[9]);

	decision = cursor(chc, x, y + 1, 10);
	switch (decision)
	{
	case 1:
		//to display all the memebers
		disp_all_std();
		break;
	case 2:
		//to search and display the information of a student
		disp_a_std();
		break;

	case 8:
		ad_std_handle();
		break;
	case 9:
		home_page();
		break;
	case 10:
		main(0);
		break;
	default:
		break;
	}
}

void sch_std()
{
	int i, decision, x, y;
	char chc[8] = {16, ' ', ' ', ' ', ' ', ' ', ' ', ' '};
	headMessage("Search isuuers details");
	printf("\n\n\n\t\t\t");
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 SELECT CATEGOIES \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

	design(14);
	x = 25;
	y = 19;
	set_print(x - 7, y, "Search individual issuer's :", chc[1]);
	set_print(x, y + 1, "1. General info", chc[0]);
	set_print(x, y + 2, "2. History in library'", chc[1]);
	set_print(x, y + 3, "3. List of books currently issued", chc[2]);
	set_print(x, y + 4, "4. Books issued and returned", chc[3]);
	set_print(x, y + 5, "5. List of fines", chc[4]);
	set_print(x, y + 6, "6. Back", chc[5]);
	set_print(x, y + 7, "7. Return to home page", chc[6]);
	set_print(x, y + 8, "8. Exit", chc[7]);

	decision = cursor(chc, x, y + 1, 8);
	if (decision == 6)
		ad_std_handle();
	else if (decision == 7)
		home_page();
	else if (decision == 8)
		main(0);
}

void ad_cred_handle() // handle credential of both student and admin
{
	int i, decision, x, y;
	char chc[9] = {16, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
	headMessage("Admin handling credentials");
	printf("\n\n\n\t\t\t");
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 SELECT CATEGOIES \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

	design(12);
	x = 25;
	y = 19;
	set_print(x, y, "1. Add admin credential", chc[0]);
	set_print(x, y + 1, "2. Add issuer credential", chc[1]);
	set_print(x, y + 2, "3. Delete admin's credential", chc[2]);
	set_print(x, y + 3, "4. Delete issuer's credential", chc[3]);
	set_print(x, y + 4, "5. Modify admin's credential", chc[4]);
	set_print(x, y + 5, "6. Modify issuer's credential", chc[5]);
	set_print(x, y + 6, "7. Back", chc[6]);
	set_print(x, y + 7, "8. Return to home page", chc[7]);
	set_print(x, y + 8, "9. Exit", chc[8]);

	decision = cursor(chc, x, y, 9);

	if (decision == 1)
		add_ad_cred();
	else if (decision == 2)
		add_std_cred();
	else if (decision == 3)
		dlt_ad_cred();
	else if (decision == 4)
		dlt_std_cred();
	else if (decision == 5)
		mfy_ad_cred();
	else if (decision == 6)
		mfy_std_cred();
	else if (decision == 7)
		admin_menu();
	else if (decision == 8)
		home_page();
	else if (decision == 9)
		main(0);
}

void std_menu()
{
	int i, decision, x, y;
	char chc[9] = {16, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
	headMessage("Student menu");
	printf("\n\n\n\t\t\t");
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 SELECT CATEGOIES \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

	design(14);
	x = 25;
	y = 19;
	set_print(x - 7, y, "View :", chc[1]);
	set_print(x, y + 1, "1. General info", chc[0]);
	set_print(x, y + 2, "2. History in library'", chc[1]);
	set_print(x, y + 3, "3. List of books currently issued", chc[2]);
	set_print(x, y + 4, "4. Books issued and returned", chc[3]);
	set_print(x, y + 5, "5. List of fines", chc[4]);
	set_print(x, y + 6, "6. Change cedential", chc[5]);
	set_print(x, y + 7, "7. Search Books in library", chc[6]);
	set_print(x, y + 8, "8. Return to home page", chc[7]);
	set_print(x, y + 9, "9. Exit", chc[8]);

	decision = cursor(chc, x, y + 1, 9);

	if (decision == 6)
		change_cred();
	else if (decision == 7)
		sch_book(0);
	else if (decision == 8)
		home_page();
	else if (decision == 9)
		main(0);
}

int main(int d)
{
	if (d != 0)
		home_page();
	else
		printf("\n\n\n\n\n\t\t\t Thank you for using the program !!! \n\n");

	return 0;
}

/**************************************  FROM EMPTY.h  **************************************/
/**************************************  FROM EMPTY.h  **************************************/
/**************************************  FROM EMPTY.h  **************************************/
/**************************************  FROM EMPTY.h  **************************************/

/************  FROM MAIN MENU  ***************/
// options from main menu
void rules()
{
	headMessage("Library rules");

	// display the rules here
	getch();
	main_menu();
}

void about()
{
	headMessage("About system");
	getch();
	main_menu();
}

/************  FROM ADMIN MENU  ***************/
// options from admin menu

//functions to be determined later
void keep_data() // sets important data like fines %, no of days to issue books, ...
{
	headMessage("Keep important data in file");
	getch();
	admin_menu();
}

/************  FROM ADMIN BOOK MENU  ***************/
//@dura : working on this
// options from admin's book handling menu

void add_book()
{
	headMessage("Add new books");
	addBook(); //from h.h
	getch();
	ad_book_handle();
}

void issue()
{
	headMessage("Issue books from library");
	issueBook(); //from h.h
	getch();
	ad_book_handle();
}

void retrn()
{
	headMessage("Return books to the library");
	returnBook(); //from h.h
	getch();
	ad_book_handle();
}

void mfy_book()
{
	headMessage("Modify the book records");
	updateBookInfo(); //from h.h
	getch();
	ad_book_handle();
}

void dlt_book()
{
	headMessage("Delete books from library");
	deleteBookInfo(); //from h.h
	getch();
	ad_book_handle();
}

/************  FROM ADMIN STUDENT MENU  ***************/

// options from admin's student handling menu

void add_std()
{
	headMessage("Admin adding issuers in the library");
	addStudent(); //from h.h
	getch();
	ad_std_handle();
}

void mfy_std()
{
	headMessage("Modifying issuers details");
	getch();
	ad_std_handle();
}

void dlt_std()
{
	headMessage("Deleting students' info'");
	getch();
	ad_std_handle();
}

void add_ad_cred()
{
	headMessage("Add new admin credentials");
	getch();
	ad_cred_handle();
}

void disp_all_std(){
	headMessage("Display All Memebers");
	getAllStudents();//from h.h
	getchar();
	getch();
	disp_std();
}
void disp_a_std(){
	headMessage("Display Memeber Details");
	getAStudent();//from h.h
	getch();
	ad_std_handle();
}
/************  FROM ADMIN CREDENTIAL MENU  ***************/
// options from admin's credentials handling menu

void add_std_cred()
{
	headMessage("Add new issuer credentials");
	getch();
	ad_cred_handle();
}

void dlt_ad_cred()
{
	headMessage("Delete admin credentials");
	getch();
	ad_cred_handle();
}

void dlt_std_cred()
{
	headMessage("Delete issuer credentials");
	getch();
	ad_cred_handle();
}

void mfy_ad_cred()
{
	headMessage("Modify admin credentials");
	getch();
	ad_cred_handle();
}

void mfy_std_cred()
{
	headMessage("Modify issuer credentials");
	getch();
	ad_cred_handle();
}

/************  FROM STUDENT MENU  ***************/
// option for student menu
void change_cred()
{
	headMessage("Change own credential");
	getch();
	std_menu();
}


/***************** FUNCTION TO READ NEW RECORD DETAILS *******************/
/*
	* these functins has the declaration in h.h files
	* defined by @dura
	* supposed to be in the m.h file
	* but defined in menu.h file because this file is suppose to contain the functions with design part
	* m.h should not contain the code that include the design design(windows dependent) functions
*/

Student inputStudentDetails()
{
    Student s;
    /* your code to read the new student details */
    printf("\nWe will input the new student details here.");
    //also need no validate the student

 int x, y;
    char chc[1] = {' '}, choice;
    headMessage("Add Student of library in system");
    design(29);
	x=19;			y=15;
	setxy(0,y);
	
	printMessageCenter("Enter Student's information");
	
	set_print(x, y+4, "ID \t :- ______________________", chc[0]);
	set_print(x, y+6, "Name \t :- ______________________", chc[0]);
	set_print(x, y+8, "Issue Date\t :- ______________________", chc[0]);
	set_print(x, y+10, "ExpiryDate\t :- ______________________", chc[0]);
	set_print(x, y+12, "Quota \t :- ______________________", chc[0]);

	setxy(x+17,y+4);
	scanf("%d", &s.id);
	fseek(stdin, 0, SEEK_END);
	
	setxy(x+17,y+6);
	scanf("%[^\n]s", s.name);
	fseek(stdin, 0, SEEK_END);
	
	setxy(x+17,y+8);
	scanf("%[^\n]s", s.issueDate);
	fseek(stdin, 0, SEEK_END);
	
	setxy(x+17,y+10);
	scanf("%[^\n]s", s.expiryDate);
	fseek(stdin, 0, SEEK_END);
	
	setxy(x+17,y+12);
	scanf("%d", &s.quota);
	fseek(stdin, 0, SEEK_END);

    return s;
}

Admin inputAdminDetails()
{
    Admin a;
    /* your code to read the new admin details */

	int x, y;
    char chc[1] = {' '}, choice;
    headMessage("Add Admin of library in system");
    design(29);
	x=19;			y=15;
	setxy(0,y);
	
	printMessageCenter("Enter Admin's information");
	
	set_print(x, y+4, "ID \t :- ______________________", chc[0]);
	set_print(x, y+6, "Name \t :- ______________________", chc[0]);
	set_print(x, y+8, "IssueDate\t :- ______________________", chc[0]);
	set_print(x, y+10, "ExpiryDate\t :- ______________________", chc[0]);

	setxy(x+17,y+4);
	scanf("%d", &a.id);
	fseek(stdin, 0, SEEK_END);
	
	setxy(x+17,y+6);
	scanf("%[^\n]s", a.name);
	fseek(stdin, 0, SEEK_END);
	
	setxy(x+17,y+8);
	scanf("%[^\n]s", a.issueDate);
	fseek(stdin, 0, SEEK_END);
	
	setxy(x+17,y+10);
	scanf("%[^\n]s", a.expiryDate);
	fseek(stdin, 0, SEEK_END);
	
    return a;
}

Book inputBookDetails()
{
    Book b;
    /* your code to read the details of the new book */
    printf("\nWe will input the book details here.");

     int x, y;
    char chc[1] = {' '}, choice;
    headMessage("Add book of library in system");
    design(29);
	x=19;			y=15;
	setxy(0,y);
	
	printMessageCenter("Enter Book's information");
	
	set_print(x, y+4, "ID \t :- ______________________", chc[0]);
	set_print(x, y+6, "Title \t :- ______________________", chc[0]);
	set_print(x, y+8, "Author \t :- ______________________", chc[0]);
	set_print(x, y+10, "Cost \t :- ______________________", chc[0]);
	set_print(x, y+12, "Quantity \t :- ______________________", chc[0]);
	set_print(x, y+14, "Condition \t :- ______________________", chc[0]);
	set_print(x, y+16, "Status \t :- ______________________", chc[0]);

	setxy(x+17,y+4);
	scanf("%d", &b.id);
	fseek(stdin, 0, SEEK_END);
	
	setxy(x+17,y+6);
	scanf("%[^\n]s", b.title);
	fseek(stdin, 0, SEEK_END);
	
	setxy(x+17,y+8);
	scanf("%[^\n]s", b.author);
	fseek(stdin, 0, SEEK_END);
	
	setxy(x+17,y+10);
	scanf("%f",&b.cost);
	fseek(stdin, 0, SEEK_END);
	
	setxy(x+17,y+12);
	scanf("%d", &b.qty);
	fseek(stdin, 0, SEEK_END);
	
	setxy(x+17,y+14);
	scanf("%d", &b.cdn);
	fseek(stdin, 0, SEEK_END);
	
	setxy(x+17,y+16);
	scanf("%[^\n]s", b.status);
	fseek(stdin, 0, SEEK_END);

    return b;
}

Issue inputIssueDetails()
{
    Issue i;
    /* read details of the issue and do validation*/
    printf("\nWe will input the details for issue and validate here.");

	int x, y;
    char chc[1] = {' '}, choice;
    headMessage("Issuing a book");
    design(29);
	x=19;			y=15;
	setxy(0,y);
	
	printMessageCenter("Enter Issue's information");
	
	set_print(x, y+4, "ID \t :- ______________________", chc[0]);
	set_print(x, y+6, "UserID \t :- ______________________", chc[0]);
	set_print(x, y+8, "BookID \t :- ______________________", chc[0]);
	set_print(x, y+10, "IssueDate \t :- ______________________", chc[0]);
	set_print(x, y+12, "ReturnDate  :- ______________________", chc[0]);
	set_print(x, y+14, "ReturnedDate:- ______________________", chc[0]);


	setxy(x+17,y+4);
	scanf("%d", &i.iId);
	fseek(stdin, 0, SEEK_END);

	setxy(x+17,y+6);
	scanf("%d", &i.uId);
	fseek(stdin, 0, SEEK_END);

	setxy(x+17,y+8);
	scanf("%d", &i.bId);
	fseek(stdin, 0, SEEK_END);
	
	setxy(x+17,y+10);
	scanf("%[^\n]s", i.issueDate);
	fseek(stdin, 0, SEEK_END);
	
	setxy(x+17,y+12);
	scanf("%[^\n]s", i.returnDate);
	fseek(stdin, 0, SEEK_END);
	
	setxy(x+17,y+14);
	scanf("%[^\n]s", i.returnedDate);
	fseek(stdin, 0, SEEK_END);
    return i;
}

Issue checkReturnConditions()
{
    Issue i;
    /*do all the return condition validation*/
    printf("\nHere is the validations while returning the book.");
    return i;
}

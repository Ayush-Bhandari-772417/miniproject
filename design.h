COORD c = {0, 0};
char user[20];

void setxy (int x, int y)		// set curosor in output console
{
	c.X = x; c.Y = y; // Set X and Y coordinates
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void printMessageCenter(const char* message)				// Display any massagae at the centre
{
	int len, pos;
	len = (80 - strlen(message))/2;			//calculate how many space need to print
	for(pos =0 ; pos < len ; pos++)
		printf(" ");        		//print space
	printf("%s",message);	    		//print message
}

void heading(int a, int b)				// Design of heading
{
	int i;
	printf("\t");
	for(i=1; i<a; i++)
	printf("\xB2\xDB");
	if(b)
	printf("\n");
}

void headMessage(const char *message)			// printing head of the program
{
	system("cls");
	heading(33, 1);
	heading(5, 0);
	printf("\t\t\t\t\t");
	heading(5, 1);
	heading(5, 0);
	printf("\tLibrary management System LIBMAX");
	heading(5, 1);
	heading(5, 0);
	printf("\t\t\t\t\t");
	heading(5, 1);
	heading(33, 1);
	printf("\n\t----------------------------------------------------------------\n");
	printMessageCenter(message);
	printf("\n\t----------------------------------------------------------------");
}

void design(int n)				// design of all selection menu
{
	int i;
	printf("\n\n\n\n\n\t\t");			// Design
	for(i=1; i<50; i++)
	printf("*");
	for(i=1; i<n; i++)
	printf("\n\t\t* \t\t\t\t\t\t*");
	printf("\n\t\t");
	for(i=1; i<50; i++)
	printf("*");
}

void set_print(int x, int y, const char *m, char c)			// function to set cursor & display
{
	setxy(x, y);					// function call to locate cursor
	printf("%c %s", c, m);			// print sent message in that location
}

int cursor(char chc[], int x, int y, int n)			// move the selection
{
	int i, decide=1;
	char c;
	while(c != 13)
	{
		for(i=0; i<n; i++)
		{
			setxy(x,y+i);
			printf("%c",chc[i]);
		}
		for(i=0; i<2; i++)
		{
			c = getch();
			if(c==13)				// check enter key 
				break;
		}
		if ((c==72) || (c==75))		// check up and left arrow
		{
			if ( (decide-1)>=1)
				decide-=1;
		}
		else if ((c==77) || (c==80))		// check down and right arrow
		{
			if ( (decide+1)<=n)
				decide+=1;
		}
		for (i=0; i<n; i++)
			chc[i]=' ';
		chc[decide-1]=16;
	}
	return decide;
}

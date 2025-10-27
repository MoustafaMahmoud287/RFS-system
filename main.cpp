#include <conio.h>
#include <sstream>
#include "RFS.h"
#include "Book.h"
#include "Library.h"
const int EM = 25; // End of Medium



void CleanScreen(void);
int ShowMenu(void);
char againYON();

int  main ()
{
    // RFS code
    CLibrary Library("Library.db");
	char again; //a flag to indicate do selected option again
	int choice; //user selected option
	bool exit=false; // flag to terminate execution
	while(true) //loop forever
	{
		CleanScreen();
		choice=ShowMenu();
//		if(choice == EM) return EM;
			//show menu and get user option
		switch(choice) //handling user input
		{
		case 1:
			again='Y';
			while(again=='Y')
           {
               //loop as user wants to continue
			     if(Library.AddNewBook())
			     {
			       	cout <<"a New Book has been"
                         <<" successfully added\n";
                    cout <<"Do you want to add another"
                         <<" (y/n)?";
					again=againYON();
				}
				else
				{
					again='N';
					cout<<"couldn't add a New Student\n";
					cin.get();
				}
			}
			break;
		case 2:
			again='Y';
			while(again=='Y')
			{
				if(Library.SearchByTitle())
				{
					cout<<"a Search has been"
						<<" successfully Done\n";
					cout<<"Do you want to Search again"
						<< "(y/n)?";
					again=againYON();
					cin.ignore() ;
				}
				else
				{
					again='N';
					cout<<"There is no Matching results\n";
					cout<<"Press any key to continue";
					cin.get();
				}
			}
			break;
		case 3:
			again='Y';
			while(again=='Y')
			{
				if(Library.SearchByNumber())
				{
					cout<<"a Search has been"
						<<" successfully Done\n";
					cout<<"Do you want to Search again"
						<< "(y/n)?";
					again=againYON();
					cin.ignore() ;
				}
				else
				{
					again='N';
					cout<<"There is no Matching results\n";
					cout<<"Press any key to continue";
					cin.get();
				}
			}
			break;
		case 4:
			again='Y';
			while(again=='Y')
			{
				if(Library.FindByAuthor())
				{
					cout<<"a Search has been"
						<<" successfully Done\n";
					cout<<"Do you want to Search again"
						<< "(y/n)?";
					again=againYON();
					cin.ignore() ;
				}
				else
				{
					again='N';
					cout<<"There is no Matching results\n";
					cout<<"Press any key to continue";
					cin.get();
				}
			}
			break;
		case 5:
			again='Y';
			while(again=='Y')
			{
				if(Library.FindByPublisher())
				{
					cout<<"a Search has been"
						<<" successfully Done\n";
					cout<<"Do you want to Search again"
						<< "(y/n)?";
					again=againYON();
					cin.ignore() ;
				}
				else
				{
					again='N';
					cout<<"There is no Matching results\n";
					cout<<"Press any key to continue";
					cin.get();
				}
			}
			break;
		case 6:
            again='Y';
			while(again=='Y')
			{
				if(Library.ModifyCost())
				{
					cout<<"Book has been"
						<<" successfully modified\n";
					cout<<"Do you want to modify another book"
						<< "(y/n)?";
					again=againYON();
				}
				else
				{
					again='N';
					cout<<"There is no Matching results\n";
					cout<<"Press any key to continue";
					cin.get();
				}
			}
			break;
		case 7:
            again='Y';
			while(again=='Y')
			{
				if(Library.ModifyQuantity())
				{
					cout<<"Book has been"
						<<" successfully modified\n";
					cout<<"Do you want to modify another book"
						<< "(y/n)?";
					again=againYON();
				}
				else
				{
					again='N';
					cout<<"There is no Matching results\n";
					cout<<"Press any key to continue";
					cin.get();
				}
			}
			break;
		case 8:
            again='Y';
			while(again=='Y')
			{
				if(Library.RemoveBook())
				{
					cout<<"Book has been"
						<<" successfully removed\n";
					cout<<"Do you want to modify another book"
						<< "(y/n)?";
					again=againYON();
				}
				else
				{
					again='N';
					cout<<"There is no Matching results\n";
					cout<<"Press any key to continue";
					cin.get();
				}
			}
			break;
		case 9:
		    {
				    Library.Sort() ;
				    cout<<"The Books have been sorted successfully\n";
					cout<<"Press any key to continue";
					again = 'N' ;
					cin.get();
			}
			break;
        case 10:
			again='Y';
			while(again=='Y')
			{
				if(Library.ZeroQuantity())
				{
					cout<<"a Search has been"
						<<" successfully Done\n";
					cout<<"Do you want to Search again"
						<< "(y/n)?";
					again=againYON();
				}
				else
				{
					again='N';
					cout<<"There is no Matching results\n";
					cout<<"Press any key to continue";
					cin.get();
				}
			}
			break;
        case 11:
			again='Y';
			while(again=='Y')
			{
				if(Library.AboveCost())
				{
					cout<<"a Search has been"
						<<" successfully Done\n";
					cout<<"Do you want to Search again"
						<< "(y/n)?";
					again=againYON();
				}
				else
				{
					again='N';
					cout<<"There is no Matching results\n";
					cout<<"Press any key to continue";
					cin.get();
				}
			}
			break;
		case 12: // terminate execution
			exit=true; //set exit flag
			break;
		}
		// break infinite loop to terminate execution
		if(exit)
			break;
	}
}
/*/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\*/
char againYON()
{
	char again=0;
	while((again!='Y')&&(again!='N'))
	{
		again=cin.get();
		again=toupper(again);
	}
	return again;
}




/*/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\*/
// Clean Screen Function
// print an empty 25 lines
/*/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\*/
void CleanScreen()
{
	cin.ignore();
	cout.flush();
	for(int i=0;i<25;i++)
		cout<<endl;
}
/*/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\*/
// Show Menu Function
// print the menu options and get user input
// return user input to calling function for processing
/*/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\*/
int ShowMenu(void)
{
	int choice;
	cout<<"\t\t\t\t MainMenu\n\n";
	cout<<"\t\t\t (1) Add New Book.\n";
	cout<<"\t\t\t (2) Search for a book (by book title).\n";
	cout<<"\t\t\t (3) Search for a book (by book number).\n";
	cout<<"\t\t\t (4) Find all books by author.\n";
	cout<<"\t\t\t (5) Find all books by publisher.\n";
	cout<<"\t\t\t (6) Modify book cost (provide book number).\n";
    cout<<"\t\t\t (7) Modify book quantity (provide book number).\n";
	cout<<"\t\t\t (8) Remove book (provide book number).\n";
	cout<<"\t\t\t (9) Sort books by title.\n";
	cout<<"\t\t\t (10) Find all books with zero quantity.\n";
	cout<<"\t\t\t (11) Find all books with cost above a given value .\n";
	cout<<"\t\t\t (12) Exit.\n\n";
	cout<<"\t\t Enter your choice (1...12) : ";
	cin>>choice;
	cin.ignore();
	return choice;
}

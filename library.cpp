//////////////////////////////////////////////////////////////////////
#include "library.h"
#include "book.h"
#include "RFS.h"
#include "string.h"
//////////////////////////////////////////////////////////////////////
CLibrary::CLibrary(char filename[]): rfs(sizeof(CBook),filename)
{   }
bool CLibrary::AddNewBook()
{
	CBook NewBook;
	cout<<"\t\t\tAdding New Book\n\n";
	cout<<"Book Number : ";
	cin>>NewBook.Book_Number;
	cin.ignore(); // to avoid bug in getline
	cout<<"Book Name : ";
	cin.getline( NewBook.Book_Title , 100 );
	cin.ignore(); // to avoid bug in getline
	cout<<"Author : ";
	cin.getline( NewBook.Book_Author , 100 );
	cin.ignore(); // to avoid bug in getline
	cout<<"Publisher : ";
	cin.getline( NewBook.Book_Publisher , 100 );
	cin.ignore(); // to avoid bug in getline
	cout<<"Quantity : ";
	cin>>NewBook.Book_Quantity;
	cin.ignore(); // to avoid bug in getline
	cout<<"Number of Pages : ";
	cin>>NewBook.Book_Pages;
	cin.ignore();
	cout<<"Cost : ";
	cin>>NewBook.Book_Cost;
	return(rfs.put(&NewBook));
}
bool CLibrary::SearchByTitle()
{
	CBook Book;
	unsigned int Location = 0 ;
	char Title[100];
	cout<<"\t\t\tSearch for Book By Title\n\n";
	cout<<"Enter The Title to Search for : ";
	cin.getline(Title,100);
	 // for getline bug
	while( rfs.get( &Book , Location++ ) )
        if( strcmp( Book.Book_Title , Title ) == 0 && Book.isActive() ){
            cout<<"Book Number : "<<Book.Book_Number<<endl;
            cout<<"Book Title : "<<Book.Book_Title<<endl;
            cout<<"Book Author : "<<Book.Book_Author<<endl;
            cout<<"Book Publisher : "<<Book.Book_Publisher<<endl;
            cout<<"Book Quantity : "<<Book.Book_Quantity<<endl;
            cout<<"Number Of Pages : "<<Book.Book_Pages<<endl;
            cout<<"Book Cost : "<<Book.Book_Cost<<endl<<endl;
            return true ;
        }
	return false;
}
bool CLibrary::SearchByNumber()
{
	CBook Book;
	unsigned int Location = 0;
	unsigned int num;
	cout<<"\t\t\tSearch for Book By Number\n\n";
	cout<<"Enter The Number to Search for : ";
	cin>>num;
	while( rfs.get( &Book , Location++ ) )
        if( Book.Book_Number == num && Book.isActive() ){
            cout<<"Book Number : "<<Book.Book_Number<<endl;
            cout<<"Book Title : "<<Book.Book_Title<<endl;
            cout<<"Book Author : "<<Book.Book_Author<<endl;
            cout<<"Book Publisher : "<<Book.Book_Publisher<<endl;
            cout<<"Book Quantity : "<<Book.Book_Quantity<<endl;
            cout<<"Number Of Pages : "<<Book.Book_Pages<<endl;
            cout<<"Book Cost : "<<Book.Book_Cost<<endl<<endl;
            return true  ;
        }
	return false;
}
bool CLibrary::FindByAuthor()
{
    bool found = false ;
    CBook Book ;
    char Author[ 100 ] ;
    unsigned int Location = 0 ;
   	cout<<"\t\t\tFind Books By Author\n\n";// for getline bug
	cout<<"Enter The Author to Search for : ";
	cin.getline( Author , 100 ) ;
	while( rfs.get( &Book , Location++ ) )
        if( strcmp( Book.Book_Author , Author ) == 0 && Book.isActive() ){
            found = true ;
            cout<<"Book Number : "<<Book.Book_Number<<endl;
            cout<<"Book Title : "<<Book.Book_Title<<endl;
            cout<<"Book Author : "<<Book.Book_Author<<endl;
            cout<<"Book Publisher : "<<Book.Book_Publisher<<endl;
            cout<<"Book Quantity : "<<Book.Book_Quantity<<endl;
            cout<<"Number Of Pages : "<<Book.Book_Pages<<endl;
            cout<<"Book Cost : "<<Book.Book_Cost<<endl<<endl;
        }
        return found ;
}
bool CLibrary::FindByPublisher()
{
    bool found = false ;
    CBook Book ;
    char Publisher[ 100 ] ;
    unsigned int Location = 0 ;
   	cout<<"\t\t\tFind Books By Publisher\n\n";
	cout<<"Enter The Publisher to Search for : ";
	cin.getline( Publisher , 100 ) ;
	while( rfs.get( &Book , Location++ ) )
        if( strcmp( Book.Book_Publisher , Publisher ) == 0 && Book.isActive() ){
            found = true ;
            cout<<"Book Number : "<<Book.Book_Number<<endl;
            cout<<"Book Title : "<<Book.Book_Title<<endl;
            cout<<"Book Author : "<<Book.Book_Author<<endl;
            cout<<"Book Publisher : "<<Book.Book_Publisher<<endl;
            cout<<"Book Quantity : "<<Book.Book_Quantity<<endl;
            cout<<"Number Of Pages : "<<Book.Book_Pages<<endl;
            cout<<"Book Cost : "<<Book.Book_Cost<<endl<<endl;
        }
        return found ;
}
bool CLibrary::ZeroQuantity()
{
    bool found = false ;
    CBook Book ;
    unsigned int Location = 0 ;
   	cout<<"\t\t\tFind Books with zero Quantity\n\n";
	while( rfs.get( &Book , Location++ ) )
        if( Book.Book_Quantity == 0 && Book.isActive() ){
            found = true ;
            cout<<"Book Number : "<<Book.Book_Number<<endl;
            cout<<"Book Title : "<<Book.Book_Title<<endl;
            cout<<"Book Author : "<<Book.Book_Author<<endl;
            cout<<"Book Publisher : "<<Book.Book_Publisher<<endl;
            cout<<"Book Quantity : "<<Book.Book_Quantity<<endl;
            cout<<"Number Of Pages : "<<Book.Book_Pages<<endl;
            cout<<"Book Cost : "<<Book.Book_Cost<<endl<<endl;
        }
        return found ;
}
bool CLibrary::AboveCost()
{
    bool found = false ;
    CBook Book ;
    unsigned int Cost ;
    unsigned int Location = 0 ;
   	cout<<"\t\t\tFind Books with cost above a given value \n\n";
	cout<<"Enter The Cost : ";
	cin>>Cost ;
	while( rfs.get( &Book , Location++ ) )
        if( Book.Book_Cost >= Cost && Book.isActive() ){
            found = true ;
            cout<<"Book Number : "<<Book.Book_Number<<endl;
            cout<<"Book Title : "<<Book.Book_Title<<endl;
            cout<<"Book Author : "<<Book.Book_Author<<endl;
            cout<<"Book Publisher : "<<Book.Book_Publisher<<endl;
            cout<<"Book Quantity : "<<Book.Book_Quantity<<endl;
            cout<<"Number Of Pages : "<<Book.Book_Pages<<endl;
            cout<<"Book Cost : "<<Book.Book_Cost<<endl<<endl;
        }
        return found ;
}
bool CLibrary::RemoveBook()
{
	CBook Book;
    unsigned int number,i;
	cout<<"\t\t\tRemove Book\n\n";
	cout<<"Enter Book Nnumber to be removed : ";
	cin>>number;
	i=0;
	if( ! rfs.get(&Book,i++) )
		return false;
	while((number!=Book.Book_Number)|| (!Book.isActive()))
	{
		if( ! rfs.get(&Book,i++) )
			return false;
	}
	return( rfs.del(&Book) );
}
bool CLibrary::ModifyCost()
{
	CBook Book;
	unsigned int number,location;
	cout<<"\t\t\tModifying Book Cost\n\n";
	cout<<"Enter Book Number to be modified : ";
	cin>>number;
	location=0;
	if( ! rfs.get(&Book,location++) )
		return false;
	while((number!=Book.Book_Number)||(!Book.isActive()))
	{
		if( ! rfs.get(&Book,location++) )
			return false;
	}
	location--;
	cout<<"current Cost : "<<Book.Book_Cost<<endl;
	cout<<"New Cost : ";
	cin>>Book.Book_Cost;
	cin.ignore(); // cin-issue
	return( rfs.put(&Book,location) );
}
bool CLibrary::ModifyQuantity()
{
	CBook Book;
	unsigned int number,location;
	cout<<"\t\t\tModifying Book Quantity\n\n";
	cout<<"Enter Book Number to be modified : ";
	cin>>number;
	location=0;
	if( ! rfs.get(&Book,location++) )
		return false;
	while((number!=Book.Book_Number)||(!Book.isActive()))
	{
		if( ! rfs.get(&Book,location++) )
			return false;
	}
	location--;
	cout<<"Current Quantity : "<<Book.Book_Quantity<<endl;
	cout<<"New Quantity : ";
	cin>>Book.Book_Quantity;
	cin.ignore(); // cin-issue
	return( rfs.put(&Book,location) );
}

bool CLibrary::Sort()
{
    if( rfs.GetNumberOfRecords() == 0  ){
        cout<<"The Data Base is Empty\n";
        return false ;
    }
	CBook Book1,Book2;
	char Title[ 100 ] ;
	unsigned int Loc1,Loc2;
	unsigned int NRecords;
	cout<<"\t\t\t\tSort\n\n";
	NRecords= rfs.GetNumberOfRecords();
	cout<<"Sorting ...\n";
	for(Loc1=0;Loc1<NRecords-1;Loc1++)
	{
        for(Loc2=Loc1+1;Loc2<NRecords;Loc2++)
		{
            if(! rfs.get(&Book1,Loc1) )
                return false;
			if(! rfs.get(&Book2,Loc2) )
                return false;
			if(!Book2.isActive())
                continue;
            string s1 = Book1.Book_Title , s2 = Book2.Book_Title ;
            if((!Book1.isActive())||( s1 > s2 ))
			{
			    rfs.put(&Book2,Loc1);
                rfs.put(&Book1,Loc2);
			}
		}
	}
	cout<<"Sorting completed.\n";
	Loc1=0;
	while((rfs.get(&Book1,Loc1++))&&(Book1.isActive()))
	{
            cout<<"Book Number : "<<Book1.Book_Number<<endl;
            cout<<"Book Title : "<<Book1.Book_Title<<endl;
            cout<<"Book Author : "<<Book1.Book_Author<<endl;
            cout<<"Book Publisher : "<<Book1.Book_Publisher<<endl;
            cout<<"Book Quantity : "<<Book1.Book_Quantity<<endl;
            cout<<"Number Of Pages : "<<Book1.Book_Pages<<endl;
            cout<<"Book Cost : "<<Book1.Book_Cost<<endl<<endl;
	}
	return true;
}

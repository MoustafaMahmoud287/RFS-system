//////////////////////////////////////////////////////////////////////
#if !defined LibraryInclude
#define LibraryInclude
#include "RFS.h"
class CLibrary
{
    private:
        RFS rfs;
	public:
		CLibrary(char filename[]);
		bool AddNewBook();
		bool SearchByTitle();
		bool SearchByNumber();
		bool FindByAuthor();
		bool FindByPublisher();
		bool ModifyCost();
		bool ModifyQuantity();
		bool RemoveBook();
		bool Sort();
		bool ZeroQuantity();
		bool AboveCost();
};
#endif

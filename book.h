#if !defined BookInclude
#define BookInclude
#include "RFS.h"
class CBook : public Record
{
public:
	unsigned int Book_Number;
	unsigned int Book_Cost;
	unsigned int Book_Pages;
	unsigned int Book_Quantity;
	char Book_Title [100];
	char Book_Author [100];
	char Book_Publisher [100];
public:
	CBook();
	virtual ~CBook();
};
#endif

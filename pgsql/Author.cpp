#include "Author.h"

Author::Author(void)
{
	firstName = "f";
	lastName = "t";
	fatherName = "v";
}

Author::~Author(void)
{
}
void Author::print()
{
	cout<<firstName<<" "<<lastName<<" "<<fatherName<<endl;
}


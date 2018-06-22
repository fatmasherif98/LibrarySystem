#ifndef MEMBERS_H_INCLUDED
#define MEMBERS_H_INCLUDED
#include "Structs.h"
#include "Search.h"
extern int n,m,l;

void Registration();
void Borrowing_Book(int ID, int index);
void Returning_Book(int ID);
void Remove_Member();

#endif // MEMBERS_H_INCLUDED

#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED
extern int n,m,l;

typedef struct
{
    int Day;
    int Month;
    int Year;
} Date;


struct Book
{
    char Title[52];
    char Author[52];
    char Publisher[52];
    char ISBN[20];
    Date DateOfPublication; // adding slash in the scan
    int Copies;
    int CopiesAvailable; //make sure that every file has its null condition
    char Category[24];
    int rank;
} Books[100];

struct Address
{
    char Building[24];
    char Street[24];
    char City[16];
};

struct Member
{
    char Last_Name[24];
    char First_Name[24];
    int ID;
    struct Address Adr;
    char PhoneNum[12];
    int Age;
    char Mail[40];
} Members[100];

struct Borrow
{
    char ISBNB[20];
    int IDB;
    Date DateB;
    Date DateD;
    Date DateR;
} Borrows[100];



#endif // STRUCTS_H_INCLUDED

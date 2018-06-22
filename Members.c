#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <ctype.h>
#include "Members.h"
void Registration()
{
    int i,flag=0;
    printf("\nEnter the last name\n");
    fgets(Members[m].Last_Name,24,stdin);
    printf("\nEnter the first name\n");
    fgets(Members[m].First_Name,24,stdin);
    printf("\nEnter the ID\n");
    do{
    Members[m].ID = scan_check();
    }
    while( Members[m].ID== -2);
    do{
            flag=0;
    for (i=0; i<m; i++)
    {
        if(Members[i].ID==Members[m].ID)
        {
          printf("ID already exists, enter another one:\n");
          do{
            Members[m].ID = scan_check();
            }
            while( Members[m].ID== -2);
        flag=1;

        }
    }
    } while( flag == 1);
    printf("\nEnter the building address\n");
    fgets(Members[m].Adr.Building,24,stdin);
    printf("\nEnter the street address\n");
    fgets(Members[m].Adr.Street,24,stdin);
    printf("\nEnter the city-address\n");
    fgets(Members[m].Adr.City,16,stdin);
    printf("\nEnter the Phone number\n");
    fgets(Members[m].PhoneNum,12,stdin);
    printf("\nEnter the age\n");
    do{
    Members[m].Age=scan_check();
    }
    while( Members[m].Age == -2);
    printf("\nEnter the e-mail address\n");
    fgets(Members[m].Mail,40,stdin);
    m++;
    printf("\nMember is added successfully\n enter any number to go back to main menu");
    getch();
    system("cls");
}

void Borrowing_Book(int ID, int index) //user enters the title not only search by ISBN
{
    int flagD=0;
time_t t = time(NULL);
struct tm tm;
tm = *localtime(&t);
tm.tm_year +=1900;
tm.tm_mon +=1;
Date dnow;
dnow.Day = tm.tm_mday;
dnow.Month = tm.tm_mon;
dnow.Year = tm.tm_year;
    int i,count=0,member_index=0;
    do{
    //checking if this id exists
    member_index= Search_Member_ID(ID);
    if (member_index == -1){
        printf("This ID does not exist, enter another ID:\n");
        do{
            ID=scan_check();
        }
        while( ID == -2);
    }
    } while( member_index == -1);

    for(i=0; i<l; i++)
    {
        if(Borrows[i].IDB==ID)
        {
            if( Borrows[i].DateR.Day == 0)
            {
                count++;
            }
        }
        if(count==3)
        {
            printf("\nYou can't borrow more than 3 books\n");
            return;

            //can't borrow
        }
    }

    if(Books[index].CopiesAvailable != 0){
    Borrows[l].DateR.Day=0;
    Borrows[l].DateR.Month=0;
    Borrows[l].DateR.Year=0; //better zero than null -warning
    Books[index].CopiesAvailable--; //we didn't print in seperate files
    strcpy(Borrows[l].ISBNB, Books[index].ISBN);
    Borrows[l].DateB.Day = dnow.Day;
    Borrows[l].DateB.Month = dnow.Month;
    Borrows[l].DateB.Year = dnow.Year;
    Borrows[l].IDB =ID;
    do{
    printf("Enter Date due to return\n");
    scanf("%d/%d/%d",&Borrows[l].DateD.Day,&Borrows[l].DateD.Month,&Borrows[l].DateD.Year);
    getchar();
    flagD= Check_Date(Borrows[l].DateD);
    }
    while(flagD != 0);
    l++;
    printf("\nBorrowing is done successfully\n");
    } else{
    printf("Sorry this book is not available now!");
    }
}

void Returning_Book(int ID)
{time_t t = time(NULL);
struct tm tm;
tm = *localtime(&t);
tm.tm_year +=1900;
tm.tm_mon +=1;
Date dnow;
dnow.Day = tm.tm_mday;
dnow.Month = tm.tm_mon;
dnow.Year = tm.tm_year;
    int index=-1,i,w=0;
    char temp[20];
    printf("\nEnter ISBN of Book\n");
    scanf("%s",temp);
    getchar();
    w=Search_Book_ISBN(temp);
    if( w == -1){
        printf("ISBN is not found\n");
        return;
    }

    for(i=0; i<l ; i++ )
    {
        if( Borrows[i].IDB == ID && ( strcmp(temp,Borrows[i].ISBNB) == 0) && Borrows[i].DateR.Day == 0)
        {
            index=i;
            break;
        }
    }
    if( index == -1){
        printf("\nThis member did not borrow this book\n");
        return;
    }

     //IF ISBN Exists
    Borrows[index].DateR.Day = dnow.Day;
    Borrows[index].DateR.Month = dnow.Month;
    Borrows[index].DateR.Year = dnow.Year;

       if (CompareDates(Borrows[index].DateD,Borrows[index].DateR) == 0){
        printf("\nMember returned book before Due date\n");
       } else{
       printf("\nMember returned book after Due Date!!\n");
       }
        Books[w].CopiesAvailable++;
        printf("\nReturning is done successfully\n"); //Increasing no of copies available


}

void Remove_Member()
{
    int i,h,ID;
    printf("\nEnter the ID you want to remove\n");
    do{
    ID=scan_check();
    }
    while( ID == -2);
    for(i=0; i<l; i++)
    {
        if(Borrows[i].IDB==ID) //checking borrowing list
        {
            if(Borrows[i].DateR.Day==0 && Borrows[i].DateR.Month==0 && Borrows[i].DateR.Year==0)
            {
                printf("\nMember has to return the borrowed books first\n"); //if member can't be removed now
                return;
            }
        }
    }
    h=Search_Member_ID(ID); //search if ID exists
    if(h!=-1)
    {
        for(i=h; i<=m-2; i++)
        {
            Members[i]=Members[i+1];
        }
        m--;
        printf("\nMember is removed successfully\n");
    }
    else
        printf("\nMember is not added in the library\n");
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <ctype.h>
#include "Books.h"
#include "Dates.h"

void Add_New_Book()
{

int i,flag=0,flagD=0;
    struct Book b;
    printf("Enter the Title\n");
    fgets(b.Title,52,stdin);
    printf("\nEnter the Author Name\n");
    fgets(b.Author,52,stdin);
    printf("\nEnter the Publisher Name\n");
    fgets(b.Publisher,52,stdin);
    printf("\nEnter the ISBN\n");
      fgets(b.ISBN,20,stdin);
    do{
     flag=0;
    for(i=0; i<n ; i++){
        if(strcmp(Books[i].ISBN, b.ISBN) == 0){
            printf("This ISBN already exists, please enter another one:\n");
                fgets(b.ISBN,20,stdin);
                flag=1;
                break;
        }


    }} while(flag==1);
    printf("\nEnter the number of copies\n");
    do{
     b.Copies=scan_check();
    }
    while( b.Copies == -2);
    do{
    printf("\nEnter the date of Publication\n");
    scanf("%d/%d/%d",&b.DateOfPublication.Day,&b.DateOfPublication.Month,&b.DateOfPublication.Year);
    flagD=Check_Date(b.DateOfPublication);
    } while( flagD != 0);

    printf("\nEnter the category\n");
    getchar();
    fgets(b.Category,24,stdin);
    b.rank=0;
    b.CopiesAvailable = b.Copies;
    Books[n]=b;
    n++;
    printf("\nAdding the Book is done successfully\n");
}
void Add_New_Copy()
{

    char temp[20];
    int numbers,v,x;
    do
    {   printf("\nEnter the book ISBN\n");
        scanf("%s",temp);
        getchar();
        printf("\nEnter the number of copies to be added\n");
        do{
            numbers=scan_check();
            }
            while( numbers == -2);
    }
    while(numbers<0);
    v=Search_Book_ISBN(temp);
    if(v!=-1)
        {Books[v].Copies=Books[v].Copies+numbers;
        Books[v].CopiesAvailable=Books[v].CopiesAvailable+numbers;
        printf("Copies have been added successfully!\n enter any number to go to main menu\n");
        getch();
         }//adding no. of new copies to old ones
    else
    {
        printf("\nBook is not found\n");
        printf("Enter 1 if you want to add the new book, if not enter any other number\n");
        do{
         x=scan_check();
        }
        while( x == -2);
        if(x==1){

            Add_New_Book();
        }
    }
}

void Delete_Book()
{
    char temp[20];
    int v,i;
    printf("\nEnter the book ISBN\n");
    scanf("%s",temp);
    getchar();
    v=Search_Book_ISBN(temp); //returns -1 if book not found
    if(v!=-1)
    {
        for(i=v; i<=n-2; i++)
        {
            Books[i]=Books[i+1];
        }
        n--; //decreasing number of books by 1
        printf("\nDeleting is done successfully\n");
            }
    else
        printf("\nBook is not found\n");
}


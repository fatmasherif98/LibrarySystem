#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <ctype.h>
#include "Admin.h"
#include "Structs.h"
#include "Books.h"
#include "Members.h"
#include "Count.h"
#include "Dates.h"
#include "Search.h"
#include "Save.h"


int n=0,m=0,l=0;

int main()
{
    Count_Member();
    Count_Book();
    Count_Borrow();
    int x,y,z,i,flag=0;
    int ID;
    int menu=0;
    do
    {
        printf("\n-----------------------------");
        printf("\nMenu\n-------\n"); //MENUBAR
        printf("For Book Management enter(1)\nFor Member Management and Borrowing enter(2)\n");
        printf("For Administrative actions enter(3)\n");
        printf("To print all books, members or borrows, enter(4)");
        printf("\nTo save Changes enter(5)\nExit(6)\n");
        printf("Choose from menu your access\n");
        do{
        x=scan_check();
        }
        while( x == -2);
        system("cls");
        if(x==1)  //Book Management
        {
            printf("Insert a Book(1)\nSearch for a book(2)\n");
            printf("Add new copies(3)\nDelete a book(4)\nTo go back to main menu(5)\n");
            printf("\nChoose your access\n");
            do{
            y=scan_check();
            }
            while( y == -2);
            system("cls");
            switch (y)
            {
            case 1:
                Add_New_Book();
                printf("\nEnter any number to go back to main menu:");
                getch();
                system("cls");
                break;
            case 2:
                printf("To search by book ISBN, enter 1\nTo search by book title or part of it enter 2\n");
                printf("To search by Author's name enter 3\nTo search by category enter 4\n");
                do{
                y=scan_check();
                }
                while( y == -2);
                system("cls");
                z=SEARCH(y);
                if( z >= 0)
                {
                    printf("Title:%s\nAuthor:%s\nPublisher:%s\nISBN:%s\n",Books[z].Title,Books[z].Author,Books[z].Publisher,Books[z].ISBN);
                    printf("Date of publication: %d/%d/%d\n",Books[z].DateOfPublication.Day,Books[z].DateOfPublication.Month,Books[z].DateOfPublication.Year);
                    printf("Number of copies available:%d\nTotal Number of copies:%d\nCategory:%s",Books[z].CopiesAvailable,Books[z].Copies,Books[z].Category);
                }
                printf("\nEnter any number to go back to main menu:");
                getch();
                system("cls");
                break;
            case 3:
                Add_New_Copy();
                system("cls");
                break;
            case 4:
                Delete_Book();
                break;
            case 5:
                continue;
                break;
            }
        }
        else if( x==2)
        {
            printf("For registration enter (1)\nFor Borrowing enter (2)\nTo return a book enter (3)\nTo remove a member enter (4)\nTo go back to main menu enter(5)\n");
            do{
            y=scan_check();
            }
            while( y == -2);
            system("cls");
            switch(y)
            {
            case 1:
                Registration();
                break;
            case 2:
                printf("To search by book ISBN, enter (1)\nTo search by book title or part of it enter (2)\n");
                printf("To search by Author's name enter (3)\nTo search by category enter (4)\n");
                do{
                y=scan_check();
                }
                while( y == -2);
                system("cls");
                z=SEARCH(y);
                if( z >= 0){
                printf("Enter the user's ID:\n");
                do{
                ID=scan_check();
                }
                while( ID == -2);
                //getchar();
                }
                if( z >=0 )
                Borrowing_Book(ID , z);
                printf("For main menu enter any number:\n");
                getch();
                system("cls");
                break;
            case 3:
                printf("\nEnter member ID\n");
                do{
                ID=scan_check();
                }
                while( ID == -2);
                for(i=0; i<m ; i++){
                    if( Members[i].ID == ID)
                        flag=1;
                }
                if (flag == 1){
                Returning_Book(ID);
                } else
                printf("ID does not exist\n");
                printf("For main menu enter any number:\n");
                getch();
                system("cls");
                break;
            case 4:
                Remove_Member();
                printf("For main menu enter any number:\n");
                getch();
                system("cls");
                break;
            case 5:
                continue;
                break;
            }
        }
        else if(x==3)
        {
            printf("For over due books enter (1)\nFor most popular books enter(2)");
            do{
            y=scan_check();
            }
            while( y == -2);
            system("cls");
            switch(y){
                case 1:
                    Overdue_Books();
                    printf("For main menu enter any number:\n");
                    getch();
                    system("cls");
                    break;
                case 2:
                    Most_popular();
                    printf("For main menu enter any number:\n");
                    getch();
                    system("cls");
                    break;
                    }
        }
        else if( x == 4){
                printf("To print all the books enter(1)\n");
                printf("To print all the members enter(2)\n");
                printf("To print all the borrows enter(3)\n");
                do{
                y=scan_check();
                }
                while( y == -2);
                Print_Info(y);
                printf("For main menu enter any number:\n");
                getch();
                system("cls");
        }
        else if( x == 5)
        {
            Save();
        }
        else if(x == 6)
        {
            printf("To exit without saving, enter -1, to save then exit enter 2:\n");
            do{
            menu=scan_check();
            }
            while( menu == -2);
            if(menu == 2)
            {
                Save();
                menu = -1;
            }
            return 0;
        }
    }
    while( menu != -1);
    return 0;
}


/*int check_string( char *buffer){
    int q,flag=0;
    for( q=0; q<strlen(buffer); q++){
        if(isalpha(buffer[q])){
           }else{
           flag=1; }
        if(flag == 1){
            printf("Enter only letters please try again:\n");
            return -2;
        }
    }

return 0;
}*/

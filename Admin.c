#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <ctype.h>
#include "Structs.h"
#include "Admin.h"
#include "Dates.h"
#include "Search.h"
void Overdue_Books()
{
    int i,flag=0;
    time_t t = time(NULL);
    struct tm tm;
    tm = *localtime(&t);
    tm.tm_year +=1900;
    tm.tm_mon +=1;
    Date dnow;
    dnow.Day = tm.tm_mday;
    dnow.Month = tm.tm_mon;
    dnow.Year = tm.tm_year;
    printf("\nThe list of overdue books :\n");
    for (i=0; i<l; i++)
    {
        if(Borrows[i].DateR.Year==0) //won't need to check month and day already 0 together
        {
            if( CompareDates(Borrows[i].DateD, dnow) == -1 ){
                printf("User with ID:%d didn't return book with ISBN %s\n", Borrows[i].IDB, Borrows[i].ISBNB);
                flag=1;
            }
        }

    }
    if( flag == 0){
        printf("There are no over due books..");
    }
}
void Most_popular(){
int index,i,j,flag=0,r;
struct Book temp;
//counting how many times each book was borrowed
for(i=0; i<l ; i++){
    index= Search_Book_ISBN(Borrows[i].ISBNB);
    if( index != -1){
        Books[index].rank++;
    }
}
//bubble sort in descending order for rank
for(i=0; i<n; i++){
    for(j=0; j<n-1-i ; j++){
        if( Books[j].rank < Books[j+1].rank){
            temp=Books[j];
            Books[j] = Books[j+1];
            Books[j+1] = temp;
            flag=1;
        }
    }
    if( flag == 0){
        break;
    }
    flag =0;
}
//to print the top 5 books
printf("The top five books:\n");
j=5;
for(i=0; i<j; i++){
    if( Books[i].rank == Books[i+1].rank){
        printf("\tThese books have been borrowed the same no. of times:\n");
        r=Books[i].rank;
    while( Books[i].rank == r){
        printf("%s\n",Books[i].Title);
        i++;
        j++;
        if( i >= n)
            break;

    }
    printf("\t***\t\n");
    if( i >= n)
            break;
    //printf("\t***\t\n");
    i--;
    j--;
    } else{
    printf("%s\n",Books[i].Title);
       }
}
}


void Print_Info(int y){
    int i;
if( y == 1){
    for(i=0; i<n ; i++){
        printf("%s\n",Books[i].Title);
    }
} else if(y == 2){
    for(i=0; i<m ; i++){
        printf("%s %s\n",Members[i].First_Name, Members[i].Last_Name);
    }
} else if(y == 3){
    for(i=0; i<l ; i++){
        printf("Member with id:%d borrowed book with ISBN: %s\n", Borrows[i].IDB, Borrows[i].ISBNB);
    }


}
}


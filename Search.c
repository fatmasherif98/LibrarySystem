#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <ctype.h>
#include "Search.h"

int scan_check(){
    char buffer[20];
    fgets(buffer,20,stdin);
    int i,k;
for( k=0; k<strlen(buffer); k++){
    if( isalpha(buffer[k])){
    printf("Please only enter numbers, try again:\n");
        return -2;
    }
}
i=atoi(buffer);
return i;
}

int Search_Book_ISBN(char* ISBN)
{
    int i;
    int k=-1;
    for(i=0; i<n; i++) //n unknown
    {
        if ((strcmp(Books[i].ISBN,ISBN)==0))
        {
            //pointer or not?
            k=i;
            return k; //it must return a number when finding the book
        }
    }
        return k; // returns -1 when not finding

}

int Search_Member_ID(int ID)
{
    int i;
    int k=-1;
    for(i=0; i<m; i++) //m unknown
    {
        if (Members[i].ID==ID)
        {
            //pointer or not?
            k=i;
            return k; //it must return a number when finding the ID member
        }

    }
    return k; // returns -1 when not finding
}

int SEARCH(int choice)
{
    char isbn[20];
    char buffer[50];
    char bufferTotal[50];
    int i,index;
    if (choice == 1)
    {
        printf("Enter ISBN:\n");
        scanf("%s",isbn);
        getchar();
        index=Search_Book_ISBN(isbn);
        if( index == -1)
            printf("This ISBN does not exist");

    }
    else if(choice == 2)
    {
        printf("Enter title :\n");
        fgets(buffer,50,stdin);
        buffer[strcspn(buffer,"\n")] = 0;
        strlwr(buffer);
        for(i=0; i<n ; i++){
            strcpy(bufferTotal, Books[i].Title);
            strlwr(bufferTotal);
            if( strstr(bufferTotal,buffer) != NULL){
                printf("For book %s enter %d:\n",Books[i].Title,i);
            }


        }
        printf("If you can not find what you are looking for, enter -1:\n");
        do{
        index=scan_check();
        }
        while( index == -2);



    }
    else if( choice == 3)
    {
        printf("Enter Author's name:\n");
        fgets(buffer,50,stdin);
        buffer[strcspn(buffer,"\n")] = 0;
        strlwr(buffer);
        for(i=0; i<n ; i++){

            strcpy(bufferTotal, Books[i].Author);
            strlwr(bufferTotal);
            if( strstr(bufferTotal,buffer) != NULL){
                printf("For book %s enter %d:\n",Books[i].Title,i);
            }
            }
        printf("If you can not find what you are looking for, enter -1:\n");
        do{
        index=scan_check();
        }
        while( index == -2);

    }
    else if( choice == 4)
    {
        printf("Enter the category:\n");
        fgets(buffer,50,stdin);
        buffer[strcspn(buffer,"\n")] = 0;
        for( i=0; i<n; i++)
        {
            if((strcasecmp(buffer,Books[i].Category)) == 0)
            {
                printf("For book %s enter %d:\n", Books[i].Title, i);
            }
        }
        printf("If you can not find what you are looking for enter -1:\n");
        do{
        index=scan_check();
        }
        while( index == -2);
    }

    return index;
}


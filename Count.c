#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <ctype.h>
#include "Count.h"
void Count_Book()
{
    FILE *Fb;
    Fb=fopen("Books.txt","r");

    if(Fb!=NULL)
    {
        while((fscanf(Fb,"%[^,],",Books[n].Title) == 1))
        {
            fscanf(Fb,"%[^,],%[^,],%[^,],",Books[n].Author,Books[n].Publisher,Books[n].ISBN);
            fscanf(Fb,"%d/%d/%d,",&Books[n].DateOfPublication.Day,&Books[n].DateOfPublication.Month,&Books[n].DateOfPublication.Year);
            fscanf(Fb,"%d,%d,%s",&Books[n].Copies,&Books[n].CopiesAvailable,Books[n].Category);
            fscanf(Fb,"\n");
            n++;

        }
        fclose(Fb);
    }
    else
        printf("\nError opening the file\n");
}

void Count_Member()
{
    FILE *Fm;

    Fm=fopen("Members.txt","r");

    if(Fm!=NULL)
    {
        while((fscanf(Fm,"%[^,],",Members[m].Last_Name)) == 1)
        {
            fscanf(Fm,"%[^,],%d,",Members[m].First_Name,&Members[m].ID);
            fscanf(Fm,"%[^,],%[^,],%[^,],",Members[m].Adr.Building,Members[m].Adr.Street,Members[m].Adr.City);
            fscanf(Fm,"%[^,],%d,%s",Members[m].PhoneNum,&Members[m].Age,Members[m].Mail);
            fscanf(Fm,"\n");
            m++;
        }
        fclose(Fm);
    }
    else
        printf("\nError opening the file\n");

}


void Count_Borrow()
{
    FILE *Fo;
    Fo=fopen("Borrows.txt","r");
    if(Fo!=NULL)
    {
        while((fscanf(Fo,"%[^,],",Borrows[l].ISBNB) == 1))
        {
            fscanf(Fo,"%d,",&Borrows[l].IDB);
            fscanf(Fo,"%d/%d/%d,",&Borrows[l].DateB.Day,&Borrows[l].DateB.Month,&Borrows[l].DateB.Year);
            fscanf(Fo,"%d/%d/%d,",&Borrows[l].DateD.Day,&Borrows[l].DateD.Month,&Borrows[l].DateD.Year);
            fscanf(Fo,"%d/%d/%d",&Borrows[l].DateR.Day,&Borrows[l].DateR.Month,&Borrows[l].DateR.Year);
            fscanf(Fo,"\n");
            l++;
        }
        fclose(Fo);

    }
    else
        printf("\nError opening the file\n");
}

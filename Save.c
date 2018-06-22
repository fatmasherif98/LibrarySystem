#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <ctype.h>
#include "Save.h"
void Save()
{
    FILE *Fb,*Fm,*Fo;
    int i;
    Fb=fopen("Books.txt","w");
    Fm=fopen("Members.txt","w");
    Fo=fopen("Borrows.txt","w");

    if(Fm != NULL && Fb != NULL && Fo != NULL)
    {
        for(i=0; i<n; i++)
        {   Books[i].Title[strcspn(Books[i].Title,"\n")] = 0;
            Books[i].Author[strcspn(Books[i].Author,"\n")]=0;
            Books[i].Publisher[strcspn(Books[i].Publisher,"\n")]=0;
            Books[i].ISBN[strcspn(Books[i].ISBN,"\n")]=0;
            Books[i].Category[strcspn(Books[i].Category,"\n")]=0;
            fprintf(Fb,"%s,%s,",Books[i].Title,Books[i].Author);
            fprintf(Fb,"%s,%s,",Books[i].Publisher,Books[i].ISBN);
            fprintf(Fb,"%d/%d/%d,%d,%d,%s\n",Books[i].DateOfPublication.Day,Books[i].DateOfPublication.Month,Books[i].DateOfPublication.Year,Books[i].Copies,Books[i].CopiesAvailable,Books[i].Category);
        }
        for(i=0; i<m; i++)
        {   Members[i].Last_Name[strcspn(Members[i].Last_Name,"\n")] = 0;
            Members[i].First_Name[strcspn(Members[i].First_Name,"\n")] = 0;
            Members[i].Adr.Building[strcspn(Members[i].Adr.Building,"\n")] = 0;
            Members[i].Adr.Street[strcspn(Members[i].Adr.Street,"\n")] = 0;
            Members[i].Adr.City[strcspn(Members[i].Adr.City,"\n")] = 0;
            Members[i].PhoneNum[strcspn(Members[i].PhoneNum,"\n")] = 0;
            Members[i].Mail[strcspn(Members[i].Mail,"\n")] = 0;
            fprintf(Fm,"%s,%s,%d",Members[i].Last_Name,Members[i].First_Name,Members[i].ID);
            fprintf(Fm,",%s,%s,%s",Members[i].Adr.Building,Members[i].Adr.Street,Members[i].Adr.City);
            fprintf(Fm,",%s,%d,%s\n",Members[i].PhoneNum,Members[i].Age,Members[i].Mail);


        }
        for( i=0; i<l; i++)
        {
            Borrows[i].ISBNB[strcspn(Borrows[i].ISBNB,"\n")] = 0;
            fprintf(Fo,"%s,%d,%d/%d/%d,",Borrows[i].ISBNB,Borrows[i].IDB,Borrows[i].DateB.Day,Borrows[i].DateB.Month,Borrows[i].DateB.Year);
            fprintf(Fo,"%d/%d/%d,",Borrows[i].DateD.Day,Borrows[i].DateD.Month,Borrows[i].DateD.Year);
            fprintf(Fo,"%d/%d/%d\n",Borrows[i].DateR.Day,Borrows[i].DateR.Month,Borrows[i].DateR.Year);
        }

    fclose(Fb);
    fclose(Fm);
    fclose(Fo);
    printf("Saved successfully!");
    } else{
    printf("Can't open files");
    }

}

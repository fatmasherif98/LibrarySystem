#include "Structs.h"
#include "Dates.h"
int CompareDates(Date DateD,Date DateR)
{
        if( DateD.Year < DateR.Year){
            return -1;
        } else if( DateD.Year > DateR.Year){
        return 0;
        } else if ( DateD.Month > DateR.Month){
            return 0;
            } else if( DateD.Month < DateR.Month){
            return -1;
            } else if( DateD.Day < DateR.Day){
            return -1;
            } else{
            return 0;
            }
}

int Check_Date(Date date ){
    //if( isalpha(date.Day) || isalpha(date.Month) || isalpha(date.Year)){
      //  printf("You can not enter letters!\n");
        //return -1;
    //}
    if(
       date.Year <= 2040 && date.Year>=1900){
     if( date.Month >=1 && date.Month <=12){
        if((date.Day>=1 && date.Day<=31) && (date.Month==1 || date.Month==3 || date.Month==5 || date.Month==7 || date.Month==8 || date.Month==10 || date.Month==12))
               return 0;
        else if((date.Day>=1 && date.Day<=30) && ( date.Month==4 || date.Month==6 || date.Month==9 || date.Month==11))
                return 0;
        else if((((date.Day >=1 && date.Day <=29) && date.Month == 2) && (date.Year%4==0) ) || ((date.Day >=1 && date.Day <= 28) && (date.Year%4 != 0)))
            return 0;
        else
        {printf("Day is not valid\n");
        return -1;

        }
    } else{
    printf("Month is not valid\n");
    return -1;
    }
} else{
printf("Year is not valid\n");
return -1;
}
}

#include<stdio.h>

void calcDay(int date,int month,int year)
{
    int day, year_digit, century_digit;
    year_digit = year / 100;
    century_digit = year % 100;
    day = (date+((13*(month-2)-1)/5)+year_digit+(year_digit/4)+(century_digit/4)-2*century_digit)%7;
    switch (day) {
        
        case 0:
            printf("The day is Sunday.\n");
            break;
        case 1:
            printf("The day is Monday.\n");
            break;
        case 2:
            printf("The day is Tuesday.\n");
            break;
        case 3:
            printf("The day is Wednesday.\n");
            break;
        case 4:
            printf("The day is Thursday.\n");
            break;
        case 5:
            printf("The day is Friday.\n");
            break;
        case 6:
            printf("The day is Saturday.\n");
            break;
    }
}
int main()
{
    int month,date,year;
    printf("Enter the date:");
    scanf("%d %d %d",&date);
    printf("Enter the month:");
    scanf("%d %d %d",&month);
    printf("Enter the year:");
    scanf("%d %d %d",&year);
    if (date>32){
        printf("Invalid date\n");
        if(month>12){
            printf("Invalid month\n");
            if (date>1000 & date>9999){
                printf("Invalid year\n");
                
            }
        }
    }
    
    calcDay(date,month,year);
}



// #include <stdio.h>
// int main ()
// {
  
// int year;
  
// printf ("Enter a year= ");
  
// scanf ("%d", &year);
  
// if (year % 400 == 0)
    
// printf ("Leap year");
  
//   else if (year % 100 != 0 && year % 4 == 0)
    
// printf ("Leap year");
  
//   else
    
// printf ("Not Leap Year");
  
// return 0;

// }
#include <stdio.h>
#include <time.h>
/*check given year is leap year or not*/
int isLeapYear(int year, int mon) 
{
    int flag = 0;
    if (year % 100 == 0) 
    {
            if (year % 400 == 0) 
            {
                    if (mon == 2) 
                    {
                            flag = 1;
                    }
            }
    } 
    else if (year % 4 == 0) 
    {
            if (mon == 2) 
            {
                    flag = 1;
            }
    }
    return (flag);
}
 
 
int main()
{
 
    int DaysInMon[] = {31, 28, 31, 30, 31, 30,
                       31, 31, 30, 31, 30, 31};
    int Days, Month, Year;
    int days, month, year;
    char dob[100];
    time_t ts;
    struct tm *ct;
    	/*get current date.*/
    ts = time(NULL);
    ct = localtime(&ts);
 
    printf("Date: %d/%d/%d\n",
            ct->tm_mday, ct->tm_mon + 1, ct->tm_year + 1900);
 
    days = DaysInMon[month - 1] - days + 1;
 
    /* leap year checking*/
    if (isLeapYear(year, month)) 
    {
            days = days + 1;
    }

	FILE *fp;
	char name[50];
	int roll;
	printf("Enter name: ");
    gets(name);
    fp = fopen(name, "w");
    fprintf(fp,"\nName: ");
    fputs(name, fp);
    fputs("\n", fp);
    
 
    /* enter date of birth */
    printf("Enter date of birth (DD/MM/YYYY) : ");
    scanf("%d/%d/%d",&Days,&Month, &Year);
    days=Days;
    month=Month;
    year=Year;
     /* calculating age in no of days, years and months */
    days = days + ct->tm_mday;
    month = (12 - month) + (ct->tm_mon);
    year = (ct->tm_year + 1900) - year - 1;
 
    /* checking for leap year feb - 29 days */
    if (isLeapYear((ct->tm_year + 1900), (ct->tm_mon + 1))) 
    {
            if (days >= (DaysInMon[ct->tm_mon] + 1)) 
            {
                    days = days - (DaysInMon[ct->tm_mon] + 1);
                    month = month + 1;
            }
    } 
    else if (days >= DaysInMon[ct->tm_mon]) 
    {
            days = days - (DaysInMon[ct->tm_mon]);
            month = month + 1;
    }
 
    if (month >= 12) 
    {
            year = year + 1;
            month = month - 12;
    }
    fprintf(fp, "\nDate of birth: %d/%d/%d", Days, Month, Year);
    fputs("\n", fp);
    printf("Enter roll number: ");
    scanf("%d",&roll);
    fprintf(fp,"\nRoll number: %d", roll);
    fputs("\n", fp);
    printf("\nProfile created.");
    fprintf(fp,"\nAge: %d years", year);
    fclose (fp);	
}


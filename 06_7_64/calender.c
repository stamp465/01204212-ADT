#include <stdio.h>
int main()
{
    long int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    char *months[] =
        {" ",
         "January",
         "February",
         "March",
         "April",
         "May",
         "June",
         "July",
         "August",
         "September",
         "October",
         "November",
         "December"};
    long int d = 0, m, y, i;
    //scanf("%d/%d/%d", &d, &m, &y);
    /*if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
    {
        month[2] += 1;
    }
    for (i = 1; i < m; i++)
        d += month[i];*/

    printf("Enter year: ");
    scanf("%ld", &y);
    printf("Enter month: ");
    scanf("%ld", &m);
    for (i = 1990; i < y; i++)
    {
        d += 365;
        if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0))
            d += 1;
    }
    if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
        month[2] += 1;
    for (i = 1; i < m; i++)
        d += month[i];
    long int start = 1 + d % 7;
    printf("====================\n");
    printf("%s %ld\n", months[m], y);
    printf("Sun Mon Tue Wed Thu Fri Sat\n");
    long int j = 0;
    while (1)
    {
        if (j >= start)
        {
            printf("%3ld ", j - start + 1);
        }
        else
        {
            printf("    ");
        }
        if ((j + 1) % 7 == 0)
        {
            //printf("%ld", j);
            printf("\n");
        }
        j++;
        if (j > month[m] + start - 1)
        {
            break;
        }
    }
    //printf("%ld", d);
    //printf("%ld", start);
}
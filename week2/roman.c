#include <stdio.h>

int chnum[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
char *roman[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

int main()
{
    int N;
    scanf("%d", &N);
    while (N--)
    {
        int i, num, j;
        scanf("%d", &num);
        for (i = 0; i < 13; i++)
        {
            int check = num / chnum[i];
            num = num % chnum[i];
            for (j = 0; j < check; j++)
            {
                printf("%s", roman[i]);
            }
        }
        printf("\n");
    }
}
/*
int main(void)
{
    int N, i = 0, num;
    scanf("%d", &N);
    for (i; i < N; i++)
    {
        scanf("%d", &num);
        while (num != 0)
        {
            if (num >= 1000)
            {
                printf("M");
                num -= 1000;
            }
            else if (num >= 900)
            {
                printf("CM");
                num -= 900;
            }
            else if (num >= 500)
            {
                printf("D");
                num -= 500;
            }
            else if (num >= 400)
            {
                printf("CD");
                num -= 400;
            }
            else if (num >= 100)
            {
                printf("C");
                num -= 100;
            }
            else if (num >= 90)
            {
                printf("XC");
                num -= 90;
            }
            else if (num >= 50)
            {
                printf("L");
                num -= 50;
            }
            else if (num >= 40)
            {
                printf("XL");
                num -= 40;
            }
            else if (num >= 10)
            {
                printf("X");
                num -= 10;
            }
            else if (num >= 9)
            {
                printf("IX");
                num -= 9;
            }
            else if (num >= 5)
            {
                printf("V");
                num -= 5;
            }
            else if (num >= 4)
            {
                printf("IV");
                num -= 4;
            }
            else if (num >= 1)
            {
                printf("I");
                num -= 1;
            }
        }
        printf("\n");
    }

    return 0;
}
*/
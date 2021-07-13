#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int N, i, j, num, sum, check, fac, forfac;
    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        scanf("%d", &num);
        for (j = num - 1; j > 0; j--)
        {
            check = j;
            sum = 0;
            while (check > 0)
            {
                fac = 1;
                int k = 1;
                forfac = check % 10;
                while (k <= forfac)
                {
                    fac = fac * k;
                    k++;
                }
                sum = sum + fac;
                check = check / 10;
            }
            if (sum == j)
            {
                printf("%d\n", sum);
                break;
            }
        }
    }
}

/*
int strNum[4] = {40585, 145, 2, 1};

int main()
{
    int N, j = 0;
    scanf("%d", &N);
    for (j; j < N; j++)
    {
        int i = 0, num;
        scanf("%d", &num);
        for (i; i < 4; i++)
        {
            if (num > strNum[i])
            {
                printf("%d\n", strNum[i]);
                break;
            }
        }
    }
    return 0;
}
*/
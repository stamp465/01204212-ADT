#include <stdio.h>
#include <math.h>

int main()
{
    long long N, i = 0, x = 0, y = 0, status[4][4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}, state = 400000;
    scanf("%lld", &N);
    char walk[N + 2];
    scanf("%s", walk);
    for (i; i < N; i++)
    {
        if (walk[i] == 'L')
            state--;
        if (walk[i] == 'R')
            state++;
        if (walk[i] == 'F')
        {
            x += status[state % 4][0];
            y += status[state % 4][1];
        }
    }
    float ans = sqrt(x * x + y * y);
    printf("%.4f", ans);
}

/*
4
RRRR
18
FFRFFRFLFRFFRFLFRF
5
FFFFF
*/
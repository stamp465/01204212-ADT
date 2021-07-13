#include <stdio.h>
#include <math.h>

int main()
{
    double N, af, ans, check;
    scanf("%lf %lf", &N, &af);
    while (1)
    {
        ans = 0.5 * (af + N / af);
        check = fabs(af - ans);
        printf("%.10lf %.10lf %.10lf\n", ans, af, check);
        af = ans;
        if (check <= 1e-10)
        {
            break;
        }
    }
    printf("%.10lf", ans);
    return 0;
}
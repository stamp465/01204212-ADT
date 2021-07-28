#include<stdio.h>
#include<math.h>
int sum=0;
void check(int m,int n)
{
    int i;
    if (m==0 || n==0)
    {
        return;
    }
    for (i=0;i<20;i++)
    {
        if (pow(2,i)>m || pow(2,i)>n)
        {
            int maxpow;
            int spacem,spacen;
            int minusm,minusn;
            maxpow=pow(2,i-1);//8
            spacem=m/maxpow;//1
            spacen=n/maxpow;//1
            sum+=spacem*spacen;//1
            //printf("%d %d %d %d \n",sum,maxpow,m,n);
            minusm=m%maxpow;//1
            minusn=n%maxpow;//3
            //printf("%d %d\n",minusm,minusn);
            check(minusm,minusn);//1,3
            check(minusm,maxpow*spacen);//1,8
            check(minusn,maxpow*spacem);//3,8
            break;
        }
    }
}

int main()
{
    int m,n;
    scanf("%d %d",&m,&n);
    check(m,n);
    printf("%d",sum);
    return 0;
}

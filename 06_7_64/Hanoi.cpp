#include <cstdio>

void toh(int n,char from,char to, char aug){
    if(n==1)
        printf("Move from %c to %c\n",from,to);
    else{
        toh(n-1,from,aug,to);
        printf("Move from %c to %c\n",from,to);
        toh(n-1,aug,to,from);
    }
}
int main(){
    int n;

    scanf("%d",&n);
    toh(n,'A','B','C');

return 0;}

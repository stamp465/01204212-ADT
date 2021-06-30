#include<stdio.h>
int main(){
  int month[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
  int d,m,y,i;
  scanf("%d/%d/%d",&d,&m,&y);
  if((y%4==0&&y%100!=0)||(y%400==0)){
    month[2] += 1;
  }
  for(i=1;i<m;i++) d+=month[i];
  printf("%d",d);
}

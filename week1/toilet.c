#include<stdio.h>
int main(){
  int ln,lo,c,n;
  scanf("%d %d %d %d",&ln,&lo,&c,&n);
  if( (c*1000)%( (lo-ln)*n)!=0 )
    printf("%d",(c*1000)/((lo-ln)*n)+1);
  else 
    printf("%d",(c*1000)/((lo-ln)*n));
}

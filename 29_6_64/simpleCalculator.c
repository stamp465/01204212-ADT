#include<stdio.h>

int main(){
  int x,y;
  char o;
  scanf("%d %c %d",&x,&o,&y);
  if(o=='+') printf("%d",x+y);
  else if(o=='-') printf("%d",x-y);
  else if(o=='*') printf("%d",x*y);
  else if(o=='/') printf("%.2f",(float)x/(float)y);
  else if(o=='%') printf("%d",x%y);
  else printf("Unknown Operator");
  return 0;
}

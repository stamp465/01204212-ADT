#include<stdio.h>
int main(){
  int x,y,z;
  scanf("%d %d %d ",&x,&y,&z);
  char a,b;
  scanf("%c %c",&a,&b);
  if( a=='y' || a=='Y' ){
    x += y;
  }
  if( b=='y' || b=='Y' ){
    if(x%z!=0){ 
      x = x + z;
    }
    x /= z;
  }
  printf("%d",x);
  return 0;
}

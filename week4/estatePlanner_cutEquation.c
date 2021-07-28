#include<stdio.h>
int main(){
	int m,n;
	scanf("%d %d",&m,&n);
	int i,j,ans=0,two=2,newans = m*n;
	while(1){
		ans +=  ( ( newans ) - ( (m/two) * (n/two) * 4 )  ) ;
		newans = (m/two) * (n/two) ;
		m = (m/two) * two;
		n = (n/two) * two;
		if( two>m && two>n ) break;
		two *= 2;
	}
	printf("%d\n",ans);
	return 0;
}
//Big-oh notation O(log2(max(m,n)))


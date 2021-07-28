#include<stdio.h>
int main(){
	int m,n,set2[20] = {1};
	scanf("%d %d",&m,&n);
	int i,j,ans=0,two=2,newans = m*n;
	for(i=1;i<=20;i++){
		set2[i] = two;
		ans +=  ( newans - ( (m/set2[i]) * (n/set2[i]) * (set2[i] * set2[i] ))  ) / ( set2[i-1] * set2[i-1] );
		newans = (m/set2[i]) * (n/set2[i]) * (set2[i] * set2[i] );
		m = (m/set2[i]) * set2[i];
		n = (n/set2[i]) * set2[i];
		if( two>m && two>n ) break;
		two *= 2;
	}
	printf("%d\n",ans);
	return 0;
}
//Big-oh notation if m > n : O(log2(m))
//Big-oh notation if m < n : O(log2(n))

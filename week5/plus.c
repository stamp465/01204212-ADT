#include<stdio.h>
#include<string.h>

int i,j,k,st;

char a[10000];
char b[10000];
int s1[10000];
int s2[10000];
int ans[10000];

int to_int(char x[],int n,int s[]){
	for(int i=0;i<n;i++){
		s[i] = x[i] - '0';
	}
	return n;
}

int plus(int x[],int y[],int n,int m){
	int nub,i=n-1,j=m-1,tod=0;
	for (nub=0; i>=0&&j>=0; i--,j--,nub++) 
	{ 
		ans[nub] = (x[i] + y[j] + tod) % 10; 
		tod = (x[i] + y[j] + tod) / 10; 
		//printf("%d",ans[nub]);
	} 
	while (i>=0) 
	{ 
		ans[nub] = (x[i] + tod) % 10; 
		tod = (x[i] + tod) / 10; 
		//printf("%d",ans[nub]);
		nub++,i--;
	}
	if (tod > 0) {
		ans[nub] = tod;
		//printf("%d",ans[nub]);
		nub++;
	} 
	return nub;
}

int main(){
	int nnn;
	scanf("%s %s",a,b);
	int lens1 = to_int(a,strlen(a),s1);
	int lens2 = to_int(b,strlen(b),s2);
	if(lens1>lens2)	nnn=plus(s1,s2,lens1,lens2);
	else			nnn=plus(s2,s1,lens2,lens1);
	for(int i=nnn-1;i>=0;i--){
		printf("%d",ans[i]);
	}
}

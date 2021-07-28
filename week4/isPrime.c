#include<stdio.h>
#include<math.h>

int main(){
	int n;
	scanf("%d",&n);
	int check = ceil(sqrt(n)),ans=1;
	if(n<=2){
		if(n==2) printf("1");
		if(n<2) printf("0");
		return 0;
	}
	for(int i=2;i<=check;i++){
	    if(n%i==0){
	        printf("0");
	        return 0;
	    }
	}
	printf("1");
	return 0;
}

//Big-oh notation O(sqrt(n))

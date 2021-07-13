#include<stdio.h>
#include<stdlib.h>

void findStats(double *avg, int *maxi,int *mini, int *nums, int n){
	*avg = 0;
	*maxi = *nums;
	*mini = *nums;
	int i;
	for (i=0;i<n;i++){
		*avg += (float)*(nums+i);
		if( *(nums+i) > *maxi ){
			*maxi = *(nums+i);
		}
		if( *(nums+i) < *mini ){
			*mini = *(nums+i);
		}
		//printf("%d ",*(nums+i));
	}
	*avg /= n;
	
}   

int main(){
    int n, i, maxi,mini;
    double avg;
    int* nums;

    scanf("%d", &n);
    nums = (int*) malloc(sizeof(int)*n);
    for (i=0;i<n;i++)
        scanf("%d", nums+i);
    findStats(&avg,&maxi,&mini,nums,n);
    printf("%.2f %d %d", avg, maxi, mini);
    return 0;
}

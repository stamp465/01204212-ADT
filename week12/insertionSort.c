#include <stdio.h>
int main()
{
    int n,now,i,j,k;
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++)	
		scanf("%d",&arr[i]);
    for (i=1;i<n;i++) {
        now = arr[i];
        j = i - 1;
        while (1) {
        	if( j<0 || arr[j] <= now){
        		arr[j+1] = now;
        		break;
			}
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        
        for (k=0;k<n;k++)
	        printf("%d ", arr[k]);
	    printf("\n");
    }
    return 0;
}

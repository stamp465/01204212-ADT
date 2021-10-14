#include <stdio.h>
int arr[1000][1000];
int n,m;
int max = 1;

int choose(int now,int save[],int len){
	for(int i=0;i<len;i++){
		printf("%d ",save[i]);
	}printf("\n");
	for(int i=now;i<n;i++){
		save[len] = i;
		int check = 1;
		/*for (int x=0;x<len+1;x++) {
	        for (int y=x+1;y<len+1;y++)
	            if (arr[save[x]][save[y]] == 0)	check = 0;
	    }
		if( check == 1){
			max = (max < len+1 ) ? len+1 : max;	
			
		}*/
		choose(i+1,save,len+1);
	}
}

int main()
{
    scanf("%d %d",&n,&m);
    
    for(int i=0;i<m;i++){
        int x,y; 
		scanf("%d %d",&x,&y);
        arr[x][y] = 1;
        arr[y][x] = 1;
    }
    
	int save[n+1];
    choose(0,save,0);
    
	//printf("%d\n",max);
	
    return 0;
}



#include<stdio.h>
int n;
int goi[4]={-1,0,1,0};
int goj[4]={0,1,0,-1};
char arr[105][105];
int visit[105][105];

int traverseMaze(int sti,int stj){
	int i,j,k;
	visit[sti][stj] = 0;
	if(arr[sti][stj]=='G'){
		return 1;
	}
	else{
		for(i=0;i<4;i++){
			if( arr[sti + goi[i]][stj + goj[i]]!='#' && visit[sti + goi[i]][stj + goj[i]] == 1 ){
				int a = traverseMaze(sti + goi[i],stj + goj[i]);
				if(a==1 && arr[sti][stj] != 'S'){
					arr[sti][stj] = '.';
					return 1;
				}
			}
		}
		return 0;
	}
	
}

int main(){
	int i,j,starti,startj;
	scanf("%d ",&n);
	
	for(i=0;i<=n+1;i++)
	    for(j=0;j<=n+1;j++)
	        visit[i][j] = 0;
	
    char c[105];
    for(int i=0;i<n;i++){
        char c[105];
        fgets(c, 105, stdin);
        for(int j=0;j<n;j++){
			arr[i+1][j+1] = c[j];
			visit[i+1][j+1] = 1;
	        if(arr[i+1][j+1]=='S'){
	        	starti = i+1;
				startj = j+1;
			}
		}
    }
    	
	traverseMaze(starti,startj);
	
	for(i=1;i<=n;i++){
	    for(j=1;j<=n;j++){
	        printf("%c",arr[i][j]);
	    }
	    printf("\n");
	}
}

/*
12
############
#   #      #
S # # #### #
### #    # #
#    ### # G
#### # # # #
#  # # # # #
## # # # # #
#        # #
###### ### #
#      #   #
############ 

4
####
####
S  G
####

*/

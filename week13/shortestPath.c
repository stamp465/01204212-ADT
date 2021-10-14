#include <stdio.h>

int min(int x,int y){	return x<y ? x : y;		}
int arr[1000][1000];

int main(){
	int n,m,p;
	scanf("%d %d %d",&n,&m,&p);
	for(int i=0;i<n;i++){
	    for(int j=0;j<n;j++){
	        if(i!=j)	arr[i][j]=1e8;
	    }
	}
	for(int k=0;k<m;k++){
	    int x,y,z;
	    scanf("%d %d %d",&x,&y,&z);
	    arr[x][y]=z;
	    arr[y][x]=z;
	}
	for(int k=0;k<n;k++){
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            arr[i][j]=min(arr[i][j],arr[i][k]+arr[k][j]);
	        }
	    }
	}
	while(p--){
	    int x,y;
	    scanf("%d %d",&x,&y);
	    printf("%d\n",(arr[x][y]!=1e8) ? arr[x][y] : -1);
	}
	return 0;
}

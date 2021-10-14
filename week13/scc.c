#include <stdio.h>
int arr[1000][1000];
int re[1000][1000];
int ans[1000],in[1000],out[1000],visit[1000],visit2[1000];
int n,m,t=0,max=0;

int dfs(int now){
	//printf("%d\n",now);
	visit[now] = 1;
	t++;
	in[now] = t;
	for(int j=0;j<n;j++){
		if( arr[now][j] == 1 && visit[j] == 0 ) {
			dfs(j);
		}
	}
	t++;
	out[now] = t;
}

int dfs2(int now,int len,int willans[]){
	//printf("%d ",now);
	willans[len] = now;
	visit2[now] = 1;
	for(int j=0;j<n;j++){
		if( re[now][j] == 1 && visit2[j] == 0 ) {
			dfs2(j,len+1,willans);
		}
	}
	if(	len+1 > max	) {
		max = len+1;
		for(int i=0;i<len+1;i++){
			ans[i] = willans[i];
		}
	}
}

int main()
{
    scanf("%d %d",&n,&m);
    
    for(int i=0;i<m;i++){
        int x,y; 
		scanf("%d %d",&x,&y);
        arr[x][y] = 1;
        re[y][x] = 1;
    }
    
    for(int i=0;i<n;i++){
    	if(in[i]==0)	dfs(i);
	}
	
	for(int i=0;i<n;i++){
		printf("%d\t",in[i]);
	}printf("\n");
    for(int i=0;i<n;i++){
		printf("%d\t",out[i]);
	}
	
	for(int i=0;i<n;i++){
		int max = 0;
		int savej = 0;
		for(int j=0;j<n;j++){
			if(out[j]>max){
				max = out[j];
				savej = j;
				out[j] = 0;
			}
		}
		if(visit2[savej]==0){
			int willans[n+1] ;
			printf("%d\n",savej);
			dfs2(savej,0,willans);
			//printf("\n");
		}
	}
	
	for(int i=0;i<max;i++){
		for(int j=i+1;j<max;j++){
			if(ans[j]<ans[i]){
				int tmp = ans[i];
				ans[i] = ans[j];
				ans[j] = tmp;
			}
		}
	}
	for(int i=0;i<max;i++){
		printf("%d ",ans[i]);
	}
    return 0;
}

/*
5 5
1 0
2 1
0 2
0 3
3 4
*/

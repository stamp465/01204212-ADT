#include<stdio.h>
int m,p,n,inew=0;
char word[100010];
char check[100010];
char newword[100010];

void gennew(int start){
	int i,j,k;
	newword[inew] = '[';
	inew++;
	for(i=0;i<p;i++){
		if(word[start+i]!=check[i]){
			newword[inew] = '?';
			inew++;
		}
		else{
			newword[inew] = check[i];
			inew++;
		}
	}
	newword[inew] = ']';
	inew++;
}

int strcmpS(int start){
	int i,j,k,nub=0;
	for(i=0;i<p;i++){
		if(word[start+i]!=check[i]){
			nub++;
		}
	}
	if(nub<=n){
		gennew(start);
		return start+p-1;
	}
	return start;
}

int main(){
	int i,j,k;
	scanf("%d %d %d ",&m,&p,&n);
	scanf("%s",word);
	scanf("%s",check);
	
	for(i=0;i<m;i++){
		//printf("%c ",word[i]);
		int a=i;
		if(i<=m-p)
			a = strcmpS(i);
		if(a==i){
			newword[inew] = word[i];
			inew++;
		}
		else{
			i = a;
		}
	}
	
	//printf("%s\n",word);
	//printf("%s\n",check);
	printf("%s\n",newword);
}

/*
18 3 0
acabababababcbabab
aba

18 3 1
acabababababcbabab
aba

19 3 3
acabababababcbababa
aba

15 4 2
AAAGTGTGTCTGATT
GTAT

*/

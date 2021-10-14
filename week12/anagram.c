#include<stdio.h>

int main(){
	int n,m;
	scanf("%d %d ",&n,&m);
	char string[n][52];
	char check[52];
	int savechar[n][26];
	int nubchar[n];
	for(int i=0;i<n;i++){
		for(int j=0;j<26;j++){
			savechar[i][j] = 0;
		}
		scanf(" %s",string[i]);
		for(int j=0;j<52;j++){
			if(string[i][j]=='\0'){
				nubchar[i] = j;
				break;
			}
			savechar[i][ string[i][j] - 'a' ] ++;
		}
	}
	for(int i=0;i<m;i++){
		
		int fornub[26];
		int saveme[26];
		int len = 0,xx=0;
		for(int j=0;j<26;j++){
			fornub[j] = 0;
		}
		scanf(" %s",check);
		for(int j=0;j<52;j++){
			if(check[j]=='\0'){
				len = j;
				break;
			}
			fornub[ check[j] - 'a' ] ++;
			if( fornub[ check[j] - 'a' ] == 1  ){
				saveme[xx] = check[j] - 'a';
				xx++;
			}
		}
		
		for(int k=0;k<n;k++){
			if( len == nubchar[k] ){
				int ch = 1;
				for(int l=0;l<xx;l++){
					if( savechar[k][saveme[l]] != fornub[saveme[l]] ){
						ch = 0;
						break;
					}
				}
				if(ch)	printf("%s ",string[k]);
			}
		}
		printf("\n");
	}
	
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char wongleb[1000005];
char qoo1[] = {'[','(','{'};
char qoo2[] = {']',')','}'};
////////////////////////////////////////////////////////////////////
typedef struct node {
  int          data;
  struct node *next;
} node_t;

typedef node_t stack_t;

stack_t* push(stack_t *nodest,int value){
	node_t* new_node =  (node_t *)malloc(sizeof (node_t));
	new_node->data = value;
	new_node->next = NULL;
	
	new_node->next = nodest;
	nodest = new_node;
	
	return nodest;
}

int top(stack_t *nodest){
	if(nodest==NULL) 	return -1;
	else				return nodest->data;
}

stack_t* pop(stack_t *nodest){
	if(nodest==NULL){}
	else {
		node_t* tmp =  nodest;
		nodest = nodest->next;
		free(tmp);
	}
	return nodest;
}

int empty(stack_t *nodest){
	if(nodest==NULL) 	return 1;
	else				return 0;
}

int size(stack_t *nodest){
	node_t* to =  nodest;
	int i=0;
	for(;to!=NULL;to=to->next){
		i++;
	}
	return i;
}
////////////////////////////////////////////////////////////////////
int isIn(char a,char check[]){
	for(int i=0;i<3;i++){
		if (a==check[i]) return i+1;
	}return 0;
}

int checkwondleb(stack_t *nodest,char wongleb[]){
	int lenwondleb = strlen(wongleb),i;
	for(i=0;i<lenwondleb;i++){
		//printf("%d %c ",i,wongleb[i]);
		int ch1 = isIn(wongleb[i],qoo1);
		//printf("ch1 = %d ",ch1);
		if(ch1){
			nodest = push(nodest,wongleb[i]);
		}
		
		int ch2 = isIn(wongleb[i],qoo2);
		//printf("ch2 = %d ",ch2);
		if(ch2){
			if(empty(nodest)) return 0;
			else{
				int ch2ex = isIn(top(nodest),qoo1);
				//printf("ex = %d ",ch2ex);
				if(ch2==ch2ex){
					nodest = pop(nodest);
				}
				else return 0;
			}
		}
		//printf("\n");
	}
	
	
	if(empty(nodest)) 	return 1;
	else				return 0;
}

int main(void) {
  stack_t *s = NULL;
  int      n, i;
  scanf("%d", &n);
  scanf(" %s", wongleb);
  printf("%d",checkwondleb(s,wongleb));
  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char wongleb[1000005];
////////////////////////////////////////////////////////////////////
typedef struct node {
  char			data;
  struct node 	*next;
} node_t;

typedef node_t stack_t;

stack_t* push(stack_t *nodest,char value){
	node_t* new_node =  (node_t *)malloc(sizeof (node_t));
	new_node->data = value;
	new_node->next = NULL;
	
	new_node->next = nodest;
	nodest = new_node;
	
	return nodest;
}

char top(stack_t *nodest){
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
int checkwondleb(stack_t *nodest,char wongleb[]){
	int lenwondleb = strlen(wongleb),i,status=1;
	for(i=0;i<lenwondleb;i++){
		if(wongleb[i]=='x'){
			status = 0;
		}
		else if(wongleb[i]=='y'){
			if(i!=lenwondleb-1)	return 0;
			//return 1;
		}
		else{
			if(status){
				nodest = push(nodest,wongleb[i]);
			}
			else{
				char ch = top(nodest);
				nodest = pop(nodest);
				if(ch==wongleb[i]){}
				else{
					return 0;
				}
			}
		}
	}
	
	//printf("%d\n",size(nodest));
	if(empty(nodest)) 	return 1;
	else				return 0;
}

int main(void) {
  stack_t *s = NULL;
  int      n, i;
  scanf("%s", wongleb);
  printf("%d",checkwondleb(s,wongleb));
  return 0;
}

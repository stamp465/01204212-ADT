#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char postfix[1000005];
char qoo[] = {'+','-','*','/'};
int checkqoo[1000005];
////////////////////////////////////////////////////////////////////
typedef struct node {
  float          data;
  struct node *next;
} node_t;

typedef node_t stack_t;

stack_t* push(stack_t *nodest,float value){
	node_t* new_node =  (node_t *)malloc(sizeof (node_t));
	new_node->data = value;
	new_node->next = NULL;
	
	new_node->next = nodest;
	nodest = new_node;
	
	return nodest;
}

float top(stack_t *nodest){
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
int chartoint(char want[]){
	
}

int isIn(char a,char check[]){
	for(int i=0;i<4;i++){
		if (a==check[i]) return i+1;
	}return 0;
}

float checkpostfix(stack_t *nodest,char postfix[]){
	int len=strlen(postfix),st=-1,en=0;
	for(int i=0;i<len;i++){
		int ch = isIn(postfix[i],qoo);
		if(ch){
			float b = top(nodest);
			nodest = pop(nodest);
			float a = top(nodest);
			nodest = pop(nodest);
			if(postfix[i]=='+') nodest = push(nodest,a+b);
			else if(postfix[i]=='-') nodest = push(nodest,a-b);
			else if(postfix[i]=='*') nodest = push(nodest,a*b);
			else if(postfix[i]=='/') nodest = push(nodest,a/b);
			//printf("oper %f\n",top(nodest));
		}
		else{
			nodest = push(nodest,(float)(postfix[i]-'0'));
			//printf("push %f\n",top(nodest));
		}
	}
	
	return top(nodest);
}

int main(void) {
  stack_t *s = NULL;
  int      n, i;
  scanf("%d", &n);
  scanf(" %s", postfix);
  printf("%.2f",checkpostfix(s,postfix));
  return 0;
}

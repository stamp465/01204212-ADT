#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int          data;
  struct node *next;
} node_t;

typedef node_t stack_t;

// Write your code here
stack_t* push(stack_t *nodest,int value){
	node_t* new_node =  (node_t *)malloc(sizeof (node_t));
	new_node->data = value;
	new_node->next = NULL;
	
	new_node->next = nodest;
	nodest = new_node;
	
	return nodest;
}

void top(stack_t *nodest){
	if(nodest==NULL) 	printf("Stack is empty.\n");
	else				printf("%d\n",nodest->data);
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

void empty(stack_t *nodest){
	if(nodest==NULL) 	printf("Stack is empty.\n");
	else				printf("Stack is not empty.\n");
}

void size(stack_t *nodest){
	node_t* to =  nodest;
	int i=0;
	for(;to!=NULL;to=to->next){
		i++;
	}
	printf("%d\n",i);
}
// ...

int main(void) {
  stack_t *s = NULL;
  int      n, i, command, value;

  scanf("%d", &n);
  for (i=0; i<n; i++) {
    scanf("%d", &command);
    switch(command) {
      case 1:
        scanf("%d", &value);
        s = push(s, value);
        break;
      case 2:
        top(s);
        break;
      case 3:
        s = pop(s);
        break;
      case 4:
        empty(s);
        break;
      case 5:
        size(s);
        break;
      }
  }
  return 0;
}

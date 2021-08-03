#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int          data;
  struct node *next;
} node_t;

typedef node_t queue_t;

// Write your code here
queue_t* enqueue(queue_t *nodest,int value){
	node_t* new_node = (node_t*)malloc(sizeof (node_t));
	new_node->data = value;
	new_node->next = NULL;
	
	node_t* to = nodest;
	if(nodest==NULL){
		nodest = new_node;
		return nodest;
	}
	for(;to->next!=NULL;to=to->next){}
	to->next = new_node;

	return nodest;
}

queue_t* dequeue(queue_t *nodest){
	if(nodest==NULL){
		printf("Queue is empty.\n");
		return nodest;
	}
	node_t* tmp = nodest;
	nodest = nodest->next;
	printf("%d\n",tmp->data);
	free(tmp);
	return nodest;
}

void show(queue_t *nodest){
	if(nodest==NULL) 	printf("Queue is empty.\n");
	else{
		node_t* to = nodest;
		for(;to!=NULL;to=to->next){
			printf("%d ",to->data);
		}printf("\n");
	}
}

void empty(queue_t *nodest){
	if(nodest==NULL) 	printf("Queue is empty.\n");
	else				printf("Queue is not empty.\n");
}

void size(queue_t *nodest){
	node_t* to =  nodest;
	int i=0;
	for(;to!=NULL;to=to->next){
		i++;
	}
	printf("%d\n",i);
}
// ...

int main(void) {
  queue_t *q = NULL;
  int      n, i, command, value;

  scanf("%d", &n);
  for (i=0; i<n; i++) {
    scanf("%d", &command);
    switch(command) {
      case 1:
        scanf("%d", &value);
        q = enqueue(q, value);
        break;
      case 2:
        q = dequeue(q);
        break;
      case 3:
        show(q);
        break;
      case 4:
        empty(q);
        break;
      case 5:
        size(q);
        break;
    }
  }
  return 0;
}

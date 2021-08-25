#include <stdio.h>
#include <stdlib.h>

// You can define your own (one or more)
// structures here. However, we eventually
// need the data type "tree_t".
// For example:
// typedef struct node {
//    ...
// } node_t;
// typedef node_t tree_t;

// Write your code here
typedef struct tree {
	int value;
	int depth;
	int child;
	struct tree *next_sibling;
	struct tree *first_child;
} tree_t;
// Week 6 Copy...
typedef struct node1 {
  struct tree	*pointer;
  struct node1 	*next;
} queue_t;
typedef struct node2 {
  int data;
  struct node2 	*next;
} stack_t;
// Queue
queue_t* enqueue(queue_t *nodest,tree_t *value){
	queue_t* new_node = (queue_t*)malloc(sizeof (queue_t));
	new_node->pointer = value;
	new_node->next = NULL;
	
	queue_t* to = nodest;
	if(nodest==NULL){
		nodest = new_node;
		return nodest;
	}
	for(;to->next!=NULL;to=to->next){}
	to->next = new_node;

	return nodest;
}

queue_t* dequeue(queue_t *nodest){
	if(nodest==NULL)	return nodest;
	queue_t* tmp = nodest;
	nodest = nodest->next;
	free(tmp);
	return nodest;
}

int emptyQueue(queue_t *nodest){
	if(nodest==NULL) 	return 1;
	else				return 0;
}

// Stack
stack_t* push(stack_t *nodest,int value){
	stack_t* new_node =  (stack_t *)malloc(sizeof (stack_t));
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
		stack_t* tmp =  nodest;
		nodest = nodest->next;
		free(tmp);
	}
	return nodest;
}

int emptyStack(stack_t *nodest){
	if(nodest==NULL) 	return 1;
	else				return 0;
}

// Week 6
tree_t* searchXX(tree_t *nodest,int value){	
	if( nodest == NULL || nodest->value == value) return nodest;
	tree_t* to = searchXX(nodest->first_child,value);
	return ( to != NULL) ? to : searchXX(nodest->next_sibling,value);
}

int search(tree_t *nodest,int value){	
	return (searchXX(nodest,value)==NULL) ? 0 : 1;
}

tree_t* attach(tree_t *nodest,int parent,int child){
	tree_t* new_node =  (tree_t *)malloc(sizeof (tree_t));
	new_node->value = child;
	new_node->depth = 0;
	new_node->child = 0;
	new_node->next_sibling = NULL;
	new_node->first_child = NULL;
	
	if(nodest==NULL){
		return nodest = new_node;
	}

	tree_t* to  = searchXX(nodest,parent);
	to->child += 1;
	new_node->depth = to->depth+1;
	if(to->first_child==NULL){
		to->first_child = new_node;	
	}
	else{
		to = to->first_child;
		while(to->next_sibling!=NULL)	to = to->next_sibling;
		to->next_sibling = new_node;	
	}
	return nodest;
}

void deleted(tree_t *nodest){
	tree_t* tmp = nodest;
	if( nodest == NULL ) return ;
	if( nodest->first_child!=NULL )		deleted(nodest->first_child);
	if( nodest->next_sibling!=NULL )	deleted(nodest->next_sibling);
	free(tmp);
}

void detachXX(tree_t *nodest,int value){	
	if( nodest == NULL ) return ;
	//printf("= 1...%d %d...\n",nodest->value,value);
	if( nodest->first_child!= NULL )
	if( nodest->first_child->value == value )	{
		//printf("case1\n");
		tree_t* tmp = nodest->first_child;
		if(nodest->first_child->next_sibling!=NULL){
			nodest->first_child = nodest->first_child->next_sibling;
			if(tmp->first_child!=NULL)	deleted(tmp->first_child),free(tmp);
		}
		else{
			nodest->first_child = NULL;
			if(tmp->first_child!=NULL)	deleted(tmp->first_child),free(tmp);
		}
		return ;
	}
	if( nodest->next_sibling!= NULL )
	if( nodest->next_sibling->value == value )	{
		//printf("case2\n");
		tree_t* tmp = nodest->next_sibling;
		if(nodest->next_sibling->next_sibling!=NULL){
			nodest->next_sibling = nodest->next_sibling->next_sibling;
			if(tmp->first_child!=NULL)	deleted(tmp->first_child),free(tmp);
		}
		else{
			nodest->next_sibling = NULL;
			if(tmp->first_child!=NULL)	deleted(tmp->first_child),free(tmp);
		}
		return ;
	}
	//printf("go2\n");
	detachXX(nodest->first_child,value);
	detachXX(nodest->next_sibling,value);	
}

tree_t* detach(tree_t *nodest,int value){	
	tree_t* to = nodest;
	if(to==NULL)	return nodest;
	detachXX(to,value);
	return nodest;
}

int degree(tree_t *nodest,int value){
	return searchXX(nodest,value)->child;
}

int is_root(tree_t *nodest,int value){
	return (searchXX(nodest,value)->depth==0) ? 1 : 0;
}

int is_leaf(tree_t *nodest,int value){
	return (searchXX(nodest,value)->child==0) ? 1 : 0;
}

tree_t* searchsiblings(tree_t *pa,tree_t *nodest,int value){	
	if( nodest == NULL || nodest->value == value) return (nodest == NULL) ? nodest : pa;
	tree_t* to = searchsiblings(nodest,nodest->first_child,value);
	return ( to != NULL) ? to : searchsiblings(pa,nodest->next_sibling,value);
}

void siblings(tree_t *nodest,int value){
	tree_t* to = searchsiblings(NULL,nodest,value);
	if(to!=NULL)	to = to->first_child;
	while(to!=NULL){
		if(to->value!=value)	printf("%d ",to->value);
		to = to->next_sibling;
	}printf("\n");
}

int depth(tree_t *nodest,int value){
	return searchXX(nodest,value)->depth;
}

stack_t* searchprint_path(stack_t* s,tree_t *nodest,int value){	
	if( nodest == NULL ) return NULL;
	if( nodest->value == value )	{
		stack_t* s = NULL;
		s = push(s,nodest->value);
		return s;
	}
	stack_t* to = searchprint_path(s,nodest->first_child,value);
	return ( to != NULL) ? to = push(to,nodest->value) : searchprint_path(to,nodest->next_sibling,value);
}

void print_path(tree_t *nodest,int start,int end){
	stack_t* ss = searchprint_path(ss,searchXX(nodest,start),end);
	while(!emptyStack(ss)){
		int a = top(ss);
		if(a!=-1)	printf("%d ",a);
		ss = pop(ss);
	}
	printf("\n");
}

int path_length(tree_t *nodest,int start,int end){
	return depth(nodest, end)-depth(nodest, start)+1;
}

void ancestor(tree_t *nodest,int end){
	stack_t* ss = NULL;
	ss = searchprint_path(ss,nodest,end);
	while(!emptyStack(ss)){
		int a = top(ss);
		if(a!=-1)	printf("%d ",a);
		ss = pop(ss);
	}
	printf("\n");
}

void dfs(tree_t *nodest){
	if( nodest == NULL ) return ;
	printf("%d ",nodest->value);
	dfs(nodest->first_child);
	dfs(nodest->next_sibling);
}

void print_tree(tree_t *nodest){
	if( nodest == NULL ) return ;
	for(int i=0;i<nodest->depth;i++)	printf("\t");
	printf("%d\n",nodest->value);
	print_tree(nodest->first_child);
	print_tree(nodest->next_sibling);
}

void bfs(tree_t *nodest){
	queue_t *q = NULL;
	q = enqueue(q,nodest);
	while(!emptyQueue(q)){
		tree_t* to = q->pointer;
		printf("%d ",to->value);
		to = to->first_child;
		while(to!=NULL){
			q = enqueue(q,to);
			to = to->next_sibling;
		}
		q = dequeue(q);
	}printf("\n");
}

void descendant(tree_t *nodest,int start){
	tree_t* xx = searchXX(nodest,start);
	bfs(xx);
}
// ...

int main(void) {
  tree_t *t = NULL;
  int n, i, command;
  int parent, child, node, start, end;

  scanf("%d", &n);
  for (i=0; i<n; i++) {
    scanf("%d", &command);
    switch(command) {
      case 1:
        scanf("%d %d", &parent, &child);
        t = attach(t, parent, child);
        break;
      case 2:
        scanf("%d", &node);
        t = detach(t, node);
        break;
      case 3:
        scanf("%d", &node);
        printf("%d\n", search(t, node));
        break;
      case 4:
        scanf("%d", &node);
        printf("%d\n", degree(t, node));
        break;
      case 5:
        scanf("%d", &node);
        printf("%d\n", is_root(t, node));
        break;
      case 6:
        scanf("%d", &node);
        printf("%d\n", is_leaf(t, node));
        break;
      case 7:
        scanf("%d", &node);
        siblings(t, node);
        break;
      case 8:
        scanf("%d", &node);
        printf("%d\n", depth(t, node));
        break;
      case 9:
        scanf("%d %d", &start, &end);
        print_path(t, start, end);
        break;
      case 10:
        scanf("%d %d", &start, &end);
        printf("%d\n", path_length(t, start, end));
        break;
      case 11:
        scanf("%d", &node);
        ancestor(t, node);
        break;
      case 12:
        scanf("%d", &node);
        descendant(t, node);
        break;
      case 13:
        bfs(t);
        break;
      case 14:
        dfs(t);
        break;
      case 15:
        print_tree(t);
        break;
    }
  }
  return 0;
}

#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int data;
	struct node *next;
}node_t;

node_t *append(node_t* nodest){
	int dat;
	scanf(" %d",&dat);

    node_t *new_node = (node_t*)malloc(sizeof(node_t));
    node_t *to = nodest;  
  
    new_node->data  = dat;
    new_node->next = NULL;
 
	if (nodest == NULL)
    {
       nodest = new_node;
       return nodest;
    } 
      
    while (to->next != NULL)
        to = to->next;
    to->next = new_node;
    return nodest;   
}

void get(node_t *nodest){
	int want,i=0;
	scanf(" %d",&want);
	
	node_t *to=nodest;
	//printf("%p\n",nodest);
	
	while(1){
		//printf("can");
		if(i==want){
			//printf("can2");
			printf("%d\n",to->data);
			break;
		}
		to = to->next;
		i++;
	}
	//printf("%p\n",nodest);
	return ;
}

void show(node_t *startNode){
	node_t *to = startNode;
	while(to!=NULL){
		printf("%d ",to->data);
		to = to->next;
	}printf("\n");
}

node_t *reverse(node_t *nodest){
	node_t *before = NULL;
    node_t *now = nodest;
    node_t *after = NULL;
    while (now != NULL) {
    	
        after = now->next;
        now->next = before;
        
        before = now;
        now = after;
    }
	nodest = before;
	return nodest;
}

node_t *append2(node_t* nodest,int dat){
    node_t *new_node = (node_t*)malloc(sizeof(node_t));
    node_t *to = nodest;  
  
    new_node->data  = dat;
    new_node->next = NULL;
 
	if (nodest == NULL)
    {
       nodest = new_node;
       return nodest;
    } 
    //printf("go\n");
    while (to->next != NULL)
        to = to->next;
    to->next = new_node;
    //printf("gogo\n");
    return nodest;   
}


node_t *cut(node_t *nodest){
	int st,en,i=0,ch=0;
	scanf("%d %d",&st,&en);
	
	node_t *new_node = NULL;
	node_t *to = nodest;
	
	while(to!=NULL){
		if( i>=st && i<=en){
			//printf("%d ",to->data);
			new_node = append2(new_node,to->data);
			//printf("xxx\n");
		}
		to = to->next;
		i++;
	}
	
	//printf("\n");
	//printf("xxx%dxxx\n",nodest->data);
	return new_node;
}


int main(void) {
	node_t *startNode;
	int n,i;
	char command;
	
	startNode = NULL;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf(" %c",&command);
		switch(command){
			case 'A':
				startNode = append(startNode);
				break;
			case 'G':
				get(startNode);
				break;
			case 'S':
				show(startNode);
				break;
			case 'R':
				startNode = reverse(startNode);
				break;
			case 'C':
				startNode = cut(startNode);
				break;
			default:
				break;
		}
	}
	return 0;
}

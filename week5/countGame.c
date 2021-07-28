#include<stdio.h>
#include<stdlib.h>

int n,m;
int isIn(int c,int m){
	while(c!=0){
		if(c%10==m) return 1;
		c/=10;
	}
	return 0;
}

typedef struct node {
	int data;
	int number;
	struct node *next;
}node_t;

void show(node_t *startNode){
	node_t *to = startNode;
	while(to->next!=startNode){
		printf("%d ",to->data);
		to = to->next;
	}
	printf("%d ",to->data);
	printf("\n");
	
	to = to->next;
	while(to->next!=startNode){
		printf("%d ",to->number);
		to = to->next;
	}
	printf("%d ",to->number);
	printf("\n");
}

void delete(node_t *to){
	node_t *tmp = to->next;
	if(to->next->next->data==-1) delete(to->next);
	to->next = to->next->next;
	free(tmp);
}

void play(node_t *startNode){
	node_t *to = startNode;
	int count=1;
	while(1){
		if(to->next->data==-1) delete(to);
		if(count%m==0||isIn(count,m)){
			to->data -= 1;
			//printf("%d %d %d\n",count,to->number,to->data);
		}
		if(to->next==to) break;
		to = to->next;
		count++;
	}
	printf("%d\n",to->number);
}

node_t *append(node_t* nodest,int dat,int num)
{  
    node_t *new_node = (node_t*)malloc(sizeof(node_t));  
    new_node->data = dat; 
    new_node->number = num; 
    if(nodest == NULL)  
    {  
        nodest = new_node; 
        //printf("%d\n",nodest->data); 
        new_node -> next = nodest;    
    }  
    else  
    {  
        node_t *to = nodest;  
        while(to -> next != nodest)  
        {  
            to = to -> next;  
        }  
        to -> next = new_node;  
		//printf("%d\n",to -> next ->data);  
        new_node -> next = nodest;  
    }  
	return nodest;
}  

int main(void) {
	node_t *startNode;
	startNode = NULL;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		int s;
		scanf("%d",&s);
		startNode = append(startNode,s,i);
	}
	//show(startNode);
	play(startNode);
	return 0;
}

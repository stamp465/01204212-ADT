#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node {
	int data0;
	double data1;
	char data2[20];
	int c0,c1,c2;
	struct node *next;
}node_t;

node_t *append(node_t* nodest){
	int check;
	scanf(" %d",&check);
	int dat0;
	double dat1;
	char dat2[20];
	
	if(check==0){
		scanf(" %d",&dat0);
	}
	if(check==1){
		scanf(" %lf",&dat1);
	}
	if(check==2){
		scanf(" %s",dat2);
	}

    node_t *new_node = (node_t*)malloc(sizeof(node_t));
    node_t *to = nodest;  
	
	new_node->c0=0;
	new_node->c1=0;
	new_node->c2=0;
    if(check==0) new_node->data0  = dat0,new_node->c0=1;
    if(check==1) new_node->data1  = dat1,new_node->c1=1;
    if(check==2) strcpy(new_node->data2,dat2),new_node->c2=1;
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
	
	while(1){
		if(i==want){
			if(to->c0!=0) printf("%d ",to->data0);
			if(to->c1!=0) printf("%lf ",to->data1);
			if(to->c2!=0) printf("%s ",to->data2);
			printf("\n");
			break;
		}
		to = to->next;
		i++;
	}
	return ;
}

void show(node_t *nodest){	
	node_t *to=nodest;
	//printf("%p\n",nodest);
	
	while(to!=NULL){
		if(to->c0!=0) printf("%d ",to->data0);
		if(to->c1!=0) printf("%lf ",to->data1);
		if(to->c2!=0) printf("%s ",to->data2);
		to = to->next;
	}
	printf("\n");
	return ;
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

node_t *show_reverse(node_t *nodest){	
	node_t *re=reverse(nodest);
	show(re);
	nodest = reverse(re);
	return nodest;
}

void insert(node_t *nodest){
	int want,i=0;
	scanf(" %d",&want);
	int check;
	scanf(" %d",&check);
	int dat0;
	double dat1;
	char dat2[20];
	
	if(check==0){
		scanf(" %d",&dat0);
	}
	if(check==1){
		scanf(" %lf",&dat1);
	}
	if(check==2){
		scanf(" %s",dat2);
	}

    node_t *new_node = (node_t*)malloc(sizeof(node_t));
    node_t *to = nodest;  
	
	new_node->c0=0;
	new_node->c1=0;
	new_node->c2=0;
    if(check==0) new_node->data0  = dat0,new_node->c0=1;
    if(check==1) new_node->data1  = dat1,new_node->c1=1;
    if(check==2) strcpy(new_node->data2,dat2),new_node->c2=1;
    new_node->next = NULL;
		
	while(1){
		if(i==want){
			new_node->next = to->next;
 			to->next = new_node;
			break;
		}
		to = to->next;
		i++;
	}
	return ;
}

node_t *delete(node_t *nodest){
	int want,i=0;
	scanf(" %d",&want);
		
	node_t *to=nodest;
	if(want==0){
  		nodest = to->next;
  		free(to);
  		return nodest;
	}
	else{
		while(1){
			if(i==want-1){
				node_t *tmp = to->next;
				to->next = to->next->next;
				free(tmp);
				break;
			}
			to = to->next;
			i++;
		}
		return nodest;
	}
}

void change(node_t *nodest){
	int want,i=0;
	scanf(" %d",&want);
	int check;
	scanf(" %d",&check);
	int dat0;
	double dat1;
	char dat2[20];
	
	if(check==0){
		scanf(" %d",&dat0);
	}
	if(check==1){
		scanf(" %lf",&dat1);
	}
	if(check==2){
		scanf(" %s",dat2);
	}
	
	node_t *to = nodest;
		
	while(1){
		if(i==want){
			to->c0=0;
			to->c1=0;
			to->c2=0;
			if(check==0) to->data0  = dat0,to->c0=1;
    		if(check==1) to->data1  = dat1,to->c1=1;
    		if(check==2) strcpy(to->data2,dat2),to->c2=1;
			break;
		}
		to = to->next;
		i++;
	}
	return ;
}

void is_empty(node_t *nodest){
	if (nodest == NULL)
    {
       printf("Empty\n");
       return ;
    } 
    printf("Not Empty\n");
    return ;
}

void length(node_t *nodest){
	node_t *to = nodest;
	int i = 0;	
	while(to!=NULL){
		to = to->next;
		i++;
	}
	printf("%d\n",i);
	return ;
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
				startNode = show_reverse(startNode);
				break;
			case 'I':
				insert(startNode);
				break;
			case 'C':
				change(startNode);
				break;
			case 'D':
				startNode = delete(startNode);
				break;
			case 'E':
				is_empty(startNode);
				break;
			case 'L':
				length(startNode);
				break;
			default:
				break;
		}
	}
	return 0;
}

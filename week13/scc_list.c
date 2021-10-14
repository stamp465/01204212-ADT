#include<stdio.h>
#include<stdlib.h>

int n,m;
int count_g=0,count_ans=0;

typedef struct g{
    int name;
    int visit;
    int s;
    struct g *link;
}g_t;

typedef struct node{
    int name;
    struct node* next;
}node_t;

node_t* push(node_t* s, int name){
    node_t* tmp = (node_t*)malloc(sizeof(node_t));
    tmp->name = name;
    tmp->next = NULL;
    if(s == NULL){
        s = tmp;
        return s;
    }
    tmp->next = s;
    return tmp;
}

int pop(node_t** s){
    if(*s==NULL){
        return -1;
    }else{
        node_t* tmp = *s;
        *s = (*s)->next;
        int name = tmp->name;
        free(tmp);
        return name;
    }
}

g_t* createnode(int name){
    g_t *tmp = (g_t*)malloc(sizeof(g_t));
    tmp->name = name;
    tmp->visit = 0;
    tmp->s = 0;
    tmp->link = NULL;
    return tmp;
}

g_t** linking(g_t** graph, int n1, int n2){
    g_t* tmp1 = graph[n1];
    while(tmp1->link!=NULL){
        tmp1 = tmp1->link;
    }
    tmp1->link = createnode(n2);
    return graph;
}

void printg(g_t** graph, int n){
    int i;
    for(i=0;i<n;i++){
        printf("node : %d, ",graph[i]->name);
        g_t* tmp = graph[i]->link;
        while(tmp!=NULL){
            printf("link to %d, ",tmp->name);
            tmp = tmp->link;
        }
        printf("\n");
    }
}

void prints(node_t* s){
    while(s!=NULL){
        printf("%d ",s->name);
        s = s->next;
    }
    printf("\n");
}

node_t* dfs(int i,g_t** gp,node_t* fstack){
	//printf("%d ",i);
	gp[i]->visit = 1;
	g_t* tmp = gp[i]->link;
	while(tmp!=NULL){
		if(gp[tmp->name]->visit == 0)	fstack = dfs(tmp->name,gp,fstack);
        tmp = tmp->link;
	}
	fstack = push(fstack,i);
	return fstack;
}

void dfs2(int i,g_t** gp,int group[],int count){
	
	group[count] = i;
	count++;
	
	gp[i]->visit = 1;
	g_t* tmp = gp[i]->link;
	while(tmp!=NULL){
		if(gp[tmp->name]->visit == 0)	dfs2(tmp->name,gp,group,count);
        tmp = tmp->link;
	}
	
	count_g = (count > count_g) ? count : count_g;
}

int main(){
    int n,m,i;
    scanf("%d %d",&n,&m);
    g_t** graph = (g_t**)malloc(sizeof(g_t*)*n);
    g_t** tgraph = (g_t**)malloc(sizeof(g_t*)*n);
    node_t* fstack = NULL;
    node_t* fstack2 = NULL;
    for (i=0;i<n;i++){
        graph[i] = createnode(i);
        tgraph[i] = createnode(i);
    }
    for (i=0;i<m;i++){
        int u,v;
        scanf("%d %d",&u,&v);
        graph = linking(graph,u,v);
        tgraph = linking(tgraph,v,u);
    }
    
    for(int i=0;i<n;i++){
    	if(graph[i]->visit==0)	fstack = dfs(i,graph,fstack);
	}	
	
	/*printf("\n");	
	prints(fstack);
	printf("\n");*/
	
	int group[n+1],ans[n+1];
	
	int n2 = n;
    while(n--){
    	int i = pop(&fstack);
    	if(tgraph[i]->visit==1)	continue;
    	
		count_g=0;
		dfs2(i,tgraph,group,0);
    	
		/*for(int x=0;x<count_g;x++){
    		printf("%d ",group[x]);
		}printf("\n");
		printf("%d\n",count_g);*/
		
		if(count_ans < count_g){
			count_ans = count_g;
			for(int x=0;x<count_g;x++){
	    		ans[x] = group[x];
			}
		}
	}
	for(int x=0;x<count_ans;x++){
    	printf("%d ",ans[x]);
	}printf("\n");
    
    
}

/*
5 5
1 0
2 1
0 2
0 3
3 4

8 9        
0 1
1 2
2 3
2 4
3 0
4 5
5 6
6 4
6 7
*/

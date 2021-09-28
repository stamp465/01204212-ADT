#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tree {
    char word[20];
    int freq;
    struct tree*left;
    struct tree*right;
} tree_t;

typedef tree_t bst_t;

typedef struct heap {
  tree_t* *data;
  int last_index;
} heap_t;

heap_t *init_heap(int m){
  heap_t *new = (heap_t*)malloc(sizeof(heap_t));
  new->data = (tree_t**)malloc(sizeof(tree_t*)*m+3);
  new->last_index = 1;
  return new;
}

tree_t* tmptree(int freq ,char word[]){
tree_t*new = (tree_t*)malloc(sizeof(tree_t));
  new -> right = NULL;
  new -> left = NULL;
  new->freq = freq;
  strcpy(new->word,word);
  return new;
}

void bfs(heap_t *min_heap){
  int i;
  for(i=1;i<min_heap->last_index;i++){
    printf("%d ",min_heap->data[i]->freq);
  }
  printf("\n");
}


void insert(heap_t*min_heap,tree_t*data){
    //bfs(min_heap);
  min_heap->data[min_heap->last_index] = data;
  int current = min_heap->last_index;
  int parent = current/2;
  while(parent != 0){
    if(min_heap->data[current]->freq<min_heap->data[parent]->freq){
      tree_t* tmp = min_heap->data[current];
      min_heap->data[current] = min_heap->data[parent];
      min_heap->data[parent] = tmp;
      current = parent;
      parent = current/2;
    }
    else{
      break;
    }
  }
  min_heap->last_index++;
  // bfs(min_heap);
}

tree_t* delete(heap_t *min_heap){
  if(min_heap->last_index == 1){
    return NULL;
  }
  tree_t* delete_tree = min_heap->data[1];
  min_heap->data[1]=min_heap->data[min_heap->last_index-1];
  min_heap->last_index--;
  if(min_heap->last_index == 1){
    return delete_tree;
  }
  int current = 1;
  int child_1 = current*2;
  int child_2 = current*2+1;
  while(1){
      if(child_1<min_heap->last_index && child_2<min_heap->last_index && min_heap->data[child_2]->freq<min_heap->data[child_1]->freq && min_heap->data[current]->freq>min_heap->data[child_2]->freq)
      {
        tree_t* tmp = min_heap->data[current];
        min_heap->data[current] = min_heap->data[child_2];
        min_heap->data[child_2]=tmp;
        current = child_2;
        child_1 = current*2;
        child_2 = current*2+1;
      }
      else if(child_1<min_heap->last_index && min_heap->data[child_1]->freq<min_heap->data[current]->freq){
        tree_t* tmp = min_heap->data[current];
        min_heap->data[current] = min_heap->data[child_1];
        min_heap->data[child_1]=tmp;
        current = child_1;
        child_1 = current*2;
        child_2 = current*2+1;
        
      }
      else{
        break;
      }
    
  }
  return delete_tree;
}

tree_t* new_tree(tree_t*x ,tree_t*y){
	
tree_t*new = (tree_t*)malloc(sizeof(tree_t));
  new -> left = x ;
  new -> right = y;
  int a ;
  a = x->freq;
  int b ;
  if(y!=NULL)
  	b = y->freq;
  else	b=0;
  printf("%d %d\n",a,b);
  new->freq = x->freq + y->freq;
  return new;
}

void dfs(tree_t *t,int bin[],int location){
    int i =0;
    if(t->right == NULL || t->left == NULL){
        printf("%s" ,t->word);
        for(i=0;i<location;i++){
            printf("%d" ,bin[i]);
        }
        printf("\n");
        return ;
    }
    bin[location]=0;
    dfs(t->left,bin,location+1);
    bin[location]=1;
    dfs(t->right,bin,location+1);
}

int main(void) {
  heap_t *min_heap = NULL;
  tree_t *t_x = NULL;
  tree_t *t_y = NULL;
  tree_t *sum_tree =NULL;
  int    m, i,x;
  
  char word[20];
  scanf("%d " ,&m);
  int ans[m];
  min_heap = init_heap(m*2);
  for(i=0;i<m;i++){
    scanf("%s %d",word ,&x);
    tree_t*new = tmptree(x,word);
    insert(min_heap ,new);
  }
  printf("agshdghh\n");
  int aa=0;
  while(min_heap->last_index >2){
  	  //printf("%d",aa++);
      t_x = delete(min_heap);
      t_y = delete(min_heap);
      /*if(t_y==NULL) {
      	printf("aaa\n");
	  	dfs(t_x,ans,0);
	  	//dfs(t_y,ans,0);
      	break;
	  }*/
	  
      sum_tree = new_tree(t_x,t_y);printf("%d -> ",min_heap->last_index);
      insert(min_heap,sum_tree);
      
      bfs(min_heap);
    }
  //dfs(t_x,ans,0);
  return 0;
}

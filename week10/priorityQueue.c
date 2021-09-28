#include <stdio.h>
#include <stdlib.h>

typedef struct heap {
  int *data;
  int last_index;
} heap_t;

// Write your code here

heap_t* init_heap(int m) {
	heap_t* xxnxx = (heap_t *)malloc(sizeof (heap_t));
	xxnxx->data = (int *)malloc(sizeof (int) * (m+5));
	xxnxx->data[0] = NULL;
	xxnxx->last_index = 1;
	return xxnxx;
}

void bfs(heap_t* xxnxx){
	for(int i=1;i<xxnxx->last_index;i++){
		printf("%d ",-(xxnxx->data[i]));
	}printf("\n");
}

void insert(heap_t* xxnxx, int data){
	data = -data;
	xxnxx->data[xxnxx->last_index] = data;
	int now = xxnxx->last_index;
	xxnxx->last_index++;
	while(1){
		int pa = now/2;
		if(pa==0)	break;
		//printf("be = %d %d\n",now,pa);
		//bfs(xxnxx);
		if( xxnxx->data[pa] > xxnxx->data[now] ){
			int ch;
			ch = xxnxx->data[pa];
			xxnxx->data[pa] = xxnxx->data[now];
			xxnxx->data[now] = ch;
		}
		else	break;
		//printf("af = %d %d\n",now,pa);
		//bfs(xxnxx);
		now = pa;
	}
}

void delete_max(heap_t* xxnxx){
	if(xxnxx->last_index==1)	return ;
	xxnxx->data[1] = xxnxx->data[xxnxx->last_index-1];
	xxnxx->last_index--;
	int now = 1;
	if(xxnxx->last_index<=2)	return ;
	while(1){
		int c2 = now*2+1, c1 = now*2;
		if( c2 < xxnxx->last_index && c1 < xxnxx->last_index && xxnxx->data[now] > xxnxx->data[c2] && xxnxx->data[c2] < xxnxx->data[c1]){
			int ch;
			ch = xxnxx->data[c2];
			xxnxx->data[c2] = xxnxx->data[now];
			xxnxx->data[now] = ch;
			now = c2;
		}
		else if( c1 < xxnxx->last_index && xxnxx->data[now] > xxnxx->data[c1] ){
			int ch;
			ch = xxnxx->data[c1];
			xxnxx->data[c1] = xxnxx->data[now];
			xxnxx->data[now] = ch;
			now = c1;
		}
		else	break;

	}
}

int find_max(heap_t* xxnxx){
	if(xxnxx->last_index==1)	return -1;
	return -xxnxx->data[1];
}

void update_key(heap_t* xxnxx, int old_key, int new_key){
	for(int i=1;i<xxnxx->last_index;i++){
		if(-(xxnxx->data[i]) == old_key){
			xxnxx->data[i] = -new_key;
			int now = i;
			while(1){
				int pa = now/2;
				if(pa==0)	break;
				if( xxnxx->data[pa] > xxnxx->data[now] ){
					int ch;
					ch = xxnxx->data[pa];
					xxnxx->data[pa] = xxnxx->data[now];
					xxnxx->data[now] = ch;
				}
				else	break;
				now = pa;
			}
			if(xxnxx->last_index<=2)	return ;
			while(1){
				int c2 = now*2+1, c1 = now*2;
				if( c2 < xxnxx->last_index && c1 < xxnxx->last_index && xxnxx->data[now] > xxnxx->data[c2] && xxnxx->data[c2] > xxnxx->data[c1]){
					int ch;
					ch = xxnxx->data[c2];
					xxnxx->data[c2] = xxnxx->data[now];
					xxnxx->data[now] = ch;
					now = c2;
				}
				else if( c1 < xxnxx->last_index && xxnxx->data[now] > xxnxx->data[c1] ){
					int ch;
					ch = xxnxx->data[c1];
					xxnxx->data[c1] = xxnxx->data[now];
					xxnxx->data[now] = ch;
					now = c1;
				}
				else	break;
		
			}
			break;
		}
	}
}

// ...

int main(void) {
  heap_t *max_heap = NULL;
  int    m, n, i;
  int    command, data;
  int    old_key, new_key;

  scanf("%d %d", &m, &n);
  max_heap = init_heap(m);
  for (i=0; i<n; i++) {
    scanf("%d", &command);
    switch (command) {
      case 1:
        scanf("%d", &data);
        insert(max_heap, data);
        break;
      case 2:
        delete_max(max_heap);
        break;
      case 3:
        printf("%d\n", find_max(max_heap));
        break;
      case 4:
        scanf("%d %d", &old_key, &new_key);
        update_key(max_heap, old_key,
                   new_key);
        break;
      case 5:
        bfs(max_heap);
        break;
    }
  }
  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <week9.h>

#ifndef __avl_tree__
typedef struct node {
  int    data;
  int    height;
  struct node *left;
  struct node *right;
} node_t;

typedef node_t avl_t;
#endif

// Write your code here
// ** Note that the print_tree() function
// has been implemented already and
// included in the week9.h header

int max(int a,int b){
	return (a>b)? a : b;
}

int height(avl_t* t){
	if(t==NULL)	return -1;
	else		return t->height;
}

avl_t* New_node(int data){
	avl_t* node = (avl_t*)malloc(sizeof(avl_t));
    node->data   = data;
    node->left   = NULL;
    node->right  = NULL;
    node->height = 0;
    return(node);
}

avl_t* right_right(avl_t* t){
	avl_t* a = t;
	avl_t* b = t->left;
	a->left = b->right;//printf("111");
	b->right = a;
	a->height = max( height(a->right), height(a->left) )+1;
	b->height = max( height(b->right), height(b->left) )+1;
	return b;
}

avl_t* left_left(avl_t* t){
	avl_t* a = t;
	avl_t* b = t->right;
	a->right = b->left;
	b->left = a;
	a->height = max( height(a->right), height(a->left) )+1;
	b->height = max( height(b->right), height(b->left) )+1;
	return b;
}

avl_t* insert(avl_t* t, int data){
	
	if(t == NULL){
		return New_node(data);
	}
	else if(t->data > data){
		t->left = insert(t->left,data);
	}
	else if(t->data < data){
		t->right = insert(t->right,data);
	}
	
	t->height = max( height(t->right), height(t->left) )+1;
	//printf("Now = %d h = %d\n",t->data,t->height);
	if( height(t->left) - height(t->right) > 1 ){		
		//printf("data %d case left\n",data);
		if( height(t->left->left) > height(t->left->right) ){
			//printf("right right\n");
			return right_right(t);
		}
		else{
			//printf("left right\n");
			t->left = left_left(t->left);
			return right_right(t);
		}
	}
	if( height(t->right) - height(t->left) > 1 ){	
		//printf("data %d case right\n",data);	
		if( height(t->right->right) > height(t->right->left) ){
			//printf("left left\n");
			return left_left(t);
		}	
		else{
			//printf("right left\n");
			t->right = right_right(t->right);
			//printf("gogo\n");
			return left_left(t);
		}
	}
	return t;
}

int find_min(avl_t* t){
	avl_t* copy_t = t;
	int finded = 0;
	if(t==NULL){
		return finded;
	}
	while(1){
		if(copy_t->left==NULL)	{
			finded = copy_t -> data;
			break;
		}
		copy_t = copy_t->left;
	}
	return finded;
}

avl_t* delete(avl_t* t,int data){
	if(t==NULL){
		return t;
	}
	//printf("Now = %d \n",t->data);
	if(t->data == data){
		if(t->left == NULL) {
			return t->right;
		}
		else if(t->right == NULL){
			return t->left;
		}
		else{
			t->data = find_min(t->right);
			t->right = delete(t->right,t->data);
		}
	}
	else if(t->data > data){
		t->left = delete(t->left,data);
	}
	else{
		t->right = delete(t->right,data);
	}
	
	t->height = max( height(t->right), height(t->left) )+1;
	//printf("Now = %d h = %d\n",t->data,t->height);
	if( height(t->left) - height(t->right) > 1 ){		
		//printf("data %d case left\n",data);
		if( height(t->left->left) > height(t->left->right) ){
			//printf("right right\n");
			return right_right(t);
		}
		else{
			t->left = left_left(t->left);
			return right_right(t);
		}
	}
	if( height(t->right) - height(t->left) > 1 ){	
		//printf("data %d case right\n",data);	
		if( height(t->right->right) > height(t->right->left) ){
			//printf("left left\n");
			return left_left(t);
		}
		else{
			t->right = right_right(t->right);
			return left_left(t);
		}
	}
	return t;
}

// ...

int main(void) {
  avl_t *t = NULL;
  int   n, i;
  int   command, data;

  scanf("%d", &n);
  for (i=0; i<n; i++) {
    scanf("%d", &command);
    switch (command) {
      case 1:
        scanf("%d", &data);
        t = insert(t, data);
        break;
      case 2:
        scanf("%d", &data);
        t = delete(t, data);
        break;
      case 3:
        print_tree(t);
        break;
    }
  }
  return 0;
}

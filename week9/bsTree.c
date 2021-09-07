#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int    data;
  struct node *left;
  struct node *right;
} node_t;

typedef node_t bst_t;

// Write your code here
bst_t* New_node(int data){
	bst_t* node = (bst_t*)malloc(sizeof(bst_t));
    node->data   = data;
    node->left   = NULL;
    node->right  = NULL;
    return(node);
}

bst_t* insert(bst_t* t,int data){
	bst_t* newnode = New_node(data);
	bst_t* copy_t = t;
	if(t==NULL){
		return newnode;
	}
	while(1){
		if(copy_t->data > data){
			if(copy_t->left==NULL)	{
				copy_t->left = newnode;
				break;
			}
			copy_t = copy_t->left;
		}
		else{
			if(copy_t->right==NULL)	{
				copy_t->right = newnode;
				break;
			}
			copy_t = copy_t->right;
		}
	}
	return t;
}

int find(bst_t* t,int data){
	bst_t* copy_t = t;
	int finded = 0;
	if(t==NULL){
		return finded;
	}
	while(1){
		if(copy_t->data == data){
			finded = 1;
			break;
		}
		else if(copy_t->data > data){
			if(copy_t->left==NULL)	{
				break;
			}
			copy_t = copy_t->left;
		}
		else{
			if(copy_t->right==NULL)	{
				break;
			}
			copy_t = copy_t->right;
		}
	}
	return finded;
}

int find_min(bst_t* t){
	bst_t* copy_t = t;
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

int find_max(bst_t* t){
	bst_t* copy_t = t;
	int finded = 0;
	if(t==NULL){
		return finded;
	}
	while(1){
		if(copy_t->right==NULL)	{
			finded = copy_t -> data;
			break;
		}
		copy_t = copy_t->right;
	}
	return finded;
}

bst_t* delete(bst_t* t,int data){
	bst_t* copy_t = t;
	if(t==NULL){
		return t;
	}
	if(copy_t->data == data){
		if(copy_t->left == NULL) {
			return copy_t->right;
		}
		else if(copy_t->right == NULL){
			return copy_t->left;
		}
		else{
			copy_t->data = find_min(copy_t->right);
			copy_t->right = delete(copy_t->right,copy_t->data);
		}
	}
	else if(copy_t->data > data){
		copy_t->left = delete(copy_t->left,data);
	}
	else{
		copy_t->right = delete(copy_t->right,data);
	}
	return t;
}

// ...

int main(void) {
  bst_t *t = NULL;
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
        scanf("%d", &data);
        printf("%d\n", find(t, data));
        break;
      case 4:
        printf("%d\n", find_min(t));
        break;
      case 5:
        printf("%d\n", find_max(t));
        break;
    }
  }
  return 0;
}


/*
13
1 50
1 8
1 61
1 1
1 35
1 87
2 50
3 50
2 8
2 61
3 8
3 87
3 61
*/

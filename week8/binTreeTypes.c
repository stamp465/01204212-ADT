#include <stdio.h>
#include <stdlib.h>
#include <week8.h>

#ifndef __bin_tree__
typedef struct node {
  int    data;
  struct node *left;
  struct node *right;
} node_t;

typedef node_t tree_t;
#endif

// Write your code here
// ** Note that the attach() function has
// been implemented already and included
// in the week8.h header
int power(int a,int p){
	int ans = 1;
	for(int i=0;i<p;i++){
		ans *= a;
	}
	return ans;
}

int height(tree_t *t){
	if(t==NULL)	return -1;
	int hl = height(t->left);
	int hr = height(t->right);
	return (hl>hr)? hl+1 : hr+1;

}

int size(tree_t *t){
	if(t==NULL)	return 0;	
	return size(t->left)+ size(t->right) + 1;

}

int is_full(tree_t *t){
	if(t==NULL)	return 1;
	if(t->left!=NULL&&t->right==NULL)	return 0;
	if(t->left==NULL&&t->right!=NULL)	return 0;
	if(is_full(t->left)==0)		return 0;
	if(is_full(t->right)==0)	return 0;
	return 1;
}

int is_perfect(tree_t *t){
	return ( power(2,height(t)+1)-1 == size(t) );
}

int is_complete2(tree_t *t, int index, int all) {
  if (t == NULL)		return 1;
  if (index >= all)		return 0;
  return (is_complete2(t->left, 2*index+1, all) && is_complete2(t->right, 2*index+2, all));
}

int is_complete(tree_t *t){
	return is_complete2(t,0,size(t));
}

int is_degenerate(tree_t *t){
	if(t==NULL)	return 1;
	if(t->left!=NULL&&t->right!=NULL)	return 0;
	if(is_degenerate(t->left)==0)	return 0;
	if(is_degenerate(t->right)==0)	return 0;
	return 1;
}

int is_skewed(tree_t *t){
	if(t==NULL)	return 1;
	if(t->left!=NULL&&t->left->right!=NULL)		return 0;
	if(t->right!=NULL&&t->right->left!=NULL)	return 0;
	if(is_skewed(t->left)==0)	return 0;
	if(is_skewed(t->right)==0)	return 0;
	return 1;
}
// ...

int main(void) {
  tree_t *t = NULL;
  int n, i;
  int parent, child;
  int branch; // 0 root, 1 left, 2 right

  scanf("%d", &n);
  for (i=0; i<n; i++) {
    scanf("%d %d %d", &parent, &child, &branch);
    t = attach(t, parent, child, branch);
  }

  printf("%d %d %d %d %d\n", is_full(t), is_perfect(t), is_complete(t), is_degenerate(t), is_skewed(t));

  return 0;
}

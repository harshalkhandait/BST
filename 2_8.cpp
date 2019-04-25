#include<iostream>
struct node{
	int key;
	struct node *left, *right;
};
struct node *newNode(int item){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}
void inorder(struct node *root){
	if (root != NULL){
		inorder(root->left);
		printf("%d \n", root->key);
		inorder(root->right);
	}
}
void printRotated(struct node *root, int space){
    // Base case
    if (root == NULL)
        return;
    // Increase distance between levels
    space += 10;
    // Process right child first
    printRotated(root->right, space);
    // Print current node after space
    // count
    printf("\n");
    for (int i = 10; i < space; i++)
        printf(" ");
    printf("%d\n", root->key);
    // Process left child
    printRotated(root->left, space);
}
struct node* insert(struct node* node, int key){
	// If the tree is empty, return a new node
	if (node == NULL) return newNode(key);
	// Otherwise, recurssively down the tree */
	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);
	// return the (unchanged) node pointer
	return node;
}
int main(){
	struct node *root   = newNode(1);
  root->left   = newNode(2);
  root->right  = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);
  root->right->left  = newNode(6);
  root->right->right = newNode(7);
	inorder(root);
	printRotated(root,0);
	return 0;
}

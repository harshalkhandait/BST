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
		std::cout << root->key << '\n';
		inorder(root->right);
	}
}
struct node* insert(struct node* node, int key){
	/* If the tree is empty, return a new node */
	if (node == NULL) return newNode(key);
	/* Otherwise, recurssively down the tree */
	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);
	/* return the (unchanged) node pointer */
	return node;
}
void mirror(struct node* node){
  if (node == NULL){
  return;
  }else{
    struct node* temp;
    mirror(node->left);
    mirror(node->right);
    /* swap the pointers in this node */
    temp	= node->left;
    node->left = node->right;
    node->right = temp;
  }
}
int main(){
	struct node *root1 = NULL;
  int temp,choice=1;
  // Input for first tree
  while (choice) {
    std::cout << "Enter the Element :";
    std::cin >> temp;
    root1 = insert(root1,temp);
    std::cout << "Do you want to enter more elements ?" << '\t';
    std::cin >> choice;
  }
	// print inoder traversal of the BST
	inorder(root1);
  mirror(root1);
  inorder(root1);
	return 0;
}

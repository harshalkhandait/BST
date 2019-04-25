#include <iostream>
using namespace std;
struct node{
	int data;
	struct node* left, *right;
};
int isBSTUtil(struct node* root, node *&prev);
int isBST(node *root);
struct node *newNode(int item);
void inorder(struct node *root);
struct node* insert(struct node* node, int key);
int main(){
	struct node *root = NULL;
  int temp,choice=1;
  // Input for first tree
  //std::cout << "Enter elements of first tree" << '\n';
  while (choice) {
    std::cout << "Enter the Element :";
    std::cin >> temp;
    root = insert(root,temp);
    std::cout << "Do you want to enter more elements ?" << '\t';
    std::cin >> choice;
  }
	// print inoder traversal of the BST
	inorder(root);
  if (isBST(root))
		std::cout << "Given Tree Is BST" << '\n';
	else
		std::cout << "Given Tree Not a BST" << '\n';
	return 0;
}
int isBSTUtil(struct node* root, node *&prev)
{
	// traverse the tree in inorder fashion and
	// keep track of prev node
	if (root)
	{
		if (!isBSTUtil(root->left, prev))
		return 0;

		// Allows only distinct valued nodes
		if (prev != NULL && root->data <= prev->data)
		return 0;

		prev = root;

		return isBSTUtil(root->right, prev);
	}

	return 1;
}

int isBST(node *root){
node *prev = NULL;
return isBSTUtil(root, prev);
}
struct node *newNode(int item){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = item;
	temp->left = temp->right = NULL;
	return temp;
}
void inorder(struct node *root){
	if (root != NULL){
		inorder(root->left);
		printf("%d \n", root->data);
		inorder(root->right);
	}
}
struct node* insert(struct node* node, int key){
	/* If the tree is empty, return a new node */
	if (node == NULL) return newNode(key);
	/* Otherwise, recurssively down the tree */
	if (key < node->data)
		node->left = insert(node->left, key);
	else if (key > node->data)
		node->right = insert(node->right, key);
	/* return the (unchanged) node pointer */
	return node;
}

#include <iostream>
struct node{
	int data;
	struct node* left;
	struct node* right;
};
struct node* newNode(int data) {
  struct node* node = (struct node*)malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;

  return(node);
}
struct node* insert(struct node* node, int key)
{
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
void printPath(struct node *root, int *arr = NULL, int l=0){

	if(root->left == NULL && root->right == NULL){
		for(int i = 0;i<l;i++){
			std::cout<<arr[i]<<"  ->  ";
		}
		std::cout << root->data << "\n";
		return;
	}
	int *arr_new = new int[l+1];
	for(int i = 0;i<l;i++){
		arr_new[i] = arr[i];
	}
	arr_new[l] = root->data;
	if(root->left!=NULL){
		printPath(root->left,arr_new,l+1);
	}
	if(root->right!=NULL){
		printPath(root->right,arr_new,l+1);
	}
}
int main()
{
  struct node *root=NULL;
  int temp,choice=1;
  while (choice) {
    std::cout << "Enter the Element :";
    std::cin >> temp;
    root = insert(root,temp);
    std::cout << "Do you want to enter more elements ?" << '\t';
    std::cin >> choice;
  }
  /* Print all root-to-leaf paths of the input tree */
  printPath(root);
  return 0;
}

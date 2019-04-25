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
	if (root != NULL)
	{
		inorder(root->left);
		printf("%d \n", root->key);
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
int isSame(struct node* root1, struct node* root2) {
    // Check if both the trees are empty
    if (root1 == NULL && root2 == NULL)
        return 1;
    // If any one of the tree is non-empty
    // and other is empty, return false
    else if (root1 != NULL && root2 == NULL){
        return 0;
    }else if (root1 == NULL && root2 != NULL){
        return 0;
			}else {
        if (root1->key == root2->key && isSame(root1->left, root2->left) && isSame(root1->right, root2->right))
            return 1;
        else
            return 0;
    }
}
int main()
{
	struct node *root1 = NULL;
  struct node *root2 = NULL;
  int temp,choice=1;
  // Input for first tree
  std::cout << "Enter elements of first tree" << '\n';
  while (choice) {
    std::cout << "Enter the Element :";
    std::cin >> temp;
    root1 = insert(root1,temp);
    std::cout << "Do you want to enter more elements ?" << '\t';
    std::cin >> choice;
  }
	// print inoder traversal of the BST
	inorder(root1);
  // same process for second tree
  choice=1;
  std::cout << "Enter elements of second tree" << '\n';
  while (choice) {
    std::cout << "Enter the Element :";
    std::cin >> temp;
    root2 = insert(root2,temp);
    std::cout << "Do you want to enter more elements ?" << '\t';
    std::cin >> choice;
  }
  inorder(root2);
  int flag = isSame(root1,root2);
  if (flag) {
    std::cout << "Trees are same" << '\n';
  }else{
    std::cout << "Trees are not same" << '\n';
  }
	return 0;
}

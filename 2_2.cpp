#include<iostream>
struct node
{
	int key;
	struct node *left, *right;
};
struct node *newNode(int item)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}
void inorder(struct node *root)
{
	if (root != NULL)
	{
		inorder(root->left);
		printf("%d \n", root->key);
		inorder(root->right);
	}
}
struct node* insert(struct node* node, int key)
{
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
int isStructurallySame(struct node* a,struct node* b)
{
    // 1. both empty
    if (a==NULL && b==NULL)
        return 1;
    // 2. both non-empty -> compare them
    if (a!=NULL && b!=NULL)
        return(isStructurallySame(a->left, b->left) && isStructurallySame(a->right, b->right));
    // 3. one empty, one not -> false
    return 0;
}
int main(){
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
  int flag = isStructurallySame(root1,root2);
  if (flag) {
    std::cout << "Trees are Structurally same" << '\n';
  }else{
    std::cout << "Trees are not Structurally same" << '\n';
  }
	return 0;
}

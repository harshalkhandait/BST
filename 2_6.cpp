
#include<iostream>
using namespace std;
struct node{
    int data;
    struct node *left,*right;
};
struct node* newnode(int data){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
};
struct node* insert(struct node* root,int data){
    if(root == NULL)
        return newnode(data);
    if(data < root->data)
        root->left = insert(root->left, data);
    else if(data > root->data)
        root->right = insert(root->right, data);
    return root;
};
void inorder(struct node* root){
	if(root == NULL){
		return;
	}
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
int sumPossible(struct node *root,int sum){
	if(root==NULL){
		if(sum==0){
			return true;
		}
		return false;
	}
	sum = sum - root->data;
	return sumPossible(root->left,sum) || sumPossible(root->right,sum);
}
int main(){
    struct node *root = NULL;
    root = insert(root,91);
	  root = insert(root,88);
    root = insert(root,71);
    root = insert(root,01);
    root = insert(root,54);
    root = insert(root,75);
    if(sumPossible(root,55))//argument passed tree and value
        cout<<"Sum Possible\n";
    else
        cout<<"Sum not possible\n";
}

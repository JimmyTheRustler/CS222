#include <iostream>
using namespace std;

struct TreeNode
{
	int value;
	TreeNode* left;
	TreeNode* right;
};

void insert(TreeNode* &root, int data)
{
	if( root == NULL )
	{
		root = new TreeNode();
		root -> value = data;
		root -> left = NULL;
		root -> right = NULL;
	}
	else if( data < root -> value )
	{
		insert(root -> left, data);
	}
	else if( data > root -> value )
	{
		insert(root -> right);
	}
}

void inorder(TreeNode* root){
	
	if(root != NULL){
		inorder(root -> left);
		cout << root -> value << endl;
		inorder(root -> right);
		//cout << root-> value << endl;
	}
}

void cleanUp(TreeNode* &root){
	
	if(root != NULL){
		cleanUp(root->left);
		cleanUp(root->right);
		delete root;
		root = NULL;	
	}
}

int main()
{
	int numbers;
	int add;
	cout << "How many numbers do you want? ";
	cin >> numbers >> endl;
	
	for(int i = 0; i < numbers; i++)
	{
		cout << "Enter number " << i+1 << ": ";
		cin >> add >> endl;
		insert(root, add);
		
	}

	return 0;
}



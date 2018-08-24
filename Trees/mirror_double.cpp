//program to find mirror and doubling on a bst
#include<bits/stdc++.h>
using namespace std;
struct tree{
	int num;
	tree* left;
	tree* right;
};
tree* create_node(int num){
	tree* newnode=new tree;
	newnode->left=newnode->right=NULL;
	newnode->num=num;
	return newnode;
}
void insert_node(tree** root,int num){
	if(*root==NULL){
		*root=create_node(num);
	}
	else{
		if(num>(*root)->num)
			insert_node((&(*root)->right),num);
		else
			insert_node((&(*root)->left),num);
	}
}
void preorder(tree* root){
	if(root==NULL)
		return;
		cout<<root->num<<" ";
		preorder(root->left);
		preorder(root->right);
	
}
void postorder(tree* root){
	if(root==NULL)
		return ;
		postorder(root->left);
		postorder(root->right);
		cout<<root->num<<" ";
	
}
void inorder(tree* root){
	if(root==NULL)
		return ;
		inorder(root->left);
		cout<<root->num<<" ";
		inorder(root->right);
	
}
void double_tree(tree** root){
	tree* oldleft;
	if(*root==NULL)
		return ;
	double_tree(&(*root)->left);
	double_tree(&(*root)->right);

	oldleft=(*root)->left;
	(*root)->left=create_node((*root)->num);
	(*root)->left->left=oldleft;
}
void mirror_tree(tree** root){
	tree* oldleft;
	if(*root==NULL)
		return ;
	mirror_tree(&(*root)->left);
	mirror_tree(&(*root)->right);

	oldleft=(*root)->left;
	(*root)->left=(*root)->right;
	(*root)->right=oldleft;
}

int main(){
	tree* root=NULL;int choice=3;int num;
	while(choice!=7){
		cout<<"\n1.insert ";
		cout<<"\n2.preorder ";
		cout<<"\n3.postorder ";
		cout<<"\n4.inorder ";
		cout<<"\n5.mirror tree";
		cout<<"\n6.double tree";
		cout<<"\n7.Exit ";
		cout<<"\n\nEnter the choice ";
		cin>>choice;
		switch(choice){
			case 1:cout<<"\n\nEnter the number ";cin>>num;
			insert_node(&root,num);break;
			case 2:preorder(root);break;
			case 3:postorder(root);break;
			case 4:inorder(root);break;
			case 5:mirror_tree(&root);break;
			case 6:double_tree(&root);break;
			case 7:cout<<"\n\nThe program is exiting .........";return 0;break;
			default:cout<<"\n\nEnter the valid choice !!!!!!!!";break;
		}
	}
	return 0;
}
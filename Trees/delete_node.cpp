//program to delete a node from a bst
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
void inorder(tree* root){
	if(root==NULL)
		return ;
		inorder(root->left);
		cout<<root->num<<" ";
		inorder(root->right);
	
}
tree* minValue(tree* root){
	while(root->left!=NULL){
		root=root->left;
	}
	return root;
}
tree* delete_node(tree* root,int num){
	if(root==NULL)
		return root;
	if(root->num>num){
		root->left=delete_node(root->left,num);
	}
	else if(root->num<num){
		root->right=delete_node(root->right,num);
	}
	else{
		if(root->left==NULL){
			tree* temp=root->right;
			free(root);
			return temp;
		}
		else if(root->right==NULL){
			tree* temp=root->left;
			free(root);
			return temp;
		}
		tree* temp=minValue(root->right);
		root->num=temp->num;
		root->right=delete_node(root->right,temp->num);
	}
	return root;
}
int main(){
	tree* root=NULL;int choice=3;int num;
	while(choice!=4){
		cout<<"\n1.insert ";
		cout<<"\n2.inorder ";
		cout<<"\n3.delete node ";
		cout<<"\n4.Exit ";
		cout<<"\n\nEnter the choice ";
		cin>>choice;
		switch(choice){
			case 1:cout<<"\n\nEnter the number ";cin>>num;
			insert_node(&root,num);break;
			case 2:inorder(root);break;
			case 3:cout<<"\nEnter the number to delete ";cin>>num;
				root=delete_node(root,num);break;
			case 4:cout<<"\n\nThe program is exiting .........";return 0;break;
			default:cout<<"\n\nEnter the valid choice !!!!!!!!";break;
		}
	}
	return 0;
}
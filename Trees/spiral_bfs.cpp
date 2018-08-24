//program to perform breadth first search in a bst
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
int height(tree* root){
	if(root==NULL)
		return 0;
	else{
		int lheight=height(root->left);
		int rheight=height(root->right);
	if(lheight>rheight)
		return lheight+1;
	else
		return rheight+1;
}
}
void PrintGivenLevel(tree* root,int level,bool ltr){
	if(root==NULL)
		return;
	if(level==1)
		cout<<root->num<<" ";
	else if(level>1){
		if(ltr){
			PrintGivenLevel(root->left,level-1,ltr);
			PrintGivenLevel(root->right,level-1,ltr);
		}
		else{
			PrintGivenLevel(root->right,level-1,ltr);
			PrintGivenLevel(root->left,level-1,ltr);
		}
	}
}
void spiral(tree* root){
	int ht=height(root);
	bool ltr=false;
	for(int i=1;i<=ht;i++){
		PrintGivenLevel(root,i,ltr);
		ltr=!ltr;
	}
}
int main(){
	tree* root=NULL;int choice=1;int num;
	while(choice!=3){
		cout<<"\n1.insert ";
		cout<<"\n2.Spiral traverse ";
		cout<<"\n3.Exit ";
		cout<<"\n\nEnter the choice ";
		cin>>choice;
		switch(choice){
			case 1:cout<<"\n\nEnter the number ";cin>>num;
			insert_node(&root,num);break;
			case 2:spiral(root);break;
			case 3:cout<<"\n\nThe program is exiting .........";return 0;break;
			default:cout<<"\n\nEnter the valid choice !!!!!!!!";break;
		}
	}
	return 0;
}
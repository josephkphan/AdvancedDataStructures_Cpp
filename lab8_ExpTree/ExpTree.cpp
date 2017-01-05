#include"ExpTree.h"
#include<stdlib.h>
#include<iostream>
#include<stack>
#include<string>
#include<sstream>
using namespace std;


int ExpTree::evaluate(){
		evaluate_rec(root);	
}
int ExpTree::evaluate_rec(Node * node){
	if (node == NULL )
		return 0;
	if (node->op == '0')
		return 0;
	evaluate_rec(node->left);
	evaluate_rec(node->right);
	switch(node->op){
		case '+':
			node ->value = node->left->value + node->right->value;
			break;

		case '-':
			node ->value = node->left->value - node->right->value;
			break;

		case '*':
			node ->value = node->left->value * node->right->value;
			break;

		case '/':
			node ->value = node->left->value / node->right->value;
			break;

	}	
			cout<<endl<<node->left->value<< " ";
			cout<<node->right->value<< " ";
			cout<<node->value<<endl;
	return node->value;
	
}

ExpTree::ExpTree(){
	root = NULL;
}

ExpTree::~ExpTree(){
	deleteTree(root);
}

void ExpTree::deleteTree(Node* node){
  if(node == NULL)
		return;	
	deleteTree(node->left);
	deleteTree(node->right);
	delete node;    

}

void ExpTree::print_inorder_rec(Node* node){
    if(node == NULL)
		return;	
	print_inorder_rec(node->left);
	node->print();
	print_inorder_rec(node->right);                                                                    
}

void ExpTree::print_preorder_rec(Node* node){
  if(node == NULL)
		return;	
	node->print();
	print_preorder_rec(node->left);
	print_preorder_rec(node->right);    
}

void ExpTree::print_postorder_rec(Node* node){
  if(node == NULL)
		return;	
	print_postorder_rec(node->left);
	print_postorder_rec(node->right);    
	node->print();
}

void ExpTree::print_inorder(){
	print_inorder_rec(root);
}

void ExpTree::print_preorder(){
	print_preorder_rec(root);
}

void ExpTree::print_postorder(){
	print_postorder_rec(root);
}

void ExpTree::build(){
	stack <Node*> s;
	int v;
	string expr;
	Node* x1,x2;
	Node* n;
	string token;
	getline(cin,expr);
	istringstream stream(expr);
	while(stream>>token){
		//operate on token
		if(token.compare("+")==0){
			Node * temp = new Node();
			temp->value = -1;
			temp->op = '+';
			temp->right = s.top();
			s.pop();
			temp->left = s.top();
			s.pop();
			s.push(temp);
			root = s.top();
		}else if(token.compare("-")==0){
			Node * temp = new Node();
			temp->value = -1;
			temp->op = '-';
			temp->right = s.top();
			s.pop();
			temp->left = s.top();
			s.pop();
			s.push(temp);
			root = s.top();
			
		}else if(token.compare("*")==0){
			Node * temp = new Node();
			temp->value = -1;
			temp->op = '*';
			temp->right = s.top();
			s.pop();
			temp->left = s.top();
			s.pop();
			s.push(temp);
			root = s.top();

		}else if(token.compare("/")==0){
			Node * temp = new Node();
			temp->value = -1;
			temp->op = '/';
			temp->right = s.top();
			s.pop();
			temp->left = s.top();
			s.pop();
			s.push(temp);
			root = s.top();

		}else{ //number
			v = atof(token.c_str());
			s.push(new Node(v,'0',NULL,NULL));
			root = s.top();
		}
	}
}



#include<string>
#include<iostream>
using namespace std;
class ExpTree{
	private:
		struct Node{
			int value;
			char op;
			Node* left, *right;
			Node(){
				value = 0;
				op = '0';
				left = right = NULL;
			}
			Node(int v, char o, Node*r, Node*l){
				value = v;
				op = o;
				left = l;
				right = r;
				
			}
			void print(){
				if(op!='0')
					cout<<op<<" ";
				else
					cout<<value<<" ";
			}   
			//friend ostream& operator<< (ostream &out, const Node& other){
			/*
			Node& operator=(const Node& node){
				this->value = node.value;
				this->op = node.op;
				this->left = node.left;
				this->right = node.right;
				return *this;
			}
*/	
		};

		Node* root;	
		void print_inorder_rec(Node*);
		void print_preorder_rec(Node*);
		void print_postorder_rec(Node*);
		void deleteTree(Node*);
		int evaluate_rec(Node*);
	public:
		ExpTree();
		~ExpTree();
		void print_inorder();
		void print_preorder();
		void print_postorder();

		void build();
		int evaluate();

};

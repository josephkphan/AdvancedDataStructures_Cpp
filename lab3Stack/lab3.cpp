/* Lab 3: Stack
 *Partners: Nicholas Thompson and Joseph Phan
 */

#include<iostream>
#include<sstream>
#include<stdlib.h>
#include<assert.h>
#include<string>
using namespace std;

struct Node{
	double data;
	Node *next;
};

class Stack{
	public:
		//Constructor;
		Stack();
		~Stack();
		//Operators

		//Mutators
		void push(double);
		double pop();
	
		//Const functions
		double top();	
	
	private:
		Node *head; 
		int size;
};
Stack::Stack(){
	size = 0;
	head = new Node();
	head->data = 0;
	head->next = NULL;
}
Stack::~Stack(){
	while(size!=0)
		pop();
}
void Stack::push(double x){
	Node *tmp = new Node();
	tmp->data = x;
	tmp->next = this->head;
	this->head = tmp;
	size++;	
}
double Stack::top(){
	return head->data;
}
double Stack::pop(){
	assert(size>0);
	double x = top();
	Node * tmp = head;
	head= head->next;
	delete tmp;
	size--;
	return x;
}

int main(){
	Stack s;
	double x1,x2;
	string expr, token;
	getline(cin,expr);
	istringstream stream(expr);
	while(stream>>token){
		//operate on token
		if(token.compare("+")==0){
			x1 = s.pop();
			x2 = s.pop();
			s.push(x1+x2);
		}else if(token.compare("-")==0){
			x1 = s.pop();
			x2 = s.pop();
			s.push(x2-x1);
			
		}else if(token.compare("*")==0){
			x1 = s.pop();
			x2 = s.pop();
			s.push(x1*x2);

		}else if(token.compare("/")==0){
			x1 = s.pop();
			x2 = s.pop();
			s.push(x2/x1);

		}else{ //number
			x1 = atof(token.c_str());
			s.push(x1);
		}
	}
	cout<<"Final Value: "<<s.top()<<endl;
	return 0;
}

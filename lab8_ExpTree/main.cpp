#include"ExpTree.h"
#include<iostream>
#include<string>

using namespace std;

int main(){

	ExpTree test;
	test.build();	
	test.print_inorder();
	cout<<endl;	
	test.print_postorder();	
	cout<<endl<<test.evaluate()<<endl;
	return 0;
}

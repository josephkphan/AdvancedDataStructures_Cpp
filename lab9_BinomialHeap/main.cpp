#include<iostream>
#include<vector>
#include "BinomialHeap.h"
#include<time.h>
int main(){
	clock_t t;
	BinomialHeap<int> test;
	test.push(3);
	test.push(5);
	test.push(1);
	test.push(7);
	test.push(9);
	test.pop();	
	test.pop();	
	test.pop();	
	cout<<"Push 3,5,1,7,9 and pop 3 times"<<test.top()<<endl;
	BinomialHeap<int> test2;
	test2=test;
	cout<<"Top after assignment"<<test2.top()<<endl;
	cout<<"Size:"<<test2.size()<<endl;

	cout<<endl<<"Benchmark, ran function 10,000 times"<<endl;
	t=clock();
	for(int i=0; i<10000; i++)
		test.top();
	cout<<"Time took to top "<< ((float)((clock() - t)))/ CLOCKS_PER_SEC<<endl;

	t=clock();
	for(int i=0; i<10000; i++)
		test.size();
	cout<<"Time took to size "<< ((float)((clock() - t)))/ CLOCKS_PER_SEC<<endl;

	t=clock();
	for(int i=0; i<10000; i++)
		test.push(9);
	cout<<"Time took to push "<< ((float)((clock() - t)))/ CLOCKS_PER_SEC<<endl;

	t=clock();
	for(int i=0; i<10000; i++)
		test.pop();
	cout<<"Time took to pop "<< ((float)((clock() - t)))/ CLOCKS_PER_SEC<<endl;
	
	return 0;
}

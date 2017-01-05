/* Lab Partners:
 * File Name: Lab4.cpp
 * Lab time: Tuesday 9:15
 */

#include<cstdlib>
#include<iostream>
#include"queue.h"
using namespace std;

int main(){
	Queue Q;
	Q.enqueue(6);
	Q.enqueue(4);
	Q.enqueue(2);
	Q.enqueue(3);
	Q.enqueue(8);
	Queue Q2(Q);
	while(!Q.isEmpty())	
		cout<<Q.dequeue()<<endl;
	while(!Q2.isEmpty())	
		cout<<Q2.dequeue()<<endl;
	return 0;
}

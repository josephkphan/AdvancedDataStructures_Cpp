/* Lab Partners:
 * File Name: queue.cpp
 * Lab time: Tuesday 9:15
 */
#include<iostream>
#include<cstdlib>
#include"queue.h"
Queue::Queue(){
	head = NULL;
}

Queue::Queue(const Queue& Q){
	head=NULL;
	Node* tmp = Q.head;
	while(tmp!= NULL){
		enqueue(tmp->data);
		tmp = tmp->next;
	}
}

Queue::~Queue(){
	while(!isEmpty())
		dequeue();
}

void Queue::enqueue(int x){
	//case 1
	if(isEmpty()){
		head = new Node(x, NULL);
		return;
	}
	//case 2
	if(head->data < x){
		Node* n = new Node(x, head);
		head = n;
		return;
	}
	//case 3 after head
	Node* tmp = head;
	while((tmp->next != NULL) && (tmp->next->data >=x))
		tmp = tmp->next;
	Node* n = new Node(x,tmp->next);
	tmp->next = n;
}

int Queue::dequeue(){
	if(isEmpty()){
		//queue was empty
		return -9999;
	}
	Node* tmp = head;
	int value = head->data;
	head = head->next;
	delete tmp;
	return value;
}

bool Queue::isEmpty(){
	if(head==NULL)
		return true;
	else
		return false;	
}

/* Lab Partners:
 * File Name: queue.h
 * Lab time: Tuesday 9:15
 */

class Queue{
	private:
		struct Node{
			Node* next;
			int data;
			Node(int d, Node* n){
				data = d;
				next = n;
			}
		};
		Node* head;	
	public:
		Queue();
		Queue(const Queue& Q);
		~Queue();
		void enqueue(int);
		int dequeue();
		bool isEmpty();
};


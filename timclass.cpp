/*Created by Joseph Phan
File Name: timclass.cpp
File Description: Models time data type using class
Practicingdealing with objects
*/

#include<iostream>
using namespace std;

class time{
	private:
		int hrs;
		int mins;
		int secs;
	public:
		time(){} //constructor
		time(int h, int m, int s){ hrs=h; mins=m; secs=s; } //constructor w/ initalizing time
		void gettime(){ //gets time from user
			char dummy;
			cout<<"\n Enter time(format 8:50:29):";
			cin>>hrs>>dummy>>mins>>dummy>>secs;
		}
		void disptime(){ cout<<hrs<<":"<<mins<<":"<<secs; }
};

int main(int argc, char **argv){
	time t1; //creates a time 
	time t2(12,29,59);
	
	cout<<"\nTime number 1:";
	t1.gettime();
	
	cout<<"\nTime number 1: ";
	t1.disptime();
	cout<<"\nTime number2: ";
	t2.disptime();

	return 0;	
}

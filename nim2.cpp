/*Created by Joseph Phan
File Name: Nim 2
further practice with classes
*/
#include<iostream>
using namespace std;

class nim{
	private:
		int sticks;

	public:
		nim(){sticks = 13;}
		void userMove(){//user input and removes user selected amount of sticks
			int user;
			cout<<"There are " << sticks << " sticks remaining.";
			cout<<"\nYou can take 1, 2, or 3 sticks. How many do you want to take?\n";
			cin>> user;
			sticks -= user;
		}
		int cpuMove(){//cpu move and removes calculated amount of sticks
			int cpu = (sticks+3)%4; // calculates cpu move
			cout<<"\nThere are" << sticks << "sticks remaining.";
			cout<<"\nI'll take"<<cpu<<"stick(s)";		
			sticks -= cpu;
			return sticks;	
		}
};

int main(){
	nim n;
	do{
		n.userMove();
	}while(n.cpuMove()!=1);//quits if 1 stick is left
	cout<<"\nThere is 1 stick left, and you must take it.\nYou Lose\n";
	return 0;
}

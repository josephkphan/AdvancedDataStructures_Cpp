//Created by Joseph Phan
//first C++ file created
//File Name: Nim.cpp
#include<iostream>
using namespace std;

int main(){
	int sticks = 13;
	int user, cpu;

	do{
		cout<<"\nThere are " << sticks << " sticks remaining.";
		cout<<"\nYou can take 1, 2, or 3 sticks. How many do you want to take?\n";
		cin>> user;

		//Calculation
		sticks -= user;
		cpu = 4 - user;
		cout<<"\nThere are" << sticks << "sticks remaining.";
		cout<<"\nI'll take"<<cpu<<"stick(s)";		
		sticks -= cpu;
	}while(sticks!=1);
	cout<<"\nThere is 1 stick left, and you must take it.\nYou Lose\n";
	return 0;
}

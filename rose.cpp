//Created by Joseph phan
//Rose.cpp
//practicing using enum data type and switch

#include<iostream>
using namespace std;

enum rose { N=0, NE=45, E=90, SE=135, S=180, SW=225, W=270, NW=315 };

int main(){
	int degrees = 0;

	while( degrees >=0 ){
		cout <<"\nEnter a course in degrees: \n";
		cin >> degrees;
		cout << "Course is ";

		switch(degrees){
		case N: cout<<"N"; break;
		case NE: cout<<"NE"; break;
		case E: cout<<"E"; break;
		case SE: cout<<"SE"; break;
		case S: cout<<"S"; break;
		case SW: cout<<"SW"; break;
		case W: cout<<"W"; break;
		case NW: cout<<"NW"; break;
		default: cout<<degrees<<" degrees";

		}
	}	
	return 0;
}

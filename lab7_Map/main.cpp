//main.cpp
#include"Map.h"
#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

int main(){
	Map<int,int> M;
	M.insert(1,100);
	M.insert(2,200);
	cout<<M.value_of(1)<<endl;
	cout<<M.value_of(2)<<endl;
	cout<<M.value_of(3)<<endl;
	cout<<"printing: "<<M<<endl;
	M.remove_key(2);
	cout<<M.value_of(2)<<endl;
	cout<<"printing: "<<M<<endl;

	return 0;
}

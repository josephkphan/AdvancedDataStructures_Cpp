#include<stdio.h>
#include<stdlib.h>
void AddBinary(int a[8], int b[8], int c[8]) { //c = a+b
	int i, temp;
	int carry = 0;
	for (i=7; i>=0; i--) {
		temp = a[i] + b[i] + carry;
		if (temp >=2){
			carry = 1;
			temp = temp-2;
		}else{
			carry = 0;
		}
		c[i] = temp;
	}

}

void SubBinary(int a[8], int b[8], int c[8]) {// c = a - b
	int i, temp;
	int carry = 0;
	for(i=7; i>=0; i--){
		temp = a[i] - b[i] - carry;
		if (temp <0){
			c[i] = 1;
			carry = 1;
		}else{
			c[i] = temp;
			carry = 0;
		}
	}
}

int main() {
	int i;
	int a[8] = {0,1,0,1,0,1,1,0 };
	int b[8] = {0,0,1,0,1,0,1,0 };
	int c[8];
	AddBinary(a, b, c);
	printf("\n");
	for (i=0; i<8; i++){
		printf("%d", c[i]);
	}
	printf("\n");
	SubBinary(a,b,c); 
	for (i=0; i<8; i++){
		printf("%d", c[i]);
	} 
	printf("\n");
	return 0;
}

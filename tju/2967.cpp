#include <iostream>
#include <cstdio>

using namespace std;

void triangle(int n){
	int k=1;
	for(int i=0;i<n;i++){
		for(int j=n;j>i+1;j--)
			printf(" ");
		for(int x=0;x<k;x++)
			printf("*");
		printf("\n");
		k+=2;	
	}

}

void parallelogram(int w, int h){
	for(int i=h;i>0;i--){
		for(int j=0;j+1<i;j++)
			printf(" ");
		for(int j=0;j<w;j++)
			printf("*");
		printf("\n");	
	}

}

void rectangle(int w, int h){
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++)
			printf("*");
		printf("\n");
	}

}

int C,A,B;

int main(){
	while(cin>>C){
		if(C==-1)break;
		switch(C){
			case 1:
				cin>>A;
				triangle(A);
				break;
			case 2:
				cin>>A>>B;
				parallelogram(A,B);
				break;
			case 3:
				cin>>A>>B;
				rectangle(A,B);
				break;	
		}
		printf("\n");	
	}
	return 0;

}

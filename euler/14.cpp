#include <iostream>
#include <cstring>

using namespace std;

int main(){
	long long a,b,d=0,R;
	for(int i=1;i<1000000;i++){		
		for(a=i,b=0;a!=1;b++){
			if(a&1)
				a=a*3+1;
			else
				a=a/2;		
		}
		if(b>d){
			R=i;
			d=b;
		}	
	}
	cout<<R<<endl;
}

#include <iostream>
#include <cmath>

using namespace std;

long long N,Z,A;
bool ok;
int main(){	
	cin>>N;
	ok=N>=1?1:0;
	A=ok?N:-1*N;
	Z=(A*(A+1))/2;
	if(!ok){
		Z--;
		Z*=-1;
	}
	cout<<Z<<endl;
	return 0;
}

#include <iostream>
#include <cmath>
using namespace std;
int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n=1000000000;
	while(cin>>n){
		double div=sqrt(n);
		int nd=(int)div;
		if((div-nd)==0)
			cout <<nd<<endl;			
		else
			cout <<"XXX"<<endl;		
	}	
}

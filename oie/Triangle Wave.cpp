#include <iostream>
#include <cmath>
using namespace std;
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int a,b,c;
	string m[10];
	for(int i=1;i<=9;i++)
		m[i]=string(i,i-1+'1');
	string line="";
	cin>>a;
	for(int j=0;j<a;j++){
		cin>>b>>c;
		for(int i=0;i<c;i++){
			int x=1;
			bool back=false;
			for(int j=1;j<b*2;j++){
				cout<<m[x]<<endl; 
				if(x==b)
					back=true;
				if(back)
					x--;
				else
					x++;
			}
			if(b || c)
				cout<<endl;
		}
	}
	return 0;
}

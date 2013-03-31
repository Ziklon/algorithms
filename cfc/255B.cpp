#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <map>
using namespace std;

typedef long long ll;

int main(){
	ios::sync_with_stdio(false);
	string cad;
	cin>>cad;
	map<char,int>M;
	for(int i=0;i<cad.size();i++)M[cad[i]]++;
	
	int xx=M['x'];
	int yy=M['y'];
	int ans=max(xx,yy)-min(xx,yy);
	
	if(max(xx,yy)==M['x'])
		cout<<string(ans,'x')<<endl;
	else
		cout<<string(ans,'y')<<endl;
			
	return 0;
}

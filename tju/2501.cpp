#include <iostream>
#include <cstdio>

using namespace std;

string line;
int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n;
	cin>>n;
	while(n--){
		cin>>line;
///		if(line=="#")break;
		long long dev=0;
		int c=0;
		for(int i=0;i<line.size();i++){
			if(line[i]=='X')c=0;
			else{
				dev+=++c;
			}
		}
		cout<<dev<<endl;

	}
	return 0;
}
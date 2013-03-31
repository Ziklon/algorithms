#include <iostream>
#include <cstdio>

using namespace std;

string line;
int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	while(getline(cin,line)){
		if(line=="#")break;
		long long dev=0;
		for(int i=0;i<line.size();i++){
			if(isalpha(line[i]))
			    dev+=(line[i]-'A'+1)*(i+1);
		}
		cout<<dev<<endl;

	}
}
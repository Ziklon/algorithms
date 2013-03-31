#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
string url;

string port[]={"http","ftp"};
string other;

int main(){
	ios::sync_with_stdio(0);
	cin>>url;
	
	for(int i=0;i<2;i++){
		string sub=port[i];
		if(url.find(sub)==0){
			url=url.substr(sub.size());
			other=url.substr(1);
			int index=other.find("ru")+1;		
			if(index>=1){
				cout<<sub<<"://"<<url.substr(0,index)<<".ru";
				url=url.substr(index+2);
				if(url.size()>0)cout<<"/"<<url<<endl;
				
				cout<<endl;
				break;
			}			
		}
	}
	
	return 0;
}

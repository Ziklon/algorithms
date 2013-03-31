#include <iostream>
#include <cstdio>
#include <fstream>
using namespace std;

int main(){
	//freopen("in.txt","r",stdin);
	int num=0;
	string line;
	bool ok=1;
	while(ok){
		int low=1;
		int hih=10;
		bool ans=1;
		while(1){
			cin>>num;
			getline(cin,line);
			if(num==0){
				ok=0;
				break;
			}
			getline(cin,line);
			if(line=="right on"){
				if(num<low || num>hih)ans=0;
				break;
			}
			line=line.substr(4);
			if(line=="low"){
				low=num+1;
			}else{
				hih=num-1;
			}
			ans=ans&(hih>=low);
		}
		if(ok){
			if(!ans)cout<<"Stan is dishonest"<<endl;
			else cout<<"Stan may be honest"<<endl;
		}
	}
	return 0;

}
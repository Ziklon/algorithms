#include <iostream>
#include <cmath>
#include <sstream>
using namespace std;
int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	string line="aa";
	while(line.size()>0){
		getline(cin,line);
		if(line.size()>0){
			long num=0;
			bool ok=false;
			for(int i=0;i<line.size();i++){
				if(isalpha(line[i]) && !ok){
					ok=true;
				}
				if(!isalpha(line[i]) && ok){
					ok=false;
					num++;
				} 					
			}
			cout <<num<<endl;
		}
	}
	return 0;
}

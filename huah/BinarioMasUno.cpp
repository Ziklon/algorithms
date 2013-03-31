#include <iostream>
#include <vector>
using namespace std;
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	string line="";
	int caso=1;
	while(getline(cin,line)){
		for(int i=line.size()-1;i>=0;i--){
			if(line[i]=='0'){
				line[i]='1';
				break;
			}else
				line[i]='0';
		}
		if(line.find("1")==string::npos)
			line=string(1,'1')+line;
		printf("Caso #%d: %s\n",caso++,line.c_str());	
	}
}

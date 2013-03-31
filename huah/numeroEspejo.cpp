#include <iostream>
#include <vector>
using namespace std;

int mult(string s){
	int r=1;
	for(int i=0;i<s.size();i++)
		r*=(s[i]-'0');
	return r;
}
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	string line="";
	int caso=1;
	while(cin>>line){
		string rpt="NO";
		for(int i=1;i<line.size();i++){
			 string s1="",s2="";
			 s1=line.substr(0,i);
			 s2=line.substr(i,line.size()-i);
			 if(mult(s1)==mult(s2)){
			 	rpt="YES";
			 	break;
			 }
		}
		printf("Caso #%d: %s\n",caso,rpt.c_str());
		caso++;	
	}
}

#include <iostream>
#include <sstream>
using namespace std;
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	string line="";
	getline(cin,line);
	for(int i=1;line!="";i++){		
		istringstream is(line);
		int pos=0,num,val=0;
		for(int j=0;is>>num;j++){
			if(num>val){
				val=num;
				pos=j;
			}
		}
		printf("Caso #%d: %d\n",i,pos);
		getline(cin,line);
	}
}

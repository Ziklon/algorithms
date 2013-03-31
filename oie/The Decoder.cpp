#include <iostream>
#include <cmath>
using namespace std;
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	string line="aa";
	while(line.size()>0){
		getline(cin,line);
		if(line.size()>0){
			for(int i=0;i<line.size();i++)
				line[i]=line[i]-7;
			
			cout << line<<endl;
		}
	}
	return 0;
}

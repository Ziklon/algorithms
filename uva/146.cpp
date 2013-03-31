#include <iostream>
#include <algorithm>

using namespace std;
string line;
int main(){
	while(cin>>line){
		if(line=="#")break;
		if(next_permutation(line.begin(),line.end()))
			cout<<line<<endl;
		else
			cout<<"No Successor"<<endl;
	}
	return 0;
}

#include <iostream>
using namespace std;
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	string s="aa"; 	
	while(getline(cin,s)){
		if(s.size()==0){
			cout<<endl;
			continue;
		}
		long long ns=0;
		for(long long i=0;i<s.size();i++){
			if(isdigit(s[i]))
				ns+=s[i]-'0';
			else 		 
				if(s[i]=='!')
					cout<<endl;
				else{
					if(s[i]=='b')
						cout << string(ns,' ');
					else
						cout << string(ns,s[i]);
					ns=0;
				}		
		}
		cout<<endl;
	}
	return 0;
}

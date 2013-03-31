#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int N;
string s;

string complete(string cur){
	while(cur.size()<4)cur="0"+cur;
	return cur;
}

vector<string> parse(string s){
	int ubi=0;
	vector<string> ans;
	s=s+":";
	for(int i=0;i<s.size();i++){
		if(s[i]==':'){
			if(ubi==i){
				ubi=i;
				continue;
			}
			string tmp=s.substr(ubi,i-ubi);			
			tmp=complete(tmp);				
			ans.push_back(tmp);
			ubi=i+1;
		}	
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	
	cin>>N;		
	for(int i=0;i<N;i++){
		cin>>s;		
		int ubi=s.find("::");
		if(ubi>=0){
			s=s.substr(0,ubi+1)+"0000:"+s.substr(ubi+2);					
			while(count(s.begin(),s.end(),':')<7){
			  s=s.substr(0,ubi+1)+"0000:"+s.substr(ubi+1);
			}
		}
		cout<<s<<endl;
		
		vector<string> ans=parse(s);
		cout<<ans[0];	
		for(int j=1;j<ans.size();j++)
			cout<<":"<<ans[j];
		cout<<endl;		
	}
		
	return 0;
}

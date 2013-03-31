#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(){
	int n;
	string line;
	cin>>n;
	while(n--){
		cin>>line;
		map<char,int>M;
		int mx=0;
		for(int i=0;i<line.size();i++){
		    M[line[i]]++;
		    mx=max(M[line[i]],mx);
		}
		vector<pair<char,int> >vp(M.begin(),M.end());
		string res="";
		for(int i=0;i<vp.size();i++){
			if(vp[i].second==mx)
			    res+=vp[i].first;
		}
		cout<<res<<endl;
	}
	return 0;
}
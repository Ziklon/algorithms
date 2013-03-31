#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <vector>
#include <iostream>

using namespace std;

typedef long long ll;

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	//ios::sync_with_stdio(false);
	map<int,vector<int> >M;	
	int N,tmp;
	cin>>N;
	for(int i=0;i<2*N;i++){
	    cin>>tmp;
	    M[tmp].push_back(i+1);
	}
	vector<pair<int,vector<int> > > v(M.begin(),M.end());
		
	for(int i=0;i<v.size();i++){
	  if(v[i].second.size()%2==1){
	    cout<<-1<<endl;
	    return 0;             
	  }  
	}    
	for(int i=0;i<v.size();i++){
	  vector<int> cur=v[i].second;
	  for(int j=0;j<cur.size();j+=2){
            cout<<cur[j]<<" "<<cur[j+1]<<endl;
          }    
       }
       return 0;
}

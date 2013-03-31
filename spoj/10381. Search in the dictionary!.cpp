#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;


typedef long long ll;

int T,N,nodo,K;
int trie[500000][26];
int term[500000];
int mask[500000];


bool ans;
void add(char *s){
	int p=0;
	for(int i=0;i<strlen(s);i++){
		mask[p]|=(1<<(s[i]-'a'));
		if(trie[p][s[i]-'a']==0)
			p=trie[p][s[i]-'a']=++nodo;
		else
			p=trie[p][s[i]-'a'];
	}
	//cout<<s<<" "<<p<<endl;
	term[p]=1;
}

char buff[22];

vector<string> v;
void dfs(int nodo, string s){
	if(term[nodo]){
		v.push_back(s);
		//return;
	}
	for(int i=0;i<26;i++){
		if(mask[nodo]&(1<<i)){
			dfs(trie[nodo][i],s+string(1,'a'+i));
		}
	}	
}

int main(){
	freopen("input","r",stdin);
	memset(trie,0,sizeof trie);
	memset(term,0,sizeof term);
	memset(mask,0,sizeof mask);	
	scanf("%d",&N);
	nodo=0;
	for(int i=0;i<N;i++){
		scanf("%s",buff);
		add(buff);
	}
	scanf("%d",&K);
	for(int i=0;i<K;i++){
		scanf("%s",buff);
		int p=0;
		for(int j=0;j<strlen(buff);j++){
			p=trie[p][buff[j]-'a'];
		}		
		v.clear();
		if(p!=0){
			for(int k=0;k<26;k++)
				if(mask[p]&(1<<k))
					dfs(trie[p][k],buff);
		}		
		sort(v.begin(),v.end());		
		printf("Case #%d:\n",i+1);
		if(v.size()==0)printf("No match.\n");
		else{
			for(int j=0;j<v.size();j++)
				printf("%s\n",v[j].c_str());
		}		
	}
	return 0;
}



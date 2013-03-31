#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
typedef long long ll;

int T,N,nodo;
int trie[200005][10];
int term[200005];
int mask[200005];


bool ans;
void add(char *s){
	int p=0;
	for(int i=0;i<strlen(s);i++){
		mask[p]|=1<<(s[i]-'0');
		if(trie[p][s[i]-'0']==0)
			p=trie[p][s[i]-'0']=++nodo;
		else
			p=trie[p][s[i]-'0'];
		if(term[p])ans=1;
	}
	term[p]=1;
	if(__builtin_popcount(mask[p]))ans=1;
}

int main(){
	//freopen("input","r",stdin);
	scanf("%d\n",&T);
	while(T>0){
		nodo=0;
		memset(trie,0,sizeof trie);
		memset(term,0,sizeof term);	
		memset(mask,0,sizeof mask);		
		scanf("%d\n",&N);
		ans=0;
		for(int i=0;i<N;i++){
			char buff[20];
			scanf("%s\n",buff);
			add(buff);
		}		
		if(ans==1)
			printf("NO\n");
		else
			printf("YES\n");
		T--;
	}
	return 0;
}

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
typedef long long ll;

const int ALPH_SIZE = 10;

struct Node{
	int words;
	int prefixes;
	vector<Node*> links;
	Node(){
		words=prefixes=0;
		links.resize(ALPH_SIZE,NULL);
	}
};


class Trie{
	public:
	Trie(){
		myRoot=new Node();
		myCount=1;
	}
	int countPrefixes(const string& s)const;
	void insert(const string s);	
	private:
	Node* myRoot;
	int myCount;
};

int Trie::countPrefixes(const string& s)const{
	int len=s.size();
	Node* t=myRoot;
	for(int i=0;i<len;i++){
		if(t->links[s[i]-'0']==NULL)return 0;
		t=t->links[s[i]-'0'];
	}
	return t->prefixes;
}
void Trie::insert(const string s){
	int len=s.size();
	Node* t=myRoot;
	for(int i=0;i<len;i++){
		if(t->links[s[i]-'0']==NULL){
			t->links[s[i]-'0']=new Node();
			++myCount;
		}
		t=t->links[s[i]-'0'];
		++(t->prefixes);
	}
	++(t->words);	
}
string phone[10000];
char buff[1001];
int T,N;


int main(){
	//freopen("input","r",stdin);
	scanf("%d\n",&T);
	while(T--){
		bool valid=1;
		scanf("%d",&N);
		for(int i=0;i<N;i++){
			scanf("%s",buff);
			phone[i]=string(buff);
		}
		sort(phone,phone+N);		
		Trie* miTrie;
		miTrie=new Trie();
		for(int i=N-1;i>=0 && valid;i--){
			miTrie->insert(phone[i]);
			if(miTrie->countPrefixes(phone[i])>1)
				valid=0;;
		}		
		delete miTrie;		
		printf("%s\n",valid?"YES":"NO");
	}
	return 0;
}

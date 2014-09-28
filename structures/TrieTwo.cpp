#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;



struct Node{
	bool is_end;
	int prefix_count;
	Node* child[26];	
}*head;

void init(){
	head=new Node();
	head->prefix_count=0;
	head->is_end=false;	
	for(int i=0;i<26;i++)
		head->child[i]=NULL;
}

void insert(string word){
	Node* current=head;
	current->prefix_count++;
	
	for(int i=0;i<word.size();i++){
		int letter=word[i]-'A';
		if(current->child[letter]==NULL){
			current->child[letter]=new Node();
		}
		current->child[letter]->prefix_count++;
		current=current->child[letter];
	}
	current->is_end=true;
}

bool search(string word){
	Node* current=head;
		
	for(int i=0;i<word.size();i++){
		int letter=word[i]-'A';
		if(current->child[letter]==NULL)return 0;
		current=current->child[letter];
	}	
	return current->is_end;	
}

int words_with_prefix(string word){
	Node* current=head;
		
	for(int i=0;i<word.size();i++){
		int letter=word[i]-'A';
		if(current->child[letter]==NULL)return 0;
		current=current->child[letter];
	}
	return current->prefix_count;
}

void drop(Node* node){
	if(node==NULL)return;
	for(int i=0;i<26;i++)drop(node->child[i]);
	
	delete node;
	

}


string s;
int main(){
	ios::sync_with_stdio(false);
	
	int T,N;
	cin>>T;
	for(int i=0;i<T;i++){
		cin>>N;
		vector<string> v(N);
		for(int j=0;j<N;j++){
			cin>>v[j];
			insert(v[j]);
		}
		drop(head);
				
		init();
		bool ok=0;
		for(int j=0;j<N;j++){
		   if(words_with_prefix(v[j])>0)ok=1;
		   if(ok)break;
		}
		if(ok)puts("YES");
		else puts("NO");		
	}
	
}

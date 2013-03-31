#include <iostream>
#include <vector>
#include <cstdio>


using namespace std;

struct Node{
	int info;
	Node* next;
	Node(){
		next=NULL;
		info=0;
	}
	
	Node(int _info){
		info=_info;
		next=NULL;
	}	

};

struct List{
	Node* first;
	Node* last;
	
	List(){
		first=last=NULL;
	}
	bool isEmpty(){
		return first==NULL;
	}
	
	void add(int info){
		Node p(info);
		if(isEmpty())
			first=last=&p;
		else{
			last->next=&p;
			last=&p;
			
		}
		
	}
	void print(){
		Node* p=first;
		
		while(p!=NULL){
			
			//printf("%d ",p->info);
			p=p->next;
		}
		printf("\n");
	}
	
	

};

int main(){
	List L;
	L.add(5);
	L.add(3);
	L.add(5);
	L.add(3);
	L.add(1);
	L.print();
	

}
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

struct Node{
	int data;
	Node* next;
	Node(){
		data=0;
		next=NULL;
	}
};

struct List{
	Node* start;
	List(){
		start=NULL;
	}
};

void push(List *sList, int val){
	Node* p;
	p=(Node*)malloc(sizeof(Node));
	p->data=val;
	p->next=sList->start;
	sList->start=p;
}

void print(List* sList){
	Node* p=sList->start;
	while(p!=NULL){
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
	
}
void remove(List* sList, int val){
	Node* p=sList->start;
	Node* prev=NULL;
	while(p->data!=val && p!=NULL){
		prev=p;
		p=p->next;
	}
	if(p==NULL)return;
	if(prev==NULL){
		sList->start=p->next;
		free(p);
		
	}else{
		prev->next=p->next;
		free(p);
	}
		
}
		

int main(){
	
	List lista;
	for(int i=0;i<10;i++)
		push(&lista,i*5);
	
	remove(&lista, 45);
		
	print(&lista);
		
	return 0;	
	
}


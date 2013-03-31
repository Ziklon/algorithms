#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

struct node{
	int x,y;
	node(int _x, int _y){
		x=_x;
		y=_y;
	}
};

bool operator <(const node& a,const node& b){
		return a.x>b.x;
}

int main(){
	priority_queue<node> q;
	q.push(node(1,5));
	q.push(node(6,20));
	q.push(node(9,0));
	q.push(node(20,11));
	vector<node> v;
	v.push_back(node(5,10));
	sort(v.begin(),v.end());
	
	while(!q.empty()){
		node p=q.top();
		cout<<p.x<<endl;
		q.pop();
	}
	system("pause");

}
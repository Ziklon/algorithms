#include <iostream>
#include <queue>
#include <functional>

using namespace std;

int main(){
	priority_queue<int, vector<int>, greater<int> > q;
	q.push(10);
	q.push(100);
	q.push(15);
	q.push(50);
	q.push(230);
	while(!q.empty()){
		cout<<q.top()<<endl;
		q.pop();
	}
	system("pause");

}
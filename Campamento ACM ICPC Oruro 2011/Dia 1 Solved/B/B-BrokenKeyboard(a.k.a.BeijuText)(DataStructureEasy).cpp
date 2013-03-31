#include <iostream>
#include <sstream>
#include <utility>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <functional>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <stdio.h>
#include <string.h>
using namespace std;

struct B{
	string back;
	vector<string> front;
	int size;
	bool flag;
	
	B(){ size = 0, flag = false; }
	
	void insert(char ch){
		if(ch == '['){
			front.push_back("");
			size++;
			flag = true;
		}
		else if(ch == ']'){
			flag = false;
		}
		else{
			if(flag) front[size-1].push_back(ch);
			else back.push_back(ch);
		}
	}
	
	void printf(){
		for(int i=size-1; i>=0 ;i--)
			cout<<front[i];
		cout<<back<<endl;
	}
};

int main(){
	//freopen("B.in", "r", stdin);
	//freopen("B.out", "w", stdout);
	string s; //Or char s[100002]
	while(cin>>s){ //Or while(gets(s))
		int n = s.size(); //Or int n = strlen(s)
		B str;
		for(int i=0; i<n ;i++)
			str.insert(s[i]);
		str.printf();
	}
}

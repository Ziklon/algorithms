#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class TheMoviesLevelOneDivOne {
public:
	long long find(int, int, vector <int>, vector <int>);
};

long long TheMoviesLevelOneDivOne::find(int n, int m, vector <int> row, vector <int> seat) {
	long long res=0;
    map<int,vector<int> > mp;
    map<int,vector<int> >::iterator it;
    for(int i=1;i<48;i++){
    	vector<int> v;
		for(int j=0;j<row.size();j++){
			if(row[j]==i)
				v.push_back(seat[j]);
		}
		if(v.size()>0)
			mp[i]=v;	
	}
	for(int i=1;i<=n;i++){
		it=mp.find(i);
		if(it!=mp.end()){
			vector<int> v=mp[i];
			long sum=0;
			int pos=0;
			sort(v.begin(),v.end());						
			for(int j=0;j<v.size();j++){
				int n=0;
				if(j==0){
					n=v[j]-2;			
				}else{
					n=v[j]-v[j-1]-2;					
				}
				if(n<=0)
					n=0;
				pos=v[j];	
				sum+=n;
			}
			int p=0;
			if(pos!=m)
				p=(m-pos)-2;
			if(p<=0)
				p=0;
			res+=sum+p;
			
		}else{
			res+=(m-1);
		}
	}
	
	if(m>=2)
    	return res;
    return 0;
	
}


double test0() {
	int p0 = 2;
	int p1 = 3;
	int t2[] = {1, 2};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {2, 3};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	TheMoviesLevelOneDivOne * obj = new TheMoviesLevelOneDivOne();
	clock_t start = clock();
	long long my_answer = obj->find(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p4 = 1LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int p0 = 2;
	int p1 = 3;
	int t2[] = {1, 1, 1, 2, 2, 2};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {1, 2, 3, 1, 2, 3};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	TheMoviesLevelOneDivOne * obj = new TheMoviesLevelOneDivOne();
	clock_t start = clock();
	long long my_answer = obj->find(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p4 = 0LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int p0 = 4;
	int p1 = 7;
	int t2[] = {1};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {1};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	TheMoviesLevelOneDivOne * obj = new TheMoviesLevelOneDivOne();
	clock_t start = clock();
	long long my_answer = obj->find(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p4 = 23LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int p0 = 10;
	int p1 = 8;
	int t2[] = {1, 9, 6, 10, 6, 7, 9, 3, 9, 2};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {7, 7, 3, 3, 7, 1, 5, 1, 6, 2};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	TheMoviesLevelOneDivOne * obj = new TheMoviesLevelOneDivOne();
	clock_t start = clock();
	long long my_answer = obj->find(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p4 = 54LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

int main() {
	int time;
	bool errors = false;
	
	time = test0();
	if (time < 0)
		errors = true;
	
	time = test1();
	if (time < 0)
		errors = true;
	
	time = test2();
	if (time < 0)
		errors = true;
	
	time = test3();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!

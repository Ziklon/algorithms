#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int T,A[10];
int getDistance(int x1,int y1, int x2, int y2){
	return abs(x2-x1)+abs(y1-y2);
}
int main(){
	scanf("%d",T);
	int x,y,z;
	while(T--){
		for(int i=0;i<6;i++)
			scanf("%d",&A[i]);
		x=getDistance(A[0],A[1],A[2],A[3]);
		y=getDistance(A[4],A[5],A[2],A[3]);
		z=getDistance(A[0],A[1],A[4],A[5]);
		vector<int> v;
		v.push_back(x);
		v.push_back(y);
		v.push_back(z);
		sort(v.begin(),v.end());
		string dev="";
		if(v[1]==v[0] || v[1]==v[2])dev+="isosceles ";
		if(v[1]!=v[0] && v[1]!=v[2])dev+="scalene ";
		if()
		
	}


}

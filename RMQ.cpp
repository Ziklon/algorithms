#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <queue>
#include <map>
#define N 10
using namespace std;
typedef long long ll;
int M[N][4];
int A[] = { 2, 4, 3, 1, 6, 7, 8, 9, 1, 7 };


void process(){
    for(int i=0;i<N;i++)M[i][0]=i;            
    for(int j=1;(1<<j)<=N;j++){            
        for(int i=0;(i+(1<<j)-1)<N;i++){                
            if (A[M[i][j - 1]] < A[M[i + (1 << (j - 1))][j - 1]])
					M[i][j] = M[i][j - 1];
				else
					M[i][j] = M[i + (1 << (j - 1))][j - 1];
        }       
    }        
}

int RMQ(int i, int j){
    int k=log2(j-i+1);    
    if (A[M[i][k]] <= A[M[j - (1 << k) + 1][k]])
        return M[i][k];
    return M[j - (1 << k) + 1][k];    
}

int main(){
   #ifdef LocalHost
		freopen("D:/input.txt","r",stdin);
   #endif
   process();
   cout<<RMQ(0,2)<<endl;     
   return 0;      
}

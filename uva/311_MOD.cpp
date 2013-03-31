#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <cmath>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sz size()
#define fill(x,i) memset(x,i,sizeof(x))
using namespace std;

string line;
int dp[1010];
int go(int n){
   if(n<0)return 1<<30;
   if(n==0)return 0;
   int& ref=dp[n];
   if(ref!=-1)return ref;
   ref=1<<30;
   for(int i=1;i<=6;i++)
      ref=min(ref,1+go(n-i*i));
   return ref;   
}

int main(){
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  long long i,n,sum,dev;
  fill(dp,-1);
  while(getline(cin,line)){
    if(line=="0 0 0 0 0 0")break;
    istringstream is(line);
    sum=0;
    dev=0;
    for(i=1;i<=6;i++){
       is>>n;
       sum+=(n*i*i);
    }
    while(sum>1000){
      sum-=36;
      dev++;
    }
    dev+=go(sum);
    printf("%d\n",dev);
  }
  return 0;
}

/*
int main(){
   cout<<"hello"<<endl;
   system("pause");
}*/

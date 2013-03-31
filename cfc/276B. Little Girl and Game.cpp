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
#define REP(i,a) for(int i=0;i<int(a);i++)
using namespace std;
typedef long long ll;

string cad;

int cnt_odd(vector<int>& v){
    int ans=0;
    REP(i,v.size())ans+=v[i]&1;
    return ans;
}

int main(){
   #ifdef LocalHost
		freopen("D:/input.txt","r",stdin);
   #endif
   cin>>cad;   
   vector<int> v(26,0);
   
   REP(i,cad.size())v[cad[i]-'a']++;
   int mx=0;
   int sum=0;
   if(cnt_odd(v)<=1){
        cout<<"First"<<endl;
        return 0;
   }
   int who=0;
   while(1){
       int aa=-1;
       int cnt=0;
       REP(i,26){
           if(v[i]>0){
               v[i]--;
               int tmp=cnt_odd(v);
               if(tmp>=2 && tmp>cnt){
                    cnt=tmp;
                    aa=i;
               }               
               v[i]++;            
           } 
       }
       if(aa!=-1){
            v[aa]--;        
       }else break;
       who=(who+1)%2;    
   }
   if(who==1)cout<<"First"<<endl;
   else cout<<"Second"<<endl;
   return 0;      
}

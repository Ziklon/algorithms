#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (int)n; i++)
#define debug(v) cout<<#v<<" = "<<(v)<<endl;
#define adebug(x,n) cout <<#x<<endl; REP(i,n)cout<<x[i]<<char(i+1==n?10:32)
#define mdebug(x,m,n) cout <<#x<<endl; REP(i,m)REP(j,n)cout<<x[i][j]<<char(j+1==n?10:32)

using namespace std;

string num;
string digits[]={"1","14","144"};


int check(string num){
    int ans=0;
    REP(i,3){
       if(num.size()>=digits[i].size()){
          string sub=num.substr(0,digits[i].size());
          if(sub==digits[i]){              
              if(num.size()==digits[i].size())return 1;              
              ans=max(ans,check(num.substr(digits[i].size())));            
          }        
       }
        
    }
    return ans;
    
}

int main(){
    cin>>num;
    
    if(check(num))puts("YES");
    else puts("NO");
          
    return 0;      
}

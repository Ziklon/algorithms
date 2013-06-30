#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (int)n; i++)
#define debug(v) cout<<#v<<" = "<<(v)<<endl;
#define adebug(x,n) cout <<#x<<endl; REP(i,n)cout<<x[i]<<char(i+1==n?10:32)
#define mdebug(x,m,n) cout <<#x<<endl; REP(i,m)REP(j,n)cout<<x[i][j]<<char(j+1==n?10:32)

using namespace std;
typedef long long ll;
int T,N;
char c;

map<int,vector<string> > parse(string& s){
    map<int,vector<string> > ans;
    REP(mask,1<<s.size())if(mask>0  && __builtin_popcount(mask)%2==0){
        string tmp;
        REP(i,s.size())if(mask&(1<<i))tmp+=s[i];
        ans[__builtin_popcount(mask)].push_back(tmp);
    }
    return ans;
}
int points(string &s){
    int ans=0;
    REP(i,s.size())if(i>=1)ans+=abs(s[i]-s[i-1]);
    return ans;
}


int main(){
   #ifdef LocalHost
      freopen("input.txt","r",stdin);
   #endif
   cin>>T;
   REP(t,T){
       cin>>N;
       string left,right;       
       REP(i,N){
           cin>>c;
           if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')left+=c;
           else right+=c;
       }
       sort(left.begin(),left.end());
       sort(right.begin(),right.end());
       map<int,vector<string> > mleft=parse(left);
       map<int,vector<string> > mright=parse(right);
       int len=10;
       int anspt=-1;
       string anscad="";
       while(len>=1){            
            if(mleft.count(len) && mright.count(len)){
                vector<string> va=mleft[len]; 
                vector<string> vb=mright[len];                 
                
                REP(i,va.size())REP(j,vb.size()){
                    string tmp=va[i]+vb[j];
                    sort(tmp.begin(),tmp.end());
                    int pt=points(tmp);
                    
                    if((anspt<pt) || (anspt==pt && anscad.size() < tmp.size())  || (anspt==pt && anscad.size()==tmp.size() && anscad>tmp)){
                        anspt=pt;
                        anscad=tmp;
                    }
                }
            }        
            len-=2;
       }
       if(anspt==-1)cout<<-1<<endl;
       else cout<<anscad<<" "<<anspt<<endl;
        
   }
   return 0;      
}


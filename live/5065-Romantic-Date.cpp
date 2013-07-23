#include<bits/stdc++.h>
#define REP(i,n)for (int i=0;i<n;i++)
#define first fst
#define second snd
#define sz size()
#define all(v) (v).begin(), (v).end()
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
int T;
string cad="23456789TJQKA";
string tipe="DCHS",s;
map<string,pair<int,int> >M;
int main(){
    cin>>T;
    while(T--){
        vector<pair<int,int> > me,she;

        REP(i,26){
            cin>>s;
            int xx=cad.find(s[0]);
            int yy=tipe.find(s[1]);
            me.pb(mp(xx,yy));
        }
        sort(all(me));

        REP(i,13)REP(j,4){
            pair<int,int> tmp=mp(i,j);
            if(binary_search(all(me),tmp)==0)she.pb(tmp);
        }
        int ans=0;
        int idx=0;
        int mm=0;
        while(idx<26){
            while(idx<26 && me[idx]<she[mm])idx++;
            if(me[idx]>she[mm]){
                ans+=1;
                mm++;
            }
            idx++;
        }
        cout<<ans<<endl;

    }
    return 0;
}


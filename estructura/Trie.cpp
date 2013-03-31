#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>

#define sz size()
using namespace std;
int state[1200000][27];
int  hm[1200000];


struct T{
  int statecount;
 
  T(){
     clear();
  }
 
  void clear(){
      memset( state[ 0 ] , -1 , sizeof( state[ 0 ] ) );
      hm[0] = 0;
      statecount = 1;
  }
 
  void add( string & s ){
    s += 'z' + 1;
    int pos = 0;
    int L = s.sz;
    int cnt= 0;
    int ant =  0;
    for(int i = 0 ; i < L ; ++i ){
      int p = s[ i ] - 'a';
      if( state[pos][p] == -1 ){ 
        state[pos][p] =  statecount ; 
		hm[ statecount ]  = 0;       
        memset( state[ statecount] , -1 , sizeof( state[statecount] ) );
        statecount++;
        ++cnt;
      }
      ant = pos;
      pos = state[ pos ][ p ];
      if( cnt == 1 && ant != 0 ){
         ++hm[ant];
      }
     
    }
       
   }
   
   int f( string s ){
     int SZ = s.sz;
     int ans = 1;
     int pos = 0;
     for(int i = 0 ; i < SZ - 2 ; ++i ){
        int p = s[i] - 'a';
        pos = state[pos][p];
        ans += hm[pos] > 0 ;
     }
     return ans;
   }
 
};
 
T trie;
 
 
string s[100003];
int n;
 
 
 
int main(){
 while( cin >> n ){
   trie.clear();
   for(int i = 0 ; i < n ; ++i ){ 
		cin >> s[i] ;
		trie.add(s[i]);
	}
   int ans = 0 ;
   for(int i = 0 ; i < n ; ++i )ans += trie.f(s[i]);
   
   printf("%.2lf\n",(double)ans/n);
 }
 return 0;
}

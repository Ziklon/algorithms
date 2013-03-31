#include <iostream>

using namespace std;

int main(){

    string aux="";
    while(getline(cin,aux)){
        string dev="";
        string kk="";
        for(int i=0;i<aux.size();i++){
            if(aux[i]!=' ')
                kk=aux[i]+kk;
            else{
                dev+=kk;
                dev+=' ';
                kk="";
           }
        }
        if(kk!="")dev+=kk;
        cout<<dev<<endl;
    }
    return 0;
}

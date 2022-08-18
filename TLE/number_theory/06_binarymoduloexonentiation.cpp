#include<bits/stdc++.h>
using namespace std;
#define nl '\n'

long long binaryexpo(long long a, long long b, long long m){
    long long res=1;
    while(b>0){
        if(b%2){
            res=(res*a)%m;
            b--;
        }
        a=(a*a)%m;
        b/=2;
    } 
    return res;  
}
int main(){
    int a,b,m;
    cin>>a>>b>>m;
    cout<<binaryexpo(a,b,m);
}
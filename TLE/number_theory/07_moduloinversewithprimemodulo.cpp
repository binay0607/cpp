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
    int n;cin>>n;
    int mod=1e9+7;
    //formula: modulo inverse of n with modulo m= (a^(m-2))%m
    cout<<binaryexpo(n,mod-2,mod)<<nl;

}
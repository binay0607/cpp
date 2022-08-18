#include<bits/stdc++.h>
using namespace std;
#define nl '\n'
#define MOD         1000000007
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

long long modinverse(long long x, long long m){
    return binaryexpo(x,m-2,m);
}

//here we are going to find nCr
int main(){
//for a single computation don't precompute 

    long long n,r;cin>>n>>r;
    //precomputation
    vector<long long> fact(n+1,1);
    vector<long long> ifact(n+1,1);
    for(long long i=1;i<=n;i++){
        fact[i]= (fact[i-1]%MOD*i%MOD)%MOD;
        ifact[i]=modinverse(fact[i],MOD);
    }
    //now the answers can be calculated in O(1) time
    long long nCr= ((fact[n]*ifact[n-r])%MOD*ifact[r])%MOD;
    cout<<nCr<<nl;

    

}
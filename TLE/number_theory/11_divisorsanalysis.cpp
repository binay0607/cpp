#include<bits/stdc++.h>
using namespace std;
#define nl '\n'
#define ll long long 

//Theory--->
//If we have the prime factorisation of a number 
//which we can easily get if we have pre calculated the spf of number in range
// let: N= p1^k1 * p2^k2 * ........* pm^km
//then possibilty of powers of each prime is their power+1
//So number of divisors becomes= (k1+1)*(k2+1)*(k3+1)*......*(km+1)
//=>number of non-prime divisors=(k1+1)*(k2+1)*(k3+1)*......*(km+1) - m

//Sum of divisors= (1+p1+p1^2+p1^3+.....p1^k1)* (1+p2+p2^2+p2^3+.....p2^k2) *..........
//=> this we can calculate using G.P

//Product of divisors= 
//if N is a not perfect square i.e. it has even divisors : N^[no. of divisors/2]
//if N has odd divisors : N^[no. of divisors-1/2]* sqrt(N)
//explainion=> as divisors appear in pair and their multiplication is equal to N

//code for no. of divisors: use this when you have to find divisors of many numbers
int main(){
    ll n=10000;
    vector<ll> spf(n+1);
    for(ll i=0;i<n;i++){
        spf[i]=i;
    }
    for(ll i=2;i<=n;i++){
        if(spf[i]==i){
            for(ll j=i*i;j<=n;j+=i){
                spf[j]=min(spf[j],i);
            }
        }
    }
    ll val;cin>>val;
    ll numofdivisors=1;
    while(val>1){
        int prime= spf[val];
        int count=0;
        while(val%prime==0){
            val/=prime;
            count++;
        }
        //here count it power of that prime
        numofdivisors*=(count+1);
    }
    cout<<numofdivisors<<nl;

}
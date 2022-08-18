#include<bits/stdc++.h>
using namespace std;
#define nl '\n'
//smallest prime factor of all the numbers in a range
int main(){
    int n=100;
    vector<int> spf(n+1);
    for(int i=0;i<n;i++){
        spf[i]=i;
    }
    for(int i=2;i<=n;i++){
        if(spf[i]==i){
            for(int j=i*i;j<=n;j+=i){
                spf[j]=min(spf[j],i);
            }
        }
    }

    cout<<spf[13]<<nl;
}
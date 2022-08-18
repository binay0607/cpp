#include<bits/stdc++.h>
using namespace std;
#define nl '\n'
int main(){
    int n=1000;
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
    //prime factorisation done.
    // vector<int> v;
    int val;cin>>val;
    
    //this one is better if we change the spf to store the greatest prime instead of smallest
    // while(val>1){
        
    //     v.push_back(spf[val]);
    //     val/=spf[val];
    // }

    while(val>1){
        int prime= spf[val];
        cout<<prime<<" ";
        int count=0;
        while(val%prime==0){
            val/=prime;
            count++;
        }
        cout<<count<<nl;
    }

    // for(auto el:v){
    //     cout<<el<<" ";
    // }cout<<nl;



}
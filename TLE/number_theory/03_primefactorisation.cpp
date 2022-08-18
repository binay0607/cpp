#include<bits/stdc++.h>
using namespace std;
#define nl '\n'

int main(){
    int n;cin>>n;
    vector<pair<int,int>> v;
    for(int i=2;i*i<=n;i++){
        int count=0;
        while(n%i==0){
            count++;
            n/=i;
        }
        
        if(count>0)v.push_back({i,count});
    }
    if(n>1){
        v.push_back({n,1});
    }
    for(auto el:v){
        cout<<el.first<<" ^ "<<el.second<<nl;
    }
}
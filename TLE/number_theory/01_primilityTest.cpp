#include<bits/stdc++.h>
using namespace std;
#define nl '\n'
// finding if a number is prime or not with the timecomplexity of O(sqrt(n))
int main(){
    int n;cin>>n;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            cout<<" Not Prime"<<nl;
            return 0;
        }
    }
    cout<<"Prime"<<nl;
}
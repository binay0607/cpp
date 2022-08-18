#include<bits/stdc++.h>
using namespace std;
#define nl '\n'

int* seive(int n){
    int *arr= new int[n+1]();
    for(int i=2;i<=n;i++){
        if(arr[i]==0){
            for(int j=i*i; j<=n;j+=i){
                arr[j]=1;
            }
        }
    }
    return arr;

}
int main(){
    int n=10000;
    int *a= seive(n);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        bool c=true;
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                if(a[n-n/i]==0){
                    cout<<"alice"<<nl;
                    c=false;
                    break;
                    
                }
            }
        }
        if(c){
            cout<<"bob"<<nl;
        }
    }
    
}
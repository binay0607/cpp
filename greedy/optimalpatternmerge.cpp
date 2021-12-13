#include<bits/stdc++.h>
using namespace std;
void print_q(priority_queue<int, vector<int>> heep){
    while(!heep.empty()){
        cout<<heep.top()<<" ";
        heep.pop();
    }
    

}
template<typename T> void printt(T& heep ){
    while(!heep.empty()){
        cout<<heep.top()<<" ";
        heep.pop();
    }
    cout<<endl;
}


int main(){
    int n; 
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    priority_queue<int, vector<int>,greater<int> > minheap;
    for(int i=0; i<n;i++){
        minheap.push(a[i]);
    }
    printt(minheap);
    priority_queue<int, vector<int> > maxheap;
    for(int i=0; i<n;i++){
        maxheap.push(a[i]);
    }
    printt(maxheap);
    
    // int ans=0;
    // while(minheap.size()>1){
    //     int e1= minheap.top();
    //     minheap.pop();
    //     int e2= minheap.top();
    //     minheap.pop();
    //     ans+=e1+e2;
    //     minheap.push(e1+e2);
    // }
    // cout<<ans<<endl;
}
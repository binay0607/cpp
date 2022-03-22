//out of all the possible permutation we have to print the kth one
//here n will be given and the element of the permutation are ranging in 1 to n inclusive
//here we will be using modulation logic dividing the permutations into sections
#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define li list<int>
#define nl "\n"
#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define mp make_pair
#define ppc __builtin_popcount
#define fs(x)	 	cout<<fixed<<showpoint<<setprecision((x))
#define rep(i,a,b)  for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define ceel(a,b)   ((a+b-1)/b)
#define all(x)      (x).begin(),(x).end()
#define ll          long long
#define dp2(n,k) int** dp = new int*[n+1];for(int i=0;i<=n;i++){dp[i] = new int[k+1];}
#define M           1000000007
#define INF         1e18

vector<int > kth_permutation(int n,int k){
    vector<int> a; //to store values from 1 to n
    int fact=1;   
    for(int i=1;i<n;i++){
        fact*=i;  //factorial need till n-1 only
        a.push_back(i);
    }
    a.push_back(n);
    vector<int> ans;
    k--; //0 base indexing
    while(true){
        ans.push_back(a[k/fact]);
        a.erase(a.begin()+(k/fact));
        if(a.size()==0){
            break;
        }
        k=k%fact; //to move to the subsection
        fact= fact/a.size();
    }
    return ans;
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

    int n;cin>>n;
    int k;cin>>k;
    vector<int> ans;
    ans=kth_permutation(n, k);
    for(int el:ans){
        cout<<el<<" ";
    }cout<<nl;
}

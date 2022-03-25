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
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    int n;cin>>n;
    vi nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int target;cin>>target;
    vector<vector<int>> ans;
        
    sort(nums.begin(),nums.end());

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int currtarget= target-(nums[i]+nums[j]);
            int l=j+1;
            int r=n-1;
            while(l<r){
                if(nums[l]+nums[r]<currtarget){
                    int temp=l+1;
                    while(nums[temp]==nums[l] && temp<r){
                        temp++;
                    }
                    l=temp;
                        // l++;
                }else if(nums[l]+nums[r]>currtarget){
                    int temp=r-1;
                    while(nums[temp]==nums[r] && temp>l){
                        temp--;
                    }
                    r=temp;
                        // r--;
                }else{
                    vector<int> quad(4,0);
                    quad[0]=nums[i];
                    quad[1]=nums[j];
                    quad[2]=nums[l];
                    quad[3]=nums[r];
                    ans.push_back(quad);
                    while(l<r&& nums[l]==quad[2])l++;
                    while(l<r&& nums[r]==quad[3]) r--;


                }
            }
            while(j+1<n && nums[j+1]==nums[j])j++;
        }
        while(i+1<n && nums[i+1]==nums[i])i++;
    }
    for(auto v:ans){
        for(auto el:v){
            cout<<el<<" ";
        }cout<<nl;
    }
        
}
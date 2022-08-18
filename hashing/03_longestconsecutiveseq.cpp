//so there will be an unsorted array we have to print the longest sequence we can make
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
    unordered_map<int,int > mp;
 
    for(int i=0;i<n;i++){
         mp[nums[i]]++;
    }
    int longeststreak=0;
       
    for(int i=0;i<n;i++){
        if(mp.find(nums[i]-1)==mp.end()){
            int currentnum=nums[i];
   
            int currentstreak=1;
            while(mp.find(currentnum+1)!=mp.end()){
                currentstreak++;
                currentnum++;
            }

            longeststreak=max(currentstreak,longeststreak);
        }
    }
    cout<<longeststreak<<nl;
}
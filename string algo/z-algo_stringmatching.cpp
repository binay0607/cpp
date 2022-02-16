// must do dryrun
//z-algo can be effectly used to find indexes for multiple pattern match

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

int * zalgo(string s){
    
    int len=s.size();
    int * z= new int[len]();
    int l=0,r=0;
    for(int i=1;i<len;i++){
        if(i>r){
   
            l=i;
            r=i;
            // r-l is working as index for pattern(suffix)
            while(r<len && s[r-l]==s[r]){
                r++;
            }
            z[i]=r-l;
            r--;
            
            
        }else{
            // i-l is working as index for pattern as l is poiting to same chat start of pattern(suffix)
            if(z[i-l]+i<=r){
                z[i]=z[i-l];
            }else{
                // making it just as the starting case just that here some of the char are checked we just move forward
                l=i;
                while(r<len && s[r-l]==s[r]){
                    r++;

                }
                z[i]=r-l;
                r--;
            }
        }
        
    }
    return z;
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    string text,pattern;cin>>text>>pattern;
    string s= pattern+"$"+text;
    int *z= zalgo(s);
    // for(int i=0;i<s.size();i++){
    //     cout<<z[i]<<" ";
    // }
    // cout<<nl;
    for(int i=pattern.size()+1;i<=s.size();i++){
        if(z[i]==pattern.size()){
            cout<<i-pattern.size()<<nl;
            // as pattern is also infused
        }
    }

}
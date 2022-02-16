// we have to find the pattern in the text
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

// it finds suffix same as pefix
int * findlps(string p){
    int len= p.size();
    int *lps= new int[len];
    lps[0]=0;
    int i=1;
    int j=0;
    while(i<len){
        if(p[i]==p[j]){
            lps[i]=j+1;
            j++;
            i++;
        }else{
            if(j!=0){
                j=lps[j-1];
            }else{
                lps[i]=0;
                i++;
            }
        }
    }
    return lps;
    
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    string text,pattern;cin>>text>>pattern;
    int * lps= findlps(pattern);
    // for(int i=0;i<pattern.size();i++){
    //     cout<<lps[i]<<nl;
    // }
 
    int i=0,j=0;
    while(i<text.size() && j<pattern.size()){
        if(text[i]==pattern[j]){
            i++;
            j++;
        }else{
            if(j!=0){
                j=lps[j-1];
            }else{
               i++; 
            }
        }
    }
    if(j==pattern.size()){
        cout<<"Found"<<nl;
    }else{
        cout<<"Not Found"<<nl;
    }
    

}
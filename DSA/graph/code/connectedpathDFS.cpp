
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
#define INF         1e1

void print(int** edges, int n, int sv, bool* visited){
  cout << sv << " ";
  visited[sv] = true;
  for(int i=1; i<n; i++){
    if(i==sv){
      continue;
    }
    if(edges[sv][i]==1){
      if(visited[i]){
        continue;
      }
      print(edges, n, i, visited);
    }
  }
}

int main(){
  int n;
  int e;
  cin >> n >> e;

  int** edges = new int*[n+1];
  for(int i=0; i<=n; i++){
    edges[i]=new int[n+1];
    for(int j=0; j<=n; j++){
      edges[i][j]=0;
    }
  }

  for(int i=0; i<e; i++){
    int f,s;
    cin >> f >> s;
    edges[f][s]=1;
    edges[s][f]=1;
  }

  bool* visited = new bool[n+1];

  for(int i=0; i<n; i++){
    visited[i]=false;
  }

  print(edges, n+1, 1, visited);
  cout<<nl;

  return 0;
}
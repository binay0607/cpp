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


void printboard( int**board,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j]<<" ";
        }
    }
    cout<<nl;
}

void ratinamaze(int ** board,int** sol,int n, int row,int col){
    
    if(row==n-1 && col==n-1){
        sol[row][col]=1;
        printboard(sol,n);
        sol[row][col]=0;
        return;
    }
    if(row <0 || col<0 || row>n-1 || col>n-1|| board[row][col]==0 /*path is blocke*/ || sol[row][col]==1 /*path is alredy taken*/){
        return;
    }

    
    sol[row][col]=1;
    ratinamaze(board, sol,n,row-1,col);
    ratinamaze(board, sol,n,row,col-1);
    ratinamaze(board, sol,n,row+1,col);
    ratinamaze(board, sol,n,row,col+1);
    sol[row][col]=0;
     
     
     return;
     
}
   
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    int n;cin>>n;
    int ** board=new int*[n];
    int **sol=new int *[n];
    for(int i=0;i<n;i++){
        board[i]=new int [n];
        sol[i]=new int [n];
        for(int j=0;j<n;j++){
            cin>>board[i][j];
            sol[i][j]=0;

        }
    }
    ratinamaze(board,sol,n,0,0); //(0,0) starting pos
}
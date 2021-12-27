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
int board[10][10];
bool ispossible(int n,int row,int col){
    // for same col
    for(int i=row-1;i>=0;i--){
        if(board[i][col])return false;
    }

    // for upper left diagonal
    for(int i=row-1,j=col-1;i>=0&&j>=0;j--,i--){
        if(board[i][j])return false;
    }

    // for upper right diagonal
    for(int i=row-1,j=col+1; i>=0&& j<n;i--,j++){
        if(board[i][j])return false;
    }


    return true; //no queen in the path

}

bool nqueen(int n,int row){   //to print all the sol add print  at row==n and make nqueen a void fun;
    if(row==n){
        //we have placed all the queens now time to print the matrix
        return true;
       
        
    }
    for(int j=0;j<n;j++){ //we know the row to work on
        if(ispossible(n,row,j)){
            board[row][j]=1;
            if(nqueen(n,row+1)){
                return true;
            }
            board[row][j]=0;
        }
    }
    return false;
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

    int n;cin>>n;
    memset(board,0,11*11*sizeof(int));
    if(nqueen(n,0)){// 0 is the starting row
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<board[i][j]<<" ";
            }
        }
        cout<<nl;
    }else{
        cout<<"NO SOLUTION WAS FOUND"<<nl;
    }
    


}
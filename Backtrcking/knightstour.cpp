// here if the knight(horse) starts from pos (0,0) we have to find at which number it will travel all the pos
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


bool issafe(int x,int y, int**board, int n){
    return (x>=0 && y>=0 && x<n && y<n && board[x][y]==-1);
}
void printboard( int**board,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j]<<" ";
        }
    }
    cout<<nl;
}
int row[8] = {2, 1, -1, -2, -2, -1, 1, 2 };
int col[8] = {1, 2, 2, 1, -1, -2, -2, -1 };
bool knightstour(int** board, int n,int x,int y,int movei, vector<pair<int,int>> moves ){
  
    if(movei==n*n){
        return true;

    }
    int next_x, next_y;
    for(int i=0;i<n;i++){
        next_x=x+row[i];
        next_y= y+col[i];
        if(issafe(next_x,next_y,board,n)){
            board[next_x][next_y]=movei+1;
            if(knightstour(board,n, next_x,next_y,movei+1,moves)){
                return true;
            }else{
                 board[next_x][next_y]=-1;
            }
           

        }
    }

    return false;


}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

    int n;cin>>n;;
    int **board= new int *[n];
    for(int i=0;i<n;i++){
        board[i]=new int [n];
        for(int j=0;j<n;j++){
            board[i][j]=-1;
        }
    }
    printboard(board,n);

    vector<pair<int ,int>> moves;
    moves.push_back(make_pair(2,1));
    moves.push_back(make_pair(1,2));
    moves.push_back(make_pair(-1,2));
    moves.push_back(make_pair(-2,1));
    moves.push_back(make_pair(-2,-1));
    moves.push_back(make_pair(-1,-2));
    moves.push_back(make_pair(1,-2));
    moves.push_back(make_pair(2,-1));
    board[0][0]=1;
    // as we start from here (0,0) pos
    if(knightstour(board,n,0,0,1,moves)){
        printboard(board,n);
        
    }else cout<<"SOL NOT FOUND"<<nl;
  



}
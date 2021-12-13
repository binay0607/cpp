#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define vvi vector<vi> 
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
#define MAXN 1000
bool checker(char arr[][MAXN], int n, int m, int i, int j, string s, bool**visited)
{
	if (s.length() == 0)
	{
		return true;
	}
	if (i < 0 || j < 0 || i >= n || j >= m)
	{
		return false;
	}
	int row_array[] = { i - 1, i, i + 1 };
	int col_array[] = { j - 1, j, j + 1 };
	for (int p = 0; p < 3; p++)
	{
		for (int q = 0; q < 3; q++)
		{
			if (row_array[p] == i && col_array[q] == j)
			{
				continue;
			}

			int row = row_array[p];
			int col = col_array[q];
			if (row < 0 || col < 0 || row >= n || col >= m)
			{
				continue;
			}
			if (arr[row][col] == s[0] && !visited[row][col])
			{
				visited[row][col] = true;
				bool checked = checker(arr, n, m, row, col, s.substr(1), visited);
				if (checked)
				{
					return checked;
				}
				else
				{
					visited[row][col] = false;
				}
			}
		}
	}
	return false;
}




int solve(char arr[][MAXN],int n, int m)
{
    
    bool** visited = new bool* [n];
    for (int i = 0; i < n; i++)
	{
		visited[i] = new bool[m];
		for (int j = 0; j < m; j++)
		{
			visited[i][j] = false;
		}
	}
    
    
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] == 'C')
			{
                //creating dynamic boolean 2d array
				
                
                //checking
				if(checker(arr, n, m, i, j, "ODINGNINJA", visited))
				{
					return 1;
				}
                
                //deleting dynamic boolean array
				for(int p=0; p<n; p++)
                {
                    for(int q=0; q<m; q++)
                    {
                        visited[p][q]=false;
                    }
                }
			}
		}
	}
	return 0;
}
int main(){
    int t;cin>>t;
    while(t--){
        int n,m;cin>>n>>m;
        char a[n][MAXN];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>a[i][j];
            }
        }

        cout<<solve(a,n,m)<<nl;
       
        

        
    }
}
// this is for directed graph--> all vertices are connected but some of them are not reachable by all the vertices we have to give comp with vertices one can go from every node to any other node
// for this we use kosaraju algorithm
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



void dfs(vector<int>*edges,int start,int n, unordered_set<int > &visited,unordered_set<int>* comp){
    comp->insert(start);
    visited.insert(start);
    for(auto el:edges[start]){
        if(visited.count(el)==0){
            dfs(edges,el,n,visited,comp);
        }
    }
}
void dfs2(vector<int>* edges,int start,unordered_set<int> &visited,stack<int> &fvertices){
    visited.insert(start);
    for(auto el:edges[start]){
        if(visited.count(el)==0){
            dfs2(edges,el, visited,fvertices);
        }
    }
    fvertices.push(start);
}
unordered_set<unordered_set<int>*>* get_ssc(vector<int>* edges,vector<int>* edgesT,int n){
    unordered_set<int> visited;
    stack<int> fvertices;
    for(int i=0;i<n;i++){
        if(visited.count(i)==0){
            dfs2(edgesT,i,visited,fvertices);
        }
    }
    visited.clear();
    unordered_set<unordered_set<int>*>* output=new unordered_set<unordered_set<int>*>();
    while(fvertices.size()!=0){
        int vertex= fvertices.top();
        fvertices.pop();
        unordered_set<int>* comp=new unordered_set<int>();
        if(visited.count(vertex)==0){
            dfs(edges,vertex,n,visited,comp);
            output->insert(comp);

        }
    }
    return output;
}

int main(){
    int n,e;
    cin>>n>>e;
    vector<int>* edges= new vector<int>[n];
    vector<int>* edgesT= new vector<int>[n];  //this will hold the transpose graph(edges)

    while(e--){
        int s,f;cin>>s>>f;
        edges[s-1].push_back(f-1);
        edgesT[f-1].push_back(s-1);
    }
    unordered_set<unordered_set<int>*>* components= get_ssc(edges,edgesT,n);
    unordered_set<unordered_set<int>*>::iterator it = components->begin();
	while (it != components->end()) {
		unordered_set<int>* component = *it;
		unordered_set<int>::iterator it2 = component->begin();
		while (it2 != component->end()) {
			cout << *it2 + 1 << " ";
			it2++;
		}
		cout << endl;
		delete component;
		it++;
	}
}

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


// defining node of tree
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        next=NULL;
    }
};

int findnoderec(Node *head, int data){
    if(head==NULL){
        return -1;
    }
    if(head->data==data){
        return 0;
    }
    int small=findnoderec(head->next,data);
    if(small==-1)return -1;
    else return 1+small;
}
int findnode(Node*head,int data){
    int idx=0;
    while(head!=NULL){
        
        if(head->data==data){
            return idx;
        }
        head=head->next;
        idx++;
        
    }
    return -1;
}
Node* takeinput(){
    int data;cin>>data;
    Node* head=NULL;
    Node* tail=NULL;

    while(data!=-1){
        Node* nextnode =new Node(data);
        if(head==NULL){
            head=nextnode;
            tail=nextnode;
        }else{
            tail->next=nextnode;
            tail=nextnode;
        }
        cin>>data;

    }
    return head;
}
void PrintLL(Node *head){
    while(head!=NULL){
        cout<<head->data<<nl;
        head=head->next;
    }
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    Node* head= takeinput();

    int val;cin>>val;
    cout<<findnode(head,val)<<nl;
    cout<<findnoderec(head,val)<<nl;
}


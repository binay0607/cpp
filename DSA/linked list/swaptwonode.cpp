
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


class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        next=NULL;
    }
};

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

void  swapnodes(Node* head, int i,int j){
    if(i>j)swap(i,j);
    // we are making j greater than i
    Node * forj=head, * fori= head;
    int k=j-i;

    // so as we have to reach fori to i and forj to j we go first 0 to k in forj and then 0 to i in fori and forj
    // as k+i==j forj now reaches j and we save i traversal as they are same in both 
    while(k--&& forj ){
        forj=forj->next;
    }
    while(i-- && forj){
        fori=fori->next;
        forj=forj->next;
    }

    swap(fori->data, forj->data);
    return;
    
}
void PrintLL(Node *head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<nl;
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    Node* head= takeinput();
    PrintLL(head);
    int i,j;cin>>i>>j;
    swapnodes(head,i,j);
    PrintLL(head);
}


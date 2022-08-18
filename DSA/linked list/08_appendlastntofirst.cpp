// this basically can be solved by just puting first size-n value at last

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
Node *appendn(Node *head,int size,int n){
    if(size-n<0){
        return NULL;
    }
    Node *thead=head;
    Node *heaad=head;
    int temp=size-n;
    while(thead!=NULL){
        temp--;
        if(temp==0){
            head=thead->next;
            thead->next=NULL;
            thead=head->next; //as we have set the next as null we just move to next node through head
            continue;
    

        }
        if(thead->next==NULL) {
           
            // cout<<thead->data<<nl;
            thead->next=heaad;
            break;
        }
        thead=thead->next;

    }
    return head;
    
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
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<nl;
}
int lengthrec(Node * head){
    if(head==NULL)return 0;
    else return 1+lengthrec(head->next);
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    Node* head= takeinput();
    int size=lengthrec(head);
    // cout<<size<<nl;
    int n;cin>>n;
    head=appendn(head,size,n);
    PrintLL(head);

}



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


Node* mergeLL(Node * head1, Node * head2){
   Node * fh=NULL;
   Node *ft= NULL;
    if(head1->data<=head2->data){
        fh=head1;ft=head1;
        head1=head1->next;
    }else{
        fh=head2;ft=head2;
        head2=head2->next;
        

    }

    while(head1 && head2){
        if(head1->data<=head2->data){
            ft->next=head1;
            ft=head1; // can directly right ft= ft->next as ft->next=head1;
            head1=head1->next;
            
        }else{
            ft->next=head2;
            ft=head2;
            head2=head2->next;
            
        }

        //here just could have write one statement ft=ft->next as they are same in both 
    }

    if(head1){
        ft->next=head1;
    }else{
        ft->next=head2;
    }
    return fh;
    
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
    Node* head1= takeinput();
    Node *head2= takeinput();
    // PrintLL(head1);
    // PrintLL(head2);
    Node * newhead= mergeLL(head1,head2);
    PrintLL(newhead);
    
}


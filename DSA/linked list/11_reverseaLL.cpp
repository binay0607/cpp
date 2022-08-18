
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
//n^2 approach as we are passing through the returned LL
Node* reverseLLn2(Node *head) {
	if(head == NULL || head -> next == NULL) {
		return head;
	}

	Node *smallAns = reverseLLn2(head -> next);

	Node *temp = smallAns;
	while(temp -> next != NULL) {
		temp = temp -> next;
	}

	temp -> next = head;
	head -> next = NULL;
	return smallAns;
}


// this is o(n) approach where we return both head and tail in pair
pair<Node*,Node *> reverseLL_2(Node *head) {

    //first==head, second==tail
	if(head == NULL || head -> next == NULL) {
		pair<Node*,Node *> ans;
		ans.first = head;
		ans.second = head;
		return ans;
	}

	pair<Node*,Node *> smallAns = reverseLL_2(head -> next);

	smallAns.second -> next = head;
	head -> next = NULL;
	pair<Node*,Node *> ans;
	ans.first = smallAns.first;
	ans.second = head;
	return ans;
}

Node* reverseLL_Better(Node *head) {
	return reverseLL_2(head).first;
}

//o(n) approach as current head is pointing to the last element after rec so we just use it
Node* reverseLL(Node *head) {
	if(head == NULL || head -> next == NULL) {
		return head;
	}

	Node *smallAns = reverseLL(head -> next);

	Node *tail = head -> next;
	tail -> next = head;
	head -> next = NULL;
	return smallAns;
}

// this is an iterative approach in recursive way here we keep track of both prev and next and keep changing the links
Node *reverse(Node *head,Node *prev)
{
if(head==NULL)
return head;
if(head->next==NULL)
{
head->next=prev;
return head;
}
Node *temp=head->next;
head->next=prev;
return reverse(temp,head);
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
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    Node* head= takeinput();
    
    head=reverse(head,NULL);//iterative one, NULL is intialized prev 
    PrintLL(head);
    head=reverseLL(head);
    PrintLL(head);

}


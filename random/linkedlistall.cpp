// singly linked list
// #include<bits/stdc++.h>
// using namespace std;

//     class node{
//         public:
//         int data;
//         node* next;

//         node(int val){
//             data= val;
//             next=NULL;
//         }

//     };
    
//     // insertion at end
//     void insertatend(node* &head, int val){
        
//         node* n=new node(val);
//         if(head==NULL){
//             head=n;
//             return;
//         }
//         node* temp=head;
//         while(temp->next!=NULL){
//             temp=temp->next;
//         }
//         temp->next=n;
//     }
//     // insertion at start
//     void insertatstart(node* &head, int val){
//         node* n=new node(val);
//         n->next=head;
//         head=n;
//     }
//     // traversal: display
//     void display(node* head){
//         node* temp=head;
//         while(temp!=NULL){
//             cout<<temp->data<<" ";
//             temp=temp->next;
//         }
//         cout<<endl;
//     }
//     // searching
//     bool search(node* head, int key){
//         node* temp=head;
//         while(temp!=NULL){
//             if(temp->data=key){
//                 return true;
//             }
//             temp=temp->next;
//         }
//         return false;
//     }
//     // deletion
//     void deletion(node* &head, int val){
//         if(head==NULL){
//                 cout<< " the list is empty;";
//                 return;
//         }
//         else if(head->data==val){
//             node* todel=head;
//             head= head->next;
           
//             delete todel;

//         }
//         else{
//             node* temp=head;
//             while(temp->next->data!=val){           //(temp->next)->data
//             temp= temp->next;
//             }
//             node* todel= temp->next;
//             temp->next=temp->next->next;
//             delete todel;
//         }

       
//     }
//     // reverseiterative
//     node* reverse(node* &head){
//         node* prev= NULL;
//         node*current= head;
//         node* next;
//         while(current!=NULL){
//             next=current->next;
//             current->next=prev;

//             prev=current;
//             current= next;
//         }
//         return prev;
//     }
//     // reverse recursive
//     node* recursiverev(node* &head){
//             if(head==NULL || head->next==NULL){
//                 return head;
//             }
//             node* newhead= recursiverev(head->next);
//             head->next->next=head;
//             head->next=NULL;
//             return newhead;
//     }
//     // reversing k nodes
//     // for k=2
//     // 1 2 3 4 5 6
//     // gives = 2 1 4 3 6 5 
//     node* reversek(node* head, int k){
//         node* prev= NULL;
//         node* current= head;
//         node* next;
//         int count=0;
//         while(current!=NULL && count<k){
//             next=current->next;
//             current->next=prev;
//             prev= current;
//             current= next;
//             count++;

//         }
//         if(next!=NULL){
//         head->next= reversek(next,k);
//         }
//         return prev;
//     }
//     // to make a cycle loop at a loop
//     void makeCycle(node* &head, int pos){
//         node* temp=head;
//         node* startnode;
//         int count=1;
//         while(temp->next!=NULL){
//             if(count==pos){
//                 startnode=temp;
//             }
//             temp= temp->next;
//             count++;
//         }
//         temp->next=startnode;
//     }
//     // to detect loop
//     bool detectcycle(node* &head){
//         node* slow=head;
//         node* fast=head;
//         while(fast!=NULL && fast->next!=NULL){
//             slow=slow->next;
//             fast=fast->next->next;

//             if(fast==slow){
//                 return true;
//             }
//         } 
//         return false;
//     }
//     // to remove the loop
//     void removecycle(node* head){
//         node* slow=head;
//         node* fast = head;

//         do{
//             slow= slow->next;
//             fast= fast->next->next;

//         }while(slow!=fast);
//         fast=head;
//         while(slow->next!= fast->next){
//             slow= slow->next;
//             fast= fast->next;

//         }
//         slow->next=NULL;
//     }
    
//     int main(){
//             node* head=NULL;
//             insertatend(head,1);
//             insertatend(head,2);
//             insertatend(head,3);
//             insertatend(head,4);
//             // display(head);
//             insertatstart(head,5);
//             // display(head);
            
//             // cout<<search(head,3)<<endl;
//             // deletion(head,5);
//             // display(head);
//             // node* newhead= reverse(head);
//             // display(newhead);
//             // node* newhead2= recursiverev(newhead);
//             // display(newhead2);
//             // int k=2;
//             // node* newhead3=reversek(head,k);
//             // display(newhead3);
//             makeCycle(head,3);
//             // display(head);
//             cout<<detectcycle(head)<<endl;
//             removecycle(head);
//             cout<<detectcycle(head)<<endl;



//     }


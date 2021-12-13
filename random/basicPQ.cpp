#include<bits/stdc++.h>
using namespace std;
 bool isPrime(int x){
        for(int i=2;i<x;i++){
            if(x%i==0){
                return false;
            }

        }
        
        return true;
    }
void fib(int x){
    int t1=0;
    int t2=1;
    int next;
    for(int i=1;i<=x;i++){
        cout<<t1<<" ";
        next=t1+t2;
        t1=t2;
        t2=next;

    }
    
}
int fact(int x){
    int factorial=1;
    for(int i=2;i<=x;i++){
        factorial*=i;
    }
    return factorial;
}
int main(){
    // prime number
    // int n;
    // cin>>n;
    // int i;
    // bool flag=1;
    // for(i=2;i<sqrt(n);i++){  //we just need to find till sqrt(n)
    //     if(n%i==0){
    //         cout<<"Not prime";
    //         flag=0;
    //         break;
    //     }
    // }
    // if(flag){
    //     cout<<"Prime";

    // }
    // ######################################################################################################################
    // // // reversing a number
    // cout<<"Enter a number: ";
    // int n;
    // cin>>n;
    // int reverseN=0;
    // while(n>0){
       
    //     reverseN= reverseN*10 + (n%10);
    //     n=n/10;
    // }
    // cout<<"Reverse of the number is: "<<reverseN;
    // #######################################################################
    // armstrong number 153=1^3+5^3+3^3
    // cout<<"Enter a number: ";
    // int n;
    // cin>>n;
    // int sum=0;
    // int realN=n;
    // while(n){
    //     sum=sum+pow(n%10,3);
    //     n=n/10;
    // }
    // if(sum==realN){
    //     cout<<"Armstrong";
    // }
    // else{
    //     cout<<"Not Armstrong";
    // }
    // ##############################################################################################
    // FUNCTION PROBLEMS
    // prime numeber between a to b
    // int a,b; cin>>a>>b;
    // for(int i=a;i<=b;i++){
    //     if(isPrime(i)){
    //         cout<<i<<" ";
    //     }
    // }
    // ##############################################################################################3
    // n terms of fibonacci sequence 
    // int n; cin>>n;
    // fib(n);
    // return 0;
    // ######################################################################################
    // factorial
    // int n;
    // cin>>n;
    // int ans= fact(n);
    // cout<<ans<<" ";
    
    


    
    

}
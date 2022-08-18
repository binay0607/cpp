#include<bits/stdc++.h>
using namespace std;
#define nl '\n'


//eulortotient funtion(phi() func) is used to find for a number n the numbers <=n which are coprime to it
//two formula to remember
//-> a^m-1= 1 mod m
//-> a^phi(n)= 1 mod m 

//formula=> p1, p2, p3 being prime factors of n
// phin(n)= n* (1-1/p1)* (1-1/p2)*............
//phin(n)= n* ((p1-1)/p1)* ((p2-1)/p2)*...........
int main(){
    int n;cin>>n;
    int number=n;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            while(n%i==0){
                n/=i;
            }
            number=(number/i)*(i-1);
        }
    }
    if(n>1){
        number= (number/n)*(n-1);
    }
    cout<<number<<nl;

}
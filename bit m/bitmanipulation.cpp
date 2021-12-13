#include<bits/stdc++.h>
using namespace std;
// know the bit at pos
int getBit(int n,int pos){
    return ((n& (1<<pos))!=0); 
    // for n=5=0101
    // 1<<(pos=2)= 0100
    // 0101 & 0100 => returns true 1
    // 1<<(pos=1)=0010
    // 0101 & 0010 => retuen false 0
}
int setBit(int n, int pos){ //sets 1 at the pos
       return ( n | (1<<pos));   

}
int clearBit(int n , int pos){ //sets 0 at pos
        int mask= ~(1<<pos);
        return(n & mask);

}
int updateBit(int n, int pos, int val){ //update value at pos
    int x= clearBit( n, pos);
    return (x | (val<<pos));
}
int ispoweroftwo(int n){ //check if number is power of 2 
// for all number which are power of 2 => n& n-1==0
        return (n && !(n & n-1)); //n is for case =0 ie check n is positive
}
int numofones(int n){   //to count number of 1 in its binary form
        int count=0;
        while(n){
            n= n & (n-1);
            count++;
        }
}
void subsets(int arr[],int n){ //all subsets of n
        for(int i=0; i< (1<<n);i++){
            for(int j=0;j<n;j++){
                if(i & (1<<j)){
                    cout<<arr[j]<<" ";
                }
            }cout<<endl;
        }
}
// find unique number in a array {2,4,6,3,4,6,2}=>3
// xor of same number twice gives 0
// xor of a number with 0 gives the same number 
int unique(int arr[],int n){
    int xorsum=0;
    for(int i=0;i<n;i++){
            xorsum= xorsum^arr[i];
    }
    return xorsum;

}
int main(){
    // cout<<getBit(5,2)<<endl; //gives 1 from 0101
    // cout<<setBit(5,1)<<endl;
    // cout<<clearBit
    
    
    // cout<< updateBit(5,1,1)<<endl; 
    // cout<<ispoweroftwo(7)<<endl; 
    // cout<<numofones(15)<<endl;
    // int arr[4]={1,2,3,4};
    // subsets(arr,4);
    int arr[7]={2,4,6,3,4,6,2};
    cout<<unique(arr,7)<<endl;



}
#include<bits/stdc++.h>
using namespace std;
int linearSearch(int arr[],int n,int key){
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            return i;
        }
    }
    return -1;

}
int binarySearch(int arr[],int n,int key){
    int start=0;
    int end=n;
    while(start<end){
        int mid=(start+end)/2;
        if(arr[mid]==key){
            return mid;
        }
        else if(arr[mid]>key){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    return -1;
}
int main(){
    // maximum and minimum
    // int n;
    // cin>>n;
    // int arr[n];
    // int max=INT_MIN; //min value of int  (have to include <climits>)
    // int min= INT_MAX; //max value of int

    // for(int i =0;i<n;i++){
    //     cin>>arr[i];
    // }
    // for(int i =0;i<n;i++){
    //     if(arr[i]<min){
    //         min=arr[i];
    //     }
    //     // or can do: minno=min(minno,arr[i])
    //     if(arr[i]>max){
    //         max=arr[i];
    //     }
    // }
    // cout<<max<<" "<<min;
    // ##################################################################################
    // searching a key in array
    int n;
    cin>>n;
    int arr[n];
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
    // int key;
    // cin>>key;
    // // linear search
    // int ans=linearSearch(arr,n,key);
    // cout<<ans;
    // // binarysearch for sorted array only
    // int ans2=binarySearch(arr,n,key);
    // cout<<ans2;
    // sorting
    // selection sort
    // for(int i=0;i<n-1;i++){  //1st to n-1 th elements
    //     for(int j=i+1;j<n;j++){ //2nd to nth elements
    //         if(arr[j]<arr[i]){
    //             int temp=arr[j];
    //             arr[j]=arr[i];
    //             arr[i]=temp;
    //         }
    //     }
    // }
    //  for(int i =0;i<n;i++){
    //     cout<<arr[i]<<" ";
    // }
    // bubble sort
    // for(int i=0;i<n;i++){  
    //     for(int j=0;j<n-i;j++){ 
    //         if(arr[j]>arr[j+1]){
    //             int temp=arr[j];
    //             arr[j]=arr[j+1];
    //             arr[j+1]=temp;
    //         }
    //     }
    // }
    //  for(int i =0;i<n;i++){
    //     cout<<arr[i]<<" ";
    // }
    // insertion sort
    for(int i=0;i<n;i++){  
       int current=arr[i];
       int j=i-1;
       while(arr[j]>current && j>=0){
           arr[j+1]=arr[j];
           j--;
       }
       arr[j+1]=current;
    }
     for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }

}
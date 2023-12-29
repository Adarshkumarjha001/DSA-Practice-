#include <iostream>
using namespace std;
bool binarysearch(int *arr,int n,int key){
    int s=0;
    int e=n-1;
    int m=s-(s-e)/2;
    while(s<e){
    if(key==arr[m]){
        return 1;
    }
    else if(key>arr[m]){
        s=m+1;
    }
    else{
        e=m-1;
    }
    m=s-(s-e)/2;
    }
    return 0;
    
    
}
int main() {
    int arr[100];
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int key;
    cin>>key;
    if(binarysearch(arr,n,key)){
        cout<<"Found";
    }
    else{
        cout<<"Not Found";
    }

    return 0;
}

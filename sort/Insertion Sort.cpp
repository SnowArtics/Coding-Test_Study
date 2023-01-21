#include <bits/stdc++.h>

using namespace std;

int n=10;
int arr[10] = {7,5,9,0,3,1,6,2,4,8};

int main()
{
    
    for(int i=1;i<sizeof(arr)/sizeof(*arr);i++){
        
        for(int j=i-1;j>=0;j--){
            if(arr[j+1]<arr[j]) swap(arr[j+1],arr[j]);
            else break;
        }
    }
    
    for(int i=0;i<sizeof(arr)/sizeof(*arr);i++){
        cout<<arr[i]<<endl;
    }

    return 0;
}
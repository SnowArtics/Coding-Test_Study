#include <bits/stdc++.h>

using namespace std;

int binarySearch(vector<int> &array, int target, int start, int end){
    while(start<=end){
        int mid = (start+end)/2;
        
        if(array[mid]==target) return mid+1;
        
        else if(array[mid]>target) end = mid -1;
        
        else start = mid+1;
    }
    
    return -1;
}

int main(void) {
    vector<int> array;
    
    int n, target;
    cin>>n>>target;
    
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        array.push_back(x);
    }
    
    int result = binarySearch(array,target, 0,n-1);
    
    cout<<endl<<result;

}
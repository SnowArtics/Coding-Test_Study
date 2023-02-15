#include <bits/stdc++.h>

using namespace std;

int binarySearch(vector<int> &array, int target, int start, int end){
    if(start>end) return -1;
    
    int mid = (start+end)/2;
    
    if(array[mid]==target) return mid+1;
    
    else if(array[mid]>target) return binarySearch(array, target, start, mid-1);
    
    else return binarySearch(array,target,mid+1,end);
    
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
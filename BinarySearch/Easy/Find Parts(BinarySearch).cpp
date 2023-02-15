//Time Complexity : (M+N) * logN

#include <bits/stdc++.h>

using namespace std;

int binarySearch(vector<int> &array, int target, int start, int end){
    if(start>end) return -1;
    
    int mid = (start + end)/2;
    
    if(array[mid]==target) return mid;
    
    else if(array[mid]>target) return binarySearch(array, target, start, mid-1);
    
    else return binarySearch(array, target, mid+1, end);
}

int main()
{
    int N, M;
    vector<int> part_array;
    vector<int> estimate;
    
    cin>>N;
    
    for(int i=0;i<N;i++){
        int x;
        cin>>x;
        part_array.push_back(x);
    }
    
    cin>>M;
    
    for(int i=0;i<M;i++){
        int x;
        cin>>x;
        estimate.push_back(x);
    }
    
    sort(part_array.begin(),part_array.end());
    
    for(int i=0;i<M;i++){
        if(binarySearch(part_array,estimate[i],0,N-1)==-1) cout<<"no"<<' ';
        else cout<<"yes"<<' ';
    }
    
}
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, k;
    vector<int> arr;
    int result = 0;
    
    cin>>n>>m>>k;
    
    for(int i=0;i<n;i++){
        int input = 0;
        cin>>input;
        
        arr.push_back(input);
    }
    
    sort(arr.begin(),arr.end());
    
    for(int i=0;i<m;i++){
        if(((i+1)%(k+1))==0){
            result+=arr[n-2];
            cout<<result<<"arr2"<<endl;
            continue;
        }
        result+=arr[n-1];
        cout<<result<<"arr1"<<endl;
    }
    
    cout<<result;
}
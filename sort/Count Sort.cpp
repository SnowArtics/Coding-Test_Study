#include <bits/stdc++.h>

using namespace std;

vector<int> arr = {7,5,9,0,3,1,6,2,9,1,4,8,0,5,2};

int main()
{
    int max = *max_element(arr.begin(),arr.end());
    vector<int> result(max+1,0);
    
    for(int i=0;i<arr.size();i++){
        result[arr[i]]++;
    }
    
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i];j++){
            cout<<i<<' ';
        }
    }

    return 0;
}
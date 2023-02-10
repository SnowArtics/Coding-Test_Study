#include <bits/stdc++.h>

using namespace std;

bool compare(int a, int b){
    return a>b;
}

int main()
{
    int range = 0;
    vector<int> array;
    cin>>range;
    
    for(int i=0;i<range;i++){
        int num = 0;
        cin>>num;
        array.push_back(num);
    }

    sort(array.begin(),array.end(),compare);
    
    for(int i=0;i<range;i++){
        cout<<endl<<array[i]<<' ';
    }

    return 0;
}
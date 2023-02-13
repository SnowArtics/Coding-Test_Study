#include <bits/stdc++.h>

using namespace std;

bool compare(pair<string,int>a,pair<string,int>b){
    return a.second<b.second;
}

int main()
{
    vector<pair<string,int> > list;
    int N;
    cin>>N;
    
    for(int i=0;i<N;i++){
        string name;
        int num;
        cin>>name;
        cin>>num;
        
        list.push_back({name,num});
    }
    
    sort(list.begin(),list.end(),compare);
    
    for(int i=0;i<N;i++){
        cout<<list[i].first<<' ';
    }

    return 0;
}

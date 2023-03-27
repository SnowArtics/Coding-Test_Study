/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    vector<char> string;
    
    int result = 0;
    
    for(int i=0;i<s.length();i++){
        char temp = s[i];
        
        string.push_back(temp);
    }
    
    for(int i=0;i<s.length();i++){
        int count = 0;
        for(int j=i+1;j<s.length();j++){
            if(string[i]!=string[j]){
                count += j-i;
            }
            if(string[i]==string[j]){
                count += count;
            }
        }
        result += count;
    }
    
    cout<<result;
    
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

set<set<string>> _setResult;

bool CompareString(string& _banned, string& _user){    
    if(_banned.size() != _user.size()) return false;
    for(int i=0;i<_banned.size();++i){
        if(_banned[i] == '*') continue;
        if(_banned[i] != _user[i]) return false;
    }
    return true;
}

// 받은 문자열을 set에 있는지 비교해서 넣음
void DFS(vector<vector<string>>& _string, int _i, set<string>& result){
    if(_string.size() == _i){
        _setResult.insert(result);
        return;
    }
    for(int i=0;i<_string[_i].size();++i){
        if(result.find(_string[_i][i]) != result.end()) continue;
        result.insert(_string[_i][i]);
        DFS(_string, _i+1, result);
        result.erase(_string[_i][i]);
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    vector<vector<string>> banned_list;
    for(int i=0;i<banned_id.size();++i){
        vector<string> temp_banned_list;
        for(int j=0;j<user_id.size();++j){
            if(CompareString(banned_id[i], user_id[j]))
                temp_banned_list.push_back(user_id[j]);
        }
        banned_list.push_back(temp_banned_list);
    }
    
    set<string> tempSet;
    DFS(banned_list, 0, tempSet);
    
    return _setResult.size();
}
#include <bits/stdc++.h>
using namespace std;

int common(int,int);
tuple<bool,vector<int>,vector<int>> dfs(int ,int ,int ,vector<int>& );

int main() {
    int n;
    cin>>n;
    int c;
    vector<int> cards(n);
    for(int i=0; i<n; i++) {
        cin>>c;
        cards[i] = c;
    }
    
    tuple<bool,vector<int>,vector<int>> res = dfs(0,0,0,cards);
    if(get<0>(res)) {
        cout<<"YES\n";
        cout<<get<1>(res).size()<<" "<<get<2>(res).size()<<endl;
        for(int card: get<1>(res))
            cout<<card<<" ";
        cout<<endl;
        for(int card: get<2>(res))
            cout<<card<<" ";
        return 0;
    }
    cout<<"NO";
}

tuple<bool,vector<int>,vector<int>> dfs(int sum,int other,int i,vector<int>& cards) {
    if(i >= cards.size()) return {0,{},{}};
    if(common(sum+cards[i],other)) {
        return {1,{i},{}};
    }
    if(common(sum,other+cards[i])) {
        return {1,{},{i}};
    }
    if(common(sum,other)) {
        return {1,{},{}};
    }
    tuple<bool,vector<int>,vector<int>> res;
    res = dfs(sum,other,i+1,cards);
    if(get<0>(res)) return res;
    
    res = dfs(sum+cards[i],other,i+1,cards);
    if(get<0>(res)) {
        get<1>(res).push_back(i);
        return res;
    }
    
    res = dfs(sum,other+cards[i],i+1,cards);
    if(get<0>(res)) {
        get<2>(res).push_back(i);
        return res;
    }
    return {0,{},{}};
}

int common(int a, int b) {
    unordered_set<int> nums;
    for(int i=1; i<(a>>1); i++) {
        int n = a/i;
        if(n*i == a)
            if(n!=1) nums.insert(n);
    }
    for(int i=1; i<(b>>1); i++) {
        int n = b/i;
        if(n*i == b)
            if(nums.count(n)) return true;
    }
    return false;
}
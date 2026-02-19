#include <bits/stdc++.h>
using namespace std;

int common(int,int);

int main() {
    int n;
    cin>>n;
    int c;
    vector<int> cards(n);
    for(int i=0; i<n; i++) {
        cin>>c;
        cards[i] = c;
    }
    if(n==2) {
        if(common(cards[0],cards[1])) {
            cout<<"YES\n1 1\n1\n2";
            return 0;
        }
    } else {
        if(common(cards[0],cards[1])) {
            cout<<"YES\n1 1\n1\n2";
            return 0;
        }
        if(common(cards[0],cards[2])) {
            cout<<"YES\n1 1\n1\n3";
            return 0;
        }
        if(common(cards[1],cards[2])) {
            cout<<"YES\n1 1\n2\n3";
            return 0;
        }
    }
    
    cout<<"NO";    
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
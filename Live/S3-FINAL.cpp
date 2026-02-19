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
        
        if(common(cards[0]+cards[1],cards[2])) {
            cout<<"YES\n2 1\n1 2\n3";
            return 0;
        }
        if(common(cards[0]+cards[2],cards[1])) {
            cout<<"YES\n2 1\n1 3\n2";
            return 0;
        }
        if(common(cards[1]+cards[2],cards[0])) {
            cout<<"YES\n2 1\n2 3\n1";
            return 0;
        }
    }
    
    cout<<"NO";    
}
int common(int a, int b) {
    unordered_set<int> nums;
    for(int i=1; i<=a; i++) {
        int n = a/i;
        if(n*i == a)
            if(i!=1) nums.insert(i);
    }
    for(int i=1; i<=b; i++) {
        int n = b/i;
        if(n*i == b)
            if(nums.count(i)) return true;
    }
    return false;
}
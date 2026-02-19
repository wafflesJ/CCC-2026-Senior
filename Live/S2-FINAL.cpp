#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,l,q;
	cin>>n>>l>>q;
    vector<int> counter(n,0);
    for(int i = 0; i<l; i++) {
        int p,s;
        cin>>p>>s;
        --p;
        int pos = p-s;
        int spread = (2*s)+1;
        if(pos < 0) {
            spread+=pos;
            pos = 0;
        }
        counter[pos] = max(spread,counter[pos]);
    }
    vector<bool> lit(n,0);
    int count = 0;
    for(int i=0; i<n; i++) {
            count = max(count,counter[i]);
            if(count--)
                lit[i] = 1;
    }
    
    int p;
    for(int i=0; i<q; i++) {
        cin>>p;
        cout<<(lit[p-1]?"Y":"N")<<endl;
    }
}

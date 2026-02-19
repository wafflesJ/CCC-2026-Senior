#include <bits/stdc++.h>
using namespace std;


int main() {
	long long a,b,k,t;
	cin>>a>>b>>k>>t;
	if(a==b) {
	    cout<<(t==1?0:2);
	    return 0;
	}
	long long offset = max(a-b,b-a)%k;
	long long count  = max(a-b,b-a)/k;
	if(t==1) {
        cout<<min(offset+count,count+1+k-offset);
	} else if (offset==0) {
        cout<<max(offset+count,count-1+k-offset);
    } else {
        cout<<max(offset+count,count+1+k-offset);
    }
}

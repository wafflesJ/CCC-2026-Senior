#include <bits/stdc++.h>
using namespace std;


int main() {
	long long a,b,k,t;
	cin>>a>>b>>k>>t;
    if(k==abs(a-b)) {
        cout<<(t==1?1:k);
        return 0;
    }
	long long offset = abs(a-b)%k;
	long long count  = abs(a-b)/k;
	if(t==1)
        cout<<min(offset+count,count+1+k-offset);
    else
        cout<<max(offset+count,count+1+k-offset);
}

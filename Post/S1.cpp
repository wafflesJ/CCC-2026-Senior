#include <bits/stdc++.h>
using namespace std;
using llong = long long;
int main() {
	llong a,b,k,t;
	cin>>a>>b>>k>>t; --t;
	if(a==b) {
	    cout<<(t?2:0);
	    return 0;
	}
	llong dif = abs(a-b);
	if(k<=1) {
	    cout<<(dif+2*t);
	    return 0;
	}
	llong count  = dif/k;
	llong offset = dif-count*k;
	llong res =  min(count+offset,1+count+dif-offset);
	cout<<res+(t?(k==2?1:2):0);
}

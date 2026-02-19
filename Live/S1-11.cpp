#include <bits/stdc++.h>
using namespace std;

long long mod(long long a, long long b) {
    while(a>0) a-=b;
}

int main() {
	long long a,b,k,t;
	cin>>a>>b>>k>>t;
	if(a==b) {
	    cout<<(t==1?0:2);
	    return 0;
	}
	if(k==0||k==1) {
	    cout<<(t==1?max(a-b,b-a):max(a-b,b-a)+2);
	    return 0;
	}
	long long offset = max(a-b,b-a)%k;
	long long count  = max(a-b,b-a)/k;
	if(t==1) {
        cout<<min(offset+count,count+1+k-offset);
	} else if (offset==0) {
        cout<<max(offset+count,count-1+k-offset);
    } else {
        cout<<min(2+min(offset+count,count+1+k-offset),max(offset+count,count+1+k-offset));
    }
}


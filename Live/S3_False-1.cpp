#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    cout<<100<<endl;
    for(int k=0;k<100;k++) {
        cout<<(10e5/2)<<" "<<(10e5/2)<<endl;
        int index = 0;
        for(int i=0;i<10e5;i++) {
            cout<<index<<" ";
            index+=k;
            if(index>=10e5) index -= 10e5;
        }
        cout<<endl;
        index = 1;
        for(int i=0;i<10e5;i++) {
            cout<<index<<" ";
            index+=k;
            if(index>=10e5) index -= 10e5;
        }
    }
}

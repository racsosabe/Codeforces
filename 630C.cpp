#include<bits/stdc++.h>
using namespace::std;

int main(){
	int n;
	cin >> n;
	long long q = 1LL;
	if(n < 32){
		cout << (1<<(n+1))-2 << endl;
	}
	else{
		q <<= 31;
		n-=31;
		cout << (q<<(n+1))-2 << endl;
	}
	return 0;
}
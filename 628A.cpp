#include<bits/stdc++.h>
using namespace::std;

long long msb(long long n){
	long long number = n;
	number |= number>>1;
	number |= number>>2;
	number |= number>>4;
	number |= number>>8;
	number |= number>>16;
	return (number+1)>>1;
}

int main(){
	long long n,b,p;
	int count = 0;
	cin >> n >> b >> p;
	long long match = 2*b+1;
	long long towels = n*p;
	while(n!=1){
		count += msb(n)>>1;
		n = (long long)(msb(n)>>1) + n - msb(n);
	}
	cout << count*match << " " << towels << endl;
	return 0;
}
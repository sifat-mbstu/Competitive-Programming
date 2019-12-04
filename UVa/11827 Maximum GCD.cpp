#include<bits/stdc++.h>
using namespace std;

int GCD(int a, int b){
	if(a%b==0) return b;
	return GCD(b,a%b);
}

int main(){
	int T,N,a[99],ans;
	string s;

	cin>>T;
	getline(cin,s);

	while(T--){
		getline(cin,s);
		istringstream is(s);
		N = 0;

		while(is>>a[N]) ++N;

		ans = 0;

		for(int i = 0;i<N;++i)
			for(int j = i+1;j<N;++j)
				ans = max(ans,GCD(a[i],a[j]));

		cout<<ans<<endl;
	}
	return 0;
}

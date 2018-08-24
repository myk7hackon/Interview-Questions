#include<bits/stdc++.h>
using namespace std;
int nth_prime(int n){
	int check=0;int c=0;
	for(int i=2;i<100000;i++){
		check=0;
		for(int j=2;j<=i/2;j++){
			if(i%j==0){
				check=1;break;
			}
		}
			if(check==0)
				c++;
			if(c==n)
				return i;
		}
	}	

int return_val(int x,int y){
	if(abs(x)>abs(y)){
		if(x>0){
			return (4*x*x-3*x+y);
		}
		else{
			return (4*x*x-x-y);
		}
	}
	else{
		if(y>0){
			return (4*y*y-y-x);
		}
		else{
			return (4*y*y-3*y+x);
		}
	}
}
int main(){
	char inp[4];
	int n;int x,y;int val;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>inp;
		x=inp[0]-'0';
		if(x<0)
			{x=(-1)*(inp[1]-'0');}
		y=inp[2]-'0';
		if(y<0)
			{y=(inp[3]-'0');
				if(y<0)
				{y=(-1)*(inp[4]-'0');}
			}
		//cout<<x<<" "<<y<<"\n";
		val=return_val(x,y)+1;
		cout<<val<<"\n";
		int ans=nth_prime(val);
		cout<<ans;
	}

	return 0;
}
#include<bits/stdc++.h>
using namespace std;
bool isSquareFree(int n)
{
    if (n % 2 == 0)
       n = n/2;
    if (n % 2 == 0)
       return false;
    for (int i = 3; i <= sqrt(n); i = i+2)
    {
        if (n % i == 0)
        {
           n = n/i;
           if (n % i == 0)
               return false;
        }
    }
 
    return true;
}
std::vector<int> printDivisors(int n)
{
    std::vector<int> v;
    for (int i=2; i<=sqrt(n); i++)
    {
        if (n%i == 0)
        {
            if (n/i == i)
                v.push_back(i);
            else 
                {v.push_back(i);
            	v.push_back(n/i);}
        }
    }
    return v;
}
int main(){
	int n;int count=0;
	cin>>n;
	std::vector<int> v=printDivisors(n);
	for(int i=0;i<v.size();i++){
		if(isSquareFree(v[i])){
			count+=1;
		}
	}
	cout<<count<<"\n";
}
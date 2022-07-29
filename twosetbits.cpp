#include<cmath>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define maxi 10000
#define mod = 10000000007
long long int bits[maxi+1];
long long int sum;
long long binsearch(long long int n){
    long long int l = 0, h = maxi, mid;
    while(l<h){
        mid = l+(h-l+1)/2;
        if(bits[mid]<=n) l = mid;
        else h = mid-1;
    }
    return l;
}
int main(){
    bits[0] = 1;
    for(long long int i = 1; i <= maxi; i++){
        bits[i] = bits[i-1] + i;
    }
    long long int n,k,l;
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        k = binsearch(n);
        l = n-bits[k];
        cout<<(((1<<k+1)%mod+(1<<l)%mod)%mod)<<"\n";
    }
    return 0;
}
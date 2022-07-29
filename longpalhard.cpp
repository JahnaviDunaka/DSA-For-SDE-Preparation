#include<iostream>
using namespace std;
bool valid_check(long pHA[], long sHA[], int p1, int p2, long pow[], int n, int mod){
    long pre_sum = 0;
    if(p1 > 0){
        pre_sum = (pHA[p2] - pHA[p1-1] + mod)%mod;
    }
    else{
        pre_sum = pHA[p2];
    }
    long suf_sum = 0;
    if(p2 == n-1){
        suf_sum = sHA[p1];
    }
    else{
        suf_sum = (sHA[p1] - sHA[p2+1] + mod)%mod;
    }
    int diff = (n-p2)-(p1+1);
    if(diff<0){
        suf_sum = (suf_sum*pow[abs(diff)])%mod;
    }
    else if(diff != 0) pre_sum = (pre_sum*pow[diff])%mod;
    if(pre_sum == suf_sum){
        return true;
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tgh;
    cin>>tgh;
    while(tgh--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        long pHA[n];
        long sHA[n];
        long pow[n+1];
        long mod = 1e9+7;
        int prime = 31;
        pow[0] = 1;
        pow[1] = prime;
        for(int i = 2; i <= n; ++i){
            pow[i] = (pow[i-1]*prime)%mod;
        }
        pHA[0] = (s[0]*pow[1])%mod;
        for(int i = 1; i < n; i++){
            pHA[i] = (pHA[i-1]+(s[i]*pow[i+1])%mod)%mod;
        }
        sHA[n-1] = (s[n-1]*pow[1])%mod;
        for(int i = n-2; i >= 0; --i){
            sHA[i] = (sHA[i+1]+(s[i]*pow[n-i])%mod)%mod;
        }
        int odd_dist = 0, even_dist = 0;
        long maxi = 0;
        int xnx = s.length();
        for(int i = 0; i < xnx; ++i){
            int p1 = i-odd_dist, p2 = i+odd_dist;
            if(p1 >= 0 && p2 < xnx && valid_check(pHA,sHA,p1,p2,pow,n,mod) == true){
                while(p1 >= 0 && p2 < xnx && s[p1] == s[p2]){
                    if(p2-p1+1 > maxi){
                        maxi = p2-p1+1;
                    }
                    odd_dist++;
                    --p1;
                    ++p2;
                }
            }
            p1 = i-even_dist, p2 = (i+1)+even_dist;
            if(p1 >= 0 && p2 < xnx && valid_check(pHA,sHA,p1,p2,pow,n,mod) == true){
                while(p1 >= 0 && p2 < xnx && s[p1] == s[p2]){
                    if(p2-p1+1 > maxi){
                        maxi = p2-p1+1;
                    }
                    even_dist++;
                    --p1;
                    ++p2;
                }
            }
        }
        cout<<maxi<<"\n";
    }
}
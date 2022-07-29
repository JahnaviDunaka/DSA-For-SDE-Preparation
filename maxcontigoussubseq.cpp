#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int tgh;
    cin>>tgh;
    while(tgh--){
        int n;
         cin>>n;
         int a[n];
         for(int i = 0; i < n; i++){
             cin>>a[i];
        }
        int s[n];
        s[0] = a[0];
        int x = 0, y = 0;
        for(int i = 1; i < n; i++){
            s[i] = max(s[i-1]+a[i],a[i]);
            if(a[i] > s[i-1]){
                x = i;
            }
            else{
                y = i;
            }
        }
        cout<<y-x<<endl;
    }
}
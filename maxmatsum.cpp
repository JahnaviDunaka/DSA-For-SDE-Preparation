#include<iostream>
#include<vector>
using namespace std;
int main(){
    int tgh;
    cin>>tgh;
    while(tgh--){
        
        int n, m;
        cin>>n>>m;
        vector<vector<int>>grid(n,vector<int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j  < m; j++){
                int x;
                cin>>x;
                grid[i][j] = x;
            }
        }
        vector<vector<int>>sum(n+1, vector<int>(m+1));
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                sum[i][j] = max(sum[i-1][j], sum[i][j-1])+grid[i-1][j-1];
            }
        }
        cout<<sum[n][m]<<endl;
    }
    return 0;
}
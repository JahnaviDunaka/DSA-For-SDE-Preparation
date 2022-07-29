#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
void rightView(TreeNode* root){
    if(!root) cout<<""<<"\n";
    queue<TreeNode*>q,q1;
    vector<int>sol,res;
    q.push(root); 
    while(true){
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            if(curr->left) q1.push(curr->left);
            if(curr->right) q1.push(curr->right);
            res.push_back(curr->val);
        }
        if(!res.empty()) sol.push_back(res[0]);
        res.clear();
        q = q1;
        while(!q1.empty()) q1.pop();
        if(q.empty()) break;
    }
    int n = sol.size();
    for(int i = 0; i < n; i++){
        cout<<sol[i]<<" ";
    }
}
TreeNode* insert(TreeNode* root, int ele){
    if(!root) return new TreeNode(ele);
    if(ele < root->val) root->left = insert(root->left, ele);
    if(ele > root->val) root->right = insert(root->right, ele);
    return root;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        int a[N];
        for(int i = 0; i < N; i++){
            cin>>a[i];
        }
        TreeNode *root = new TreeNode(a[0]);
        for(int i = 1; i < N; i++){
            insert(root,a[i]);
        }
        rightView(root);
    }
    return 0;
}

#include<iostream>
using namespace std;
int rev(int n){
    static int rev_num = 0;
    static int base_pos = 1;
    if(n > 0){
        rev(n/10);
        rev_num += n%10*base_pos;
        base_pos *= 10;
    }
    return rev_num;
}
int main(){
    int num;
    cin>>num;
    cout<<rev(num)<<endl;
}
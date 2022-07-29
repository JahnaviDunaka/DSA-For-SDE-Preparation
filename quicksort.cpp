#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool compare(int a, int b){
    return a<=b;//for ascending
    //return a>=b; //for descending
}
int partition(int *a, int start, int end){
    int pivot = a[end];
    int parIdx = start;
    for(int i = start; i <= end-1; i++){
        if(compare(a[i],pivot)){
            swap(a[i], a[parIdx]);
            parIdx++;
        }
    }
    swap(a[parIdx],a[end]);
    return parIdx;
}
void quickSort(int *a, int start, int end){
    if(start < end){
        int idxOfPar = partition(a,start,end);
        quickSort(a,start,idxOfPar-1);
        quickSort(a,idxOfPar+1,end);
    }
}
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
        quickSort(a,0,n-1);
        for(int i = 0; i < n; i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
}
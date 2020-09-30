#include<iostream>

using namespace std;

int deg(int, int[]);

int main(){
    int n=3;
    int* table =new int [n+1];
    for(int i=0;i<n+1;i++){
        table[i]=-1;
    }
    cout<<deg(n, table);
    for(int i=0;i<n+1;i++){
        cout<<table[i]<< " | ";
    }
    return 0;
}

int deg(int n, int table[]){
    if(table[n]!=-1){
        return table[n];
    }
    if(n==1){
        table[n]=0;
    }
    else if(n==2){
        table[n]=1;
    }
    else{
        table[n] =(n-1) * (deg(n-2, table) + deg(n-1, table));
    }
    return table[n];
}

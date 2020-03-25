/*

Problem  : Given an amount, find the minimum number of coins required to make the exact amount of change. 
Solution : Recursive

*/

#include<iostream>
using namespace std;

int min_coins(int, int[],int);
int main(){
    int change=16;
    int coins[]={1,2,5,10};
    int size=sizeof(coins)/sizeof(coins[0]);
    cout<<min_coins(change,coins,size);
}

int min_coins(int change, int coins[], int size){
    if(change==0){
        return 0;
    }
    int min=change;
    for(int i=0;i<size;i++){
        if(change-coins[i]>=0){
            int count=min_coins(change-coins[i],coins,size);
            if(count+1<min){
                min=count+1;
            }
        }
    }
    return min;
}
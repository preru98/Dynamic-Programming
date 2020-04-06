/*

Problem  : Given an amount, find the minimum number of coins required to make the exact amount of change. 
Solution : Dynamic Programming : Top Down Approach 

*/

#include<iostream>
using namespace std;

int min_coins(int, int[],int);
int min_coins(int, int[],int,int[]);
int main(){
    int change=12;
    int coins[]={1,2,5,10};
    int size=sizeof(coins)/sizeof(coins[0]);
    cout<<min_coins(change,coins,size);
}

int min_coins(int change, int coins[], int size){
    int cache[50];
    for(int i=0;i<change;i++){
        cache[i]=-1;
    }
    return min_coins(change,coins,size,cache);
}

int min_coins(int change, int coins[],int size, int cache[]){
    if(change==0){
        return 0;
    }
    int min=change;
    for(int i=0;i<size;i++){
        if(change-coins[i]>=0){
            int count;
            if(cache[change-coins[i]]>=0){
                count=cache[change-coins[i]];
            }
            else{
                count=min_coins(change-coins[i],coins,size,cache);
                cache[change-coins[i]]=count;
            }
            if(count+1<min){
                min=count+1;
            }
        }
    }
    return min;
}

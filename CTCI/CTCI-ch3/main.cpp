//
//  main.cpp
//  CTCI-ch3
//
//  Created by EllenHu on 8/14/16.
//  Copyright © 2016 EllenHu. All rights reserved.
//

#include "main.hpp"
#include <iostream>
using namespace std;

class stack3_invided
{
public:
    stack3_invided(int size=30){
        buf=new int[size*3];
        ptop[0]=ptop[1]=ptop[2]=-1;
        this->size=size;
    }
    ~stack3_invided(){
        delete[] buf;
    }
    
    void push(int sizenum,int val){
        int index=sizenum*size+ptop[sizenum]+1;
        buf[index]=val;
        ptop[sizenum]++;
    }
    
    void pop(int sizenum){
        ptop[sizenum]--;
    }
    
    int topelem(int sizenum){
        int index=sizenum*size+ptop[sizenum];
        return buf[index];
    }
    bool isempty(int sizenum){
        return (ptop[sizenum]==-1);
    }
    
private:
    int *buf;
    int size;
    int ptop[3];
};

typedef struct node{
    int val,preindex;
}node;


class stack3_total
{
public:
    stack3_total(int size=30){
        buf=new node[size];
        this->size=size;
        ptop[0]=ptop[1]=ptop[2]=-1;
        current=0;
    }
    ~stack3_total(){
        delete[] buf;
    }
    void push(int num,int val){
        buf[++current].val=val;
        buf[current].preindex=ptop[num];
        ptop[num]=current;
    }
    void pop(int num){
        ptop[num]=buf[ptop[num]].preindex;
    }
    int topelem(int num){
        return buf[ptop[num]].val;
    }
    bool isempty(int num){
        return (ptop[num]==-1);
    }
    
    
private:
    node *buf;
    int size;
    int ptop[3];
    int current;
};


int main()
{
//    stack3_invided mystack;
    stack3_total mystack;
    for(int i=0;i<10;i++)
        mystack.push(0, i);
    for(int i=100;i<110;i++)
        mystack.push(1, i);
    for(int i=1000;i<1010;i++)
        mystack.push(2, i);
    
    for(int i=0;i<3;i++)
    {
        mystack.pop(i);
        cout<<"the top of mystack "<<i<<" is "<<mystack.topelem(i)<<endl;
    }
    
    while(!mystack.isempty(1))
    {
        cout<<mystack.topelem(1)<<" ";
        mystack.pop(1);
    }
    mystack.push(0, 111);
    mystack.push(1, 222);
    mystack.push(2, 333);
    for(int i=0; i<3; ++i)
        cout<<mystack.topelem(i)<<" ";
    return 1;
    
}
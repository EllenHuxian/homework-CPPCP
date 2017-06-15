//
//  main.cpp
//  ch3s2
//
//  Created by EllenHu on 8/14/16.
//  Copyright © 2016 EllenHu. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

typedef struct node{
    int value,min;
}node;


class StackWithMin{
public:
    StackWithMin(int size){
        buf=new node[size];
        top=-1;
        cur=-1;
    }
    ~StackWithMin()
    {
        delete[] buf;
    }
    
    void push(int value){
        if(buf[top].min>value|top==-1)
        {
            top++;
            buf[top].value=value;
            buf[top].min=value;
        }
        else if(buf[top].min<value){
            int temp=buf[top].min;
            top++;
            buf[top].value=value;
            buf[top].min=temp;
        }
    }
    void pop(){
        if(top>-1) top--;
        else cout<<"stack is empty."<<endl;
    }
    
    int getmin(){
        return buf[top].min;
    }
    
    bool isempty(){
        if(top<0) return false;
        else return true;
    }
    
    
private:
    int top;
    int cur;
    node *buf;
};


int main()
{
    StackWithMin mystack(30);
    for(int i=0;i<10;i++) mystack.push(20-i);
    cout<<mystack.getmin()<<endl;
    mystack.pop();
    cout<<mystack.getmin()<<endl;
    
}
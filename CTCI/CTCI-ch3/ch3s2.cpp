//
//  ch3s2.cpp
//  CTCI-ch3
//
//  Created by EllenHu on 8/14/16.
//  Copyright © 2016 EllenHu. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;


class StackWithMin{
public:
    StackWithMin(int size){
        buf=new int[size];
        top=-1;
        min=0;
    }
    ~StackWithMin()
    {
        delete[] buf;
    }
    
    void push(int value){
        if(top==-1) min=value;
        top++;
        buf[top]=value;
        if(value<min) min=value;
    }
    void pop(){
        if(top>-1) top--;
        else cout<<"stack is empty."<<endl;
    }
    
    int getmin(){
        return min;
    }
    
    bool isempty(){
        if(top<0) return false;
        else return true;
    }
    
    
private:
    int top;
    int min;
    int *buf;
};



int main()
{
    StackWithMin mystack(30);
    for(int i=0;i<10;i++) mystack.push(i+10);
    cout<<mystack.getmin()<<endl;
    
}
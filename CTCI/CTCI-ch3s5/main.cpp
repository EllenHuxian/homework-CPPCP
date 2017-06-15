//
//  main.cpp
//  CTCI-ch3s5
//
//  Created by EllenHu on 8/16/16.
//  Copyright © 2016 EllenHu. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

class stack{
public:
    stack(int stack_size=10){
        buf=new int[stack_size];
        top=-1;
        size=stack_size;
    }
    ~stack(){
        delete[] buf;
    }
    
    bool full(){
        if(top==size-1) return true;
        else return false;
    }
    
    bool isempty(){
        if(top==-1) return true;
        else return false;
    }
    int returntop(){
        return top;
    }
    
    int findtop(){
        return buf[top];
    }
    
    void push(int val){
        if(top==size-1)
        {
            cout<<"stack is full."<<endl;
            return;
        }
        else{
            
            top++;
            buf[top]=val;
            return;
        }
    }
    void pop(){
        top--;
    }
    
private:
    int size;
    int top;
    int *buf;
};



class MyQueue{
public:
    void in(int val){
     if(st1.full())
     {
         cout<<"MyQueue is full"<<endl;
         return;
     }
        while(!st1.isempty())
     {
         st2.push(st1.findtop());
         st1.pop();
     }
        st1.push(val);
        while(!st2.isempty())
        {
            st1.push(st2.findtop());
            st2.pop();
        }
    }
   
    int out(){
        int temp=0;
        if(!st1.isempty())
        {
            temp=st1.findtop();
            st1.pop();
        }
        return temp;
        
    }

private:
    stack st1;
    stack st2;
};




int main()
{
    MyQueue q;
    stack s;
    for(int i=0;i<10;i++) s.push(i);
    for(int i=0;i<10;i++)
    {
        cout<<s.findtop()<<endl;
        s.pop();
    }
    for(int i=0;i<10;i++) q.in(i);
    for(int i=0;i<10;i++) cout<<q.out()<<endl;
    return 0;
}
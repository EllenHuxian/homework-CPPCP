//
//  main.cpp
//  CTCI-ch3s6
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
    bool isempty(){
        if(top==-1) return true;
        else return false;
    }

    int peek(){
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



void SortStack(stack &s)
{
    stack empty,nonempty;
    if(s.isempty())
    {
        cout<<"stack is empty."<<endl;
        return;
    }
    else{
        nonempty.push(s.peek());
        s.pop();
        while(!s.isempty())
        {
            if(s.peek()<nonempty.peek())
            {
                nonempty.push(s.peek());
                s.pop();
            }
            else
            {
                empty.push(s.peek());
                s.pop();
                while((nonempty.peek()<empty.peek())&&(!nonempty.isempty()))
                {
                    s.push(nonempty.peek());
                    nonempty.pop();
                }
                nonempty.push(empty.peek());
                empty.pop();
            }
   
        }
    }
    while(!nonempty.isempty())
    {
        s.push(nonempty.peek());
        nonempty.pop();
    }

}







int main()
{
    stack s;
    int a[9]={1,3,2,6,4,9,8,0,7};
    for(int i=0;i<9;i++) s.push(a[i]);
    SortStack(s);
    for(int i=0;i<9;i++)
    {
            cout<<s.peek()<<endl;
            s.pop();
    }
    return 0;
}








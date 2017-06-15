//
//  main.cpp
//  CTCI-ch3s4
//
//  Created by EllenHu on 8/15/16.
//  Copyright © 2016 EllenHu. All rights reserved.
//

#include <stdio.h>
#include <iostream>

#define N 5
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




void HanoiTower(int n,stack &str,stack &bri,stack &dst)
{
    if(n==1)
    {
        dst.push(str.findtop());
        str.pop();
    }
    else
    {
        HanoiTower(n-1, str, dst, bri);
        dst.push(str.findtop());
        str.pop();
        HanoiTower(n-1, bri, str, dst);
    }
    
}


//void Hanoi(int n,char a,char b,char c)
//{
//    if(n==1)
//        cout<<"move "<<n<<" from "<<a<<" to "<<c<<endl;
//    else
//    {
//        Hanoi(n-1,a,c,b);
//        cout<<"move "<<n<<" from "<<a<<" to "<<c<<endl;
//        Hanoi(n-1,b,a,c);
//    }
//}

int main()
{
   stack st[3];
//    Hanoi(8,'a','b','c');
    for(int i=0;i<N;i++) st[0].push(N-i);
    HanoiTower(N, st[0], st[1], st[2]);
    while(!st[2].isempty())
    {
        cout<<st[2].findtop()<<endl;
        st[2].pop();
    }
}







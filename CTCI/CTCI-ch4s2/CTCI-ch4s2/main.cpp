//
//  main.cpp
//  CTCI-ch4s2
//
//  Created by EllenHu on 8/20/16.
//  Copyright © 2016 EllenHu. All rights reserved.
//

#include <stdio.h>
#include <queue>
#include <cstring>
#include <iostream>
using namespace std;

#define max 10

void init(bool (*graph)[max],bool visited[])
{
    int edgenumber,x,y;
    memset(graph,false,sizeof(graph));
    memset(visited,false,sizeof(visited));
    cout<<"input the edge number"<<endl;
    cin>>edgenumber;
    for(int i=0;i<edgenumber;i++)
    {
        cin>>x>>y;
        graph[x][y]=true;
    }
}


void haveroute(bool (*graph)[max],bool visited[])
{
    int str,des,x;
    queue<int> q;
    bool isfirst=true;
    cout<<"input start and destination"<<endl;
    cin>>str>>des;
    x=str;
    while(isfirst|!q.empty())
    {
        for(int i=0;i<max;i++)
        {
            if(graph[x][i]==true)
            {
                if(i==des)
                {
                    cout<<"the route exist"<<endl;
                    return;
                }
                else if((i!=des)&&!visited[i])
                {
                    q.push(i);
                    visited[i]=true;
                }
            }
        }
        x=q.front();
        q.pop();
    }
    cout<<"the route does not exist"<<endl;
}




int main()
{
    bool graph[max][max];
    bool visited[max];
    //bool *p=&graph[0][0];
    init(graph,visited);
    haveroute(graph, visited);
    return 0;
}
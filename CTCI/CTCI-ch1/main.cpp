//
//  main.cpp
//  CTCI-ch1
//
//  Created by EllenHu on 8/5/16.
//  Copyright © 2016 EllenHu. All rights reserved.
//

#include "main.hpp"
#include <string>
#include <cstdio>
#include <iostream>
#define N 5
using namespace std;

//s1
//bool IsUnique(string &s)
//{
//    bool isUnique=true;
//    int i=0,t=0,a[2][26];
//    for(i=0;i<26;i++)
//    {
//        a[0][i]=i;
//        a[1][i]=1;
//    }
//    for(i=0;i<s.length();i++)
//    {
//        t=s[i]-'A';
//        if(t>31&&t<58) t=t-32;
//        if(t>=0&&t<26)
//        {
//            if(a[1][t]) a[1][t]=0;
//            else {isUnique=false; break;}
//        }
//        
//      
//    }
//    return isUnique;
//}

//s2
//void reverse(char *str)
//{
//    char *p=str;
//    int length;
//    for(length=0;*p!=NULL;length++) p++;
//    int j=length-1;
//    for(int i=0;i<=length/2;i++)
//    {
//        
//        char temp=str[i];
//        str[i]=str[j];
//        str[j]=temp;
//        if(j-i==1) break;
//        if(j==i) break;
//        j--;
//    }
//    cout<<str<<endl;
//}


//s3
bool IsPart(string &s1,string &s2)
{
    string temp;
    int len1=s1.length();
    int len2=s2.length();
    int len=0;
    int count =0;
    bool ispart=false;
    if(len2>len1) {temp=s1;s1=s2;s2=temp;len=len1;len1=len2;len2=len;}
    for(int i=0;i<(len1-len2+1);i++)
    {
        if(s1[i]==s2[0])
        {
            count=1;
            int m=i+1;
            for(int j=1;j<len2;j++)
            {
                if(s1[m]!=s2[j]) break;
                count++;
                m++;
            }
            if(count==len2) {cout<<"One is a permutation of the other."<<endl;ispart=true;break;}
        }
    }
    if(!ispart) cout<<"One is not a permutation of the other."<<endl;
    return ispart;
}

//s4
//void ReplaceBlank(string &s,int length)
//{
//    int count=0;
//    string replace="%20";
//    for(int i=0;i<(length+count*3);i++)
//    {
//        if(s[i]==' ')
//        {
//            s.replace(i, 1, replace);
//            count++;
//        }
//    }
//    cout<<s<<endl;
//    
//}

//s5
//void Compression(string &s)
//{
//    int i=0,count=0,j=0;
//    int length=s.length();
//    for(;i<length-2;)
//    {
//        j=i+1;
//        while(s[i]==s[j])
//        {
//            count++;
//            i++;
//            j++;
//        }
//        if(count>0)
//        {
//            char m='0'+count+1;
//            s.replace(s.begin()+i-count+1,s.begin()+i+1,1,m);
//            length=length-count+1;
//            count=0;
//        }
//    
//    }
//    cout<<s<<endl;
//}

//s6
//void rotate(int (&matrix)[N][N])
//{
//    int temp,n=N;
//    for(int i=0;i<n/2;i++)
//    {
//        for(int j=i;j<n-i-1;j++)
//        {
//            temp=matrix[i][j];
//            matrix[i][j]=matrix[n-1-j][i];
//            matrix[n-j-1][i]=matrix[n-1-i][n-1-j];
//            matrix[n-1-i][n-1-j]=matrix[j][n-1-i];
//            matrix[j][n-1-i]=temp;
//        }
//    }
//}

//void PrintMatrix(int (&matrix)[N][N])
//{
//    for(int i=0;i<N;i++)
//    {
//        for(int j=0;j<N;j++)
//        {
//            cout<<matrix[i][j]<<" ";
//        }
//        cout<<endl;
//    }
//}


//s7
//void SetZero(int (&matrix)[N][N])
//{
//    int row[N],col[N],count=0;
//    for(int i=0;i<N;i++)
//    {
//        for(int j=0;j<N;j++)
//            if(matrix[i][j]==0)
//            {
//                row[count]=i;
//                col[count++]=j;
//            }
//    }
//    while(count>0)
//    {
//        for(int i=0;i<N;i++)
//        {
//            matrix[i][col[count-1]]=0;
//        }
//        for(int i=0;i<N;i++)
//        {
//            matrix[row[count-1]][i]=0;
//        }
//        count--;
//    }
//}

//s8
void isRotation(string &s1,string &s2)
{
    if(s1==s2) {cout<<"s1 equals s2"<<endl; return;}
    if(s1.length()!=s2.length()) {cout<<"s1 and s2 have different length"<<endl; return;}
    if(s1.length()==s2.length()&&s1.length()>0)
    {
        string s3=s1+s1;
        cout<<s3<<endl;
        if(IsPart(s3,s2)) cout<<"s2 is a rotation of s1"<<endl;
        else cout<<"s2 is not a rotation of s1"<<endl;
    }
}


int main()
{
    string s1="Coding";
    string s2="Coding Interview 1";
    string s3="Mr John Smith";
    string s4="aaabbbbbcdeef";
    string s5="waterbottle";
    string s6="eraottlewat";
    isRotation(s5, s6);
    //int matrix[N][N]={1,2,3,4,5,6,7,8,9};
    //int matrix[N][N]={1,1,1,1,1,1,1,0,1,1,0,1,1,1,1,1,1,0,1,1,1,0,1,1,1};
    //PrintMatrix(matrix);
    //cout<<endl;
    //SetZero(matrix);
    //rotate(matrix);
    //PrintMatrix(matrix);
    //Compression(s4);
    //ReplaceBlank(s3,13);
    //IsPart(s1,s2);
    //char s2[8]="coding2";
    //s2[7]=NULL;
    //reverse(s2);
    //if(IsUnique(s)) cout<<"The string is unique."<<endl;
    //else cout<<"The string is not unique."<<endl;
    return 0;
}
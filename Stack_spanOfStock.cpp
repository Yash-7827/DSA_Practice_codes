#include<iostream>
#include<bits/stdc++.h>
#include<vector>

using namespace std;

void spanOfStock(vector<int> arr)
{
    stack<int> s;
    s.push(0);
    int span,i;
    
    for(i=0; i<arr.size(); i++)
    {
        while(s.empty()==false&&arr.at(s.top())<=arr.at(i))
        {
            s.pop();
        }
        span=s.empty()? i+1 : i-s.top();
        cout<<span<<" ";
        s.push(i);
    }
}

int main(){
    vector<int> arr;
    int element,size;
    
    std::cout<<"Enter number of elements: ";
    std::cin>>size;
    
    for(int i=0;i<size;i++)
    {
        std::cout<<"Enter element: ";
        std::cin>>element;
        arr.push_back(element);
    }
    
    spanOfStock(arr);
}

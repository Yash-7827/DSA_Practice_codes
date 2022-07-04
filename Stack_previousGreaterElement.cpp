#include <bits/stdc++.h>
#include<vector>
using namespace std;

void prevGreater(vector<int> arr) {
    stack<int>s;

    s.push(arr[0]);
    cout << "- ";

    for (int i = 1; i < arr.size(); i++)
    {
        while (s.empty() == false && s.top() <= arr[i])
            s.pop();
        if (s.empty())
            cout << "- ";
        else
            cout << s.top() << " ";
        s.push(arr.at(i));
    }
}

int main()
{
    vector<int> arr;
    
    int size,element;
    
    std::cout<<"Enter number of elements : ";
    std::cin>>size;
    
    for(int i=0;i<size;i++)
    {
        std::cout<<"Enter element : ";
        std::cin>>element;
        arr.push_back(element);
    }
    
    prevGreater(arr);
    return 0;
}

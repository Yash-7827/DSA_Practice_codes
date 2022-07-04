#include<iostream>
#include<bits/stdc++.h>
#include<stack>

using namespace std;

bool checkPair(char val1, char val2)
{
    return((val1=='{'&&val2=='}')||(val1=='['&&val2==']')||(val1=='('&&val2==')'));
}

bool checkBalanced(string exp){
    stack<char> s;
    
    for(int i=0;i<exp.length();i++){
        if(exp[i]=='{'||exp[i]=='('||exp[i]=='[')
        {
            s.push(exp[i]);
        }
        else
        {
            if(s.empty())
                return false;
            else if(checkPair(s.top(),exp[i]))
            {
                s.pop();
                continue;
            }
            return false;
        }
    }
    return s.empty();
}

int main(){
    string exp;
    
    std::cin>>exp;

    checkBalanced(exp)? std::cout<<"Balanced!" : std::cout<<"Not Balanced!";
}

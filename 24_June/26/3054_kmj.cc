#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str;
    cin >> str;
    int size = str.size();

    cout << "..";
    for (int i = 0; i < size; i++)
    {
        if (i % 3 == 2)
        {
            cout << "*";
        }
        else
        {
            cout << "#";
        }
        if (i != size - 1)
        {
            cout << "...";
        }
        else
        {
            cout << "..";
        }
    }
    cout << "\n";
    for (int i = 0; i < size; i++)
    {
        if (i % 3 == 2)
        {
            cout << ".*.*";
        }
        else
        {
            cout << ".#.#";
        }
    }
    cout << "."<<'\n';
    cout << "#";

    for (int i = 0; i < size; i++)
    {
        if(i%3==0){
            cout<<"."<<str[i]<<"."<<"#";
        }
        else if(i%3==1&& i!=size-1){
            cout<<"."<<str[i]<<"."<<"*";
        }
        else if(i%3==1&& i==size-1){
            cout<<"."<<str[i]<<"."<<"#";
        }
        else{
            cout<<"."<<str[i]<<"."<<"*";
        }
    }

    cout << "\n";
    for (int i = 0; i < size; i++)
    {
        if (i % 3 == 2)
        {
            cout << ".*.*";
        }
        else
        {
            cout << ".#.#";
        }
    }
    cout << ".";
    cout << '\n';
    cout << "..";
    for (int i = 0; i < size; i++)
    {
        if (i % 3 == 2)
        {
            cout << "*";
        }
        else
        {
            cout << "#";
        }
        if (i != size - 1)
        {
            cout << "...";
        }
        else
        {
            cout << "..";
        }
    }
}
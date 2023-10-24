#include<iostream>
#include<string>
using namespace std;


int main(){
    string str;
    cin>>str;

    int ph=0;
    int pg=0;
    char chr;
    cout << fixed;
    cout.precision(2);
    for(int i=0;i<str.length();i++){
        chr=str[i];
        if (chr == 'S' || chr == 'A' || chr == 'D')
            pg++;
        if (chr == 'H' || chr == 'A' || chr == 'P' || chr == 'Y') {
            ph++;
        }

    }
    if(ph==0&&pg==0)
        cout<<"0.5";
    else
        cout << (double)ph + (double)(pg + ph);
}
//컨트롤 쉬프트 s

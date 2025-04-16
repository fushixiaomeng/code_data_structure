#include<iostream>
#include<string>
using namespace std;

int main()
{
    string str = "Hello world!!!";
    int len = sizeof(str[0]);
    cout << "Length of string: " << len << endl;
    std::cout<<str<<std::endl;
    return 0;
}


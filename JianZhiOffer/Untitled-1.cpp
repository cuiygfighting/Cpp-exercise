#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>
int main()
{
    uint32_t x=1;
    decltype(x++) y=2;
    cout<<x<<" "<<y<<endl;
    while(1);
}
#include <bits/stdc++.h>
using namespace std;
int main()
{   
    int n,f=1;
    cout<<"Enter the Number:";
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        f=f*i;
    }
    cout<<"Factorial of "<<n<<" is "<<f;
    return 0;
}

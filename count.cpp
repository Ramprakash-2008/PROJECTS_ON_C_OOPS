/*
Description:
This C++ program counts the number of times a specified digit appears in a given integer. It extracts each digit using modulo and division operations and compares it with the target digit.

Sample Output:
enter the number : 122345212
enter the number to be find its count : 2
the count of 2 is :3
```
*/
#include<iostream>
using namespace std;
int main(){
    long int n;int t,count=0,temp=0;
    cout<<"enter the number : ";
    cin>>n;
    cout<<"enter the number to be find its count :";cin>>t;
    while(n!=0){
        temp=n%10;
        if(temp==t){
            count++;
        }n/=10;
    }
    cout<<"the count of "<<t<<" is :"<<count<<endl;
    return 0;
}

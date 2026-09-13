/*
**Description:**
This C++ program calculates the maximum weighted sum 
of an array among all possible cyclic rotations.
It also identifies the rotation number that 
produces the maximum sum.

**Sample Output:**

```text
enter the size of the array :4
enter element1: 8
enter element2: 3
enter element3: 1
enter element4: 2
maximum sum :29
its turn :1
```
*/
#include<iostream>
using namespace std;
int reverse_n(int a[],int size){
    int temp,b=0;int s=0,rm=0;
    for(int r=0;r<size;r++){
        temp=0;
        for(int i=0;i<size;i++ ){
            temp+=a[(s+i)%size]*i;
        }if(temp>b){b=temp,rm=r;} 
    s=(s-1+size)%size; }
    return rm;
}
int reverse(int a[],int size){
    int temp,b=0;int s=0,rm=0;
    for(int r=0;r<size;r++){
        temp=0;
        for(int i=0;i<size;i++ ){
            temp+=a[(s+i)%size]*i;
        }if(temp>b){b=temp,rm=r;}
    s=(s-1+size)%size;   }
    return b;
}

int main(){
    int *a,s;
    cout<<"enter the size of the array :";
    cin>>s;a=new int[s];
    for(int i=0;i<s;i++){
        cout<<"enter element"<<i+1<<": ";
        cin>>a[i];
    }
    cout<<"maximum sum :"<<reverse(a,s)<<"\nits turn :"<<reverse_n(a,s);
    return 0;
}

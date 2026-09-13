/*
Description:
This C++ program converts an integer into a vector 
of its digits and increments the number by one using
 digit-wise operations. It correctly handles carry-over
 cases, including numbers containing 9.

Sample Output:

enter the number :129
before incrementing :
1 2 9
after incrementing :
1 3 0
*/
#include<iostream>
#include<vector>
using namespace std;
 vector<int> getarr(int n){
    int temp=n,i=0;
    while(temp!=0){
        temp/=10;i++;
    }int in=i-1;
    vector<int> arr(i);
    while(n!=0){
        arr[in--]=n%10;
        n/=10;
    }
return arr;
}
vector <int> ince(vector<int> b,int s){
int i=s-1;
    while((i>=0)){
        if(b[i]<9){
            b[i]+=1;break;
        }
        else{
            b[i]=0;
        i--;
        }
    }
    if(i<0){
        b.insert(b.begin(),1);
    }
    return b;
}
void display(vector<int> b){
for(int x:b)
    {
        cout<<x<<" ";
    }cout<<endl;}
int main(){
    int a,s=0;
    vector <int> b;
    cout<<"enter the number :";
    cin>>a;
    b=getarr(a);s=b.size();
    cout<<"before incrementing :"<<endl;
    display(b);
    b=ince(b,s);
    cout<<"after incrementing :"<<endl;
    display(b);
return 0;
}
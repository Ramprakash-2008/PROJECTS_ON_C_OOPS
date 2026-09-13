#include<iostream>
using namespace std;
int main(){
    int n,m=1;
    while(m!=0){int sum=0;
    int l1[8]={1,7,10,4,8,12,13,11};
    int l2[6]={3,7,10,14,12,11};
    int l3[7]={6,4,7,15,14,13,11};
    int l4[9]={9,4,5,8,10,15,13,14,11};
    int l5[8]={2,5,8,12,15,13,14,11};
    cout<<"guess any number between 1 and 15 !!"<<endl;
    cout<<"guessed yes-1/no-0 :"<<endl;
    cin>>n;cout<<endl;
    if(n){
    for(int i=0;i<8;i++){
        cout<<l1[i]<<"\t";
    } cout<<endl;
    cout<<"whether your number belongs to this ?(yes-1/no-0) :";
    cin>>n;
    cout<<endl; 
    if(n){sum+=10;}
    for(int i=0;i<6;i++){
        cout<<l2[i]<<"\t";
    }cout<<endl;
    cout<<"whether your number belongs to this ?(yes-1/no-0) :";
    cin>>n;cout<<endl;
    if(n){sum+=20;}
    for(int i=0;i<7;i++){
        cout<<l3[i]<<"\t";
    }cout<<endl;
    cout<<"whether your number belongs to this ?(yes-1/no-0) :";
    cin>>n;cout<<endl;
    if(n){sum+=30;}
     for(int i=0;i<9;i++){
        cout<<l4[i]<<"\t";
    }cout<<endl;
    cout<<"whether your number belongs to this ?(yes-1/no-0) :";
    cin>>n;cout<<endl;
    if(n){sum+=40;}
     for(int i=0;i<8;i++){
        cout<<l5[i]<<"\t";
    }cout<<endl;
    cout<<"whether your number belongs to this ?(yes-1/no-0) :";
    cin>>n;cout<<endl;
    if(n){sum+=50;}}
    cout<<"wait for result!!"<<endl;
    switch(sum){
        case  10: cout<<"The number you guessed is 1"<<endl;break;
        case  20: cout<<"The number you guessed is 3"<<endl;break;
        case  30: cout<<"The number you guessed is 6"<<endl;break;
        case  40: cout<<"The number you guessed is 9"<<endl;break;
        case  50: cout<<"The number you guessed is 2"<<endl;break;
        case  60: cout<<"The number you guessed is 7"<<endl;break;
        case  70: cout<<"The number you guessed is 10"<<endl;break;
        case  80: cout<<"The number you guessed is 4"<<endl;break;
        case  90: cout<<"The number you guessed is 5"<<endl;break;
        case  100: cout<<"The number you guessed is 8"<<endl;break;
        case  110: cout<<"The number you guessed is 12"<<endl;break;
        case  120: cout<<"The number you guessed is 15"<<endl;break;
        case  130: cout<<"The number you guessed is 13"<<endl;break;
        case  140: cout<<"The number you guessed is 14"<<endl;break;
        case  150: cout<<"The number you guessed is 11"<<endl;break;
        default: cout<<"The number is not in the list !!"<<endl;
    }
    cout<<"do you want to re-play it ?? (yes-1/no-0)"<<endl;
    cin>>m;
}cout<<"thank you for playing !!"<<endl;
return 0;
}

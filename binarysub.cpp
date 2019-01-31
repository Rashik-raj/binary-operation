#include<iostream>
using namespace std;
void sub(int);
int main()
{
    int n;
    cout<<"---SUBTRACTION OF BINARY NUMBER USING TWO'S COMPLEMENT---"<<endl<<endl;
    cout<<"Enter number of bits in a binary number (note that first bit denotes sign)::";
    cin>>n;
    sub(n);
    return 0;
}
void sub(int n)
{
    int num1[n],num2[n],i,temp=0,result[n+1];
    for(i = 0; i<=n; i++){
        result[i]=0;
    }
    cout<<"Enter first binary number::";
    for(i = 0; i<n; i++){
        cin>>num1[i];
    }
    cout<<"Enter second binary number::";
    for(i = 0; i<n; i++){
        cin>>num2[i];
    }
    //1's compliment
    for(i = 0; i<n ; i++){
        if(num2[i]==0)
            num2[i]++;
        else
            num2[i]--;
    }
    if(num2[n-1]==0)
        num2[n-1]++;//2's compliment
    else{
        for(i=n-1;i>=0;i--){//2's compliment
            if(num2[i]==1){
                num2[i]--;
                temp=1;
            }
            else{
                num2[i]+=temp;
                break;
            }
        }
    }
    cout<<endl;
    for(i=n-1;i>=0;i--){
        result[i+1]=result[i+1]+num1[i]+num2[i];
        if(result[i+1]>1){//carry
            result[i+1]=result[i+1]%2;
            result[i]=1;
        }
    }
    cout<<endl<<"The result is=";
    if(result[0]==1)//if carry remove 1st digit to get result
    {
        for(i = 1; i<=n; i++){
            cout<<result[i];
        }
    }
    else{//take 2's compliment of result to get result
        for(i = 0; i<=n ; i++){
            if(result[i]==0)
                result[i]++;
            else
                result[i]--;
        }
        if(result[n]==0)
            result[n]++;//2's compliment
        else{
            temp=0;
            for(i=n;i>=0;i--){//2's compliment
                if(result[i]==1){
                    result[i]--;
                    temp=1;
                }
                else{
                    result[i]+=temp;
                    break;
                }
            }
        }
        for(i = 1; i<=n; i++){
            cout<<result[i];
        }
    }
}

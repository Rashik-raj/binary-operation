#include<iostream>
using namespace std;
int div(int);
int main()
{
    int n;
    cout<<"---SUBTRACTION OF BINARY NUMBER USING TWO'S COMPLEMENT---"<<endl<<endl;
    cout<<"Enter number of bits in a binary number (note that first bit denotes sign)::";
    cin>>n;
    div(n);
    return 0;
}
int div(int n)
{
    int A[n],B[n],Q[n],Bc[n],AQ[2*n],EA[2*n],EAt[2*n],Qs=1,c=n,i,j,temp=0,temp2,e;
    cout<<"Enter binary dividend(double the bit of divisor)::";
    for(i = 0; i<2*n; i++){
        cin>>AQ[i];
    }
    cout<<"Enter binary divisor::";
    for(i = 0; i<n; i++){
        cin>>B[i];
    }
    //1's compliment of B
    for(i = 0; i<n ; i++){
        if(B[i]==0)
            Bc[i]=B[i]+1;
        else
            Bc[i]=B[i]-1;
    }
    if(Bc[n-1]==0)
        Bc[n-1]++;//2's compliment
    else{
        for(i=n-1;i>=0;i--){//2's compliment
            if(Bc[i]==1){
                Bc[i]--;
                temp=1;
            }
            else{
                Bc[i]+=temp;
                break;
            }
        }
    }
    for(i = 0; i<n; i++){
        A[i]=AQ[i];
        Q[i]=AQ[i+n];
    }
    if((A[0]==0 && B[0]==0) || (A[0]== 1 && B[0]==1))//getting the sign of the result
    {
        Qs=0;
    }
    for(i=0;i<2*n;i++)//initializing EA with 0
    {
        EA[i]=0;
    }
    for(i=n-1,j=2*i+1 ;i>=0;i--,j--)
    {
        EA[j]=EA[j]+A[i]+Bc[i];
        if(EA[j]>1)
        {
            EA[j]=EA[i]%2;
            EA[j-1]=1;
        }
    }
    e=EA[n-1];
    if(e==1)//check if overflow occur or not
    {
        cout<<"OVERFLOW ERROR!!!";
        return 0;
    }
    else//no overflow can continue calculation
    {
        //division starts
        while(c>0)
        {
            //shifting e,A and Q to left
            e=A[0];//shifting first digit of A to e
            temp2=Q[n-1];
            Q[n-1]=0;
            for(i=n-1;i>0;i--)//shifting Q to left
            {
                temp=Q[i-1];
                Q[i-1]=temp2;
                temp2=temp;
            }
            for(i=n-1;i>0;i--)//shifting A to left
            {
                temp=A[i];
                A[i]=temp2;
                temp2=temp;
            }
            A[0]=temp2;
            //shifting left completed

            if(e==1)
            {
                for(i=0;i<2*n;i++)//initializing EA with 0
                {
                    EA[i]=0;
                }
                for(i=n-1,j=2*i+1 ;i>=0;i--,j--)
                {
                    EA[j]=EA[j]+A[i]+Bc[i];
                    if(EA[j]>1)
                    {
                        EA[j]=EA[i]%2;
                        EA[j-1]=1;
                    }
                }
                for(i=0;i<n;i++)//Update A
                {
                    A[i]=EA[i+n];
                }
                Q[n-1]=1;
                c--;
            }
            else
            {
                for(i=0;i<2*n;i++)//initializing EAtemp with 0
                {
                    EAt[i]=0;
                }
                for(i=n-1,j=2*i+1 ;i>=0;i--,j--)
                {
                    EAt[j]=EAt[j]+A[i]+Bc[i];
                    if(EAt[j]>1)
                    {
                        EAt[j]=EAt[i]%2;
                        EAt[j-1]=1;
                    }
                }
                if(EAt[n-1]==1)
                {
                    for(i=0;i<2*n;i++)//Update EA with EAtemp
                    {
                        EA[i]=EAt[i];
                    }

                    for(i=0;i<n;i++)//Update A
                    {
                        A[i]=EA[i+n];
                    }
                    Q[n-1]=1;
                    c--;
                }
                else
                {
                    c--;
                }
            }
        }
        cout<<endl<<"Quotient=";
        for(i=0;i<n;i++)
        {
            cout<<Q[i];
        }
        cout<<endl<<"Remainder=";
        for(i=0;i<n;i++)
        {
            cout<<A[i];
        }
                return 0;
    }
}

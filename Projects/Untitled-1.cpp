#include<iostream>
using namespace std;
int x[30];
int n,nr;

void tipar()

{
    int i;
    for(i=1; i<=n; i++)
        cout<<x[i]<<' ';
    cout<<'\n';
    nr++;
}

int valid(int k)

{
    int i;
    for(i=1; i<k; i++)
        if(x[i]==x[k])return 0;
    return 1;
}

void back()

{
    int i,k=1;
    x[1]=0;
    while(k>0)//stiva nu este vida
    {
        while(x[k]<n)
        {
            x[k]=x[k]+1;
            //x[1]=1;
            //x[2]=1;
            //x[2]=2;
            //x[3]=1
            //x[3]=2
            //x[3]=3
            //x[2]=3
            if(valid(k))
                if(k==n) tipar();
                else
                {
                    k=k+1;
                    //x[2]=0
                    //x[3]=0
                    x[k]=0;
                }
        }
        k=k-1;
    }
}

int main()

{
    cin>>n;
    back();
    cout<<nr;
}
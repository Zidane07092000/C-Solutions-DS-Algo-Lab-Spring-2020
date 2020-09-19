#include<iostream>
#include<string>
#include<vector>
#include<string.h>
#include<math.h>
using namespace  std;
vector <string> remove(int n,vector <string>);
vector <string> findexpr(int n)
{
    int i,j,k,l,c=4;
    vector<string> v,v1,v2,v3,v4;
    string a1,a2,a3,a4;
    if (n==1)
    {
        v.push_back("1");
    }
    else
    {
        i=1;
        v1=findexpr(i);
        v2=findexpr(n-i);
        a1=v1[0];
        a2=v2[0];
        a1.append("+");
        a1.append(a2);
        v.push_back(a1);
        for(i=2;i<n;i++)
        {
            for(j=2;j<n;j++)
            {
                if (i*j==n && i<=j)
                {
                    v3=findexpr(i);
                    v4=findexpr(j);
                    for(k=0;k<v3.size();k++)
                    {
                        a3=v3[k];
                        for(l=0;l<v4.size();l++)
                        {
                            string temp;
                            a4=v4[l];
                            temp.append(a3);
                            temp.insert(0,"(");
                            temp.append(")");
                            temp.append("*");
                            temp.append("(");
                            temp.append(a4);
                            temp.append(")");
                            v.push_back(temp);
                        }
                    }
                }
            }
            
        }
    }
    return v;   
}
vector <string> final(int n)
{
    vector <string>v,v1,v2;
    int i,j,k,l;
    string a1,a2;
    v=findexpr(n);
    for(i=2;i<sqrt(n);i++)
    {
        if ((n%i)==0)
        {
        v1=final(i);
        v2=final(n/i);
        for(j=0;j<v1.size();j++)
        {
            a1=v1[j];
            for(k=0;k<v2.size();k++)
            {
                string a3;
                a2=v2[k];
                a3.append(a1);
                a3.insert(0,"(");
                a3.append(")");
                a3.append("*");
                a3.append("(");
                a3.append(a2);
                a3.append(")");
                v.push_back(a3);
            }

        }
        }
    }
    for(i=1;i<n/2+1;i++)
    {
        v1=final(i);
        v2=final(n-i);
        for(j=0;j<v1.size();j++)
        {
            a1=v1[j];
            for(k=0;k<v2.size();k++)
            {
                string a3;
                a2=v2[k];
                a3.append(a1);
                a3.append("+");
                a3.append(a2);
                v.push_back(a3);
            }

        }
    }
    return v;
}
vector <string> remove(int n,vector <string> v)
{
    int i,j,c;
    vector<string> f;
    string a1,a2;
    v=final(n);
    f.push_back(v[0]);
    for(i=1;i<v.size();i++)
    {
        a1=v[i];
        c=1;
        for(j=0;j<f.size();j++)
        {
            a2=f[j];
            if (a1==a2)
            {
                c=0;
                break;
            }
        }
        if (c==1) f.push_back(v[i]);
    }
    return f;
}  
vector<string> Sort(vector <string> v)  
{  
    int i, j;  
    string temp;
    for (i = 0; i < v.size()-1; i++)
    {      
        for (j = 0; j < v.size()-i-1; j++)
        {  
            if (v[j].size() > v[j+1].size())
            {
                temp=v[j];
                v[j]=v[j+1];
                v[j+1]=temp;
            }
        }
    }
    return v;
}  
int main()
{
    int n,i;
    cout<<"Enter n:";
    cin>>n;
    vector<string>v,f;
    v=final(n);
    f=remove(n,v);
    cout<<"+++Before Sorting"<<"\n";
    for(i=0;i<f.size();i++)
    {
        cout<<f[i]<<"\n";
    }
    cout<<f.size()<<" Expressions..."<<"\n";
    cout<<endl;
    cout<<"+++After Sorting"<<"\n";
    f=Sort(f);
    for(i=0;i<f.size();i++)
    {
        cout<<f[i]<<"\n";
    }
    cout<<f.size()<<" Expressions..."<<"\n";
    printf("\n");

}
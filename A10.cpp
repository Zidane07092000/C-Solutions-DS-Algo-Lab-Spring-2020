#include <bits/stdc++.h>
using namespace std;
#define inf 99999 
struct graph
{
    int n;
    vector<vector <char> > Op;
    vector<vector <int> > P;

};
graph gengraph(int n,vector<vector <char> > Op,vector<vector <int> > P)
{
    graph G;
    G.n=n;
    G.Op=Op;
    G.P=P;
    int i,j,c;
    char type;
    cin>>i;
    while (i!=-1)
    {
        cin>>j>>c>>type;
        G.Op[i][j]=type;
        G.P[i][j]=c;
        cin>>i;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if (i==j) G.P[i][j]=0;
            if (G.Op[i][j]=='-')
            {
                G.P[i][j]=inf;
            }
        }
    }
    return G;
}
graph getAIgraph(graph G,vector<vector <char> > Op,vector<vector <int> > P)
{
    int i,j,n=G.n;
    graph AI;
    AI.n=n;
    AI.Op=Op;
    AI.P=P;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if (G.Op[i][j]=='a')
            {
                AI.Op[i][j]='a';
                AI.P[i][j]=G.P[i][j];
            }
            else
            {
                AI.P[i][j]=inf;
            }      
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if (i==j) AI.P[i][j]=0;
        }
    }
    return AI;
} 
vector<vector<int> > APSP(graph G)  
{  
    int V=G.n;
    vector <vector <int> >D;
    
    int dist[V][V], i, j, k;  
    for (i = 0; i < V; i++)  
        for (j = 0; j < V; j++)  
            dist[i][j] = G.P[i][j];  
    for (k = 0; k < V; k++)  
    {   
        for (i = 0; i < V; i++)  
        {    
            for (j = 0; j < V; j++)  
            {   
                if (dist[i][k] + dist[k][j] < dist[i][j])  
                    dist[i][j] = dist[i][k] + dist[k][j];  
            }  
        }  
    }
    cout<<"\t";
    for(i=0;i<V;i++)
    {
        cout<<i<<"\t";
    }
    cout<<endl<<endl;
    for (i = 0; i < V; i++)  
    {  
        cout<<i<<"  ->\t";
        for (j = 0; j < V; j++)  
        {  
            if (dist[i][j] == inf)  
                cout<<"-\t";
            else
                cout<<dist[i][j]<<"\t";  
        }  
        cout<<endl;  
    }  
    for(i=0;i<V;i++)
    {
        vector <int> v;
        for(j=0;j<V;j++)
        {
            v.push_back(dist[i][j]);
        }
        D.push_back(v);
    } 
    return D;
} 
void APSPone(graph G,vector <vector <int> > dist) 
{
    int i,j,k,l,n=G.n; 
    long long int D[n][n],cost=inf;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if (dist[i][j]>=inf)
            {
                cost=dist[i][j];
                for(k=0;k<n;k++)
                {
                    for(l=0;l<n;l++)
                    {
                        if (G.Op[k][l]=='n')
                        {
                            if ((dist[i][k]>=inf || dist[l][j]>=inf)) continue;
                            else if(cost>dist[i][k]+G.P[k][l]+dist[l][j])
                            {
                                cost=dist[i][k]+G.P[k][l]+dist[l][j];
                            }
                            
                        }
                    }
                }
                D[i][j]=cost; 
            }
            else
            {
                D[i][j]=dist[i][j];
            }
            
        }
    }
    cout<<"\t";
    for(i=0;i<n;i++)
    {
        cout<<i<<"\t";
    }
    cout<<endl<<endl;
    for (i = 0; i < n; i++)  
    {  
        cout<<i<<"  ->\t";
        for (j = 0; j < n; j++)  
        {  
            if (D[i][j] >= inf)  
                cout<<"-\t";
            else
                cout<<D[i][j]<<"\t";  
        }  
        cout<<endl;  
    }  
}
void APSPany(graph G,vector <vector <int> > dist) 
{
    int i,j,k,l,n=G.n; 
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if (dist[i][j]>=inf)
            {
                for(k=0;k<n;k++)
                {
                    for(l=0;l<n;l++)
                    {
                        if (G.Op[k][l]=='n')
                        {
                            dist[i][j]=min(dist[i][j],dist[i][k]+G.P[k][l]+dist[l][j]);
                        }
                    }
                }
            }
            
        }
    }
    cout<<"\t";
    for(i=0;i<n;i++)
    {
        cout<<i<<"\t";
    }
    cout<<endl<<endl;
    for (i = 0; i < n; i++)  
    {  
        cout<<i<<"  ->\t";
        for (j = 0; j < n; j++)  
        {  
            if (dist[i][j] == inf)  
                cout<<"-\t";
            else
                cout<<dist[i][j]<<"\t";  
        }  
        cout<<endl;  
    }  
}
void prngraph(graph G)
{
    int i,j,n=G.n;
    for(i=0;i<n;i++)
    {
        cout<<i<<"  ->";
        for(j=0;j<n;j++)
        {
            if (G.Op[i][j]!='-')
            {
                cout<<j<<" ("<<G.P[i][j]<<","<<G.Op[i][j]<<")"<<"  ";
            }
        }
        cout<<endl;
    }
}
int main()
{
    int n,i,j;
    vector<vector <char> > Op;
    vector<vector <int> > P;
    graph G,AI;
    cin>>n;
    vector <vector <int> > D;
    for(i=0;i<n;i++)
    {
        vector <int> p;
        vector <char> o;
        for(j=0;j<n;j++)
        {
            o.push_back('-');
            p.push_back(-1);  
        }
        Op.push_back(o);
        P.push_back(p);
    }
    G=gengraph(n,Op,P);
    cout<<endl;
    cout<<" +++Original graph"<<endl;
    prngraph(G);
    cout<<endl;
    AI=getAIgraph(G,Op,P);
    cout<<"+++AI subgraph"<<endl;
    prngraph(AI);
    cout<<endl;
    cout<<"+++ Cheapest AI prices"<<endl;
    cout<<endl;
    D=APSP(AI);
    cout<<endl;
    cout<<"+++ Cheapest prices with at most one  non-AI legs"<<endl<<endl;
    APSPone(G,D);
    cout<<endl;
    cout<<"+++ Cheapest prices with any number of non-AI legs"<<endl<<endl;
    APSPany(G,D);
    cout<<endl;

}
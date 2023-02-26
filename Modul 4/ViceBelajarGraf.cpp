#include <bits/stdc++.h>
using namespace std;

vector<int> adjList[101];
int cekvisit[101];

void DFS(int i)
{
    cekvisit[i] = true;
    for(int j = 0; j < adjList[i].size(); j++)
    {
        int nextvertex = adjList[i][j];
        if(!cekvisit[nextvertex])
        {
            DFS(nextvertex);
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int jumlahvertex, jumlahedge;
    int vertex1, vertex2;
    int total_komponen = 0;

    cin >> jumlahvertex >> jumlahedge;
    for(int i = 0; i <= jumlahvertex; i++)
    {
        cekvisit[i] = 0;
    }
    for(int i = 0; i < jumlahedge; i++)
    {
        cin >> vertex1 >> vertex2;
        adjList[vertex1].push_back(vertex2);
        adjList[vertex2].push_back(vertex1);
    }
    for(int i = 1; i <= jumlahvertex; i++)
    {
        if(!cekvisit[i])
        {
            DFS(i);
            total_komponen++;
        }
    }
    total_komponen -= 1;

    cout << total_komponen << endl;
    
    return 0;
}
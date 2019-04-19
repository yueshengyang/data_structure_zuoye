#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
typedef struct Graph
{
    int time;
    char name;
}graph[9][9];
int early[9];
int last[9];
void inite(graph G)
{
    for (int i=1;i<=8;i++)
    for(int j=1;j<=8;j++){
        G[i][j].name='-';
        G[i][j].time=-1;
    }
    G[1][2].name='A';
    G[1][2].time=6;
    G[1][3].name='B';
    G[1][3].time=2;
    G[2][3].name='E';
    G[2][3].time=3;
    G[2][4].name='C';
    G[2][4].time=3;
    G[2][5].name='D';
    G[2][5].time=5;
    G[3][6].name='H';
    G[3][6].time=4;
    G[4][7].name='F';
    G[4][7].time=2;
    G[5][7].name='G';
    G[5][7].time=3;
    G[6][7].name='I';
    G[6][7].time=2;
    G[7][8].name='J';
    G[7][8].time=2;
}
void voe(graph G)
{
    int v;
    for(int i=1;i<8;i++){
        for(int j=1;j<9;j++){
            if(G[i][j].time>0){
            v=G[i][j].time+early[i];
            if(v>early[j])  early[j]=v;
            }
        }
    }
    for (int i=1;i<9;i++)  last[i]=early[8];
    for (int j=8;j>0;j--)
    for(int i=1;i<8;i++){
        if (G[i][j].time>0){
            v=last[j]-G[i][j].time;
            if(v<last[i])  last[i]=v;
        }
    }
}
void schedule(graph G)
{
    cout<<"工程至少应该在在"<<early[8]<<"天内完成！"<<endl;
    for (int i=1;i<9;i++){
        for (int j=1;j<9;j++){
            if(G[i][j].time>0)
                cout<<"第"<<early[i]+1<<"-"<<last[j]+1<<"天内完成工序"<<G[i][j].name<<endl;
        }
    }
}

int main()
{
    graph G;
    inite(G);
    voe(G);
    schedule(G);
    return 0;
}

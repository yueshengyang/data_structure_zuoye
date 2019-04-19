#include <iostream>
#include <stack>
#include <queue>
using namespace std;
typedef struct sad
{
    int x;
    int y;
}node;
int picture[7][7]={
    {1,1,1,1,1,1,1},
    {1,0,1,0,1,0,1},
    {1,0,1,0,0,1,1},
    {1,1,0,1,0,0,1},
    {1,1,1,0,0,1,1},
    {1,1,1,1,1,0,1},
    {1,1,1,1,1,1,1}};
void search_pic(int picture[7][7],int visit[7][7],node rute[7][7])
{
    int x,y;
    node nodes;
    nodes.x=1;nodes.y=1;
    queue<node> q;
    visit[1][1]=1;
    q.push(nodes);
    while(!q.empty()){
        nodes=q.front();
        q.pop();
        x=nodes.x;y=nodes.y;
        if((picture[x+1][y]==0)&&(visit[x+1][y]==0)){
            rute[x+1][y]=nodes;
            visit[x+1][y]=1;
            nodes.x=x+1;nodes.y=y;
            q.push(nodes);
        }
        if((picture[x+1][y+1]==0)&&(visit[x+1][y+1]==0)){
            rute[x+1][y+1]=nodes;
            visit[x+1][y+1]=1;
            nodes.x=x+1;nodes.y=y+1;
            q.push(nodes);
        }
        if((picture[x+1][y-1]==0)&&(visit[x+1][y-1]==0)){
            rute[x+1][y-1]=nodes;
            visit[x+1][y-1]=1;
            nodes.x=x+1;nodes.y=y-1;
            q.push(nodes);
        }
        if((picture[x][y+1]==0)&&(visit[x][y+1]==0)){
            rute[x][y+1]=nodes;
            visit[x][y+1]=1;
            nodes.x=x;nodes.y=y+1;
            q.push(nodes);
        }
        if((picture[x][y-1]==0)&&(visit[x][y-1]==0)){
            rute[x][y-1]=nodes;
            visit[x][y-1]=1;
            nodes.x=x;nodes.y=y-1;
            q.push(nodes);
        }
        if((picture[x-1][y+1]==0)&&(visit[x-1][y+1]==0)){
            rute[x-1][y+1]=nodes;
            visit[x-1][y+1]=1;
            nodes.x=x-1;nodes.y=y+1;
            q.push(nodes);
        }
        if((picture[x-1][y]==0)&&(visit[x-1][y]==0)){
            rute[x-1][y]=nodes;
            visit[x-1][y]=1;
            nodes.x=x-1;nodes.y=y;
            q.push(nodes);
        }
        if((picture[x-1][y-1]==0)&&(visit[x-1][y-1]==0)){
            rute[x-1][y-1]=nodes;
            visit[x-1][y-1]=1;
            nodes.x=x-1;nodes.y=y-1;
            q.push(nodes);
        }

    }
}
void realeas_pic(node rute[7][7])
{
    stack<node> s;
    node nod;
    nod.x=5;nod.y=5;
    s.push(nod);
    while(!((nod.x==1)&&(nod.y==1))){
        nod=rute[nod.x][nod.y];
        s.push(nod);
    }
    cout<<"迷宫的最短路径为："<<endl;
    while(!s.empty()){
        nod=s.top();s.pop();
        cout<<"("<<nod.x<<","<<nod.y<<") ";
    }
}
int main()
{
    int visit[7][7]={0};
    node nodes;
    nodes.x=5;nodes.y=5;
    node rute[7][7]={nodes};
    search_pic(picture,visit,rute);
    realeas_pic(rute);
    return 0;
}

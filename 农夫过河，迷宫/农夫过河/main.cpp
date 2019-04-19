#include <iostream>
#include <queue>
#include <stdlib.h>
using namespace std;

#define MAXSIZE 16
typedef int EntryType;
queue<int> q;


int farmer(int state)
{
    return ((state & 0x8) != 0);
}

int wolf(int state)
{
    return ((state & 0x4) != 0);
}

int cabbage(int state)
{
    return ((state & 0x2) != 0);
}

int goat(int state)
{
    return ((state & 0x1) != 0);
}

int is_safe(int state)//安全返回1，不安全返回0
{
    if((goat(state) == cabbage(state)) &&
        (goat(state) != farmer(state)))  // 羊菜同岸且农夫不在场
        return(0);
    if((goat(state) == wolf(state)) &&
        (goat(state) != farmer(state)))  // 狼羊同岸且农夫不在场
        return(0);
    return(1);
}

void river_crossing_problem()
{
    int route[16];           // 记录已经考虑过的状态
    int state;               // 记录当前时刻的状态（状态编号的二进制形式即状态本身）
    int aftercross;          // 记录渔夫当前的选择（渡河对象）会导致的结果状态
    int passenger;           // 临时变量，用于表达农夫的选择（对应二进制位为1表示选中该乘客）

    int results[16]={0};     // 输出结果
    int counter, i;

    q.push(0x00);

    for(int i = 0; i < 16; i++){
        route[i] = -1;
    }

    while((!q.empty()) /*&& (route[15] == -1)*/)
    {
        state=q.front();
        q.pop();
        for( passenger = 1; passenger<= 8; passenger <<= 1 )
        {
            if(((state & 0x08) != 0) == ((state & passenger) != 0)){
                aftercross = state^( 0x08|passenger );
                if(is_safe(aftercross) && (route[aftercross] == -1)){//route[after]!=-1是为了保证不会重复进行已经进行过的操作
                    // 如果渡河后状态安全，则将其状态入队
                    route[aftercross] = state;  // 将当前状态的索引记录到路径数组中（下标索引为后续状态值）
                    q.push(aftercross);
                }
            }
        }
    }

    // 输出过河策略：0表示在东岸 1表示在西岸，初始状态为0000，终止状态为1111
    if(route[15] != -1)
    {
        counter = 0;
        for(state = 15; state != 0; state = route[state]){
            results[counter] = state;
            counter++;
        }

        for(i = 0; i< counter; i++){
            state= results[i];
            aftercross = results[i+1];
            if(state & 0x08){
                cout<<"农夫从南岸到北岸:";
            }
            else{
                cout<<"农夫从北岸到南岸:";
            }
            switch(state^aftercross ){
            case 12:
                cout<<"把狼带过河"<<endl;
                break;
            case 10:
                cout<<"把菜带过河"<<endl;
                break;
            case 9:
                cout<<"把羊带过河"<<endl;
                break;
            default:
                cout<<"什么也不带"<<endl;
                break;
            }
        }
    }
}

int main(void)
{
    river_crossing_problem();
    system("pause");
    return 0;
}

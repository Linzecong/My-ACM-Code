#include <iostream>  
#include <queue>  
#include <cstdio>  
#include <cstring>  
#include <string>  
using namespace std;  
  
typedef struct{  
    int x, y;     
}Point;  
  
typedef struct{  
    Point humen, box[3];  
    int step;  
}Node;  
bool mark[8][8][8][8][8][8][8][8];  
char maps[10][10];  
int moves[4][2] = { 0, 1, 0, -1, 1, 0, -1, 0 };  
int N, M;  
Node start;  
  
bool judge_finish( Node n ){//判断是否结束  
    for( int i = 0; i < 3; i++ ){  
        if( maps[n.box[i].x][n.box[i].y] != '@' ){  
            return false;  
        }  
    }  
    return true;  
}  
  
bool judge_push( Node n ){//判断这种状态是否存在  
    if( n.humen.x < 0 || n.humen.x >= N || n.humen.y < 0 || n.humen.y >= M || maps[n.humen.x][n.humen.y] == '#' ){//判断人是否出界或撞墙  
        return false;  
    }  
    for( int i = 0; i < 3; i++ ){//判断箱子是否出界  
        if( n.box[i].x < 0 || n.box[i].x >= N || n.box[i].y < 0 || n.box[i].y >= M ){  
            return false;  
        }  
    }  
    for( int i = 0; i < 3; i++ ){//判断人时候和箱子相撞  
        if( n.humen.x == n.box[i].x && n.humen.y == n.box[i].y ){  
            return false;  
        }  
    }  
    for( int i = 0; i < 3; i++ ){//判断箱子与箱子是否相撞  
        for( int j = i + 1; j < 3; j++ ){  
            if( n.box[i].x == n.box[j].x && n.box[i].y == n.box[j].y ){  
                return false;  
            }  
        }  
    }  
    for( int i = 0; i < 3; i++ ){//判断箱子是否撞墙  
        if( maps[n.box[i].x][n.box[i].y] == '#' ){  
            return false;  
        }  
    }  
    if( mark[n.humen.x][n.humen.y][n.box[0].x][n.box[0].y][n.box[1].x][n.box[1].y][n.box[2].x][n.box[2].y] ){//判断当前状态是否出现过  
        return false;  
    }  
    mark[n.humen.x][n.humen.y][n.box[0].x][n.box[0].y][n.box[1].x][n.box[1].y][n.box[2].x][n.box[2].y] = true;//若未出现过，则入队列并标记  
    return true;  
}  
  
int BFS(){  
    memset( mark, false, sizeof( mark ) );  
  
    queue<Node> q;  
    start.step = 0;  
    q.push( start );  
  
    while( !q.empty() ){  
        Node n = q.front();  
        q.pop();  
  
        if( judge_finish( n ) ){  
            return n.step;  
        }  
  
        for( int i = 0; i < 4; i++ ){  
            Node temp = n;  
            temp.humen.x += moves[i][0];  
            temp.humen.y += moves[i][1];  
            temp.step++;  
  
            int t;  
            for( t = 0; t < 3; t++ ){//判断人走一步后是否在箱子的位置上  
                if( temp.humen.x == n.box[t].x && temp.humen.y == n.box[t].y ){  
                    break;  
                }  
            }  
  
            if( t < 3 ){//若是在箱子的位置上则该箱子也移一步  
                temp.box[t].x += moves[i][0];  
                temp.box[t].y += moves[i][1];  
            }  
  
            if( judge_push( temp ) ){//判断该状态是否能够存在  
                q.push( temp );  
            }  
        }  
    }  
    return -1;  
}  
  
int main(){  
    while( scanf( "%d%d", &N, &M ) != EOF ){  
        int temp = 0;  
        for( int i = 0; i < N; i++ ){  
            scanf( "%s", maps[i] );  
            for( int j = 0; j < M; j++ ){  
                if( maps[i][j] == 'X' ){  
                    start.humen.x = i;  
                    start.humen.y = j;  
                }  
                if( maps[i][j] == '*' ){  
                    start.box[temp].x = i;  
                    start.box[temp++].y = j;  
                }  
            }  
        }  
        cout << BFS() << endl;  
    }  
    return 0;  
}  
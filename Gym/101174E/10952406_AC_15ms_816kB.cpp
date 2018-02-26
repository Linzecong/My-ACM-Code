#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int CHAR_SIZE = 26;
const int MAX_SIZE = 1e3 + 8;
const int MOD = 1000003;

inline int mp(char ch){
    return ch - 'a';
}

struct AC_Machine{
    int ch[MAX_SIZE][CHAR_SIZE], danger[MAX_SIZE], fail[MAX_SIZE];
    int sz;

    void init(){
        sz = 1;
        memset(ch[0], 0, sizeof ch[0]);
        memset(danger, 0, sizeof danger);
    }

    void _insert(char *s){
        int n = strlen(s);
        int u = 0, c;
        for(int i = 0; i < n; i++){
            c = mp(s[i]);
            if(!ch[u][c]){
                memset(ch[sz], 0, sizeof ch[sz]);
                danger[sz] = 0;
                ch[u][c] = sz++;
            }
            u = ch[u][c];
        }
        danger[u] = 1;
    }

    void _build(){
        queue<int> Q;
        fail[0] = 0;
        for(int c = 0, u; c < CHAR_SIZE; c++){
            u = ch[0][c];
            if(u){Q.push(u); fail[u] = 0;}
        }
        int r;
        while(!Q.empty()){
            r = Q.front();
            Q.pop();
            danger[r] |= danger[fail[r]];
            for(int c = 0, u; c < CHAR_SIZE; c++){
                u = ch[r][c];
                if(!u){ch[r][c] = ch[fail[r]][c]; continue; }
                fail[u] = ch[fail[r]][c];
                Q.push(u);
            }
        }
    }
}ac;

char str[22];

inline void mod(int &x){
    x -= x / MOD * MOD;
}

int dp[MAX_SIZE][22][8];

int main()
{
    int A, B, N;
    scanf("%d%d%d",&A,&B,&N);
    ac.init();
    while(N--){
        scanf("%s",str);
        ac._insert(str);
    }

    int i, j, k, w;
    memset(dp, 0, sizeof dp);
    ac._build();
    dp[0][0][0] = 1;

    for(i = 1; i <= B; i++){
        for(j = 0; j < ac.sz; j++){
            for(w = 0; w < 8; w++){
                if(dp[j][i-1][w] == 0) continue;
                for(k = 0; k < CHAR_SIZE; k++){
                    if(!ac.danger[ac.ch[j][k]]){
                        mod( dp[ac.ch[j][k]][i][w | 1] += dp[j][i-1][w] );
                        mod( dp[ac.ch[j][k]][i][w | 2] += dp[j][i-1][w] );
                        if(k == 'o' - 'a' || k == 'i' - 'a' || k == 'e' - 'a' || k == 's' - 'a' || k == 't' - 'a'){
                            mod( dp[ac.ch[j][k]][i][w | 4] += dp[j][i-1][w] ); // 0 1 3 5 7
                        }
                    }
                }
                mod( dp[0][i][w | 4] += dp[j][i-1][w] );
                for(k = 1; k < 10; k++){
                    if(!(k&1)) mod( dp[0][i][w | 4] += dp[j][i-1][w] );
                }
            }
        }
    }
    int ans = 0;
    for(j = A; j <= B; j++){
        for(i = 0; i < ac.sz; i++){
            mod( ans += dp[i][j][7]);
        }
    }
    printf("%d\n",ans);
    return 0;
}

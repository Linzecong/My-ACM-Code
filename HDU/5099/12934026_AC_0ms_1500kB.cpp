#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char A[10], B[10];

char judge () {
    for (int i = 2; i <= 4; i++)
        if (A[i] != B[i])
            return A[i] < B[i] ? '<' : '>';

    if (A[1] == B[1]) {
        char a = (A[5] == '\0' ? 'A' : A[5]);
        char b = (B[5] == '\0' ? 'A' : B[5]);

        if (a == b)
            return '=';
        return a < b ? '<' : '>';
    }
    return '=';
}

int main () {
    int cas;
    scanf("%d", &cas);
    for (int kcas = 1; kcas <= cas; kcas++) {
        scanf("%s%s", A, B);
        char ch = (A[0] == B[0] ? '=' : (A[0] < B[0] ? '<' : '>'));
        printf("Case %d: %c %c\n", kcas, ch, judge());
    }
    return 0;
}
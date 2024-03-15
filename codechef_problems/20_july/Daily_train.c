#include <stdio.h>

int fact(int n)
{
    int fac = 1, i;
    for (i = 1; i <= n; i++)
        fac = fac * i;
    return fac;
}

int main(void)
{
    int x, i, j, count, n, res = 0, a;
    char S[10][54];

    scanf("%d %d", &x, &n);
    
    for (i = 0; i < n; i++)
        scanf("%s", S[i]);
    for (i = 0; i < n; i++)
    {
        a = 54;
        for (j = 0; j < a; j = j + 4)
        {
            count = 0;
            if (S[i][j] == '0')
                count++;
            if (S[i][j + 1] == '0')
                count++;
            if (S[i][j + 2] == '0')
                count++;
            if (S[i][j + 3] == '0')
                count++;
            if (S[i][a - 1] == '0')
                count++;
            if (S[i][a - 2] == '0')
                count++;
            if (count >= x)
                res = res + fact(count) / (fact(count - x) * fact(x));
            a = a - 2;
        }
    }

    printf("%d\n",res);
    
    return 0;
}
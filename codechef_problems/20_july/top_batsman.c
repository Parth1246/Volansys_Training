#include <stdio.h>

int fact(int n)
{
    int fact = 1, i;

    for (int i = 1; i <= n; i++)
    {
        fact = fact * i;
    }
    return fact;
}

void solve()
{
    int score[11], player, sum, max = 0;
    printf("enter scores scored by players\n");
    for (int i = 0; i < 11; i++)
    {
        scanf("%d ", &score[i]);
    }

    scanf("%d", &player);

    int no_of_teams;

    no_of_teams = fact(11) / (fact(player)*fact(11-player));

    printf("the maximum number of temas can be made of %d players\n",player);
    printf("%d\n",no_of_teams);

    for(int i = 0;i<11;i++) {
        sum = 0;
        for(int j = i;j<player+i;j++) {
            sum+=score[j];
        }
        if(sum>=max) {
            max = sum;
        }
    }
    printf("the max team's sum = %d\n",max);
}

int main()
{
    int t;
    printf("enter number of test cases\n");
    scanf("%d", &t);

    while (t--)
    {
        solve();
    }
    return 0;
}

/* In discus throw, a player is given throws and the throw with the longest distance is regarded as their final score. You are given the distances for all  throws of a player. Determine the final score of the player.
Input FormatFirst line will contain T, number of test cases. Then the test cases follow.Each test case contains of a single line of input, three integers A,B, and C denoting the distances in each throw.Output Format For each test case, output the final score of the player.

Constraints
1≤T≤100
1≤A,B,C≤100 */

#include <stdio.h>

int max(int a,int b,int c) {
    int max=0;
    if(a>max)
        max=a;
    if(b>max)
        max=b;
    if(c>max)
        max=c;
    
    return max;
}

int main(void) {
	int t=3;
	while(t--) {
	    int a,b,c;
	    scanf("%d %d %d", &a,&b,&c);
	    printf("%d\n",max(a,b,c));
	}
	return 0;
}

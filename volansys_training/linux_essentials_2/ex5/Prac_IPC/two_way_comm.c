#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>

int main()
{
    // create pipe
    int p[2];

    if (pipe(p) == -1)
    {
        return 1;
    }
    else
    {
        int pid = fork();
        if (pid == 0)
        {
            // child processs
            int x;
            read(p[0], &x, sizeof(x));
            printf("Child: Recieved Sum %d\n", x);

            for (int i = 1; i < 1001; i++)
            {
                x += i * i;
            }
            write(p[1], &x, sizeof(x));
            printf("Child: Wrote Sum %d\n", x);
        }
        else
        {
            // parent process
            int y = 0;
            write(p[1], &y, sizeof(y));
            printf("Parent: Wrote Sum %d\n", y);

            read(p[0], &y, sizeof(y));
            printf("Parent: Result Sum %d\n", y);
            wait(NULL);
        }
        close(p[0]);
        close(p[1]);
    }
    return 0;
}
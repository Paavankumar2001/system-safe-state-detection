// Banker's Algorithm
#include <stdio.h>
int main()
{
    // P0, P1, P2, P3, P4 are the Process names here

    int m, n, i, j, k;
    m = 5; // Number of processes
    n = 3; // Number of resources
    int allocated[5][3] = { { 0, 1, 0 }, // P0    // Allocation Matrix
                        { 2, 0, 0 }, // P1
                        { 3, 0, 2 }, // P2
                        { 2, 1, 1 }, // P3
                        { 0, 0, 2 } }; // P4

    int max_needed[5][3] = { { 7, 5, 3 }, // P0    // MAX Matrix
                      { 3, 2, 2 }, // P1
                      { 9, 0, 2 }, // P2
                      { 2, 2, 2 }, // P3
                      { 4, 3, 3 } }; // P4

    int available[3] = { 3, 3, 2 }; // Available Resources

	int initial[m], ans[m], ind = 0;
    for (i = 0; i < m; i++)
	{
	    initial[i] = 0;
    }
    
    int rem_needed[m][n];
    for (j = 0; j < m; j++)
	{
	    for (k = 0; k < n; k++)
	        rem_needed[j][k] = max_needed[j][k] - allocated[j][k];
    }
    
    int y = 0;
    for (i = 0; i < 5; i++)
	{
        for (j = 0; j < m; j++)
		{
            if (initial[j] == 0)
			{
                int flag = 0;
                for (k = 0; k < n; k++)
				{
                    if (rem_needed[j][k] > available[k])
					{
                        flag = 1;
                         break;
                    }
                }

                if (flag == 0)
				{
                    ans[ind++] = j;
                    for (y = 0; y < m; y++)
                        available[y] += allocated[j][y];
                    initial[j] = 1;
                }
            }
        }
    }
    printf("The SAFE Sequence is\n");
    for (j = 0; j < m - 1; j++)
        printf(" P%d ->", ans[j]);
    printf(" P%d", ans[m - 1]);

    return (0);
}

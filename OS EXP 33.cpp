// Optimal Page Replacement Algorithm

#include <stdio.h>

int main()
{
    int pages[100], frames[50];
    int n, f, i, j, k;
    int pageFaults = 0, found, pos, farthest;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string: ");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for(i = 0; i < f; i++)
        frames[i] = -1;

    printf("\nPage\tFrames\n");

    for(i = 0; i < n; i++)
    {
        found = 0;

        for(j = 0; j < f; j++)
        {
            if(frames[j] == pages[i])
            {
                found = 1;
                break;
            }
        }

        if(!found)
        {
            int empty = -1;

            for(j = 0; j < f; j++)
            {
                if(frames[j] == -1)
                {
                    empty = j;
                    break;
                }
            }

            if(empty != -1)
            {
                frames[empty] = pages[i];
            }
            else
            {
                farthest = -1;
                pos = -1;

                for(j = 0; j < f; j++)
                {
                    int nextUse = -1;

                    for(k = i + 1; k < n; k++)
                    {
                        if(frames[j] == pages[k])
                        {
                            nextUse = k;
                            break;
                        }
                    }

                    if(nextUse == -1)
                    {
                        pos = j;
                        break;
                    }

                    if(nextUse > farthest)
                    {
                        farthest = nextUse;
                        pos = j;
                    }
                }

                frames[pos] = pages[i];
            }

            pageFaults++;
        }

        printf("%d\t", pages[i]);

        for(j = 0; j < f; j++)
        {
            if(frames[j] != -1)
                printf("%d ", frames[j]);
            else
                printf("- ");
        }
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", pageFaults);

    return 0;
}

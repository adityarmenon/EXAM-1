#include <stdio.h>

int main(){
    int n, bt[100], rt[100], wt[100], tat[100], q, t = 0, i, done, twt = 0, ttat = 0;
    printf("Enter the number of Processes:");
    scanf("%d", &n);

    for(i=0;i<n;i++){
        printf("Enter the burst time:");
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }

    printf("Enter the time quatum: ");
    scanf("%d",&q);

    do{
        done = 1;
        for(i=0;i<n;i++){
            if (rt[i]>0){
                done =0;
                if(rt[i]>q){
                    t += q;
                    rt[i] -= q;
                }
                else{
                    t += rt[i];
                    wt[i] = t - bt[i];
                    rt[i]=0;
                }

            }
        }
    } while (!done);

    for(i=0;i<n;i++){
        tat[i] = bt[i] + wt[i];
        twt += wt[i];
        ttat += tat[i];
    }

    printf("Process\t Burst TIme\t Waiting time \t Turnaround time \n");
    for(i=0;i<n;i++){
        printf("%d\t%d\t\t%d\t\t%d\n",i,bt[i],wt[i],tat[i]);
    }
    printf("\nTotal Waiting Time: %d", twt);
    printf("\nTotal Turnaround Time: %d", ttat);
    printf("\nAverage Waiting Time: %.2f", (float)twt / n);
    printf("\nAverage Turnaround Time: %.2f\n", (float)ttat / n);
}
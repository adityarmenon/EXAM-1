#include <stdio.h>

struct process{
    int pid, at, bt, tat, wt, ct;
};

int main(){
    struct process p[100],temp;
    int i, j, k, n, ct;
    printf("Enter the number of process: ");
    scanf("%d", &n);

    for (i=0;i<n;i++){
        p[i].pid = i;
        printf("Enter the arrival time of process %d: ",i);
        scanf("%d",&p[i].at);
        printf("Enter the Burst time of process %d: ",i);
        scanf("%d",&p[i].bt);
    }

    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;i++){
        if(p[j].at>p[j+1].at){
            temp = p[j];
            p[j] = p[j+1];
            p[j+1]= temp; }
p[0].ct = p[0].at + p[0].bt;
p[0].tat = p[0].ct - p[0].at;
p[0].wt = p[0].tat - p[0].bt;  }}
for(i=1; i<n; i++){
    ct= p[i-1].ct;
    if(p[i].at>ct){
        p[i].ct = p[i].at + p[i].bt;
    }
    else {
        p[i].ct = ct +p[i].bt;
    }
    p[i].tat = p[i].ct - p[i].at;
    p[i].wt = p[i].tat - p[i].bt;
}
printf("process id\t, Arrival Time\t, Burst TIme\t, Completion time\t Turn Around\t Waiting  Time\t");
for(i =0; i<n; i++){
printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
}
return 0;
}

#include <stdio.h>
typedef struct processes {
    char id;
    int bt,at,rt,wt,tat;
}processes;
void round_robin(processes p[],int n,int tq) {
    int t = 0,rem=n,total_wt=0,total_tat= 0;
    printf("\nGantt Chart:\n0");
    while (rem>0) {
        for (int i=0;i<n; i++) {
            if (p[i].rt > 0 && p[i].at <= t) {
                int ts;
                if (p[i].rt < tq) ts = p[i].rt;
                else ts = tq;
                p[i].rt -= ts;
                t += ts;
                printf(" -- %c -- %d", p[i].id, t);
                if (p[i].rt == 0) {
                    rem--;
                    p[i].tat = t - p[i].at;
                    p[i].wt = p[i].tat - p[i].bt;
                    total_wt += p[i].wt;
                    total_tat += p[i].tat;
                }
            }
        }
    }
    printf("\nAvg WT: %.2f\n",(float)total_wt/n);
    printf("Avg TAT: %.2f\n",(float)total_tat/n);
}
int main() {
    int n, tq;
    printf("Enter TQ: ");
    scanf("%d", &tq);
    printf("Enter number of processes: ");
    scanf("%d", &n);
     processes p[n];
    for (int i = 0; i < n; i++) {
        printf("Enter ID, BT, AT for process %d: ", i + 1);
        getchar();
        scanf("%c %d %d", &p[i].id, &p[i].bt, &p[i].at);
        p[i].rt = p[i].bt;
    }
    round_robin(p, n, tq);
    return 0;
}

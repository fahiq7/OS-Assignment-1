#include <stdio.h>
#include <string.h>

struct Process {
    char pid[10];
    int at, bt, rt, ct, wt, tat;
};

int main() {
    int n, i, time = 0, completed = 0, min_index;
    float total_wt = 0, total_tat = 0;

    scanf("%d", &n);

    struct Process p[n];

    for (i = 0; i < n; i++) {
        scanf("%s %d %d", p[i].pid, &p[i].at, &p[i].bt);
        p[i].rt = p[i].bt;
    }

    while (completed != n) {
        min_index = -1;
        int min_rt = 9999;

        for (i = 0; i < n; i++) {
            if (p[i].at <= time && p[i].rt > 0) {
                if (p[i].rt < min_rt) {
                    min_rt = p[i].rt;
                    min_index = i;
                }
            }
        }

        if (min_index == -1) {
            time++;
            continue;
        }

        p[min_index].rt--;
        time++;

        if (p[min_index].rt == 0) {
            completed++;
            p[min_index].ct = time;
            p[min_index].tat = p[min_index].ct - p[min_index].at;
            p[min_index].wt = p[min_index].tat - p[min_index].bt;

            total_wt += p[min_index].wt;
            total_tat += p[min_index].tat;
        }
    }

    printf("Waiting Time:\n");
    for (i = 0; i < n; i++) {
        printf("%s %d\n", p[i].pid, p[i].wt);
    }

    printf("Turnaround Time:\n");
    for (i = 0; i < n; i++) {
        printf("%s %d\n", p[i].pid, p[i].tat);
    }

    printf("Average Waiting Time: %.1f\n", total_wt / n);
    printf("Average Turnaround Time: %.1f\n", total_tat / n);

    return 0;
}

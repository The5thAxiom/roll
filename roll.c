#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// color list thanks to RabaDabaDoba on github
// https://gist.github.com/RabaDabaDoba/145049536f815903c79944599c6f952a

#define BLK "\e[0;30m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define WHT "\e[0;37m"

int main(int argc, char *argv[]) {
    int d = 20;
    int n = 1;
    int a = 0;

    char *critColor = RED;
    char *failColor = CYN;

    if (argc > 1)
        for (int i = 1; i < argc; i++) {
            if (argv[i][0] == '-') {
                if (argv[i][1] == 'd') d = atoi(argv[++i]);
                if (argv[i][1] == 'n') n = atoi(argv[++i]);
                if (argv[i][1] == 'a') a = atoi(argv[++i]);
            } else {
                sscanf(argv[1], "%dd%d+%d", &n, &d, &a);
            }
        }
    
    srand(clock());

    int ans = a;
    for (int i = 0; i < n; i++) {
        int roll = rand() % d + 1;
        if (roll == d) printf("\a");
        printf(
            "%s%s%d%s",
            i == 0 ? "" : " + ",
            roll == d ? critColor : roll == 1 ? failColor : "" ,
            roll,
            WHT
        );
        ans += roll;
    }

    if (a > 0) printf(" + %d = %d\n", a, ans);
    else if (n == 1) printf("\n");
    else if (n == 0) printf("0\n");
    else printf(" = %d\n", ans);
    return 0;
}

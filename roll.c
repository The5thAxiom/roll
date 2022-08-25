#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

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

    bool adv = false;
    bool dadv = false;

    char *critColor = RED;
    char *failColor = CYN;

    if (argc > 1)
        for (int i = 1; i < argc; i++) {
            if (argv[i][0] == '-') {
                switch (argv[i][1]) {
                case 'd':
                    d = atoi(argv[++i]);
                    break;
                
                case 'n':
                    n = atoi(argv[++i]);
                    break;
                
                case 'a':
                    a = atoi(argv[++i]);
                    break;

                case 'A':
                    adv = true;
                    break;

                case 'D':
                    dadv = true;
                    break;
                
                case 'v':
                    printf("version 0.1.0\n");
                    return 0;
                    break;

                case 'h':
                    printf("help coming soon :)\n");
                    return 0;
                    break;
                
                default:
                    printf("help coming soon :)\n");
                    return 0;
                    break;
                }
            } else {
                if (argv[1][0] == 'd')
                    sscanf(argv[1], "d%d+%d", &d, &a);
                else
                    sscanf(argv[1], "%dd%d+%d", &n, &d, &a);
            }
        }
    
    srand(clock());

    if (adv && !dadv) {
        if (n != 1) printf("only 1 dice can be rolled with adavntage at a time\n");
        else {
            int roll1 = rand() % d + 1;
            int roll2 = rand() % d + 1;
            int ans = a + (roll1 > roll2 ? roll1 : roll2);
            printf(
                "max(%s%d%s, %s%d%s)",
                roll1 == d ? critColor : roll1 == 1 ? failColor : "",
                roll1,
                WHT,
                roll2 == d ? critColor : roll2 == 1 ? failColor : "",
                roll2,
                WHT
            );
            if (a > 0) printf(" + %d", a);
            printf(" = %d\n", ans);
        }
    } else if (dadv && !adv) {
        if (n != 1) printf("only 1 dice can be rolled with adavntage at a time\n");
        else {
            int roll1 = rand() % d + 1;
            int roll2 = rand() % d + 1;
            int ans = a + (roll1 < roll2 ? roll1 : roll2);
            printf(
                "min(%s%d%s, %s%d%s)",
                roll1 == d ? critColor : roll1 == 1 ? failColor : "",
                roll1,
                WHT,
                roll2 == d ? critColor : roll2 == 1 ? failColor : "",
                roll2,
                WHT
            );
            if (a > 0) printf(" + %d", a);
            printf(" = %d\n", ans);
        }
    } else {
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
    }
    return 0;
}

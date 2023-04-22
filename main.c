#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

void visualize(char map[6][6]);
char findDistance(char map[6][6]);

int main() {
    char map[6][6] = {
        {'X', '0', '#', '0', '0', '0'},
        {'0', '0', '#', '#', '#', '0'},
        {'0', '0', '#', '0', '0', '0'},
        {'0', '0', '0', '0', '#', '0'},
        {'0', '0', '#', '0', '#', '0'},
        {'0', '0', '#', '#', '#', 'Y'}
    }; 

    //visualize(map);
    findDistance(map);

    return 0;
}

void visualize(char map[6][6]) {
    printf("'X': Starting position.\n");
    printf("'Y': Ending position.\n");
    printf("'#': Barrier blocks.\n");
    printf("\n");

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    return;
}

char findDistance(char map[6][6]) {
    int n;
    char cache;
    bool cont = true;
    while (cont) {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 6; j++) {
                cache = map[i][j]; // i = y; j = x

                if (cache == 'X') {
                    if (i > 0) map[i-1][j] = '1';
                    if (i < 5) map[i+1][j] = '1';
                    if (j < 5) map[i][j+1] = '1';
                    if (j > 0) map[i][j-1] = '1';
                }
                else if (cache != 'Y' && cache != '#') {
                    n = cache - '0';
                    if (n != 0) {
                        char buf[2];
                        sprintf(buf, "%d", n+1);
                        if (i > 0 && map[i-1][j] == '0') map[i-1][j] = buf[0];
                        if (i < 5 && map[i+1][j] == '0') map[i+1][j] = buf[0];
                        if (j < 5 && map[i][j+1] == '0') map[i][j+1] = buf[0];
                        if (j > 0 && map[i][j-1] == '0') map[i][j-1] = buf[0];
                    }
                }
            }
        }

        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 6; j++) {
                if (map[i][j] == 'Y'){
                    if (i > 0 && map[i-1][j] != 'X' && 
                        map[i-1][j] != '#' && 
                        map[i-1][j] != '0')
                        cont = false;
                    if (i > 0 && map[i-1][j] != 'X' && 
                        map[i-1][j] != '#' && 
                        map[i-1][j] != '0')
                        cont = false;
                    if (i > 0 && map[i-1][j] != 'X' &&  
                        map[i-1][j] != '#' && 
                        map[i-1][j] != '0')
                        cont = false;
                    if (i > 0 && map[i-1][j] != 'X' && 
                        map[i-1][j] != '#' && 
                        map[i-1][j] != '0')
                        cont = false;
                }
            }
        }
    }
    visualize(map);
    
    return map;
} 
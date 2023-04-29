#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

void visualize(char map[6][6]);
char findDistance(char map[6][6]);
void mapRoute(char map[6][6]);

int main() {
    char map[6][6] = {
        {'X', '0', '#', '0', '0', '0'},
        {'0', '0', '#', '#', '#', '0'},
        {'0', '0', '#', '0', '0', '0'},
        {'0', '0', '0', '0', '#', '0'},
        {'0', '0', '#', '0', '#', '0'},
        {'0', '0', '#', '#', '#', 'Y'}
    }; 

    
    map[6][6] = findDistance(map);
    mapRoute(map);

    return 0;
}

void mapRoute(char map[6][6]) {
    char nums[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int n = 8;
    int yy = 0, yx = 0;
    int cy = 0, cx = 0;

    for (yy = 0; yy < 6; yy++) {
        for (yx = 0; yx < 6; yx++) {
            if (map[yy][yx] == 'Y') {
                goto exitLoops1;
            }
        }
    }

    exitLoops1:

    cy = yy;
    cx = yx;

    // loop start
    
    while (true) {
        if (cy > 0 && map[cy-1][cx] == nums[n]) map[cy-1][cx] = 'p', cy--, n--;
        else if (cy < 5 && map[cy+1][cx] == nums[n]) map[cy+1][cx] = 'p', cy++, n--;
        else if (cx < 5 && map[cy][cx+1] == nums[n]) map[cy][cx+1] = 'p', cx++, n--;
        else if (cx > 0 && map[cy][cx-1] == nums[n]) map[cy][cx-1] = 'p', cx--, n--;

        else if (cy > 0 && map[cy-1][cx] == 'X') break;
        else if (cy < 5 && map[cy+1][cx] == 'X') break;
        else if (cx < 5 && map[cy][cx+1] == 'X') break;
        else if (cx > 0 && map[cy][cx-1] == 'X') break;

        else {
            n--;
        }

        if (n == -1) n = 8;
    }
    

    // loop end

    visualize(map);

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
    
    return map;
} 
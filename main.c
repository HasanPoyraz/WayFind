#include <stdio.h>
#include <stdbool.h>

#define as 6

void visualize(char map[as][as]);
char findDistance(char map[as][as]);
char mapRoute(char map[as][as]);

int main() {

    // default map
    char map[as][as] = {
        {'X', '0', '#', '0', '0', '0'},
        {'0', '0', '#', '#', '#', '0'},
        {'0', '0', '#', '0', '0', '0'},
        {'0', '0', '#', '0', '#', '0'},
        {'0', '0', '0', '0', '#', '0'},
        {'0', '0', '0', '0', '#', 'Y'}
    }; 

    
    map[as][as] = findDistance(map);
    map[as][as] = mapRoute(map);

    visualize(map);

    return 0;
}

char mapRoute(char map[as][as]) {
    char nums[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int n = 8;
    int yy = 0, yx = 0;
    int cy = 0, cx = 0;

    for (yy = 0; yy < as; yy++) {
        for (yx = 0; yx < as; yx++) {
            if (map[yy][yx] == 'Y') {
                goto exitLoops1;
            }
        }
    }

    exitLoops1:

    cy = yy;
    cx = yx;
    
    while (true) {
        if (cy > 0 && map[cy-1][cx] == nums[n]) map[cy-1][cx] = 'p', cy--, n--;
        else if (cy < as-1 && map[cy+1][cx] == nums[n]) map[cy+1][cx] = 'p', cy++, n--;
        else if (cx < as-1 && map[cy][cx+1] == nums[n]) map[cy][cx+1] = 'p', cx++, n--;
        else if (cx > 0 && map[cy][cx-1] == nums[n]) map[cy][cx-1] = 'p', cx--, n--;

        else if (cy > 0 && map[cy-1][cx] == 'X') break;
        else if (cy < as-1 && map[cy+1][cx] == 'X') break;
        else if (cx < as-1 && map[cy][cx+1] == 'X') break;
        else if (cx > 0 && map[cy][cx-1] == 'X') break;

        else {
            n--;
        }

        if (n == -1) n = 8;
    }
    
    return map;

}       

void visualize(char map[as][as]) {
    printf("'X': Starting position.\n");
    printf("'Y': Ending position.\n");
    printf("'#': Barrier blocks.\n");
    printf("\n");

    for (int i = 0; i < as; i++) {
        for (int j = 0; j < as; j++) {
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    return;
}

char findDistance(char map[as][as]) {
    int n;
    char cache;
    bool cont = true;
    while (cont) {
        for (int i = 0; i < as; i++) {
            for (int j = 0; j < as; j++) {
                cache = map[i][j]; // i = y; j = x

                if (cache == 'X') {
                    if (i > 0) map[i-1][j] = '1';
                    if (i < as-1) map[i+1][j] = '1';
                    if (j < as-1) map[i][j+1] = '1';
                    if (j > 0) map[i][j-1] = '1';
                }
                else if (cache != 'Y' && cache != '#') {
                    n = cache - '0';
                    if (n != 0) {
                        char buf[2];
                        sprintf(buf, "%d", n+1);
                        if (i > 0 && map[i-1][j] == '0') map[i-1][j] = buf[0];
                        if (i < as-1 && map[i+1][j] == '0') map[i+1][j] = buf[0];
                        if (j < as-1 && map[i][j+1] == '0') map[i][j+1] = buf[0];
                        if (j > 0 && map[i][j-1] == '0') map[i][j-1] = buf[0];
                    }
                }
            }
        }

        for (int i = 0; i < as; i++) {
            for (int j = 0; j < as; j++) {
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
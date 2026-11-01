#include <ncurses.h>
#include <time.h>
#include <stdlib.h>

#define MAX_WIDTH 50
#define MAX_HEIGHT 12


int main(void){
    int ch;
    int count = 0;

    initscr();
    noecho();
    curs_set(0);
    timeout(150);

    time_t start_time = time(NULL);
    int elapsed = 0;

    // time for start

    while(elapsed < 3){
        elapsed = (int)(time(NULL) - start_time);

        clear();
        printw("%d",elapsed);
        refresh();

        napms(200);
    }
    timeout(150);
    clear();

    // game map

    for(int i = 0; i < MAX_HEIGHT; i++){
        mvprintw(i, 0, "#");
        mvprintw(i, MAX_WIDTH - 1, "#");

    }
    for(int i = 0; i < MAX_WIDTH; i++){
        mvprintw(0, i, "#");
        mvprintw(MAX_HEIGHT - 1, i, "#");
    }
    refresh();

    // snake spawn

    srand(time(NULL));

    int x = 1 + rand() % (MAX_WIDTH - 4);
    int y = 1 + rand() % (MAX_HEIGHT - 4);

    int snake_x[100];
    int snake_y[100];
    int snake_length = 3;

    snake_x[0] = x;
    snake_y[0] = y;

    for (int i = 1; i < snake_length; i++) {
            snake_x[i] = snake_x[0] - i;
            snake_y[i] = snake_y[0];
    }

    for (int i = 0; i < snake_length; i++) {
        char symbol;
        if (i==0) symbol = '@';
        else symbol = 'o';
        mvprintw(snake_y[i], snake_x[i], "%c", symbol);
    }
    refresh();

    // apple spawn

    int apple_x = 1 + rand() % (MAX_WIDTH - 3);
    int apple_y = 1 + rand() % (MAX_HEIGHT - 3);

    mvprintw(apple_y, apple_x, "*");
    refresh();

    // movement

    int dir_x = 0;
    int dir_y = 0;

    while(1){
            ch = getch();

            // quit
            if (ch == 'q' || ch == 'Q'){
                break;
            }

            // wasd movement

            else if (ch == 'w' || ch == 'W'){
                dir_x = 0;
                dir_y = -1;
            }
            else if (ch == 's' || ch == 'S'){
                dir_x = 0;
                dir_y = 1;
            }
            else if (ch == 'a' || ch == 'A'){
                dir_x = -1;
                dir_y = 0;
            }
            else if (ch == 'd' || ch == 'D'){
                dir_x = 1;
                dir_y = 0;
            }

            if (dir_x == 0 && dir_y == 0) {
                continue;
            }

            // apple logic

            int ate_apple = 0;
            if (snake_x[0] == apple_x && snake_y[0] == apple_y) {
                ate_apple = 1;
                snake_length++;
                count++;


                apple_x = 1 + rand() % (MAX_WIDTH - 3);
                apple_y = 1 + rand() % (MAX_HEIGHT - 3);
                mvprintw(apple_y, apple_x, "*");
            }

            if (!ate_apple) {
                mvprintw(snake_y[snake_length - 1], snake_x[snake_length - 1], " ");
            }

            for (int i = snake_length - 1; i > 0; i--) {
                snake_x[i] = snake_x[i - 1];
                snake_y[i] = snake_y[i - 1];
            }

            snake_x[0] += dir_x;
            snake_y[0] += dir_y;

            if (snake_x[0] == 0 || snake_x[0] == MAX_WIDTH - 1 ||
                snake_y[0] == 0 || snake_y[0] == MAX_HEIGHT - 1) {
                break;
            }

            int self_collision = 0;

            for(int i = 1; i < snake_length; i++){
                if(snake_x[0] == snake_x[i] && snake_y[0] == snake_y[i]) self_collision = 1;
            }

            if(self_collision == 1) break;

            for (int i = 0; i < snake_length; i++) {
                char symbol = (i == 0) ? '@' : 'o';
                mvprintw(snake_y[i], snake_x[i], "%c", symbol);
            }

            mvprintw(8, 60, "score: %d", count);
            refresh();
        }
    refresh();
    start_time = time(NULL);
    elapsed = 0;
    while(elapsed < 3){
        elapsed = (int)(time(NULL) - start_time);

        clear();
        mvprintw(6, 20, "game ower");
        mvprintw(7, 20, "your score: %d", count);
        refresh();

        napms(200);
    }
    timeout(150);
    endwin();
    return 0;
}

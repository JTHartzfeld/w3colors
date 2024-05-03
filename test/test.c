#include <curses.h>
#include <w3colors.h>
#include <string.h>
extern char* tosquishname(const char* name);

int main() {
    initscr();
    if(!init_w3colors()) return -1;
    noecho();
    cbreak();
    clear();
    refresh();
    int f=w3color("grey"), b=COLOR_DARKGREEN;
    init_pair(1, f, b);
    attron(COLOR_PAIR(1));
    char* msg = "Hello World, from the W3C fanclub.";
    mvaddstr(LINES/2, (COLS-strlen(msg))/2, msg);
    attroff(COLOR_PAIR(1));
    refresh();
    getch();
    endwin();
    printf("%d %d\n", w3color("grey"), b);
    char* tmp = tosquishname("Fat Hairy Bastard");
    printf("%s %s\n", w3colorgroups[5]->aliases[1], tmp);
    return 0;
}
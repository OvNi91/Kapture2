#include <windows.h>

void color(int text, int screen)
{
    HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,screen*16+text);
    /* 0: black
       1: dark blue
       2: green
       3: blue-grey
       4: brown
       5: purple
       6: khaki
       7: light grey
       8: grey
       9: blue
      10: light green
      11: turquoise
      12: red
      13: light pink
      14: light yellow
      15: white
      fflush(stdout) allow us to print many colors on the same line */
}

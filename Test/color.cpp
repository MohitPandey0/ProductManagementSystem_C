#include <iostream>

#ifdef _WIN32
#include <windows.h>

#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#define DISABLE_NEWLINE_AUTO_RETURN  0x0008

void activateVirtualTerminal()
{       
    HANDLE handleOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD consoleMode;
    GetConsoleMode( handleOut , &consoleMode);
    consoleMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    consoleMode |= DISABLE_NEWLINE_AUTO_RETURN;            
    SetConsoleMode( handleOut , consoleMode );
}
#endif

using namespace std;

enum COLORS {
    NC=-1,
    BLACK,
    RED,
    GREEN,
    YELLOW,
    BLUE,
    MAGENTA,
    CYAN,
    WHITE,
};

/**
* Colorize terminal colors ANSI escape sequences.
*
* @param font font color (-1 to 7), see COLORS enum
* @param back background color (-1 to 7), see COLORS enum
* @param style font style (1==bold, 4==underline)
**/
const char *colorize(int font, int back = -1, int style = -1) {
    static char code[20];
    
    if (font >= 0)
        font += 30;
    else
        font = 0;
    if (back >= 0)
        back += 40;
    else
        back = 0;

    if (back > 0 && style > 0) {
        sprintf(code, "\033[%d;%d;%dm", font, back, style);
    } else if (back > 0) {
        sprintf(code, "\033[%d;%dm", font, back);
    } else {

        sprintf(code, "\033[%dm", font);
    }

    return code;
}


int main()
{
#ifdef _WIN32
    activateVirtualTerminal();
#endif

    cout << colorize(RED) << "trying red" << colorize(NC) << endl;
    cout << colorize(RED, BLACK) << "red and black background" << colorize(NC) << endl;
    cout << colorize(YELLOW, BLUE, 1) << "yellow blue bold" << colorize(NC) << endl;
    cout << colorize(BLACK, WHITE) << "Black white" << colorize(NC) << endl;
    cout << colorize(MAGENTA, CYAN) << "Magenta cyan" << colorize(NC) << endl;

    return 1;
}
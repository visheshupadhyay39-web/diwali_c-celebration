#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
    #include <windows.h>
    #define sleep_ms(ms) Sleep(ms)
    #define clear_screen() system("cls")
#else
    #include <unistd.h>
    #define sleep_ms(ms) usleep((ms) * 1000)
    #define clear_screen() system("clear")
#endif

// ANSI Color Codes
#define COLOR_RESET   "\033[0m"
#define COLOR_RED     "\033[1;31m"
#define COLOR_YELLOW  "\033[1;33m"
#define COLOR_ORANGE  "\033[38;5;208m"
#define COLOR_CYAN    "\033[1;36m"
#define COLOR_GREEN   "\033[1;32m"

void printDiya(int flameToggle) {
    clear_screen();
    printf("\n\n");

    // Flickering Flame Logic
    if (flameToggle % 2 == 0) {
        printf(COLOR_YELLOW "                 )                 \n" COLOR_RESET);
        printf(COLOR_YELLOW "                ( )                \n" COLOR_RESET);
        printf(COLOR_RED    "               (   )               \n" COLOR_RESET);
    } else {
        printf(COLOR_RED    "                (                  \n" COLOR_RESET);
        printf(COLOR_YELLOW "               ( )                 \n" COLOR_RESET);
        printf(COLOR_YELLOW "              (   )                \n" COLOR_RESET);
    }

    // Base Diya
    printf(COLOR_ORANGE "         .=============..          \n" COLOR_RESET);
    printf(COLOR_ORANGE "        /                 \\         \n" COLOR_RESET);
    printf(COLOR_ORANGE "       |   *  *  *  *  *   |        \n" COLOR_RESET);
    printf(COLOR_ORANGE "        \\                 /         \n" COLOR_RESET);
    printf(COLOR_ORANGE "         '==============='          \n\n" COLOR_RESET);
}

int main() {
    char name[50];

    printf(COLOR_CYAN "========================================\n" COLOR_RESET);
    printf(COLOR_YELLOW "   FESTIVAL OF LIGHTS: DIWALI IN C     \n" COLOR_RESET);
    printf(COLOR_CYAN "========================================\n\n" COLOR_RESET);

    printf("Apna naam enter karein: ");
    if (fgets(name, sizeof(name), stdin) != NULL) {
        // newline character remove karne ke liye
        for (int i = 0; name[i] != '\0'; i++) {
            if (name[i] == '\n') {
                name[i] = '\0';
                break;
            }
        }
    }

    printf("\nDiya jalaya jaa raha hai...");
    sleep_ms(1000);

    // Diya flicker animation loop (10 frames)
    for (int i = 0; i < 10; i++) {
        printDiya(i);
        sleep_ms(300);
    }

    // Final Festive Message
    printf(COLOR_GREEN "========================================================\n" COLOR_RESET);
    printf(COLOR_YELLOW "   HAPPY DIWALI, %s!\n" COLOR_RESET, name);
    printf(COLOR_CYAN   "   May your life shine bright with success and happiness!\n" COLOR_RESET);
    printf(COLOR_GREEN "========================================================\n\n" COLOR_RESET);

    return 0;
}
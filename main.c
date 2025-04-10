#include <stdio.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

void pasek(int moment) {
    const int dlugosc_paska = 50;
    int pos = (moment * dlugosc_paska) / 100;

    printf("\r[");
    for (int i = 0; i < dlugosc_paska; i++) {
        if (i < pos) {
            printf("=");
        } else if (i == pos) {
            printf(">");
        } else {
            printf(" ");
        }
    }
    printf("] %3d%%", moment);
    fflush(stdout);
}

int main() {
    // przykładowy proces
    for (int i = 0; i < 100; i++) {
        pasek(i);

        #ifdef _WIN32
        Sleep(20); // 100 ms
        #else
        usleep(20000); // 100000 us = 100 ms
        #endif
    }
    printf("\nŁadowanie zakończone!\n");
    return 0;
}
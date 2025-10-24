#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#include <windows.h>  // For Sleep on Windows
#define delay(seconds) Sleep((seconds) * 1000)
#else
#include <unistd.h>   // For sleep on Linux/macOS
#define delay(seconds) sleep(seconds)
#endif

// Define FSM states
typedef enum {
    RED,
    GREEN,
    YELLOW
} State;

int main() {
    State current_state = RED;
    int cycles = 5; // Number of full FSM cycles

    printf("=== Traffic Light FSM Simulation ===\n");

    while (cycles > 0) {
        switch (current_state) {
            case RED:
                printf("RED light ON - Stop!\n");
                delay(3);  // 3 seconds delay
                current_state = GREEN;
                break;

            case GREEN:
                printf("GREEN light ON - Go!\n");
                delay(3);  // 3 seconds delay
                current_state = YELLOW;
                break;

            case YELLOW:
                printf("YELLOW light ON - Get ready!\n");
                delay(2);  // 2 seconds delay
                current_state = RED;
                cycles--; // One full cycle completed
                break;

            default:
                printf("Invalid state!\n");
                exit(1);
        }
    }

    printf("=== FSM simulation ended ===\n");
    return 0;
}


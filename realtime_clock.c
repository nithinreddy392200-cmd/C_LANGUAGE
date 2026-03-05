#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#ifdef _WIN32
    #include <windows.h>
    #define CLEAR_SCREEN "cls"
#else
    #include <unistd.h>
    #define CLEAR_SCREEN "clear"
#endif

#define MAX_ALARMS 5

struct Alarm {
    int hour, min, sec;
    char ampm[3];
    int active;
};

struct Alarm alarms[MAX_ALARMS];
int alarm_count = 0;

void clear_screen() {
    system(CLEAR_SCREEN);
}

void print_welcome() {
    printf("======================================\n");
    printf("      Advanced Real-Time Clock\n");
    printf("======================================\n");
    printf("Press Ctrl+C to exit.\n\n");
}

int get_12hour(int *h) {
    printf("Hour (1-12): ");
    scanf("%d", h);
    return (*h >= 1 && *h <= 12);
}

int get_time(int *m, int *s) {
    printf("Minute (0-59): ");
    scanf("%d", m);
    if (*m < 0 || *m > 59) return 0;
    printf("Second (0-59): ");
    scanf("%d", s);
    return (*s >= 0 && *s <= 59);
}

void set_alarm() {
    if (alarm_count >= MAX_ALARMS) {
        printf("Max alarms reached!\n");
        return;
    }
    struct Alarm a;
    if (!get_12hour(&a.hour) || !get_time(&a.min, &a.sec)) {
        printf("Invalid time!\n");
        return;
    }
    printf("AM/P (A/P): ");
    scanf("%s", a.ampm);
    if (strcmp(a.ampm, "A") != 0 && strcmp(a.ampm, "P") != 0) {
        printf("Invalid AM/PM!\n");
        return;
    }
    a.active = 1;
    alarms[alarm_count++] = a;
    printf("Alarm set for %02d:%02d:%02d %s\n", a.hour, a.min, a.sec, a.ampm);
}

void show_alarms() {
    if (alarm_count == 0) {
        printf("No alarms set.\n");
        return;
    }
    for (int i = 0; i < alarm_count; i++) {
        if (alarms[i].active)
            printf("%d: %02d:%02d:%02d %s\n", i+1, alarms[i].hour, alarms[i].min, alarms[i].sec, alarms[i].ampm);
    }
}

void cancel_alarm() {
    show_alarms();
    if (alarm_count == 0) return;
    int idx;
    printf("Cancel index: ");
    scanf("%d", &idx);
    if (idx > 0 && idx <= alarm_count) {
        alarms[idx-1].active = 0;
        printf("Alarm canceled.\n");
    }
}

void display_time() {
    time_t now = time(NULL);
    struct tm *local = localtime(&now);
    int h = local->tm_hour % 12;
    if (h == 0) h = 12;
    char ampm[3] = (local->tm_hour >= 12) ? "PM" : "AM";
    printf("Date: %02d-%02d-%04d\n", local->tm_mday, local->tm_mon + 1, local->tm_year + 1900);
    printf("Time: %02d:%02d:%02d %s\n", h, local->tm_min, local->tm_sec, ampm);
}

int check_alarms(struct tm *local) {
    int h = local->tm_hour % 12; if (h == 0) h = 12;
    char curr_ampm[3] = (local->tm_hour >= 12) ? "PM" : "AM";
    for (int i = 0; i < alarm_count; i++) {
        if (alarms[i].active &&
            alarms[i].hour == h && alarms[i].min == local->tm_min &&
            alarms[i].sec == local->tm_sec && strcmp(alarms[i].ampm, curr_ampm) == 0) {
            printf("\aALARM! %02d:%02d:%02d %s TRIGGERED!\n", alarms[i].hour, alarms[i].min, alarms[i].sec, alarms[i].ampm);
            alarms[i].active = 0;
            return 1;
        }
    }
    return 0;
}

void menu() {
    int choice;
    do {
        clear_screen();
        print_welcome();
        display_time();
        printf("\nOptions:\n1. Set Alarm\n2. Cancel Alarm\n3. Show Alarms\n4. Start Clock\n");
        printf("Choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: set_alarm(); break;
            case 2: cancel_alarm(); break;
            case 3: clear_screen(); show_alarms(); getchar(); break;
            case 4: break;
            default: printf("Invalid!\n");
        }
        if (choice != 4) {
            printf("Press Enter...");
            getchar(); getchar();
        }
    } while (choice != 4);
}

int main() {
    menu();
    printf("\nStarting real-time clock...\n");
    while (1) {
        clear_screen();
        print_welcome();
        display_time();
        time_t now = time(NULL);
        struct tm *local = localtime(&now);
        check_alarms(local);
        sleep(1);
    }
    return 0;
}

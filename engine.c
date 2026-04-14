#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

#define FILE_NAME "containers.txt"

// START
void start_container(char *id) {
    pid_t pid = fork();

    if (pid == 0) {
        execl("/bin/sleep", "sleep", "1000", NULL);
        exit(1);
    } else {
        FILE *fp = fopen(FILE_NAME, "a");
        fprintf(fp, "%s %d running\n", id, pid);
        fclose(fp);

        printf("Started container %s with PID %d\n", id, pid);
    }
}

// LIST
void list_containers() {
    FILE *fp = fopen(FILE_NAME, "r");

    if (!fp) {
        printf("No containers found\n");
        return;
    }

    char id[50], status[20];
    int pid;

    printf("\nID\tPID\tSTATUS\n");

    while (fscanf(fp, "%s %d %s", id, &pid, status) != EOF) {
        printf("%s\t%d\t%s\n", id, pid, status);
    }

    printf("\n");
    fclose(fp);
}

// STOP
void stop_container(char *id) {
    FILE *fp = fopen(FILE_NAME, "r");
    FILE *temp = fopen("temp.txt", "w");

    char cid[50], status[20];
    int pid;
    int found = 0;

    while (fscanf(fp, "%s %d %s", cid, &pid, status) != EOF) {
        if (strcmp(cid, id) == 0) {
            kill(pid, SIGTERM);
            fprintf(temp, "%s %d stopped\n", cid, pid);
            found = 1;
            printf("Stopped container %s\n", id);
        } else {
            fprintf(temp, "%s %d %s\n", cid, pid, status);
        }
    }

    fclose(fp);
    fclose(temp);

    remove(FILE_NAME);
    rename("temp.txt", FILE_NAME);

    if (!found)
        printf("Container not found\n");
}

// MAIN
int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("Usage:\n");
        printf("./engine start <id>\n");
        printf("./engine ps\n");
        printf("./engine stop <id>\n");
        return 1;
    }

    if (strcmp(argv[1], "start") == 0) {
        start_container(argv[2]);
    }
    else if (strcmp(argv[1], "ps") == 0) {
        list_containers();
    }
    else if (strcmp(argv[1], "stop") == 0) {
        stop_container(argv[2]);
    }
    else {
        printf("Invalid command\n");
    }

    return 0;
}

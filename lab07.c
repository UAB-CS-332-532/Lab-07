/*
Shahaan Farrukhgit
To Compile: gcc -o lab07 labo7c
To Run: ./lab07 <filename>
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_LINE_LENGTH 1000

int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("Usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *filename = argv[1];

    FILE *fp;
    fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    while(fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        // remove the newline character from the end of the line
        line[strcspn(line, "\n")] = '\0';

        // tokenize the command and arguments
        char *token = strtok(line, " ");
        char *args[10];
        args[0] = token;
        int i = 1;
        while(token != NULL) {
            token = strtok(NULL, " ");
            args[i] = token;
            i++;
        }

        // start the timer
        time_t start_time = time(NULL);

        pid_t pid = fork();
        if(pid == -1) {
            printf("Error forking process.\n");
            exit(EXIT_FAILURE);
        } else if(pid == 0) {
            // this is the child process
            execvp(args[0], args);
            // if execvp returns, then there was an error
            printf("Error executing command: %s\n", line);
            exit(EXIT_FAILURE);
        } else {
            // this is the parent process
            int status;
            waitpid(pid, &status, 0);

            // get the end time
            
            time_t end_time = time(NULL);

            // write to the log file
            FILE *log_file;
            log_file = fopen("output.log", "a");
            fprintf(log_file, "%s\t%s\t%s", line, ctime(&start_time), ctime(&end_time));
            fclose(log_file);
        }
    }

    fclose(fp);
    return 0;
}

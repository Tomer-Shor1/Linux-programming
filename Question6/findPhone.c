/*
    This file demonstrates usage of important tools in linux, such as forks, pipes and execvp.
    The program reads the phonebook.txt file and searches for the name given as an argument.
    The program then prints the phone number of the person with the given name. If the name is not found, the program will not print anything.
    We added a phonebook.txt file to the directory, which contains the names and phone numbers of some people. This file is used for example purposes. 

    To use:
    1. $ make
    2. $ ./findPhone <name>   // NOTE: in out program you can find a person only by using their first name or last name.
    3. $ make clean
*/



#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 256

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <name>\n", argv[0]);
        exit(1);
    }

    char *name = argv[1];   // The name to search for.
    int pipe_fd1[2];
    int pipe_fd2[2];

    if (pipe(pipe_fd1) == -1 || pipe(pipe_fd2) == -1) {
        perror("pipe failed");
        exit(1);
    }

    pid_t pid1 = fork();

    if (pid1 < 0) {
        perror("Fork failed");
        exit(1);

    } else if (pid1 == 0) {
        // First child process
        close(pipe_fd1[0]); 
        dup2(pipe_fd1[1], STDOUT_FILENO); // Redirect stdout to the first pipe
        close(pipe_fd1[1]);

        close(pipe_fd2[0]); // Close both ends of the second pipe
        close(pipe_fd2[1]);

        char *grep_args[] = {"grep", name, "phonebook.txt", NULL};
        execvp("grep", grep_args);
        perror("execvp for grep failed");
        exit(1);
    }

    pid_t pid2 = fork();

    if (pid2 < 0) {
        perror("Fork failed");
        exit(1);

    } else if (pid2 == 0) {
        // Second child process
        dup2(pipe_fd1[0], STDIN_FILENO); // Redirect stdin to the first pipe
        close(pipe_fd1[1]); 
        close(pipe_fd1[0]); 

        dup2(pipe_fd2[1], STDOUT_FILENO); // Redirect stdout to the second pipe
        close(pipe_fd2[0]); 
        close(pipe_fd2[1]);

        char *cut_args[] = {"cut", "-d", ",", "-f", "2", NULL};    // Netzer said we can use cut
        execvp("cut", cut_args);
        perror("execvp for cut failed");
        exit(1);
    }

    // Parent process
    close(pipe_fd1[0]); // Close both ends of the first pipe
    close(pipe_fd1[1]);

    close(pipe_fd2[1]); // Close unused write end of the second pipe

    // Read the output from the second pipe
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;
    while ((bytes_read = read(pipe_fd2[0], buffer, BUFFER_SIZE - 1)) > 0) {
        buffer[bytes_read] = '\0';
        printf("%s", buffer);
    }

    
    close(pipe_fd2[0]); // Close the read end of the second pipe

    // Wait for both child processes to finish
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);

    return 0;
}

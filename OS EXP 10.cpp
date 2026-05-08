// C Program to illustrate Inter-Process Communication using Message Queue

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <unistd.h>

// Structure for message
struct message {
    long msg_type;
    char msg_text[100];
};

int main() {
    int msgid;
    struct message msg;

    // Generate unique key
    key_t key = ftok("progfile", 65);

    // Create message queue
    msgid = msgget(key, 0666 | IPC_CREAT);

    if (msgid == -1) {
        perror("msgget failed");
        exit(1);
    }

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(1);
    }

    // Parent Process - Sender
    if (pid > 0) {
        msg.msg_type = 1;

        printf("Parent Process:\n");
        printf("Enter message: ");
        fgets(msg.msg_text, sizeof(msg.msg_text), stdin);

        // Send message
        msgsnd(msgid, &msg, sizeof(msg.msg_text), 0);

        printf("Message sent: %s\n", msg.msg_text);
    }

    // Child Process - Receiver
    else {
        sleep(1); // wait for sender

        // Receive message
        msgrcv(msgid, &msg, sizeof(msg.msg_text), 1, 0);

        printf("\nChild Process:\n");
        printf("Received message: %s\n", msg.msg_text);

        // Remove message queue
        msgctl(msgid, IPC_RMID, NULL);
    }

    return 0;
}

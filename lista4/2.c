#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct Participant {
    char name[21];
    int is_out;
    struct Participant *next;
} Participant;
 
Participant *create_participant(char *name) {
    Participant *participant = malloc(sizeof(Participant));
    strcpy(participant->name, name);
    participant->is_out = 0;
    participant->next = NULL;
    return participant;
}
 
void insert_participant(Participant **list, Participant *participant) {
    participant->next = *list;
    *list = participant;
}
 
void remove_participant(Participant **list, char *name) {
    Participant *prev = NULL;
    Participant *curr = *list;
 
    while (curr != NULL && strcmp(curr->name, name) != 0) {
        prev = curr;
        curr = curr->next;
    }
 
    if (curr == NULL) return;
 
    if (prev == NULL) {
        *list = curr->next;
    } else {
        prev->next = curr->next;
    }
 
    free(curr);
}
 
int main() {
    Participant *participants = NULL;
    char buffer[21];
    int i, n;
 
    // Read participants
    scanf("%s", buffer);
    while (strcmp(buffer, "Fim") != 0) {
        insert_participant(&participants, create_participant(buffer));
        scanf("%s", buffer);
    }
 
    // Read starting participant
    char starting_participant[21];
    scanf("%s", starting_participant);
 
    // Read number of ball steals
    scanf("%d", &n);
 
    // Process ball steals
    for (i = 0; i < n; i++) {
        char loser[21], winner[21];
        scanf("%s %s", loser, winner);
        remove_participant(&participants, loser);
    }
 
    // Print remaining participants
    Participant *curr = participants;
    while (curr != NULL) {
        printf("%s\n", curr->name);
        curr = curr->next;
    }
 
    return 0;
}
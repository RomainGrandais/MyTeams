/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myftp-hugues.lejeune [WSL: Ubuntu]
** File description:
** structures
*/

#pragma once

#include "commons.h"

enum TableType {
    DEFAULT,
    TEAM,
    CHANNEL,
    THREAD,
    THREADS_REPLY,
    USER,
    MESSAGE
};

typedef struct team_s {
    char *TEAM_NAME;
    char *TEAM_UUID;
} team_t;

typedef struct channel_s {
    char *CHANNEL_NAME;
    char *CHANNEL_UUID;
    char *TEAM_UUID;
} channel_t;

typedef struct thread_s {
    char *THREAD_NAME;
    char *THREAD_UUID;
    char *CHANNEL_UUID;
} thread_t;

typedef struct threadsReply_s {
    char *REPLY_BODY;
    char *REPLY_UUID;
    char *TIMESTAMP;
    char *SENDER_UUID;
    char *THREADS_UUID;
} threads_reply_t;

typedef struct user_s {
    char *USER_NAME;
    char *USER_UUID;
    char *USER_STATUS;
} user_t;

typedef struct message_s {
    char *MESSAGE_BODY;
    char *MESSAGE_UUID;
    char *TIMESTAMP;
    char *SENDER_UUID;
    char *RECEIVER_UUID;
} message_t;

typedef struct teamLink_s {
    char *TEAM_UUID;
    char *USER_UUID;
} teamLink_t;

typedef struct database_s {
    int num;
    FILE *fptr;
    team_t *teams;
    unsigned int teams_size;
    channel_t *channels;
    unsigned int channels_size;
    thread_t *threads;
    unsigned int threads_size;
    threads_reply_t *threads_reply;
    unsigned int threads_reply_size;
    user_t *users;
    unsigned int users_size;
    message_t *messages;
    unsigned int messages_size;
    teamLink_t *teams_links;
    unsigned int teams_links_size;
} database_t;

/* Contains an array of word an its size. */
typedef struct warray_s {
    char **array;
    size_t size;
} warray_t;

/* Contains a buffer, its size and an array of the words in the buffer. */
typedef struct input_s {
    char *buf;
    warray_t *word_array;
    size_t read_size;
} input_t;

/* Contains informations relative to a client. */
typedef struct client_s {
    int fd;
    bool logged_in;
    user_t user;
    struct client_s *next;
} client_t;

/* Contains informations relative to a server. */
typedef struct server_s {
    bool state;
    int port;
    int sfd;
    int max_fd;
    int n_fds;
    fd_set all_fds;
    fd_set read_fds;
    client_t *clients;
    database_t *database;
} server_t;

/*
 * Contains a command name, a pointer to the associated
 * function and the description of the command.
 */
typedef struct commands_s {
    char *name;
    bool (*func)(server_t *server, client_t **client, warray_t *word_array);
    char *help_one;
    char *help_two;
} commands_t;

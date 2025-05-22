/*
** EPITECH PROJECT, 2024
** MyTeams
** File description:
** database
*/

#include "database.h"

static void print_teams(team_t *teams)
{
    printf("---------- [Teams] ----------\n");
    for (int i = 0; teams[i].TEAM_NAME != NULL; i++) {
        printf("-\n");
        printf("TEAM_NAME:\t%s\n", teams[i].TEAM_NAME);
        printf("TEAM_UUID:\t%s\n", teams[i].TEAM_UUID);
    }
}

static void print_channels(channel_t *channels)
{
    printf("\n---------- [Channels] ----------\n");
    for (int i = 0; channels[i].CHANNEL_NAME != NULL; i++) {
        printf("-\n");
        printf("CHANNEL_NAME:\t%s\n", channels[i].CHANNEL_NAME);
        printf("CHANNEL_UUID:\t%s\n", channels[i].CHANNEL_UUID);
        printf("TEAM_UUID:\t%s\n", channels[i].TEAM_UUID);
    }
}

static void print_threads(thread_t *threads)
{
    printf("\n---------- [Threads] ----------\n");
    for (int i = 0; threads[i].THREAD_NAME != NULL; i++) {
        printf("-\n");
        printf("THREAD_NAME:\t%s\n", threads[i].THREAD_NAME);
        printf("THREAD_UUID:\t%s\n", threads[i].THREAD_UUID);
        printf("CHANNEL_UUID:\t%s\n", threads[i].CHANNEL_UUID);
    }
}

static void print_threads_reply(threads_reply_t *threads_reply)
{
    printf("\n---------- [Threads Replies] ----------\n");
    for (int i = 0; threads_reply[i].REPLY_BODY != NULL; i++) {
        printf("-\n");
        printf("REPLY_BODY:\t%s\n", threads_reply[i].REPLY_BODY);
        printf("REPLY_UUID:\t%s\n", threads_reply[i].REPLY_UUID);
        printf("TIMESTAMP:\t%s\n", threads_reply[i].TIMESTAMP);
        printf("SENDER_UUID:\t%s\n", threads_reply[i].SENDER_UUID);
        printf("THREADS_UUID:\t%s\n", threads_reply[i].THREADS_UUID);
    }
}

static void print_users(user_t *users)
{
    printf("\n---------- [Users] ----------\n");
    for (int i = 0; users[i].USER_NAME != NULL; i++) {
        printf("-\n");
        printf("USER_NAME:\t%s\n", users[i].USER_NAME);
        printf("USER_UUID:\t%s\n", users[i].USER_UUID);
        printf("USER_STATUS:\t%s\n", users[i].USER_STATUS);
    }
}

static void print_messages(message_t *messages)
{
    printf("\n---------- [Messages] ----------\n");
    for (int i = 0; messages[i].MESSAGE_BODY != NULL; i++) {
        printf("-\n");
        printf("MESSAGE_BODY:\t%s\n", messages[i].MESSAGE_BODY);
        printf("MESSAGE_UUID:\t%s\n", messages[i].MESSAGE_UUID);
        printf("TIMESTAMP:\t%s\n", messages[i].TIMESTAMP);
        printf("SENDER_UUID:\t%s\n", messages[i].SENDER_UUID);
        printf("RECEIVER_UUID:\t%s\n", messages[i].RECEIVER_UUID);
    }
}

static void print_teams_links(teamLink_t *teams_links)
{
    printf("\n---------- [Teams Links] ----------\n");
    for (int i = 0; teams_links[i].TEAM_UUID != NULL; i++) {
        printf("-\n");
        printf("TEAM_UUID:\t%s\n", teams_links[i].TEAM_UUID);
        printf("USER_UUID:\t%s\n", teams_links[i].USER_UUID);
    }
}

// TEST PURPOSE ONLY
void print_database(database_t *database)
{
    print_teams(database->teams);
    print_channels(database->channels);
    print_threads(database->threads);
    print_threads_reply(database->threads_reply);
    print_users(database->users);
    print_messages(database->messages);
    print_teams_links(database->teams_links);
}

void fill_database(database_t *database, FILE *file)
{
    char line[256];

    while (fgets(line, sizeof(line), file)) {
        if (strcmp(line, "[TEAMS]\n") == 0)
            fill_team(database, file);
        if (strcmp(line, "[CHANNELS]\n") == 0)
            fill_channel(database, file);
        if (strcmp(line, "[THREADS]\n") == 0)
            fill_thread(database, file);
        if (strcmp(line, "[THREADS_REPLY]\n") == 0)
            fill_thread_reply(database, file);
        if (strcmp(line, "[USERS]\n") == 0)
            fill_user(database, file);
        if (strcmp(line, "[MESSAGES]\n") == 0)
            fill_message(database, file);
        if (strcmp(line, "[TEAMS_LINK]\n") == 0)
            fill_team_link(database, file);
    }
}

bool open_database(database_t *database)
{
    FILE *file = fopen("./storage/TeamsDatabase.db", "r");

    if (file == NULL)
        return false;
    fill_database(database, file);
    fclose(file);
    return true;
}

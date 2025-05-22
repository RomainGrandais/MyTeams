/*
** EPITECH PROJECT, 2024
** MyTeams
** File description:
** database
*/

#pragma once

#include "structures.h"

// Fillers
int fill_team(database_t *database, FILE *file);
int fill_channel(database_t *database, FILE *file);
int fill_thread(database_t *database, FILE *file);
int fill_thread_reply(database_t *database, FILE *file);
int fill_user(database_t *database, FILE *file);
int fill_message(database_t *database, FILE *file);
int fill_team_link(database_t *database, FILE *file);

// Getters
channel_t get_channel_by_uuid(database_t *database, char *uuid);

message_t get_message_by_uuid(database_t *database, char *uuid);
message_t get_message_by_sender_uuid(database_t *database, char *uuid);
message_t get_message_by_receiver_uuid(database_t *database, char *uuid);
char **get_subscribed_teams_uuids(database_t *database, char *uuid);
char **get_team_subscribers_uuids(database_t *database, char *uuid);
team_t get_team_by_uuid(database_t *database, char *uuid);
char **get_theard_reply(database_t *database, char *thread_uuid);
threads_reply_t get_thread_reply_by_uuid(database_t *database, char *uuid);
user_t get_user_by_name(database_t *database, char *username);
user_t get_user_by_uuid(database_t *database, char *uuid);

// Setters
void add_channel(database_t *database, channel_t channel);
void add_message(database_t *database, message_t message);
void add_team_link(database_t *database, teamLink_t team_link);
void add_team(database_t *database, team_t team);
void add_thread_reply(database_t *database, threads_reply_t thread_reply);
void add_thread(database_t *database, thread_t thread);
void add_user(database_t *database, user_t user);
void set_user_status(database_t *database, const char *uuid,
    const char *status);

//Savers
void save_channels(database_t *database, FILE *file);
void save_messages(database_t *database, FILE *file);
void save_team_links(database_t *database, FILE *file);
void save_teams(database_t *database, FILE *file);
void save_thread_reply(database_t *database, FILE *file);
void save_threads(database_t *database, FILE *file);
void save_users(database_t *database, FILE *file);

// Utils
int get_data_size(char *line, int data_id);
char *get_data(char *line, int data_id);
database_t *init_database(void);
bool open_database(database_t *database);
int save_database_to_file(database_t *database);
void free_database(database_t *database);

/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-hugo.murat
** File description:
** commands
*/

#pragma once

#include "structures.h"

/* Number of commands defined. */
#define NB_CMD 7


/**
 * @brief Send a list of all commands with their description.
 *
 * @param server Structure containing informations about the server.
 * @param client Pointer to structure containing informations about the client.
 * @param word_array Array containing the command.
 * @return Always return `true`.
 */
bool help(server_t *server, client_t **client, warray_t *word_array);

/**
 * @brief Log a user in the server.
 *
 * @param server Structure containing informations about the server.
 * @param client Pointer to structure containing informations about the client.
 * @param word_array Array containing the command.
 * @return Always return `true`.
 */
bool login(server_t *server, client_t **client, warray_t *word_array);

/**
 * @brief Disconnect a client of the server and logout the associated user.
 *
 * @param server Structure containing informations about the server.
 * @param client Pointer to structure containing informations about the client.
 * @param word_array Array containing the command.
 * @return Always return `false` if the client
 * is correctly disconnected and `true` otherwise.
 */
bool logout(server_t *server, client_t **client, warray_t *word_array);

/**
 * @brief List all users.
 *
 * @param server Structure containing informations about the server.
 * @param client Pointer to structure containing informations about the client.
 * @param word_array Array containing the command.
 * @return Always return `true`.
 */
bool users(server_t *server, client_t **client, warray_t *word_array);

/**
 * @brief Get informations about a user.
 *
 * @param server Structure containing informations about the server.
 * @param client Pointer to structure containing informations about the client.
 * @param word_array Array containing the command.
 * @return Always return `true`.
 */
bool user(server_t *server, client_t **client, warray_t *word_array);

/**
 * @brief Send a message from a user to another.
 *
 * @param server Structure containing informations about the server.
 * @param client Pointer to structure containing informations about the client.
 * @param word_array Array containing the command.
 * @return Always return `true`.
 */
bool send_msg(server_t *server, client_t **client, warray_t *word_array);

/**
 * @brief Get messages between two users.
 *
 * @param server Structure containing informations about the server.
 * @param client Pointer to structure containing informations about the client.
 * @param word_array Array containing the command.
 * @return Always return `true`.
 */
bool messages(server_t *server, client_t **client, warray_t *word_array);


#define HELP_HELP "/help: show help"
#define LOGIN_HELP "/login [\"user_name\"]: set the user_name used by client"
#define LOGOUT_HELP "/logout: disconnect the client from the server"
#define USERS_HELP "/users: get the list of all users that exist on the domain"
#define USER_HELP "/user [\"user_uuid\"]: get details about the requested user"
#define SEND_HELP_ONE "/send [\"user_uuid\"] [\"message_body\"]: "
#define SEND_HELP_TWO "send a message to specific user"
#define MESSAGES_HELP_ONE "/messages [\"user_uuid\"]: "
#define MESSAGES_HELP_TWO "list all messages exchanged with the specified user"


/* Array of commands_t containing all available commands. */
static const commands_t CMDS[] = {
    {"/help", &help, HELP_HELP, EMPTY_STR},
    {"/login", &login, LOGIN_HELP, EMPTY_STR},
    {"/logout", &logout, LOGOUT_HELP, EMPTY_STR},
    {"/users", &users, USERS_HELP, EMPTY_STR},
    {"/user", &user, USER_HELP, EMPTY_STR},
    {"/send", &send_msg, SEND_HELP_ONE, SEND_HELP_TWO},
    {"/messages", &messages, MESSAGES_HELP_ONE, MESSAGES_HELP_TWO}
};

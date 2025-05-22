/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myftp-hugues.lejeune [WSL: Ubuntu]
** File description:
** utils
*/

#pragma once

#include "commons.h"
#include "structures.h"


/* Syntax of myteams_server program. */
#define USAGE_MSG "USAGE: ./myteams_server port\n"
/* Length of USAGE_MSG. */
#define USAGE_MSG_LEN 29

/* Description of port program argument (first part). */
#define PORT_MSG_LO "\n\tport is the port number on "
/* Length of PORT_MSG_LO. */
#define PORT_MSG_LO_LEN 30
/* Description of port program argument (second part). */
#define PORT_MSG_LT "which the server socket listens.\n"
/* Length of PORT_MSG_LT. */
#define PORT_MSG_LT_LEN 33

/* Maximum number of arguments in a command. */
#define MAX_ARGS 6


/**
 * @brief Exit the program with a `84` error code
 * and optionally displaying an error message.
 *
 * @param msg The error message to display. Set it
 * to an empty string or `NULL` to avoid display.
 */
void error_exit(const char *msg);

/**
 * @brief Display an help message and exit the program with a `0` code.
 *
 */
void display_help(void);

/**
 * @brief Verify the provided argument and display help
 * if it is correct. Leave the program with `0` code in
 * case of success or with `84` code in case of error.
 *
 * @param arg A string containing the argument to verify.
 */
void get_help(const char *arg);

/**
 * @brief Split a string into substrings.
 *
 * @param word_array A structure to store the word array.
 * @param str A string to split.
 * @param separator A character between substrings to separate.
 * @return Array of substrings.
 */
warray_t *split_str(warray_t *word_array, const char *str, char separator);

/**
 * @brief Parse a command into an array of
 * substrings corresponding to command arguments.
 *
 * @param str String containing the command to parse.
 * @return warray_t structure containing command arguments.
 */
warray_t *parse_command(const char *str);

/**
 * @brief Free a warray_t structure.
 *
 * @param warray Structure to free.
 */
void free_warray(warray_t *warray);

/**
 * @brief Convert a user_t structure to a string.
 *
 * @param user User to stringify.
 * @return String containing user informations.
 */
char *stringify_user(user_t *user);

/**
 * @brief Convert a message_t structure to a string.
 *
 * @param user Message to stringify.
 * @return String containing message informations.
 */
char *stringify_message(message_t *message);

/**
 * @brief Create a new uuid.
 *
 * @return String containing the new uuid.
 */
char *create_uuid(void);

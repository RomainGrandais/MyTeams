/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-hugo.murat
** File description:
** utils
*/

#pragma once

#include "commons.h"

/* Syntax of myteams_cli program. */
#define USAGE_MSG "USAGE: ./myteams_cli ip port\n\n"
/* Length of USAGE_MSG. */
#define USAGE_MSG_LEN 30

/* Description of ip program argument (first part). */
#define IP_MSG_LO "\tip\tis the server ip address "
/* Length of IP_MSG_LO. */
#define IP_MSG_LO_LEN 29
/* Description of ip program argument (second part). */
#define IP_MSG_LT "on which the server socket listens\n"
/* Length of IP_MSG_LT. */
#define IP_MSG_LT_LEN 35

/* Description of port program argument (first part). */
#define PORT_MSG_LO "\tport\tis the port number "
/* Length of PORT_MSG_LO. */
#define PORT_MSG_LO_LEN 25
/* Description of port program argument (second part). */
#define PORT_MSG_LT "on which the server socket listens\n"
/* Length of PORT_MSG_LT. */
#define PORT_MSG_LT_LEN 35


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

/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myftp-hugues.lejeune [WSL: Ubuntu]
** File description:
** args
*/

#pragma once

#include "structures.h"

/**
 * @brief Verify is the provide argument is equal to `-help` or to `-h`.
 * Display a message in case of error.
 *
 * @param arg A string containing the argument to verify.
 * @return `true` if the argument is correct.
 * @return `false` if the argument is incorrect.
 */
bool verify_help_arg(const char *arg);

/**
 * @brief Get the port on which to open the socket and stored
 * it in a pointer on int. Display a message in case of error.
 *
 * @param port_str A `string` containing the port.
 * @param client A pointer to client structure
 * which will store the value of the port.
 * @return `true` if the port has successfully been get.
 * @return `false` in case of error.
 */
bool get_port(const char *port_str, client_t *client);

/**
 * @brief Get the ip on which to open the socket and stored
 * it in a client structure. Display a message in case of error.
 *
 * @param ip_str A `string` containing the ip.
 * @param client A pointer to client structure
 * which will store the value of the port.
 * @return `true` if the ip has successfully been get.
 * @return `false` in case of error.
 */
bool get_ip_address(const char *ip_str, client_t *client);

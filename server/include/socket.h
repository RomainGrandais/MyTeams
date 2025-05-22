/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myftp-hugues.lejeune [WSL: Ubuntu]
** File description:
** myftp
*/

#pragma once

#include "commons.h"

/**
 * @brief Close a socket and set its address
 * to reusable. Display a message on error.
 *
 * @param sfd File descriptor of the socket.
 * @return `true` if the socket is properly closed.
 * @return `false` if the socket is not closed properly.
 */
bool close_socket(int sfd);

/**
 * @brief Reset a socket to make it reusable.
 *
 * @param sfd Fiel descriptor of the socket.
 * @return `true` if the socket is properly reset.
 * @return `false` if an error occurred.
 */
bool reset_socket(int sfd);

/**
 * @brief Creates a socket, binds it, and returns its file descriptor.
 *
 * @param port Port to open the socket.
 * @return File descriptor of the created socket or -1 in case of error.
 */
int create_socket(int port);

/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myftp-hugues.lejeune [WSL: Ubuntu]
** File description:
** commons
*/

#pragma once

#include <arpa/inet.h>
#include <fcntl.h>
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>
#include <uuid/uuid.h>

/* UNUSED attribute for unused function parameters. */
#define UNUSED __attribute__ ((unused))

/* A string containing only a null terminator byte. */
#define EMPTY_STR ""

/* Ascii code of space character. */
#define SPACE 32

/* Ascii code of null byte terminator. */
#define NULL_BYTE 0

/* Ascii code of newline character. */
#define NEWLINE 10

#define UUID_SIZE 36

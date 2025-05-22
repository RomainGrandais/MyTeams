/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-hugo.murat [WSL: Ubuntu]
** File description:
** rfc
*/

#pragma once

/* Basic OK status. */
#define OK 200
/* Success and info or help send. */
#define INFO 214
/* Connection successfully established. */
#define CON_ESTABLISHED 220
/* Connection successfully closed. */
#define CON_CLOSE 230
/* User logged in. */
#define LOGIN 300
/* User logged out. */
#define LOGOUT 310
/* User created. */
#define USR_CREATED 320
/* Channel created. */
#define CHAN_CREATED 330
/* Thread created. */
#define THR_CREATED 340
/* Message has correctly been sent. */
#define MSG_SEND 350
/* Connection failed. */
#define CON_FAIL 400
/* Bad request. */
#define BAD_REQ 401
/* Bad syntax. */
#define BAD_SYNTAX 402
/* User already logged in. */
#define ALREADY_LOG 410
/* User not found. */
#define NO_USR 420
/* User already exist. */
#define USR_EXIST 430
/*Users List*/
#define USR_LIST 435
/* Channel already exist. */
#define CHAN_EXIST 440
/* Thread already exist. */
#define THR_EXIST 450
/* Message has not been sent. */
#define MSG_NOT_SEND 460
/* User is not loged in. */
#define NOT_CON 470
/* No message found for user. */
#define NO_MSG 480
/* Message exist. */
#define MSG_EXIST 490

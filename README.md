# Status Code Definitions for MyTeams Protocol

## Success Codes

- `200 OK`: The request has succeeded.
- `214 Help/Info`: Request for help or informational queries was successful.

## Connection Codes

- `220 Connection established`: A new connection has been successfully established.
- `230 Connection closed`: The connection has been successfully closed.

## User Codes

- `300 User Logged in`: The user has successfully logged in.
- `310 User Logged out`: The user has successfully logged out.
- `320 User Created`: A new user account has been successfully created.

## Channel and Thread Codes

- `330 Channel Created`: A new communication channel has been successfully created.
- `340 Thread Created`: A new thread within a channel has been successfully created.

## Messaging Codes

- `350 Message Send`: A message has been successfully sent.

## Client Error Codes

- `400 Bad request`: The request could not be understood by the server due to malformed syntax.
- `400 Connection failed`: The attempt to establish a connection failed.
- `410 User not found`: The specified user does not exist.
- `420 User Already Exist`: An attempt was made to create a user that already exists.
- `430 Channel Already Exist`: An attempt was made to create a channel that already exists.
- `440 Thread Already Exist`: An attempt was made to create a thread that already exists.
- `450 Message Cannot be send`: The message could not be sent due to an error in the messaging process.

## Usage

The above status codes are to be used in MyTeams Protocol. Each code corresponds to a specific state in the application's logic flow. Proper implementation ensures efficient communication of the application state to the client.

## Notes

- Codes within the same hundred range represent related statuses and must be handled within the same logical segment.
- Client must handle '400' error code with a priority as it signifies multiple types of errors.

---

MyTeams Protocol | Status Codes RFC - v1.0

#ifndef RESERVATION_H
#define RESERVATION_H

#define SLOT1       0
#define SLOT2       1
#define SLOT3       2
#define SLOT4       3
#define SLOT5       4
#define EMPTY_SLOT  0
#define NONE        0
#define NOT_FOUND  -1
#define FOUND       0

typedef struct reservation {
   u8 slot;
   u16 ID;
} Reservation;

#endif
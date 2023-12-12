#ifndef USER_H
#define USER_H

#define VIEW_PATIENT       1
#define VIEW_RESERVATIONS  2
#define USER_OUT           3

extern Patient *patientsHead;
extern Reservation *reservationsArray;

void userMode(void);
void viewPatient(Patient *patientsHead);
void viewReservations(Reservation *reservationsArray);

#endif
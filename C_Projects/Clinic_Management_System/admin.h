#ifndef ADMIN_H
#define ADMIN_H

#define PASSWORD            1234
#define SUCCESSFUL_LOGIN    1
#define FAILED_LOGIN       -1
#define ADD_PATIENT         1
#define EDIT_PATIENT        2
#define ADD_RESERVATION     3
#define CANCEL_RESERVATION  4
#define ADMIN_OUT           5

extern Patient *patientsHead;
extern Reservation *reservationsArray;

s8 adminMode(void);
s8 login(void);
void addPatient(Patient **patientsHead);
void editPatient(Patient **patientsHead);
void addReservation(Reservation *reservationsArray, Patient *patientsHead);
void cancelReservation(Reservation *reservationsArray);

#endif
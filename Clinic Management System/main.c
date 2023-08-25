#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "myTypes.h"
#include "patient.h"
#include "reservation.h"
#include "main.h"
#include "admin.h"
#include "user.h"

Patient *patientsHead = NULL;
Reservation *reservationsArray = NULL;

void main(void) {
    u16 slotNum;
    
    reservationsArray = (Reservation *)calloc(5, sizeof(Reservation));
    for(slotNum = SLOT1; slotNum <= SLOT5; ++slotNum) {
        reservationsArray[slotNum].slot = slotNum;
    }
    for(slotNum = SLOT1; slotNum <= SLOT5; ++slotNum) {
        reservationsArray[slotNum].ID = EMPTY_SLOT;
    }

    printf("Welcome!\n\n");
    modeChoice();
}

void modeChoice(void) {
    u16 modeChoice = 0;
    while(1) {
        printf("For \"Admin Mode\" enter '%d', For \"User Mode\" enter '%d': \n", ADMIN_MODE, USER_MODE);
        printf("Your choice: ");
        scanf(" %hu", &modeChoice);
        if(ADMIN_MODE == modeChoice){
            if(FAILED_LOGIN == adminMode())
                break;
        }
        else if(USER_MODE == modeChoice)
            userMode();
        else
            printf("Invalid mode choice!\n");
    }
}
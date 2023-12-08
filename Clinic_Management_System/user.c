#include <stdio.h>
#include "myTypes.h"
#include "patient.h"
#include "reservation.h"
#include "user.h"

void userMode(void) {
    u16 userOpChoice = 0;

    printf("You are now in the \"User Mode\".\n\n");
    while(USER_OUT != userOpChoice) {
        printf("To view a patient's information enter '%d', To view today's reservations enter '%d',\n"\
                "To get out of user mode enter '%d'\n", VIEW_PATIENT, VIEW_RESERVATIONS, USER_OUT);
        printf("Your choice: ");
        scanf(" %hu", &userOpChoice);
        switch(userOpChoice) {
            case VIEW_PATIENT:
                printf("\n");
                viewPatient(patientsHead);
                printf("\n");
                break;
            case VIEW_RESERVATIONS:
                printf("\n");
                viewReservations(reservationsArray);
                printf("\n");
                break;
            case USER_OUT:
                printf("\n");
                break;
            default:
                printf("\n");
                printf("Invalid operation choice.\n");
                printf("\n");
                break;
        }
    }
}

void viewPatient(Patient *patientsHead) {
    u16 inputPatientID;
    Patient *current = NULL;

    if(NULL == patientsHead) {
        printf("The patients list is empty.\n");
    }
    else {
        printf("Viewing a patient's information.\n");
        printf("Please enter the patient's ID: ");
        scanf(" %hu", &inputPatientID);
        current = patientsHead;
        while(current != NULL){
            if(current->ID == inputPatientID) {
                printf("Patient ID: %d\n", current->ID);
                printf("Name: %d\n", current->name);
                printf("Age: %d\n", current->age);
                printf("Gender: %d\n", current->gender);
                inputPatientID = NOT_FOUND;
                break;
            }
            current = current->next;
        }
        if(NOT_FOUND == inputPatientID)
            printf("There is no patient with the provided ID\n");
    }
}

void viewReservations(Reservation *reservationsArray) {
    u8 slotNum;
    u8 reservedSlots = NONE;

    printf("Today's Reservations\n\n");
    for(slotNum = SLOT1; slotNum <= SLOT5; ++slotNum) {
        if(EMPTY_SLOT != reservationsArray[slotNum].ID){
            printf("Slot %d\t", slotNum + 1);
            switch (slotNum) {
                case SLOT1:
                    printf("from 2:00 to 2:30\n");
                    break;
                case SLOT2:
                    printf("from 2:30 to 3:00\n");
                    break;
                case SLOT3:
                    printf("from 3:00 to 3:30\n");
                    break;
                case SLOT4:
                    printf("from 4:00 to 4:30\n");
                    break;
                case SLOT5:
                    printf("from 4:30 to 5:00\n");
                    break;
            }
            ++reservedSlots;
        }
    }
    if(NONE == reservedSlots)
        printf("There are no reservations for today.\n");
}
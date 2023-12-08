#include <stdio.h>
#include <stdlib.h>
#include "myTypes.h"
#include "patient.h"
#include "reservation.h"
#include "admin.h"

s8 adminMode(void) {
    u16 adminOpChoice = 0;

    if(SUCCESSFUL_LOGIN == login()) {
        printf("\n");
        printf("SUCCESSFUL LOGIN!\nYou are now in the \"Admin Mode\".\n\n");
        while(ADMIN_OUT != adminOpChoice) {
            printf("To add a patient enter '%d', To edit patient information enter '%d',\n"\
                   "To add a reservation enter '%d', To cancel a reservation enter '%d'\n"\
                   "To get out of admin mode enter '%d'\n",
                   ADD_PATIENT, EDIT_PATIENT, ADD_RESERVATION, CANCEL_RESERVATION, ADMIN_OUT);
            printf("Your choice: ");
            scanf(" %hu", &adminOpChoice);
            switch(adminOpChoice) {
                case ADD_PATIENT:
                    printf("\n");
                    addPatient(&patientsHead);
                    printf("\n");
                    break;
                case EDIT_PATIENT:
                    printf("\n");
                    editPatient(&patientsHead);
                    printf("\n");
                    break;
                case ADD_RESERVATION:
                    printf("\n");
                    addReservation(reservationsArray, patientsHead);
                    printf("\n");
                    break;
                case CANCEL_RESERVATION:
                    printf("\n");
                    cancelReservation(reservationsArray);
                    printf("\n");
                    break;
                case ADMIN_OUT:
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
    else {
        printf("Incorrect password entry for 3 times.\nNo more trials");
        return FAILED_LOGIN;
    }
    return 0;
}

s8 login(void) {
    u16 inputPass;
    u8 trials;
    for(trials = 3; trials > 0; --trials) {
        printf("Please enter the password for \"Admin Mode\" (Remaining trials: %hhu)\n", trials);
        printf("Password: ");
        scanf(" %hu", &inputPass);
        if(PASSWORD == inputPass) {
            return SUCCESSFUL_LOGIN;
        }
        else if(trials > 1) {
            printf("Incorrect password!\nPlease try again\n");
        }
        else {
            return FAILED_LOGIN;
        }
    }
}

void addPatient(Patient **patientsHead) {
    Patient *newPatient = (Patient *)malloc(sizeof(Patient));
    Patient *current = NULL;
    u16 inputID;
    
    printf("Adding a new patient record.\n");
    printf("Please enter the patient ID (numbers only , no more than 4 numbers and not '%d'):\n", USED);
    printf("Patient ID: ");
    scanf(" %hu", &inputID);
    current = *patientsHead;
    while(current != NULL){
        if(current->ID == inputID) {
            printf("This ID was used before!\n");
            inputID = USED;
            break;
        }
        current = current->next;
    }
    if(USED != inputID) {
        newPatient->ID = inputID;
        printf("Please enter the patient's name: ");
        scanf(" %s", newPatient->name);
        printf("Please enter the patient's age: ");
        scanf(" %hu", &newPatient->age);
        printf("Please enter the patient's gender(male, female): ");
        scanf(" %s", newPatient->gender);
        newPatient->next = NULL;
        if(NULL == *patientsHead)
            *patientsHead = newPatient;
        else {
            current = *patientsHead;
            while(current->next != NULL)
                current = current->next;
            current->next = newPatient;
        }
        printf("Success!\nPatient added successfully.\n");
    }
}

void editPatient(Patient **patientsHead) {
    u16 inputID;
    Patient *current = NULL;

    printf("Editting a patient's record.\n");
    printf("Enter patient ID: ");
    scanf(" %hu", &inputID);
    current = *patientsHead;
    while(current != NULL){
        if(current->ID == inputID) {
            printf("Patient ID found.\n");
            printf("Editing patient record.\n");
            printf("Please enter the patient's name: ");
            scanf(" %s", current->name);
            printf("Please enter the patient's age: ");
            scanf(" %hu", &current->age);
            printf("Please enter the patient's gender(male, female): ");
            scanf(" %s", current->gender);
            break;
        }
        current = current->next;
    }
    printf("ID not found.\n");
}

void addReservation(Reservation *reservationsArray, Patient *patientsHead) {
    Patient *current = NULL;
    u8 availableSlots = 0;
    u16 inputID;
    u16 slotNum;
    s8 found = NOT_FOUND;
    
    printf("Reserving a slot with the Doctor.\n");
    printf("Available slots:\n");
    for(slotNum = SLOT1; slotNum <= SLOT5; ++slotNum) {
        if(EMPTY_SLOT == reservationsArray[slotNum].ID){
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
            ++availableSlots;
        }
    }
    if(NONE == availableSlots)
        printf("There are no available slots.\n");
    else {
        printf("Adding a new reservation.\n");
        printf("Please enter the slot number you choose: ");
        scanf(" %hu", &slotNum);
        if((slotNum >= SLOT1) && (slotNum <= SLOT5)) {
            if(EMPTY_SLOT == reservationsArray[slotNum - 1].ID) {
                printf("Please enter the patient ID: ");
                scanf(" %hu", &inputID);
                current = patientsHead;
                while(current != NULL){
                    if(current->ID == inputID) {
                        reservationsArray[slotNum - 1].ID = inputID;
                        printf("SUCCESS!\nSlot reserved for patient %d.\n", current->ID);
                        found = FOUND;
                        break;
                    }
                    current = current->next;
                }
                if(found == NOT_FOUND) {
                    printf("There is no patient with this ID\n");
                }
            }
            else
                printf("This slot is reserved.\n");
        }
    }
}

void cancelReservation(Reservation *reservationsArray) {
    u16 slotNum;
    u8 reservedSlots;

    printf("Calnceling a reservation.\n");
    printf("Reserved Slots:\n");
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
        printf("There are no reserved slots.\n");
    else {
        printf("Enter slot number of the reservation to be canceled: ");
        scanf(" %hu", &slotNum);
        if((slotNum >= SLOT1) && (slotNum <= SLOT5)) {
            if(EMPTY_SLOT != reservationsArray[slotNum - 1].ID){
                reservationsArray[slotNum - 1].ID = EMPTY_SLOT;
                printf("SUCCESS!\nSlot reserved.\nSlot %d is now empty.\n", reservationsArray[slotNum - 1].slot);
            }
            else
                printf("This slot isn't reserved.\n");
        }
    }
}
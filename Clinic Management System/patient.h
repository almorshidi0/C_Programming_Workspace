#ifndef PATIENT_H
#define PATIENT_H

#define USED 0

typedef struct patient {
   u8 name[20];
   u16 age;
   u8 gender[7];
   u16 ID;
   struct patient *next;
} Patient;

#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_S 10


typedef struct Student {
    char name[50];
    int roll;
    char telephone[20];
    char address[50];
} Student;


typedef struct SReg {
    struct Student students[MAX_S];
    int count;
} SReg;


void initSReg(SReg* sr) {
    sr->count = 0;
}


int addStudent( SReg* sr,Student s) {

    if (sr->count == MAX_S) {
        return 0;
    }


    for (int i = 0; i < sr->count; i++) {
        if (sr->students[i].roll == s.roll) {
            return 0;
        }
    }


    sr->students[sr->count] = s;
    sr->count++;
    return 1;
}


struct Student getStudent(SReg sr, int r) {
    struct Student eStudent = { "NULL", 000000, "NULL", "NULL"};
    for (int i = 0; i < sr.count; i++) {
        if (sr.students[i].roll == r) {
            return sr.students[i];
        }
    }
    return eStudent;
}
                                                                           
 int delete(SReg* sr, int r) {
    for (int i = 0; i < sr->count; i++) {
        if (sr->students[i].roll == r) {

            for (int j = i; j < sr->count - 1; j++) {
                sr->students[j] = sr->students[j + 1];
            }
            sr->count--;
            return 1;
        }
    }
    return 0; // Student not found
}


int modify(SReg* sr,Student s) {
    for (int i = 0; i < sr->count; i++) {
        if (sr->students[i].roll == s.roll) {

            printf("Details found,Updating Values at Roll number %d .\n",s.roll);
            strcpy(sr->students[i].name, s.name);
            sr->students[i].roll = s.roll;
            strcpy(sr->students[i].telephone, s.telephone);
            strcpy(sr->students[i].address, s.address);
            return 1;
        }
    }
    return 0; // Student not found
}


void sortStudents(SReg* sr) {
    if (sr->count > 1) {
        int swapped;
        do {
            swapped = 0;
            for (int i = 0; i < sr->count - 1; i++) {
                if (strcmp(sr->students[i].name, sr->students[i + 1].name) > 0) {
                    struct Student temp = sr->students[i];
                    sr->students[i] = sr->students[i + 1];
                    sr->students[i + 1] = temp;
                    swapped = 1;
                }
            }
        } while (swapped);
    }
}


int getCount(SReg sr) {
    return sr.count;
}


void export(SReg sr, const char* fname) {
   FILE* file = fopen(fname, "w");
    if (file) {
        fwrite(&sr, sizeof(struct SReg), 1, file);
        fclose(file);
    }
}


void import(SReg* sr, const char* fname) {
    FILE* file = fopen(fname, "r");
    if (file) {
        fread(sr, sizeof(struct SReg), 1, file);
        fclose(file);
    }
}

int main() {
   
    struct SReg sRegister;

    initSReg(&sRegister);

    struct Student s1 = { "Tagore, Rabindranath", 999999, "1234567890","Kolkata"};

    struct Student s2 = { "Garai, Sanjoy", 999990, "9876543210", "Howrah"};

    addStudent(&sRegister, s1);

    addStudent(&sRegister, s2);

    struct Student mStudent = { "Sanjoy, Jane", 999999, "5555555555","Unknown_address"};

    int result = modify(&sRegister, mStudent);

    if (result) {
        printf("modified successfully.\n");
    } else {
        printf("Record not found.\n");
    }

    printf("Number of students in the register: %d\n", getCount(sRegister));



    struct Student rStudent = getStudent(sRegister, 999999);

    printf("Retrieved data is Name: %s, Roll: %d, Address : %s, Telephone : %s\n", rStudent.name, rStudent.roll,rStudent.address,rStudent.telephone);


    delete(&sRegister, 999999);

    printf("Number of students after deletion: %d\n", getCount(sRegister));

    sortStudents(&sRegister);

    export(sRegister, "students_file.txt");

    import(&sRegister,"students_file.txt");


    return 0;
}



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    char *name;
    int roll;
    char *telephone;
    char *address;
} Student;

typedef struct SReg {
    Student **students;
    int count;
} SReg;

void initSReg(SReg *sr) {
    sr->count = 0;
}

Student *createStudentRecord() {
    Student *s = (Student *)malloc(sizeof(Student));
    if (s == NULL) {
        return 0;
    }
    char temp[200];

    printf("Enter name: ");

    getchar(); 

    fgets(temp,150,stdin);

    s->name = (char *)malloc(strlen((temp)+1));

    if(s->name == NULL){
       
        free(s->name);

        s->name = NULL;
    }
    strcpy(s->name,temp);

    printf("Enter roll: ");

    scanf("%d", &s->roll);

    printf("Enter telephone: ");

    getchar(); 
    
    fgets(temp,150,stdin);

    s->telephone = (char *)malloc((strlen(temp)+1));

    if(s->telephone == NULL){
        
        free(s->telephone);

        s->telephone = NULL;
    }
    strcpy(s->telephone,temp);

    printf("Enter address: ");
   
    fgets(temp,150,stdin);

    s->address = (char *)malloc((strlen(temp)+1));

    if(s->address == NULL){
        
        free(s->address);

        s->address = NULL;
    }
    strcpy(s->address,temp);

    return s;
}

Student *createStudentRecordFromFile(FILE *file) {

    Student *s = (Student *)malloc(sizeof(Student));

    if (s == NULL) {  //  check
        return 0; 
    }

    s->name = (char *)malloc(100 * sizeof(char));

    s->telephone = (char *)malloc(50 * sizeof(char));

    s->address = (char *)malloc(100 * sizeof(char));

    if (s->name == NULL || s->telephone == NULL || s->address == NULL) { //  check
        free(s->name);
        free(s->telephone);
        free(s->address);
        free(s);
        s->name = NULL;
        s->telephone = NULL;
        s->address = NULL;
        s = NULL;
        return 0; 
    }

    fscanf(file, "%s",s->name);
    fscanf(file, "%d,%s", &s->roll, s->telephone);
    fscanf(file, "%s",s->address);

    return s;
}

void freeStudentRecord(Student *s) {
    free(s->name);
    s->name = NULL;
    free(s->telephone);
    s->telephone = NULL;
    free(s->address);
    s->address = NULL;
    free(s);
    s = NULL;
}

int addStudent(SReg *sr, Student *s,int maxStud) {
    if (sr->count >= maxStud) {
        return 0; // full
    }

    for (int i = 0; i < sr->count; i++) {
        if (sr->students[i]->roll == s->roll) {
            return 0; // already exists
        }
    }

    sr->students[sr->count] = s;
    sr->count++;
    return 1; 
}

Student getStudent(SReg *sr, int r) {
    Student emptyStudent = {NULL, 0, NULL, NULL};
    for (int i = 0; i < sr->count; i++) {
        if (sr->students[i]->roll == r) {
            return *(sr->students[i]);
        }
    }
    return emptyStudent;
}

int delete(SReg *sr, int r) {
    for (int i = 0; i < sr->count; i++) {
        if (sr->students[i]->roll == r) {
            freeStudentRecord(sr->students[i]);
            for (int j = i; j < sr->count - 1; j++) {
                sr->students[j] = sr->students[j + 1];
            }
            sr->count--;
            return 1; // deleted
        }
    }
    return 0; 
}

int modify(SReg *sr, Student *s) {
    for (int i = 0; i < sr->count; i++) {
        if (sr->students[i]->roll == s->roll) {
            freeStudentRecord(sr->students[i]);
            sr->students[i] = s;
            return 1; //  modified
        }
    }
    return 0; // not found
}

void sortStudents(SReg *sr) {
    for (int i = 0; i < sr->count - 1; i++) {
        for (int j = 0; j < sr->count - i - 1; j++) {
            if (strcmp(sr->students[j]->name, sr->students[j + 1]->name) > 0) {
                Student *temp = sr->students[j];
                sr->students[j] = sr->students[j + 1];
                sr->students[j + 1] = temp;
            }
        }
    }
}

int getCount(SReg *sr) {
    return sr->count;
}

void export(SReg *sr, const char *fname) {
    FILE *file = fopen(fname, "w");
    if (file == NULL) {
        printf("Error Opening file.\n");
        return;
    }

    for (int i = 0; i < sr->count; i++) {
        fprintf(file, "%s,%d,%s,%s\n", sr->students[i]->name, sr->students[i]->roll,
                sr->students[i]->telephone, sr->students[i]->address);
        fprintf(file,"%s","\n");
    }

    fclose(file);
}

void import(SReg *sr,const char *fname){
    FILE *file = fopen(fname,"r");
    if(file == NULL){
        printf("Error Opening File.\n");
        return;
    }
    int roll;
        printf("Enter Roll to Import Data.\n");

        scanf("%d",&roll);

    while(!feof(file)){
        
        Student *student = createStudentRecordFromFile(file);
        if(student != NULL){
            if(addStudent(sr,student,roll)){
                printf("Students Imported Successfully.\n");
            }
            else{
                printf("Failed to Import.\n");
                freeStudentRecord(student);
            }

        }
    }
    fclose(file);
}

int main() {

    SReg sr;

    initSReg(&sr);

    int maxStud = 0;
    
    printf("Enter Number of Entries : ");
    
    scanf("%d",&maxStud);
    
    sr.students = (Student **)malloc(maxStud * sizeof(Student *));

    int Q = - 999 ;

    printf("Enter The Number of Operation To Be Performed : ");

    scanf("%d",&Q);

    int mask = -999;

    while (Q) {
        printf("\n \n");
        printf("Enter 1 To Add Student Details.\n");
        printf("Enter 2 To Get Student Details.\n");
        printf("Enter 3 To Delete Student Details.\n");
        printf("Enter 4 To Modify Student Details.\n");
        printf("Enter 5 To Sort Student Details.\n");
        printf("Enter 6 To Export Student Details.\n");
        printf("Enter 7 To Import Student Details.\n");
        printf("Enter 8 To Get Student Count.\n");
        printf("Enter 9 To Free Memory And Exit Programme.\n");

        scanf("%d", &mask);

        if (mask == 1) {
            printf("\nEnter Student Details : \n");

            Student *student = createStudentRecord();

                if (addStudent(&sr, student, maxStud)) {

                    printf("Student added successfully.\n");

                } else {

                    printf("Failed to add student.\n");

                    freeStudentRecord(student);
                }
        } else if (mask == 2) {
            int r;

            printf("\nEnter roll number to get student details : ");

            scanf("%d", &r);

            Student student = getStudent(&sr, r);

            if (student.roll != 0) {

                printf("Name: %s\nRoll: %d\nTelephone: %s\nAddress: %s\n",

                       student.name, student.roll, student.telephone, student.address);
            } else {
                printf("Student not found.\n");
            }
        } else if (mask == 3) {
            int r;

            printf("\nEnter roll number to delete student: ");

            scanf("%d", &r);

            if (delete(&sr, r)) {

                printf("Student deleted successfully.\n");

            } else {
                printf("Student not found.\n");
            }
        } else if (mask == 4) {
            int roll;

            printf("Enter Student Roll to Modify : ");

            scanf("%d",&roll);
            
            for(int i=0;i<sr.count;i++){

            if((sr.students[i]->roll) == roll){

            printf("Student Details Found");  

             printf("\nModify Student Details : \n");
            
            Student *student = createStudentRecord();

                if (modify(&sr, student)) {
                    
                    printf("Student modified successfully.\n");
                } else {
                    
                    printf("Student not found.\n");
                    
                    freeStudentRecord(student);
                }
            }
            else{
                printf("No Student is Found With This Roll Number\n");
            }
            }
             
        } else if (mask == 5) {
            printf("\nSorting Students using Bubble Sort.\n");
            sortStudents(&sr);
           
        } else if (mask == 6) {
             export(&sr, "students_file.txt");

            printf("Student file is exported.\n");

        }
        
        else if (mask ==7) {
            import(&sr,"students_file.txt");
        }

        else if(mask == 8) {

           printf("The number of students are : %d\n",getCount(&sr));
        }
        
         else if (mask == 9) {

            printf("\nDeallocated Memory Successfully.\n");

            for (int i = 0; i < sr.count; i++) {

                freeStudentRecord(sr.students[i]);
            }
            free(sr.students);
            break;
        } else {
            printf("\nInvalid choice.\n");
        }
        Q--;
    }

    return 0;
}


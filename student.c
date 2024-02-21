#include "student.h"


struct student {
    char *name;
    int age;
    int id;
};

void *student_clone(void *elem){

    struct student *student;
    struct student *clone;

    student = (struct student*)elem;

    clone = (struct student*)malloc(sizeof(*clone));
     
    if (clone){
        clone.name = (char*)malloc(sizeof(char)*(strlen(student.name)+1));
        if(clone.name){
            strcpy(clone.name, student.name;
            clone->age = student->age;
            clone->id = student->id;
        }
    }
    return clone;
}

void student_destroy(void *elem){
    if (!elem){
        return;
    }

    struct student *tmp;
    tmp = (struct student*)elem;
    free(tmp->name); /* need to check if needed */
    free(tmp);
}

void student_print(void *elem){
    struct student *tmp;
    tmp = (struct student*)elem;
    printf("student name: %s, age: %d, id: %d.\n", tmp->name, tmp->age, tmp->id);
}




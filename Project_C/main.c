#include <stdio.h>
#include "datatype.h"
#include "function.h"

#define MAX 100

int main() {
    Student students[MAX];
    int studentCount = 0, choice, subChoice, count=0, order;
    loadStudents(students, &studentCount);
    Teacher teachers[MAX];
    int teacherCount = 0;
    loadTeachers(teachers, &teacherCount);
    do {
        mainMenu();
        scanf("%d", &choice);
        if (choice == 1) {
            do {
                studentMenu();
                scanf("%d", &subChoice);
                switch (subChoice) {
                    case 1: inputStudent(students, &studentCount); break;
                    case 2: displayStudents(students, studentCount); break;
                    case 3: searchStudent(students, studentCount); break;
                    case 4: editStudent(students, studentCount); break;
                    case 5: deleteStudent(students, &studentCount); break;
                    case 6:
						printf("1. A-Z\n");
						printf("2. Z-A\n");
						scanf("%d",&order);
						while(order<1 || order>2) {
							printf("1. A-Z\n");
							printf("2. Z-A\n");
							scanf("%d",&order);
					}
						
						sortStudents(students, studentCount, order);
							break;
                    case 7: resetStudents(students, &studentCount); break;
                    case 0: break;
                    default: printf("Invalid choice! Please try again.\n");
                }
            } while (subChoice != 0);
        } else if (choice == 2) {
            do {
                teacherMenu();
                scanf("%d", &subChoice);
                switch (subChoice) {
                    case 1: inputTeacher(teachers, &teacherCount); break;
                    case 2: displayTeachers(teachers, teacherCount); break;
                    case 3: searchTeacher(teachers, teacherCount); break;
                    case 4: editTeacher(teachers, teacherCount); break;
                    case 5: deleteTeacher(teachers, &teacherCount); break;
                    case 6: resetTeachers(teachers, &teacherCount); break;
                    case 0: break;
                    default: printf("Invalid choice! Please try again.\n");
                }
            } while (subChoice != 0);
        } else if (choice == 0) {
            printf("Exiting Program...\n");
        } else {
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 0); 
    return 0;
}


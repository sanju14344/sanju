#include <stdio.h>
#include <string.h>

// Define structure
struct Student {
    int id;
    char name[50];
    float marks;
};

// Global variables
struct Student students[100];  // Array of structures
int count = 0;  // Total number of students

// Function to create initial student records
void create() {
    int n;
    printf("Enter number of students to add: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        printf("\nEnter details for student %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &students[count].id);
        printf("Name: ");
        scanf(" %[^\n]", students[count].name);
        printf("Marks: ");
        scanf("%f", &students[count].marks);
        count++;
    }
}

// Function to insert a new student
void insert() {
    if (count >= 100) {
        printf("Student list is full!\n");
        return;
    }
    printf("\nEnter details for new student:\n");
    printf("ID: ");
    scanf("%d", &students[count].id);
    printf("Name: ");
    scanf(" %[^\n]", students[count].name);
    printf("Marks: ");
    scanf("%f", &students[count].marks);
    count++;
    printf("Student inserted successfully.\n");
}

// Function to delete a student by ID
void deleteStudent() {
    int id, found = 0;
    printf("Enter ID of student to delete: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            for (int j = i; j < count - 1; j++) {
                students[j] = students[j + 1];  // Shift left
            }
            count--;
            found = 1;
            printf("Student deleted successfully.\n");
            break;
        }
    }
    if (!found) {
        printf("Student with ID %d not found.\n", id);
    }
}

// Function to modify a student by ID
void modify() {
    int id, found = 0;
    printf("Enter ID of student to modify: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            printf("Enter new name: ");
            scanf(" %[^\n]", students[i].name);
            printf("Enter new marks: ");
            scanf("%f", &students[i].marks);
            found = 1;
            printf("Student modified successfully.\n");
            break;
        }
    }
    if (!found) {
        printf("Student with ID %d not found.\n", id);
    }
}

// Function to display all students
void display() {
    if (count == 0) {
        printf("No students to display.\n");
        return;
    }
    printf("\n--- Student Records ---\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d, Name: %s, Marks: %.2f\n", students[i].id, students[i].name, students[i].marks);
    }
}

int main() {
    int choice;

    do {
        printf("\n\n----- MENU -----\n");
        printf("1. Create Student Records\n");
        printf("2. Insert New Student\n");
        printf("3. Delete Student\n");
        printf("4. Modify Student\n");
        printf("5. Display All Students\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: create(); break;
            case 2: insert(); break;
            case 3: deleteStudent(); break;
            case 4: modify(); break;
            case 5: display(); break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while (choice != 6);

    return 0;
}

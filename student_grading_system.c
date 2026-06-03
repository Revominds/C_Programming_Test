#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 20
#define SUBJECTS 3

// =============================
// Structure Definition
// =============================
typedef struct
{
   char name[50];
   int scores[SUBJECTS];
   int total;
   float average;
   char grade;

} Student;

// =============================
// Function Prototypes
// =============================
char calculateGrade(float average);
void calculateResults(Student *s);
void displayReport(Student students[], int count);

// =============================
// Calculate Grade Function
// =============================
char calculateGrade(float average)
{
   if (average >= 80)
      return 'A';
   else if (average >= 70)
      return 'B';
   else if (average >= 60)
      return 'C';
   else if (average >= 50)
      return 'D';
   else if (average >= 40)
      return 'E';
   else
      return 'F';
}

// =============================
// Calculate Total, Average, Grade
// =============================
void calculateResults(Student *s)
{
   s->total = 0;

   for (int i = 0; i < SUBJECTS; i++)
   {
      s->total += s->scores[i];
   }

   s->average = s->total / 3.0;
   s->grade = calculateGrade(s->average);
}

// =============================
// Display Student Report
// =============================
void displayReport(Student students[], int count)
{
   system("cls");
   printf("\n");
   printf("====================================================================================\n");
   printf("%-20s %-10s %-10s %-10s %-10s %-10s %-10s\n",
          "Name", "Sub1", "Sub2", "Sub3", "Total", "Average", "Grade");
   printf("====================================================================================\n");

   for (int i = 0; i < count; i++)
   {
      printf("%-20s %-10d %-10d %-10d %-10d %-10.2f %-10c\n",
             students[i].name,
             students[i].scores[0],
             students[i].scores[1],
             students[i].scores[2],
             students[i].total,
             students[i].average,
             students[i].grade);
   }

   printf("====================================================================================\n");
}

// =============================
// Main Function
// =============================
int main()
{
   Student students[MAX_STUDENTS];

   int numStudents;

   system("cls");
   system("color 0b");

   printf("============================================\n");
   printf("      STUDENT GRADING SYSTEM\n");
   printf("============================================\n\n");

   do
   {
      printf("Enter number of students (1-%d): ", MAX_STUDENTS);
      scanf("%d", &numStudents);

      if (numStudents < 1 || numStudents > MAX_STUDENTS)
      {
         printf("[ERROR] Invalid number of students!\n\n");
      }

   } while (numStudents < 1 || numStudents > MAX_STUDENTS);

   getchar(); // clear newline

   // =============================
   // Input Student Data
   // =============================
   for (int i = 0; i < numStudents; i++)
   {
      system("cls");
      printf("\n=========================================\n");
      printf("    Student %d\n", i + 1);
      printf("===========================================\n\n");

      printf("Enter Student Name: ");
      fgets(students[i].name, sizeof(students[i].name), stdin);

      students[i].name[strcspn(students[i].name, "\n")] = '\0';

      for (int j = 0; j < SUBJECTS; j++)
      {
         do
         {
            printf("Enter Score for Subject %d (0-100): ", j + 1);
            scanf("%d", &students[i].scores[j]);

            if (students[i].scores[j] < 0 || students[i].scores[j] > 100)
            {
               printf("[ERROR] Score must be between 0 and 100.\n");
            }

         } while (students[i].scores[j] < 0 ||
                  students[i].scores[j] > 100);
      }

      getchar(); // clear newline

      calculateResults(&students[i]);
   }

   // =============================
   // Display Report
   // =============================
   displayReport(students, numStudents);

   // =============================
   // Class Average
   // =============================
   // float classAverage = 0;

   // for (int i = 0; i < numStudents; i++)
   // {
   //    classAverage += students[i].average;
   // }

   // classAverage /= numStudents;

   // =============================
   // Highest & Lowest Student
   // =============================

   int highestIndex = 0;
   int lowestIndex = 0;
   float classAverage = 0;

   for (int i = 1; i < numStudents; i++)
   {
      if (students[i].average > students[highestIndex].average)
      {
         highestIndex = i;
      }

      if (students[i].average < students[lowestIndex].average)
      {
         lowestIndex = i;
      }
   }

   // =============================
   // SUMMARY CALCULATIONS
   // =============================

   for (int i = 0; i < numStudents; i++)
   {
      classAverage += students[i].average;

      if (students[i].average > students[highestIndex].average)
      {
         highestIndex = i;
      }

      if (students[i].average < students[lowestIndex].average)
      {
         lowestIndex = i;
      }
   }

   classAverage /= numStudents;

   // =============================
   // SUMMARY REPORT
   // =============================
   printf("\n\n");
   printf("============================================\n");
   printf("           SUMMARY REPORT\n");
   printf("============================================\n\n");

   printf("%-5s %-20s %-10s %-10s\n",
          "No.", "Student Name", "Average", "Grade");

   printf("-------------------------------------------------\n");

   for (int i = 0; i < numStudents; i++)
   {
      printf("%-5d %-20s %-10.2f %-10c\n",
             i + 1,
             students[i].name,
             students[i].average,
             students[i].grade);
   }

   printf("-------------------------------------------------\n");
   printf("Class Average: %.2f\n", classAverage);
   printf("-------------------------------------------------\n\n");

   printf("Highest Scoring Student\n");
   printf("Name    : %s\n", students[highestIndex].name);
   printf("Average : %.2f\n\n", students[highestIndex].average);

   printf("Lowest Scoring Student\n");
   printf("Name    : %s\n", students[lowestIndex].name);
   printf("Average : %.2f\n", students[lowestIndex].average);

   printf("-------------------------------------------------\n");
   ;
   return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student
{
    int rollNo;
    char name[30];
    int *marks;
    float average;
    char grade;
};

//function defination to calculate avereage and finding the gread
void calculate_avg_grade(struct Student *student, int numSubjects)

{
    int totalMarks = 0;
    
    for (int i = 0; i < numSubjects; i++)  //running for loop i
    {
        totalMarks += student->marks[i];  //assigning total marks
    }
    
    student->average = (float)totalMarks / numSubjects;
    
    if (student->average >= 90)  //checking condition for grade
        student->grade = 'A';
        
    else if (student->average >= 80)
        student->grade = 'B';
        
    else if (student->average >= 70)
        student->grade = 'C';
        
    else if (student->average >= 60)
        student->grade = 'D';
        
    else
        student->grade = 'F';
            
}

int main()   //defination of main function
{
    int numStudents, numSubjects;

    printf("Enter no.of students : ");  
    scanf("%d", &numStudents);  //reading number of student's from the user 

    printf("Enter no.of subjects : ");
    scanf("%d", &numSubjects);  //reading number of subject's from the user

    char subjectNames[numSubjects][30];

    for (int i = 0; i < numSubjects; i++)  //running for loop,to get the subjects name
    {
        printf("Enter the name of subject %d : ", i + 1);
        scanf("%s", subjectNames[i]);  //reading name of the subject's
    }

    struct Student students[numStudents];

    for (int i = 0; i < numStudents; i++)  //running for loop,to get the student details
    {
        printf("----------Enter the student details-------------\n");
        printf("Enter the student Roll no. : ");
        scanf("%d", &students[i].rollNo);

        printf("Enter the student %d name : ", i + 1);
        scanf("%s", students[i].name);

        students[i].marks = (int *)malloc(numSubjects * sizeof(int));  //allocating memory
        
        for (int j = 0; j < numSubjects; j++)  //running for loop,to get the subject wise mark's
        {
            printf("Enter %s mark : ", subjectNames[j]);
            scanf("%d", &students[i].marks[j]);
        }

        calculate_avg_grade(&students[i], numSubjects); //calling function calculate_avg_grade
    }
    
    int choice, studentIndex;
    char continueDisplay;

    do 
    {
        printf("----Display Menu----\n");
        printf("1. All student details\n");
        printf("2. Particular student details\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);  //Read users choice
        
         switch (choice)
        {
            case 1:
            
                //Display details for all students
                
                printf("Roll No.\tName\t");
                for (int i = 0; i < numSubjects; i++)
                {
                    printf("%s\t", subjectNames[i]);
                }
                printf("Average\tGrade\n");

                for (int i = 0; i < numStudents; i++)
                {
                    printf("%d\t\t%s\t", students[i].rollNo, students[i].name);
                    for (int j = 0; j < numSubjects; j++)
                    {
                        printf("%d\t", students[i].marks[j]);
                    }
                    printf("%.2f\t%c\n", students[i].average, students[i].grade);
                }
                break;
                
            case 2:
            
                //Menu for displaying details of a particular student
                
                printf("----Menu for Particular student----\n");
                printf("1. Name.\n");
                printf("2. Roll no.\n");
                printf("Enter your choice : ");
                scanf("%d", &choice);   //Read users choice
                
                switch (choice) 
                {
                    case 1:
                        //Display details by name
                        
                        printf("Enter the name of the student : ");
                        char searchName[30];
                        scanf("%s", searchName);   //Read the name to search

                        for (int i = 0; i < numStudents; i++)  //Loop search for the student by name
                        {
                            if (strcmp(students[i].name, searchName) == 0)
                            {
                                studentIndex = i;
                                break;
                            }
                        }

                        //Display student details
                        
                        printf("Roll No.\tName\t");
                        for (int i = 0; i < numSubjects; i++)
                        {
                            printf("%s\t", subjectNames[i]);
                        }
                        printf("Average\tGrade\n");

                        printf("%d\t\t%s\t", students[studentIndex].rollNo, students[studentIndex].name);
                        for (int j = 0; j < numSubjects; j++) {
                            printf("%d\t", students[studentIndex].marks[j]);
                        }
                        printf("%.2f\t%c\n", students[studentIndex].average, students[studentIndex].grade);
                        break;
                        
                    case 2:
                    
                        //Display details by roll no.
                        
                        printf("Enter the roll no. of the student : ");
                        int searchRollNo;
                        scanf("%d", &searchRollNo);

                        for (int i = 0; i < numStudents; i++)
                        {
                            if (students[i].rollNo == searchRollNo)
                            {
                                studentIndex = i;
                                break;
                            }
                        }
                        
                        //Display student details
                        
                        printf("Roll No.\tName\t");
                        for (int i = 0; i < numSubjects; i++)
                        {
                            printf("%s\t", subjectNames[i]);
                        }
                        printf("Average\tGrade\n");

                        printf("%d\t\t%s\t", students[studentIndex].rollNo, students[studentIndex].name);
                        for (int j = 0; j < numSubjects; j++)
                        {
                            printf("%d\t", students[studentIndex].marks[j]);
                        }
                        printf("%.2f\t%c\n", students[studentIndex].average, students[studentIndex].grade);
                        break;
                        
                    default:
                        printf("Invalid choice\n");
                }
                break;
            default:
                printf("Invalid choice\n");
        }

        printf("Do you want to continue to display(Y/y) : ");
        scanf(" %c", &continueDisplay);
    }
    while (continueDisplay == 'Y' || continueDisplay == 'y');

    //Free memory allocated for subject marks
    for (int i = 0; i < numStudents; i++)
    {
        free(students[i].marks);
    }

    return 0;
}
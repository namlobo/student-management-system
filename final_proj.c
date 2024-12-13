#include<stdio.h>
#include<string.h>

#define MAX_STUDENTS 100
#define MAX_COURSES 100
#define MAX_ENROLLMENTS 100
#define MAX_TRANSACTIONS 100

struct student
{
    int st_id;
    char st_name[50];
    char st_add[100];
    int st_ph_no;
    char st_email[50];
    char st_dob[15];
    int st_count;
};

struct course
{
    int c_id;
    char c_name[50];
    char c_inst[50];
    char c_sched[50];
    int c_cred;
    int c_count;
};

struct enroll
{
    int en_count;
    int en_id;
    int en_st_id;
    int en_c_id;
    char en_date[11];
};

struct transaction
{
    int tran_count;
    int tran_id;
    int tran_st_id;
    int tran_amt;
    char tran_type[50];
    char tran_date[11];
    int tran_c_id;
};

int st_count=0;
int c_count=0;
int en_count=0;
int tran_count=0;

struct student students[MAX_STUDENTS];
struct course courses[MAX_COURSES];
struct enroll enrollments[MAX_ENROLLMENTS];
struct transaction transactions[MAX_TRANSACTIONS];
int ad_st(struct student s);
int up_st(int id, struct student s);
int del_st(int id);
void dis_st();

int ad_course(struct course c);
int up_course(int c_id, struct course c);
int del_course(int id);
void dis_course();

int en_st(struct enroll e);
int with_st(int enrollID);
void dis_en();

int ad_tran(struct transaction t);
void dis_tran();
int main()
{
    

    printf("Welcome to Student Management System\n");
    printf("---------------------------------------------------------------------------------------\n");
    printf("Enter the Module to be used\n");
    printf("---------------------------------------------------------------------------------------\n");
    printf("1. Student Details Module\n");
    printf("2. Course Details Module\n");
    printf("3. Enrollment Module\n");
    printf("4. Transaction Module\n");

    int mod;
    scanf("%d", &mod);

    switch (mod) {
        case 1: 
        {   struct student s;
            printf("Welcome to Student details module\n");
            int mod1;
            do
            {
                
                printf("***************************************************************************\n");
                printf("Enter the Function to be performed\n");
                printf("1. ADD STUDENT\n2. UPDATE STUDENT\n3. DELETE STUDENT\n4. DISPLAY STUDENT\n5. EXIT\n");
                
                scanf("%d", &mod1);
                switch (mod1) 
                {

                    case 1: 
                    {

                       
                        printf("Enter the Student ID: ");
                        scanf("%d", &s.st_id);
                        printf("Enter the Student Name: ");
                        scanf(" %[^\n]", s.st_name);
                        printf("Enter the Student Address: ");
                        scanf(" %[^\n]", s.st_add);
                        printf("Enter the Student Email ID: ");
                        scanf(" %[^\n]", s.st_email);
                        printf("Enter the Date of Birth: ");
                        scanf(" %[^\n]", s.st_dob);
                        printf("Enter the Phone Number: ");
                        scanf("%d", &s.st_ph_no);
                        ad_st(s);
                        break;
                    }
                    case 2: 
                    {    
                        
                        printf("Enter the Student ID to be Updated: ");
                        scanf("%d", &s.st_id);
                        printf("Enter the Updated Student Name: ");
                        scanf(" %[^\n]", s.st_name);
                        printf("Enter the Updated Student Address: ");
                        scanf(" %[^\n]", s.st_add);
                        printf("Enter the Updated Student Email ID: ");
                        scanf(" %[^\n]", s.st_email);
                        printf("Enter the Updated Date of Birth: ");
                        scanf(" %[^\n]", s.st_dob);
                        printf("Enter the Updated Phone Number: ");
                        scanf("%d", &s.st_ph_no);
                        up_st(s.st_id,s);

                        break;
                    }
                    case 3: 
                    {
                        int st_id;
                        printf("Enter the Student ID to be Deleted: ");
                        scanf("%d", &s.st_id);
                        del_st(s.st_id);
                        break;
                    }
                    case 4: 
                    {
                        dis_st();
                        break;
                    }
                    case 5: 
                    {
                        printf("Exiting");
                        break;
                    }
                    default:
                        printf("Invalid Input\n");
                 } 
            
            } while (mod1 != 5);
            break;
        }
        case 2: 
        {   
            struct course c;
            printf("Welcome to Course details module\n");
            int mod2;
            do
            {
                
                printf("***************************************************************************\n");
                printf("Enter the Function to be performed\n");
                printf("1. ADD COURSE\n2. UPDATE COURSE\n3. DELETE COURSE\n4. DISPLAY COURSE\n5. EXIT TO MAIN MENU\n");
                
                scanf("%d", &mod2);
                switch (mod2) 
                {
                    case 1: 
                    {
                       
                      
                        printf("Enter the Course ID: ");
                        scanf("%d", &c.c_id);
                        printf("Enter the Course Name: ");
                        scanf(" %[^\n]", c.c_name);
                        printf("Enter Instructor Name: ");
                        scanf(" %[^\n]", c.c_inst);
                        printf("Enter the Course Schedule: ");
                        scanf(" %[^\n]", c.c_sched);
                        printf("Enter the Course Credits: ");
                        scanf("%d", &c.c_cred);
                        ad_course(c);
                        break;
                    }
                    case 2: {
                        
                        
                        printf("Enter the Course ID to be Updated: ");
                        scanf("%d", &c.c_id);
                        printf("Enter the Updated Course Name: ");
                        scanf(" %[^\n]", c.c_name);
                        printf("Enter the Updated Instructor Name: ");
                        scanf(" %[^\n]", c.c_inst);
                        printf("Enter the Updated Course Schedule: ");
                        scanf(" %[^\n]", c.c_sched);
                        printf("Enter the Updated Course Credits: ");
                        scanf("%d", &c.c_cred);
                        up_course(c.c_id, c);
                        break;
                    }
                    case 3: 
                    {
                        
                       
                        printf("Enter the Course ID to be Deleted: ");
                        scanf("%d", &c.c_id);
                        del_course(c.c_id);
                        break;
                    }
                    case 4: 
                    {
                        
                        dis_course();
                        break;
                    }
                    case 5:
                    {
                        printf("Exiting");
                        break;
                    }
                    default:
                        printf("Invalid input\n");
                }
            } while(mod2!=5);
            break;
        }
        case 3: 
        {
            struct enroll e;
            printf("Welcome to Enrollment Module\n");
            int mod3;
            do
            {
                printf("***************************************************************************\n");
                printf("Enter the Function to be performed\n");
                printf("1. Enroll a student\n2. Withdraw a student\n3. Display enrollments\n4. Exit to Main Menu\n");
                
                scanf("%d", &mod3);
                switch (mod3) 
                {
                    
                    case 1: 
                    {
                        
                        
                        printf("Enter Student ID: ");
                        scanf("%d", &e.en_st_id);
                        printf("Enter Course ID: ");
                        scanf("%d", &e.en_c_id);
                        printf("Enter Enrollment ID: ");
                        scanf("%d", &e.en_id);
                        printf("Enter the Enrollment Date (YYYY-MM-DD): ");
                        scanf("%s", e.en_date);
                        en_st(e);
                        break;
                    }
                    case 2: 
                    {
                        int withID;
                        printf("Enter Enrollment ID to withdraw: ");
                        scanf("%d", &withID);
                        with_st(withID);
                        break;
                    }
                    case 3: 
                    {
                        
                        printf("Displaying enrollments:\n");
                        dis_en();
                        break;
                    }
                    case 4:
                    {
                        printf("Exiting");
                        break;
                    }
                    default:
                        printf("Invalid Input\n");
                }
            
            } while (mod3 !=4);
            break;
        }
        case 4: 
        {   struct transaction t;
            printf("Welcome to the Transaction Module\n");
            int mod4;
            do
            {
            
                printf("***************************************************************************\n");
                printf("Enter the Function to be performed\n");
                printf("1. ADD TRANSACTION\n2. DISPLAY TRANSACTION\n3. Exit to Main Menu\n");
                
                scanf("%d", &mod4);
                switch (mod4) 
                {
                   
                    case 1: 
                    {
                        
                        printf("Enter Transaction ID: ");
                        scanf("%d",&t.tran_id);
                        printf("Enter Student ID: ");
                        scanf("%d",&t.tran_st_id);
                        printf("Enter Course Id: ");
                        scanf("%d",&t.tran_c_id);
                        printf("Enter transaction type: ");
                        scanf("%s", t.tran_type);
                        printf("Enter the Transaction Amount: ");
                        scanf("%d",&t.tran_amt); 
                        ad_tran(t);
                        break;
                    }
                    case 2: 
                    {
                        printf("Displaying transactions:\n");
                        dis_tran();
                        break;
                    }
                    case 3:
                    {
                        printf("Exiting");
                        break;
                    }
                    default:
                        printf("Invalid input\n");
                }

            
            } while (mod4 != 3);
            break;
        }
        default:
            printf("Invalid Input\n");
            break;
    }

    return 0;
}

int ad_st(struct student s)
{
    if (st_count >= MAX_STUDENTS)
    {
        printf("Maximum number of students reached.\n");
        return 1;
    }
    students[st_count++] = s;
    return 0;
}

int up_st(int id, struct student s)
{
    for (int i = 0; i < st_count; i++)
    {
        if (students[i].st_id == id)
        {
            students[i] = s;
            printf("Student details updated successfully\n");
            return 0;
        }
    }
    printf("Student with ID %d not found.\n", id);
    return 1;
}

int del_st(int id)
{
    int found = 0;
    for (int i = 0; i < st_count; i++)
    {
        if (students[i].st_id == id)
        {
            found = 1;
            for (int j = i; j < st_count - 1; j++)
            {
                students[j] = students[j + 1];
            }
            st_count--;
            break;
        }
    }
    if (!found)
    {
        printf("Student with ID %d not found.\n", id);
        return 1;
    }
    return 0;
}

void dis_st()
{
    printf("Student ID\tName\tAddress\t\tPhone Number\tEmail\tDate of Birth\n");
    for (int i = 0; i < st_count; i++)
    {
        printf("%d\t\t%s\t%s\t\t%d\t%s\t\t%s\n", students[i].st_id, students[i].st_name, students[i].st_add, students[i].st_ph_no, students[i].st_email, students[i].st_dob);
    }
}

int ad_course(struct course c)
{
    if (c_count >= MAX_COURSES)
    {
        printf("Maximum number of courses reached.\n");
        return 1;
    }
    courses[c_count++] = c;
    return 0;
}

int up_course(int c_id, struct course c)
{
    for (int i = 0; i < c_count; i++)
    {
        if (courses[i].c_id == c_id)
        {
            courses[i] = c;
            printf("Course details updated successfully\n");
            return 0;
        }
    }
    printf("Course with ID %d not found.\n", c_id);
    return 1;
}

int del_course(int id)
{
    int found = 0;
    for (int i = 0; i < c_count; i++)
    {
        if (courses[i].c_id == id)
        {
            found = 1;
            for (int j = i; j < c_count - 1; j++)
            {
                courses[j] = courses[j + 1];
            }
            c_count--;
            break;
        }
    }
    if (!found)
    {
        printf("Course with ID %d not found.\n", id);
        return 1;
    }
    return 0;
}

void dis_course()
{
    printf("Course ID\tCourse Name\tInstructor\tSchedule\tCredits\n");
    for (int i = 0; i < c_count; i++)
    {
        printf("%d\t\t%s\t\t%s\t\t%s\t\t%d\n", courses[i].c_id, courses[i].c_name, courses[i].c_inst, courses[i].c_sched, courses[i].c_cred);
    }
}

int en_st(struct enroll e)
{
    if (en_count >= MAX_ENROLLMENTS)
    {
        printf("Maximum number of enrollments reached.\n");
        return 1;
    }
    enrollments[en_count++] = e;
    return 0;
}

int with_st(int enrollID)
{
    int found = 0;
    for (int i = 0; i < en_count; ++i)
    {
        if (enrollments[i].en_id == enrollID)
        {
            found = 1;

            for (int j = i; j < en_count - 1; ++j)
            {
                enrollments[j] = enrollments[j + 1];
            }
            en_count--;
            printf("Student withdrawn from enrollment ID %d\n", enrollID);
            break;
        }
    }
    if (!found)
    {
        printf("Enrollment ID not found.\n");
        return 1;
    }
    return 0;
}

void dis_en()
{
    printf("Enrollment ID\tStudent ID\tCourse ID\tEnrollment Date\n");
    for (int i = 0; i < en_count; ++i)
    {
        printf("%d\t\t%d\t\t%d\t\t%s\n", enrollments[i].en_id, enrollments[i].en_st_id, enrollments[i].en_c_id, enrollments[i].en_date);
    }
}

int ad_tran(struct transaction t)
{
    if (tran_count >= MAX_TRANSACTIONS)
    {
        printf("Maximum number of transactions reached.\n");
        return 1;
    }
    transactions[tran_count++] = t;
    return 0;
}

void dis_tran()
{
    printf("Transaction ID\tStudent ID\tType\t\tAmount\tDate\n");
    for (int i = 0; i < tran_count; ++i)
    {
        printf("%d\t\t%d\t\t%s\t\t%d\t%s\n", transactions[i].tran_id, transactions[i].tran_st_id, transactions[i].tran_type, transactions[i].tran_amt, transactions[i].tran_date);
    }
}

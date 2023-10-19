#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

void introduction()
{
    struct Person
    {
        char name[20];
        char surname[20];
        char schoolName[50];
        char department[20];
        int grade;
        char schoolNumber[20];
        char teacher[20];
    } person = {
        "Metin Erdem",
        "Pat",
        "Sivas Cumhuriyet University",
        "Computer Science",
        1,
        "************",
        "Serap Beğdaş"};

    printf("Homework: \n%s %s\n%s\n%s\n%d. grade\nNo: %s \nTeacher: %s\n \n", person.name, person.surname, person.schoolName, person.department, person.grade, person.schoolNumber, person.teacher);
}

int main()
{
    introduction();

    printf("Process Id: %d\n", (int)(getpid()));

    pid_t processId = fork();

    printf("Hello C Lang <3\n");

    if (processId < 0)
    {
        perror("Failed while forking");
    }

    if (processId == 0)
    {
        printf("Child Proccess Id %d\n", processId);
        FILE *fptr = fopen("./static/text.txt", "r");

        if (!fptr)
        {
            printf("Failed to open the file\n");
            exit(0);
        }
        else
        {
            char content;
            printf("The content of the file is: \n");
            while (content != EOF)
            {
                content = fgetc(fptr);
                printf("%c", content);
            }
        }
        printf("\nGonna end the child process\n");
        exit(0);
    }

    printf("That line is awaiting for the child process\n");

    return 0;
}

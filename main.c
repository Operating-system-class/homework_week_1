#include <stdio.h>
#include <stdlib.h>
#include <string.h>




void addTask(char *** todoList, int * size){
    char task[100];
    printf("Add a task\n");
    printf("%d:", *size);
    fflush(stdin);
    fgets(task, sizeof(task), stdin);
    printf("%s", &task[0]);

    if (todoList != NULL) {
        *todoList = (char **)realloc(*todoList, (*size) * sizeof(char*));
        strcpy((*todoList)[*size - 1], task);
        *size += 1 ;
    } else {
        printf("No todoList is created\n");
    }

}


void printTodoList(char** todoList){
    char * ptrCharSize = (char*)malloc(1);
    printf("Size of char:  %d\n", sizeof(todoList));
    int size = 1;
    if(todoList == NULL){
        printf("No todo list is created\n");
        return;
    }

    printf("Your todo list:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d. %s\n", i + 1, *(todoList + i));
    }

}

void printSelectedTask(char** todoList, int index){
    if(todoList == NULL){
        printf("No todo list is created\n");
        return;
    }

    printf("Your todo list:\n");
    for (int i = 0; i < index; i++)
    {
        printf("%d. %s\n", i + 1, *(todoList + i));
    }

}


char* createTodoList(){
    char** todoList = (char**)malloc(1);
    int sizeOfList = 1;

    if(todoList == NULL){
        printf("Memory allocation failed\n");

        return NULL;
    }

    int choice = 1;
    while (choice == 1) {
        addTask(&todoList, &sizeOfList);
        printf("Do you want to add another task? (1/0): ");
        scanf("%d", &choice);
    }


    printTodoList(todoList);
    return todoList;
}

int main()
{
    printf("Create your todo list\n");
    char* todoList = createTodoList();
    if(todoList == NULL){
        printf("Can't create todo list\n");
        return 1;
    }


    return 0;
}

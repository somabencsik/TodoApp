#ifndef TODO_H
#define TODO_H

#define TASK_LENGTH 255

#include <stdlib.h>

typedef struct _Todo
{
	char* Task;
	short Active;
} Todo;

Todo CreateTodo(char* Value)
{
	Todo NewTodo = { 0 };
	NewTodo.Task = (char*)malloc(TASK_LENGTH * sizeof(char*));
	NewTodo.Task = Value;
	NewTodo.Active = 1;
	return NewTodo;
}

#endif // !TODO_H

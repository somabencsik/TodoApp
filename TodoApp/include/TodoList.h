#ifndef TODOLIST_H
#define TODOLIST_H

#define MIN_SIZE 3

#include <string.h>

#include "Todo.h"

typedef struct _TodoList
{
	Todo* Todos;
	unsigned int Size;
	unsigned int RealSize;
	char* Name;
} TodoList;

TodoList CreateTodoList(char* name)
{
	TodoList NewTodoList = { 0 };
	NewTodoList.Todos = malloc(MIN_SIZE * sizeof(Todo));
	NewTodoList.Size = MIN_SIZE;
	NewTodoList.RealSize = 0;
	NewTodoList.Name = name;

	return NewTodoList;
}

void AddTodo(TodoList *tl, char* Task)
{
	if (tl->RealSize >= tl->Size)
	{
		tl->Size = tl->Size + MIN_SIZE;
		tl->Todos = realloc(tl->Todos, tl->Size * sizeof(Todo));
	}
	tl->Todos[tl->RealSize] = CreateTodo(Task);
	tl->RealSize = tl->RealSize + 1;
}

char* ListTodos(TodoList tl)
{
	char* everyTodo;
	everyTodo = malloc(tl.RealSize * strlen(tl.Todos[0].Task) + 1);

	strcpy(everyTodo, " - ");
	strcat(everyTodo, tl.Todos[0].Task);
	strcat(everyTodo, "\n");

	for (unsigned int i = 1; i < tl.RealSize; ++i)
	{
		strcat(everyTodo, " - ");
		strcat(everyTodo, tl.Todos[i].Task);
		strcat(everyTodo, "\n");
	}

	return everyTodo;
}

#endif // !TODOLIST_H

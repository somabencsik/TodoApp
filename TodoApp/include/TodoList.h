#ifndef TODOLIST_H
#define TODOLIST_H

#define MIN_SIZE 3

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

void ListTodos(TodoList tl)
{
	for (unsigned int i = 0; i < tl.RealSize; ++i)
	{
		printf("%d. task: %s\n", i + 1, tl.Todos[i].Task);
	}
}

#endif // !TODOLIST_H

#include <stdio.h>

#include <TodoList.h>

int main()
{
	TodoList tl = CreateTodoList("Monday");
	AddTodo(&tl, "Get up at 6am");
	AddTodo(&tl, "Get up at 7am");
	AddTodo(&tl, "Get up at 8am");
	AddTodo(&tl, "Get up at 9am");

	char* everyTodo = ListTodos(tl);

	printf("%s\n", everyTodo);

	return 0;
}
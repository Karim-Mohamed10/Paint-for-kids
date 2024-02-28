#include "LIFO.h"
LIFO::LIFO() : top(-1)
{}
void LIFO::push(Action* toPush)
{

	if (top < 5)
		items[++top] = toPush;

	else if (top == 5)
	{
		if (!items[0]->GetisRecorded())
			delete items[0];
		items[0] = NULL;
		for (int i = 1; i <= 5; i++)
			items[i - 1] = items[i];
		items[top] = toPush;
	}
}
bool LIFO::isEmpty()
{
	return top < 0;
}
void LIFO::pop()
{
	if (!isEmpty())
		top--;
}
void LIFO::pop(Action* toSave)
{
	if (!isEmpty())
	{
		toSave = items[top];
		top--;
	}
}
Action* LIFO::GetTopElement()
{
	if (!isEmpty())
	{
		return items[top];
	}
	return NULL;
}
int LIFO::GetTop()
{
	return top;
}
bool LIFO::isFull()
{
	return top == 5 ? true : false;
}
void LIFO::IncrementTop()
{
	top++;
}
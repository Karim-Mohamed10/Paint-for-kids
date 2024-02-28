#pragma once
#include "Actions/Action.h"
class LIFO
{
	enum { MaxSize = 200 };
private:
	int top;
	Action* items[MaxSize];
public:
	LIFO();
	void push(Action* topush);
	bool isEmpty();
	void pop();
	void pop(Action* toSave);
	int GetTop();
	void IncrementTop();
	bool isFull();
	Action* GetTopElement();
};


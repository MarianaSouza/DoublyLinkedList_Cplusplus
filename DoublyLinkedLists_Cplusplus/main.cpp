#include <stdio.h>
#include <math.h>
#include <iostream>
#include <iomanip>
#include <stdlib.h>

struct Node {
	int Data;
	Node * Next;
	Node * Previous;
};

Node * Start;

void AddToFront();
void AddToBack();
void DeleteFront();
void PrintListForward();
void PrintListBackward();
void DeleteBack();
void AddToMiddleAfter();
void AddToMiddleBefore();
void DeleteMiddleAfter();
void DeleteMiddleBefore();
void CleanList();

void main()
{
	Start = 0;
	int Choice;
	Choice = 0;

	printf("************** MAIN MENU ****************\n");
	printf("Please Enter one of the following Choices\n");
	printf("************** MAIN MENU ****************\n\n");

	do
	{
		printf("======================================================\n");
		printf("1.	Add a node to the front of the list.\n");
		printf("2.	Add a node to the back of the list.\n");
		printf("3.	Add a node to the middle of the list after a specific node.\n");
		printf("4.	Add a node to the middle of the list before a specific node.\n");
		printf("5.	Delete a node from the front of the list.\n");
		printf("6.	Delete a node from the back of the list.\n");
		printf("7.	Delete a node from the middle of the list after a specific node.\n");
		printf("8.	Delete a node from the middle of the list before a specific node.\n");
		printf("9.	Print a list Forward.\n");
		printf("10.	Print a list backward.\n");
		printf("11.	Clean list.\n");
		printf("======================================================\n");
		printf("12: Exit the program.\n");

		scanf_s("%d", &Choice);

		switch (Choice)
		{
		case 1:
			AddToFront();
			break;
		case 2:
			AddToBack();
			break;
		case 3:
			AddToMiddleAfter();
			break;
		case 4:
			AddToMiddleBefore();
			break;
		case 5:
			DeleteFront();
			break;
		case 6:
			DeleteBack();
			break;
		case 7:
			DeleteMiddleAfter();
			break;
		case 8:
			DeleteMiddleBefore();
			break;
		case 9:
			PrintListForward();
			break;
		case 10:
			PrintListBackward();
			break;
		case 11:
			CleanList();
			break;
		default:
			break;
		}

	} while (Choice != 12); //when the choice is == 12, the program returns
}

void AddToFront()
{
	Node * NewNode;
	NewNode = (Node *)malloc(sizeof(Node));
	printf("Enter node data to be added at the FRONT of the list: ");
	scanf("%d", &NewNode->Data);

	if (Start == 0)
	{
		NewNode->Previous = 0;
		NewNode->Next = 0;
		Start = NewNode;
	}
	else
	{
		Node *temp = Start; //if I already have something in my node, I create a temp variable for Start. it is a pointer to start.
		//We need this to loop till the end and then add a new element
		while (temp->Next != 0) //while Next from temp is different from 0, go next. 
		{
			temp = temp->Next; //temp receives the value of its Next
		}

		NewNode->Next = 0;
		temp->Next = NewNode; //We need to mark that NewNode goes ahead of Start, 
		NewNode->Previous = temp; //so, we determine temp receives Previous value here.
	}
	PrintListForward();
}

void AddToBack()
{
	Node * NewNode;
	NewNode = (Node *)malloc(sizeof(Node));
	printf("Enter node data to be added at the BACK of the list: ");
	scanf("%d", &NewNode->Data);

	if (Start == 0)
	{
		NewNode->Previous = 0;
		NewNode->Next = 0;
		Start = NewNode;
	}
	else
	{
		Node *temp = Start;
		//We need this to loop till the first and then add a new element
		while (temp->Previous != 0)
		{
			temp = temp->Previous;
		}

		NewNode->Next = temp;
		temp->Previous = NewNode;
		NewNode->Previous = 0;
	}
	PrintListForward();
}

void AddToMiddleAfter()
{
	Node * NewNode;
	NewNode = (Node *)malloc(sizeof(Node));
	printf("What is the new element Data: ");
	scanf("%d", &NewNode->Data);

	if (Start == 0)
	{
		printf("List is empty. This option does not apply.\n");
		return;
	}

	int value;
	printf("The new element will be AFTER the element: ");
	scanf("%d", &value);

	Node *beforeLast = Start;
	Node *last = Start;
	//We need this loop to find the first element of the list
	while (beforeLast->Previous != 0)
	{
		beforeLast = beforeLast->Previous;
	}
	//We need this to loop till find the position and then add a new element
	while (beforeLast->Next != 0) //this check if this is the last element
	{
		if (beforeLast->Data == value) //We found the existing element
		{
			break;
		}
		beforeLast = beforeLast->Next;
	}

	last = beforeLast->Next;

	beforeLast->Next = NewNode;
	NewNode->Previous = beforeLast;
	if (last != 0)
	{
		NewNode->Next = last;
		last->Previous = NewNode;
	}
	PrintListForward();
}

void AddToMiddleBefore()
{
	Node * NewNode;
	NewNode = (Node *)malloc(sizeof(Node));
	printf("What is the new element Data: ");
	scanf("%d", &NewNode->Data);

	if (Start == 0)
	{
		printf("List is empty. This option does not apply.\n");
		return;
	}

	int value;
	printf("The new element will be BEFORE the element: ");
	scanf("%d", &value);

	Node *beforeFirst = Start;
	Node *first = Start;

	//We need this loop to find the last element of the list
	while (beforeFirst->Next != 0)
	{
		beforeFirst = beforeFirst->Next;
	}
	//We need this to loop till find the position and then add a new element
	while (beforeFirst->Previous != 0)
	{
		if (beforeFirst->Data == value) //We found the existing element
		{
			break;
		}
		beforeFirst = beforeFirst->Previous;
	}

	first = beforeFirst->Previous;

	beforeFirst->Previous = NewNode;
	NewNode->Next = beforeFirst;
	if (first != 0)
	{
		NewNode->Previous = first;
		first->Next = NewNode;
	}
	PrintListForward();
}

void DeleteMiddleBefore()
{
	int DataToFind;
	Node * Current;
	Node * PreviousOfCurrent;
	Current = Start;
	int IsFound;
	IsFound = 0; // I think there is no match 
	PreviousOfCurrent = Current->Previous;
	if (Start == 0)
	{
		printf("List is empty. This option does not apply.\n");
		return;
	}
	printf("The element BEFORE this one will be deleted, what is the reference element: ");
	scanf("%d", &DataToFind);
	printf("\n");
	while (Current != 0)
	{
		if (Current->Data == DataToFind)
		{
			// It's a match, I found the node with desired data
			IsFound = 1; // It means it is Matched
			break;
		}

		Current = Current->Next;
		if (Current == 0)
		{
			break;
		}
		PreviousOfCurrent = Current->Previous;
	}
	if (IsFound == 0)
	{
		// Did not find that Node 
		printf("Did not Find the node, this option does not apply.\n");
		PrintListForward();
		return;
	}
	// I found the node and current pointing at it 
	if (PreviousOfCurrent->Previous == 0)
	{
		// First node found 
		printf("The node I found is the first node, this option does not apply.\n");
		PrintListForward();
		return;
	}
	if (PreviousOfCurrent->Previous == 0)
	{
		Current->Previous = 0;
		free(PreviousOfCurrent);
		PrintListForward();
		return;
	}
	Current->Previous = PreviousOfCurrent->Previous;
	PreviousOfCurrent->Previous->Next = Current;
	PrintListForward();
	return;

}

void DeleteMiddleAfter()
{
	int DataToFind;
	Node * Current;
	Node * NextOfCurrent;
	Current = Start;
	int IsFound;
	IsFound = 0; // I think there is no match 
	NextOfCurrent = Current->Next;
	if (Start == 0)
	{
		printf("List is empty. This option does not apply.\n");
		return;
	}
	printf("The element AFTER this one will be deleted, what is the reference element: ");
	scanf("%d", &DataToFind);
	printf("\n");
	while (Current != 0)
	{
		if (Current->Data == DataToFind)
		{
			// It's a match, I found the node with desired data
			IsFound = 1; // It means it is Matched
			break;
		}

		Current = Current->Next;
		if (Current == 0)
		{
			break;
		}
		NextOfCurrent = Current->Next;
	}
	if (IsFound == 0)
	{
		// Did not find that Node 
		printf("Did not Find the node, this option does not apply.\n");
		PrintListForward();
		return;
	}
	// I found the node and current pointing at it 
	if (Current->Next == 0)
	{
		// Last node found 
		printf("The node I found is the last node, this option does not apply.\n");
		PrintListForward();
		return;
	}
	if (NextOfCurrent->Next == 0)
	{
		Current->Next = 0;
		free(NextOfCurrent);
		PrintListForward();
		return;
	}
	Current->Next = NextOfCurrent->Next;
	NextOfCurrent->Previous = Current;
	free(NextOfCurrent);
	PrintListForward();
	return;

}

void DeleteBack()
{
	if (Start == 0)
	{
		printf("Nothing to delete, insert some elements first.\n\n");
	}
	else if (Start->Next == 0 && Start->Previous == 0){ //There is only one element and it should be removed.
		Start = 0; //this removes the only element
	}
	else
	{
		Node *temp = Start;
		//Go to the LAST element of the list
		while (temp->Next != 0)
		{
			temp = temp->Next;
		}

		//Loop till first element that has a Previous element
		while (temp->Previous != 0)
		{
			//Verify if the element after the current one is the first
			//We want the one before the first to remove its Previous
			if (temp->Previous->Previous == 0){
				break;
			}
			temp = temp->Previous;
		}
		Node *PreviousOfTemp = temp->Previous;
		Node * NewStart = temp;

		temp->Previous = 0;
		free(PreviousOfTemp);
		Start = NewStart;

		PrintListForward();
	}
}

void DeleteFront()
{
	if (Start == 0)
	{
		printf("Nothing to delete, insert some elements first.\n\n");
	}
	else if (Start->Next == 0 && Start->Previous == 0){ //There is only one element and it should be removed.
		Start = 0; //this removes the only element
	}
	else
	{
		Node *temp = Start;
		//Go to the LAST element of the list
		while (temp->Previous != 0)
		{
			temp = temp->Previous;
		}

		//Loop till first element that has a Next element
		while (temp->Next != 0)
		{
			//Verify if the element after the current one is the last
			//We want the one before the last to remove its next
			if (temp->Next->Next == 0){
				break;
			}
			temp = temp->Next;
		}
		Node *NextOfTemp = temp->Next;
		Node * NewStart = temp;

		temp->Next = 0;
		free(NextOfTemp);
		Start = NewStart;

		PrintListForward();
	}
}

void PrintListForward()
{
	if (Start == 0)
	{
		printf("Nothing to print, insert some elements first.\n\n");
		return;
	}
	Node *temp = Start;
	//Go to the first element
	while (temp->Previous != 0)
	{
		temp = temp->Previous;
	}

	//Print from first to last
	while (temp != 0)
	{
		printf("%d", temp->Data);
		printf("->");
		temp = temp->Next;
	}
	printf("NULL\n");
}

void PrintListBackward()
{

	if (Start == 0)
	{
		printf("Nothing to print, insert some elements first.\n\n");
		return;
	}
	Node *temp = Start;
	//Go till the last element
	while (temp->Next != 0)
	{
		temp = temp->Next;
	}

	//Print from last to first
	while (temp != 0)
	{
		printf("%d", temp->Data);
		printf("->");
		temp = temp->Previous;
	}
	printf("NULL\n");
}

void CleanList()
{
	Start = 0;
}

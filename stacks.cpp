//Operating and maintaining a stack
#include<iostream>

//Structure to define a stack
//Node contains a character and a pointer to the previous node
struct node
{
	char data;
	node* prevPtr;
};

node* push(node*, char);			//insert an item on top of the stack
node* pop(node*);					//delete an item from the top of the stack
int isEmpty(node*);					//check if the stack if empty
void printStack(node*);				//print the stack
void instructions();				//show the user menu

int main()
{
	node* headPtr = NULL;		//Points to top of the stack
	int choice;					//Stores the choice from the user
	char item;					//Stores the data the user enters

	instructions();				//Prints the instructions
	std::cin >> choice;			//Gets the user choice

	while (choice != 3)			//Loop as long as choice is not 3
	{
		//The switch statement allows us to easily work with the user choices
		switch (choice)
		{
			//The user wants to enter an item on top of the stack
		case 1:
			std::cout << "Enter a character: " << std::endl;
			std::cin >> item;
			headPtr = push(headPtr, item);
			printStack(headPtr);
			break;

			//The user wants to delete an item from the top of the stack
		case 2:
			//Check if the stack is not empty
			if (!isEmpty(headPtr))
			{
				headPtr = pop(headPtr);
				printStack(headPtr);
			}
			//The stack is empty, tell the user the stack is empty
			else
			{
				std::cout << "The stack is empty." << std::endl;
			}
			break;
			//User choice is invalid, display error and show menu again
		default:
			std::cout << "Invalid choice." << std::endl;
			instructions();
			break;
		}

		//Get choice from the user again
		instructions();
		std::cin >> choice;
	}

	std::cout << "Program terminated." << std::endl;
	return 0;
}

//Function: push
//Inputs: pointer to top of stack and item to insert
//Outputs: insert item to the top of the stack and return the new address of the top of the stack
//Errors: none
node* push(node* headPtr, char item)
{
	node* newPtr;				//newPtr - our new location
	newPtr = new node;			//allocate memory for the new location
	
	//check to see if newPtr is NULL, it will be NULL if we could not allocate memory to it
	if (newPtr != NULL)
	{
		newPtr->data = item;			//Set data to the value provided by the data provided by the user
		newPtr->prevPtr = headPtr;		//Set prevPtr of the newly created previous head of the stack		
		headPtr = newPtr;				//Set headPtr to newly created node
	}
	else
	{
		//Print error message is we cannot allocate memory
		std::cout << "Could not insert " << item << ". No memory available." << std::endl;
	}

	return headPtr;		//return location of headPtr after insertion
}

//Function: pop
//Inputs: pointer to top of stack
//Outputs: removes item from the top of the stack and return the new address of the top of the stack
//Errors: none
node* pop(node* headPtr)
{
	node* tempPtr;
	tempPtr = headPtr;				//Save the location of headPtr to a temporary location
	headPtr = headPtr->prevPtr;		//Set headPtr to the location of prevPtr
	free(tempPtr);					//Free the temporary location to clear up memory
	return headPtr;					//Return the new address of headPtr
}

//Function: instructions
//Inputs: none
//Ouputs: shows the user menu on the screen
//Errors: none
void instructions()
{
	std::cout << "Enter your choice: " << std::endl;
	std::cout << "1 to push an item into the top of the stack." << std::endl;
	std::cout << "2 to pop an item from the top of the stack." << std::endl;
	std::cout << "3 to end" << std::endl;
}

//Function: isEmpty
//Inputs: pointer to top of stack
//Outputs: returns 1 if the stack is empty, otherwise returns 0
//Errors: none
int isEmpty(node* sPtr)
{
	//Checks if sPtr is equal to NULL, if it is then it returns 1
	return sPtr == NULL;
}

//Function printStack
//Inputs: pointer to top of stack
//Outputs: prints the elements of the stack to the screen
//Errors: none
void printStack(node* currentPtr)
{
	//Check if currentPtr is NULL, if it is NULL then the stack is empty
	if (!currentPtr)
	{
		std::cout << "Stack is empty." << std::endl;
	}

	//Stack is not empty, begin printing it
	else
	{
		std::cout << "The stack is: " << std::endl;
		//Loop until we reach the end of the stack
		while (currentPtr)
		{
			printf("%c --> ", currentPtr->data);	//Print the content
			currentPtr = currentPtr->prevPtr;		//Update currentPtr to move to previous item
		}

		std::cout << "NULL" << std::endl;
	}
}
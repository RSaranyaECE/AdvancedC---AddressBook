#include <stdio.h>
#include <string.h>
#include "types.h"
#include "readinputs.h"
#include "funcs.h"


// Open file
int open_file(ReadInputs *readinputs, int option)
{
	// Open file for Insert or Delete
	if (option == 1 || option == 4)
	{
		readinputs->file_ptr = fopen(readinputs->file_name, "a+");

		if (NULL == readinputs->file_ptr)
		{
			printf("Error..File could not be opened\n");

			return 1;
		}
	}

	// Open file for Edit, Display and Search 
	else
	{
		readinputs->file_ptr = fopen(readinputs->file_name, "r+");

		if (NULL == readinputs->file_ptr)
		{
			printf("Error..File could not be opened\n");

			return 1;
		}
	}

	return 0;
}


// Read option
int read_option(char **argv)
{
	// insert
	if (strncmp(*argv, "-i", 2) == 0)

		return a_insert;

	// edit
	else if (strncmp(*argv, "-e", 2) == 0)

		return a_edit;

	// search
	else if (strncmp(*argv, "-s", 2) == 0)

		return a_search;

	// delete
	else if (strncmp(*argv, "-dl", 3) == 0)
	
		return a_delete;

	// display
	else if (strncmp(*argv, "-ds", 3) == 0)

		return a_display;
		
	// error
	else

		return a_error;
}



// Main Function
int main(int argc, char *argv[])
{
	int option;
	char decision;
	
	AddrsBook addrsbook;
	ReadInputs readinputs;

	do
	{	// read filename and option from stdin
		if (argc == 1)
		{
			printf("Enter the file name : ");
			scanf("%s", readinputs.file_name);

			printf("OPTIONS :\n\t1.Insert\n\t2.Edit\n\t3.Search\n\t4.Delete\n\t5.Display\n\n");

			printf("Enter the option : ");
			scanf("%d", &option);
		}

		// read file from command line 
		else
		{
			strcpy(readinputs.file_name, argv[2]);

			option = read_option(&argv[1]);
		}

		// open file
		if (open_file(&readinputs, option) != 0)
		{
			return 2;
		}

		// read inputs
		if (read_inputs(option, &addrsbook, &readinputs) != 0)
		{
			return 2;
		}

		// select operation
		switch (option)
		{
			// Insert
			case a_insert:

				if (insert_data_toaddrsbook(&addrsbook, &readinputs) != 0)
				{
					printf("Error..Insert failed\n");
				}

				else
				{
					printf("Successfully data inserted\n");
				}

				break;

			// Edit
			case a_edit:

				edit_data_inaddrsbook(&readinputs);
				
				break;

			// Search
			case a_search:

				search_data_inaddrsbook(&readinputs);
				
				break;

			// Delete
			case a_delete:

				delete_data_addrsbook(&readinputs);

				break;

			// Display
			case a_display:

				display_data_addrsbook(&readinputs);

				break;

			default:

				printf("Error..Your option is wrong\n");
		}

		// read decision
		printf("Do you want to continue... ");
		scanf("\n%c", &decision);

	// yes(y/ Y) restarts the program
	}while (decision == 'y' || decision == 'Y');

	return 0;
}

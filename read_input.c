#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readinputs.h"
#include "types.h"

// read spaces
int add_spaces(char *buff, int size)
{
	int index = 0;

	while (buff[index] != '\0')
		index++;

	for ( ; index < size; index++)
	{
		buff[index] = ' ';
	}

	buff[index] = '\0';
}



// Read inputs
int read_inputs(int option, AddrsBook *addrsbook, ReadInputs *readinputs)
{
	int index = 0;

	char buff[50];

	switch (option)
	{
		// Insert
		case a_insert:

			printf("Enter the Name : ");
			scanf("\n%[^\n]", buff);

			add_spaces(buff, 20);

			addrsbook->name = malloc(strlen(buff));

			strcpy(addrsbook->name, buff);

			printf("Enter the Phone number : ");
			scanf("\n%s", buff);

			if (strlen(buff) != 10)
			{
				printf("Error.. Invalid mobile number\n");

				return 1;
			}

			index = 0;

			while(buff[index] != '\0')
			{
				if (buff[index] > 47 && buff[index] < 58)

					index++;

				else
				{
					printf("Error..Invalid Mobile number\n");

					return 1;
				}
			}
			
			add_spaces(buff, 15);

			addrsbook->phone = malloc(strlen(buff));

			strcpy(addrsbook->phone, buff);

			printf("Enter the Email id : ");
			scanf("\n%s", buff);

			add_spaces(buff, 30);

			addrsbook->emailid = malloc(strlen(buff));

			strcpy(addrsbook->emailid, buff);

			printf("Enter the Address : ");
			scanf("\n%[^\n]", buff);

			add_spaces(buff, 35);

			addrsbook->addrs = malloc(strlen(buff));

			strcpy(addrsbook->addrs, buff);

			printf("Enter the City : ");
			scanf("\n%[^\n]", buff);

			add_spaces(buff, 15);

			addrsbook->city = malloc(strlen(buff));

			strcpy(addrsbook->city, buff);

			printf("Enter the Pin-code : ");
			scanf("\n%s", buff);

			if (strlen(buff) != 6)
			{
				printf("Error..Invalid pincode\n");

				return 1;
			}

			index = 0;

			while(buff[index] != '\0')
			{
				if (buff[index] > 47 && buff[index] < 58)

					index++;

				else
				{
					printf("Error..Invalid pincode\n");

					return 1;
				}
			}


			add_spaces(buff, 6);

			addrsbook->pincode = malloc(strlen(buff));

			strcpy(addrsbook->pincode, buff);

			break;

		// Edit
		case a_edit:

			printf("Enter the Name : ");
			scanf("\n%[^\n]", buff);

			add_spaces(buff, 20);
			
			readinputs->iname = malloc(strlen(buff));

			strcpy(readinputs->iname, buff);

		// Search
		case a_search:

			printf("OPTIONS: \n\t1.Name\n\t2.Phone\n\t3.Email-id\n\t4.Address\n\t5.City\n\t6.Pincode\n\n");

			printf("Enter the option");
			scanf("\n%d", &readinputs->n_option);

			switch (readinputs->n_option)
			{
				case 1:

					printf("Enter the Name : ");
					scanf("\n%[^\n]", buff);

					add_spaces(buff, 20);
			
					readinputs->new_content = malloc(strlen(buff));

					strcpy(readinputs->new_content, buff);

					break;

				case 2:

					printf("Enter the Phone number : ");
					scanf("\n%s", buff);

					if (strlen(buff) != 10)
					{
						printf("Error.. Invalid mobile number\n");

						return 1;
					}

					index = 0;

					while(buff[index] != '\0')
					{
						if (buff[index] > 47 && buff[index] < 58)

							index++;

						else
						{
							printf("Error..Invalid mobile number\n");

							return 1;
						}
					}

					add_spaces(buff, 15);
			
					readinputs->new_content = malloc(strlen(buff));

					strcpy(readinputs->new_content, buff);

					break;

				case 3:

					printf("Enter the Email id : ");
					scanf("\n%s", buff);

					add_spaces(buff, 30);
			
					readinputs->new_content = malloc(strlen(buff));

					strcpy(readinputs->new_content, buff);

					break;

				case 4:

					printf("Enter the Address : ");
					scanf("\n%[^\n]", buff);

					add_spaces(buff, 35);
			
					readinputs->new_content = malloc(strlen(buff));

					strcpy(readinputs->new_content, buff);

					break;

				case 5:

					printf("Enter the City : ");
					scanf("\n%[^\n]", buff);

					add_spaces(buff, 15);
			
					readinputs->new_content = malloc(strlen(buff));

					strcpy(readinputs->new_content, buff);

					break;

				case 6:

					printf("Enter the Pin-code : ");
					scanf("\n%s", buff);

					if (strlen(buff) != 6)
					{
						printf("Error.........\n");

						return 1;
					}

					index = 0;
					
					while(buff[index] != '\0')
					{
						if (buff[index] > 47 && buff[index] < 58)

							index++;

						else
						{
							printf("Error..Invalid pincode\n");

							return 1;
						}
					}

					add_spaces(buff, 6);
			
					readinputs->new_content = malloc(strlen(buff));

					strcpy(readinputs->new_content, buff);

					break;
			}

			break;

		// Delete
		case a_delete:

			printf("Enter the Name : ");
			scanf("\n%[^\n]", buff);

			add_spaces(buff, 20);
			
			readinputs->iname = malloc(strlen(buff));

			strcpy(readinputs->iname, buff);

		// Display
		case a_display:

			break;
	}

	return 0;
}

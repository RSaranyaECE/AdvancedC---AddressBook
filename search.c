#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readinputs.h"
#include "types.h" 

int count;

// Read data from file
int read_data_file_search(ReadInputs *readinputs, AddrsBook *addrsbook, int no_of_data)
{
	char snum[5], temp[5], buff[50];

	int index;

	// read upto EOF
	for (index = 0; feof(readinputs->file_ptr) == 0; index++)
	{
		count++;

		// read sno
		fread(snum, 1, 5, readinputs->file_ptr);
		sscanf(snum, "%d", &addrsbook[index].sno);
		fread(temp, 1, 2, readinputs->file_ptr);

		// read name
		fread(buff, 1, 20, readinputs->file_ptr);
		buff[19] = '\0';
		addrsbook[index].name = malloc(strlen(buff));
		strcpy(addrsbook[index].name, buff);
		fread(temp, 1, 2, readinputs->file_ptr);
		
		// read phone
		fread(buff, 1, 15, readinputs->file_ptr);
		buff[15] = '\0';
		addrsbook[index].phone = malloc(strlen(buff));
		strcpy(addrsbook[index].phone, buff);
		fread(temp, 1, 2, readinputs->file_ptr);
		
		// read email-id
		fread(buff, 1, 30, readinputs->file_ptr);
		buff[30] = '\0';
		addrsbook[index].emailid = malloc(strlen(buff));
		strcpy(addrsbook[index].emailid, buff);
		fread(temp, 1, 2, readinputs->file_ptr);
		
		// read address
		fread(buff, 1, 35, readinputs->file_ptr);
		buff[35] = '\0';
		addrsbook[index].addrs = malloc(strlen(buff));
		strcpy(addrsbook[index].addrs, buff);
		fread(temp, 1, 2, readinputs->file_ptr);
		
		// read city
		fread(buff, 1, 15, readinputs->file_ptr);
		buff[15] = '\0';
		addrsbook[index].city = malloc(strlen(buff));
		strcpy(addrsbook[index].city, buff);
		fread(temp, 1, 2, readinputs->file_ptr);
		
		// read pincode
		fread(buff, 1, 6, readinputs->file_ptr);
		buff[6] = '\0';
		addrsbook[index].pincode = malloc(strlen(buff));
		strcpy(addrsbook[index].pincode, buff);
		fread(temp, 1, 1, readinputs->file_ptr);
	}

	return 0;
}


// Search by name
int find_by_name(ReadInputs *readinputs, AddrsBook *addrsbook, int no_of_data)
{
	int index;

	for (index = 0; index < no_of_data; index++)
	{
		if(strncmp(readinputs->new_content, addrsbook[index].name, 19) == 0)
		{
			break;
		}	
	}

	readinputs->array_pos = index;	

	return 0;
}


// Search by phone
int find_by_phone(ReadInputs *readinputs, AddrsBook *addrsbook, int no_of_data)
{
	int index;

	for (index = 0; index < no_of_data; index++)
	{
		if(strncmp(readinputs->new_content, addrsbook[index].phone, 19) == 0)
		{
			break;
		}	
	}

	readinputs->array_pos = index;	

	return 0;
}

// Search by email-id
int find_by_emailid(ReadInputs *readinputs, AddrsBook *addrsbook, int no_of_data)
{
	int index;

	for (index = 0; index < no_of_data; index++)
	{
		if(strncmp(readinputs->new_content, addrsbook[index].emailid, 30) == 0)
		{
			break;
		}	
	}

	readinputs->array_pos = index;	

	return 0;
}

// Search by address
int find_by_addrs(ReadInputs *readinputs, AddrsBook *addrsbook, int no_of_data)
{
	int index;

	for (index = 0; index < no_of_data; index++)
	{
		if(strncmp(readinputs->new_content, addrsbook[index].addrs, 35) == 0)
		{
			break;
		}	
	}

	readinputs->array_pos = index;	

	return 0;
}


// Print data
int print_data(AddrsBook *addrsbook, int index)
{
	printf("----------------------------------------------------\n");
	
	printf("Contact %d\n", addrsbook[index].sno);

	printf("----------------------------------------------------\n");

	printf("Name : %s\n", addrsbook[index].name);

	printf("Phone : %s\n", addrsbook[index].phone);

	printf("Email id : %s\n", addrsbook[index].emailid);

	printf("Address : %s\n", addrsbook[index].addrs);

	printf("City : %s\n", addrsbook[index].city);

	printf("Pincode : %s\n", addrsbook[index].pincode);

	printf("----------------------------------------------------\n");
	
	return 0;
}


// Search by city
int find_by_city(ReadInputs *readinputs, AddrsBook *addrsbook, int no_of_data)
{
	int index;

	for (index = 0; index < no_of_data; index++)
	{
		if(strncmp(readinputs->new_content, addrsbook[index].city, 15) == 0)
		{
			print_data(addrsbook, index);
		}	
	}

	return 0;
}


// Search by pincode
int find_by_pincode(ReadInputs *readinputs, AddrsBook *addrsbook, int no_of_data)
{
	int index;

	for (index = 0; index < no_of_data; index++)
	{
		if(strncmp(readinputs->new_content, addrsbook[index].pincode, 6) == 0)
		{
			print_data(addrsbook, index);
		}	
	}

	return 0;
}


// Search data and print
int search_contacts(ReadInputs *readinputs, AddrsBook *addrsbook, int no_of_data)
{
	switch (readinputs->n_option)
	{
		// Name
		case 1:

			find_by_name(readinputs, addrsbook, no_of_data);

			print_data(addrsbook, readinputs->array_pos);

			break;

		// Phone number
		case 2:
			
			find_by_phone(readinputs, addrsbook, no_of_data);
			
			print_data(addrsbook, readinputs->array_pos);

			break;

		// Emailid
		case 3:

			find_by_emailid(readinputs, addrsbook, no_of_data);
			
			print_data(addrsbook, readinputs->array_pos);

			break;

		// Address
		case 4:

			find_by_addrs(readinputs, addrsbook, no_of_data);
			
			print_data(addrsbook, readinputs->array_pos);

			break;

		// City
		case 5:

			find_by_city(readinputs, addrsbook, no_of_data);
			
			break;

		// Pincode
		case 6:

			find_by_pincode(readinputs, addrsbook, no_of_data);
			
			break;	
	}

	return 0;
}


int search_data_inaddrsbook(ReadInputs *readinputs)
{
	int no_of_data = 20;

	AddrsBook addrsbook[no_of_data];

	// read all the data
	read_data_file_search(readinputs, addrsbook, no_of_data);

	// search contact and print
	search_contacts(readinputs, addrsbook, --count);

	fclose(readinputs->file_ptr);

	return 0;
}

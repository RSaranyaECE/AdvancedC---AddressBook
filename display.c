#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readinputs.h"
#include "types.h" 

int count;

// print contact details
int print_all_data(AddrsBook *addrsbook, int no_of_data)
{
	int index;

	for (index = 0; index < count - 1; index++)
	{
		printf("\n----------------------------------------------------\n");

		printf("Contact : %d\n", addrsbook[index].sno);

		printf("----------------------------------------------------\n");

		printf("Name : %s\n", addrsbook[index].name);

		printf("Phone : %s\n", addrsbook[index].phone);

		printf("Email id : %s\n", addrsbook[index].emailid);

		printf("Address : %s\n", addrsbook[index].addrs);

		printf("City : %s\n", addrsbook[index].city);

		printf("Pincode : %s\n", addrsbook[index].pincode);

		printf("----------------------------------------------------\n\n");
	}

	return 0;
}


// Read data from file
int read_data_file_display(ReadInputs *readinputs, AddrsBook *addrsbook, int no_of_data)
{
	char snum[5];

	char temp[5], buff[50];

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
		
		// read phone number
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


// Display data from addressbook
int display_data_addrsbook(ReadInputs *readinputs)
{
	int no_of_data = 20;

	AddrsBook addrsbook[no_of_data];

	// read all the data from file
	read_data_file_display(readinputs, addrsbook, no_of_data);

	// print all the data
	print_all_data(addrsbook, no_of_data);

	fclose(readinputs->file_ptr);

	return 0;
}

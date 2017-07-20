#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readinputs.h"
#include "types.h" 

int count;

// read data from file
int read_data_fromfile(ReadInputs *readinputs, AddrsBook addrsbook[], int no_of_data)
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

	fseek(readinputs->file_ptr, 0L, SEEK_SET);

	return 0;
}


// Find matching array position by using name
int find_array_pos(ReadInputs *readinputs, AddrsBook *addrsbook, int no_of_data)
{
	int index;

	for (index = 0; index < no_of_data; index++)
	{
		if(strncmp(readinputs->iname, addrsbook[index].name, 19) == 0)
		{
			break;
		}	
	}

	readinputs->array_pos = index;	

	return 0;
}


// Write new content to that position
int write_new_content(ReadInputs *readinputs, AddrsBook *addrsbook, int no_of_data)
{
	long fptr_pos;

	// find array position
	find_array_pos(readinputs, addrsbook, no_of_data);

	switch (readinputs->n_option)
	{
		// Edit name
		case 1:

			fptr_pos = (readinputs->array_pos * 138) + 7 + readinputs->array_pos;

			fseek(readinputs->file_ptr, fptr_pos, SEEK_SET);

			fwrite(readinputs->new_content, 1, 20, readinputs->file_ptr);

			break;

		// Edit phone number
		case 2:

			fptr_pos = (readinputs->array_pos * 138) + 29 + readinputs->array_pos;
			
			fseek(readinputs->file_ptr, fptr_pos, SEEK_SET);

			fwrite(readinputs->new_content, 1, 15, readinputs->file_ptr);
			
			break;

		// Edit email-id
		case 3:

			fptr_pos = (readinputs->array_pos * 138) + 46 + readinputs->array_pos;

			fseek(readinputs->file_ptr, fptr_pos, SEEK_SET);

			fwrite(readinputs->new_content, 1, 30, readinputs->file_ptr);

			break;

		// Edit address
		case 4:

			fptr_pos = (readinputs->array_pos * 138) + 78 + readinputs->array_pos;

			fseek(readinputs->file_ptr, fptr_pos, SEEK_SET);

			fwrite(readinputs->new_content, 1, 35, readinputs->file_ptr);

			break;

		// Edit city
		case 5:

			fptr_pos = (readinputs->array_pos * 138) + 115 + readinputs->array_pos;

			fseek(readinputs->file_ptr, fptr_pos, SEEK_SET);
			
			fwrite(readinputs->new_content, 1, 15, readinputs->file_ptr);

			break;

		// Edit pincode
		case 6:

			fptr_pos = (readinputs->array_pos * 138) + 132 + readinputs->array_pos;

			fseek(readinputs->file_ptr, fptr_pos, SEEK_SET);

			fwrite(readinputs->new_content, 1, 6, readinputs->file_ptr);
		
			char newline = '\n';

			fwrite(&newline, 1, 1, readinputs->file_ptr);

			break;	
	}

	return 0;
}


// Edit data in addrsbook
int edit_data_inaddrsbook(ReadInputs *readinputs)
{
	int no_of_data = 20;

	AddrsBook addrsbook[no_of_data];

	// read data from file
	read_data_fromfile(readinputs, addrsbook, no_of_data);

	// write new content
	write_new_content(readinputs, addrsbook, no_of_data);

	fclose(readinputs->file_ptr);

	return 0;
}

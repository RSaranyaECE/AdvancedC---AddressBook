#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readinputs.h"
#include "types.h" 

int count;

// Read all the data from file
int read_data_ffile(ReadInputs *readinputs, AddrsBook addrsbook[], int no_of_data)
{
	char snum[5], temp[5], buff[50];

	int index;

	// Read upto EOF
	for (index = 0; feof(readinputs->file_ptr) == 0; index++)
	{
		count++;

		// read sno
		fread(snum, 1, 5, readinputs->file_ptr);
		sscanf(snum, "%d", &addrsbook[index].sno);
		fread(temp, 1, 2, readinputs->file_ptr);

		// read name
		fread(buff, 1, 20, readinputs->file_ptr);
		buff[20] = '\0';
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

	// close the file
	fclose(readinputs->file_ptr);

	return 0;
}


// find array position by name
int find_array_ppos(ReadInputs *readinputs, AddrsBook *addrsbook, int no_of_data)
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


// delete content
int delete_content(ReadInputs *readinputs, AddrsBook addrsbook[], int no_of_data)
{
	long fptr_pos;

	char snum[5], delimeter = '/', newline = '\n';

	int index, iindex;

	// find array position
	find_array_ppos(readinputs, addrsbook, no_of_data);

	// open file in write mode
	readinputs->file_ptr = fopen(readinputs->file_name, "w");

	// Write all the data except that array position found by name
	for (index = 0; index < count - 1; index++)
	{
		if (index == readinputs->array_pos)

			continue;

		if (index < readinputs->array_pos)

			sprintf(snum, "%d", addrsbook[index].sno);

		else
			
			sprintf(snum, "%d", addrsbook[index - 1].sno);

		iindex = 0;

		while (snum[iindex] != '\0')

			iindex++;

		for ( ; iindex < 5; iindex++)

			snum[iindex] = ' ';

		snum[iindex] = '\0';

		fwrite(snum, 1, 5, readinputs->file_ptr);
		fwrite(&delimeter, 1, 1, readinputs->file_ptr);
		fwrite(&delimeter, 1, 1, readinputs->file_ptr);

		fwrite(addrsbook[index].name, 1, 20, readinputs->file_ptr);
		fwrite(&delimeter, 1, 1, readinputs->file_ptr);
		fwrite(&delimeter, 1, 1, readinputs->file_ptr);

		fwrite(addrsbook[index].phone, 1, 15, readinputs->file_ptr);
		fwrite(&delimeter, 1, 1, readinputs->file_ptr);
		fwrite(&delimeter, 1, 1, readinputs->file_ptr);

		fwrite(addrsbook[index].emailid, 1, 30, readinputs->file_ptr);
		fwrite(&delimeter, 1, 1, readinputs->file_ptr);
		fwrite(&delimeter, 1, 1, readinputs->file_ptr);

		fwrite(addrsbook[index].addrs, 1, 35, readinputs->file_ptr);
		fwrite(&delimeter, 1, 1, readinputs->file_ptr);
		fwrite(&delimeter, 1, 1, readinputs->file_ptr);

		fwrite(addrsbook[index].city, 1, 15, readinputs->file_ptr);
		fwrite(&delimeter, 1, 1, readinputs->file_ptr);
		fwrite(&delimeter, 1, 1, readinputs->file_ptr);

		fwrite(addrsbook[index].pincode, 1, 6, readinputs->file_ptr);
		fwrite(&newline, 1, 1, readinputs->file_ptr);
	}

	return 0;
}


int delete_data_addrsbook(ReadInputs *readinputs)
{
	int no_of_data = 20;

	AddrsBook addrsbook[no_of_data];

	// read all the data
	read_data_ffile(readinputs, addrsbook, no_of_data);

	// delete contact
	delete_content(readinputs, addrsbook, no_of_data);

	fclose(readinputs->file_ptr);

	return 0;
}

#include <stdio.h>
#include "types.h"
#include "readinputs.h"


// Calculate no.of lines 
int line_calculator(FILE *fptr)
{
	char ch;

	int count = 0;
	
	// calculate no. of newlines and return the count
	while(feof(fptr) == 0)
	{
		fread(&ch, 1, 1, fptr);

		if (ch == '\n')
		{
			count++;
		}
	}

	if (count != 0)

		return count;

	return 1;
}


// Insert data to addrsbook
int insert_data_toaddrsbook(AddrsBook *addrsbook, ReadInputs *readinputs)
{
	// line number
	int line_num = line_calculator(readinputs->file_ptr);

	char snum[5], delimeter = '/', newline = '\n';

	int index = 0;

	sprintf(snum, "%d", line_num);

	while (snum[index] != '\0')

		index++;

	for ( ; index < 5; index++)

		snum[index] = ' ';

	snum[index] = '\0';

	// write serial number
	fwrite(snum, 1, 5, readinputs->file_ptr);
	fwrite(&delimeter, 1, 1, readinputs->file_ptr);
	fwrite(&delimeter, 1, 1, readinputs->file_ptr);
	
	// write name
	fwrite(addrsbook->name, 1, 20, readinputs->file_ptr);
	fwrite(&delimeter, 1, 1, readinputs->file_ptr);
	fwrite(&delimeter, 1, 1, readinputs->file_ptr);
	
	// write phone number
	fwrite(addrsbook->phone, 1, 15, readinputs->file_ptr);
	fwrite(&delimeter, 1, 1, readinputs->file_ptr);
	fwrite(&delimeter, 1, 1, readinputs->file_ptr);
	
	// write email-id
	fwrite(addrsbook->emailid, 1, 30, readinputs->file_ptr);
	fwrite(&delimeter, 1, 1, readinputs->file_ptr);
	fwrite(&delimeter, 1, 1, readinputs->file_ptr);
	
	// write address
	fwrite(addrsbook->addrs, 1, 35, readinputs->file_ptr);
	fwrite(&delimeter, 1, 1, readinputs->file_ptr);
	fwrite(&delimeter, 1, 1, readinputs->file_ptr);
	
	// write city
	fwrite(addrsbook->city, 1, 15, readinputs->file_ptr);
	fwrite(&delimeter, 1, 1, readinputs->file_ptr);
	fwrite(&delimeter, 1, 1, readinputs->file_ptr);
	
	// write pincode
	fwrite(addrsbook->pincode, 1, 6, readinputs->file_ptr);
	fwrite(&newline, 1, 1, readinputs->file_ptr);

	// close the file
	fclose(readinputs->file_ptr);

	return 0;
}


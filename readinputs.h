#ifndef ADDRSBOOK_H
#define ADDRSBOOK_H

typedef struct _AddrsBook
{
	int sno;
	char *name;
	char *phone;
	char *emailid;
	char *addrs;
	char *city;
	char *pincode;

} AddrsBook;


typedef struct _ReadInputs
{
	char file_name[32];
	FILE *file_ptr;
	int n_option;
	char *iname;
	char *new_content;
	int array_pos;

} ReadInputs;


typedef struct _Positions
{
	long start_pos;
	long name_pos;
	long phone_pos;
	long emailid_pos;
	long addrs_pos;
	long city_pos;
	long pincode_pos;

} Positions;

int read_inputs(int option, AddrsBook *addrsbook, ReadInputs *readinputs);

#endif

#include <cstring>
#include <cstdio>
#include <cstdlib>
#include "student.h"

#define MAX_NAME_LEN 1234
#define SCAN_STUDENT_FORMAT "%1234s"// %MAX_NAME_LENs

int student::init(const char *new_name, int new_value)
{
	size_t len;
	size_t i;

	value = new_value;

	if( new_name==nullptr )
	{
		name = nullptr;
		return SUCCESS;
	}

	len = strlen(new_name);
	if( (name = new char[len + 1])==nullptr )
		return ALLOC_ERROR;
	for( i = 0; i<=len; i++ )
		name[i] = new_name[i];

	return SUCCESS;
}

void student::rm()
{
	if( name!=nullptr )
	{
		delete[] name;
		name = nullptr;
	}
	value = 0;
}

student &student::operator=(const student &x)
{
	if( this->name==x.name )
	{
		value = x.value;
		return *this;
	}

	rm();
	init(x.name, x.value);

	return *this;
}

student &student::operator=(student &&x)
{
	name = x.name;
	x.name = nullptr;
	value = x.value;
	return *this;
}

long long int student::cmp(const student &x) const
{
	int namecmp = strcmp(name, x.name);

	if( namecmp==0 )
		return static_cast<long long int>(value) - x.value;

	return namecmp;
}

int student::operator>(const student &x) const
{
	int namecmp = strcmp(name, x.name);

	if( namecmp==0 )
		return value>x.value;

	return namecmp>0;
}

void student::swap(student &x)
{
	int tmp_value;
	char *tmp_name;

	tmp_name = name;
	name = x.name;
	x.name = tmp_name;

	tmp_value = value;
	value = x.value;
	x.value = tmp_value;
}

int student::read(FILE *in)
{
	char new_name[MAX_NAME_LEN + 1];
	int new_value, res_scan;

	if( (res_scan = fscanf(in, SCAN_STUDENT_FORMAT/* %MAX_NUM_LENs */, new_name))!=1 )
	{
		if( res_scan==EOF )
			return EOF_ERROR;

		return READ_ERROR;
	}
	if( fscanf(in, "%d", &new_value)!=1 )
		return READ_ERROR;

	rm();
	return init(new_name, new_value);
}

void student::print() const
{
	if( name!=nullptr )
		printf("%s\t%d\n", name, value);
}

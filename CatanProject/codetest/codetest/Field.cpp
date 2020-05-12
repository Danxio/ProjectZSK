#include "FieldClass.h"
void Field::setnumber(unsigned int x)
{
	fnumber = x;
}
void Field::setzasob(unsigned int x)
{
	zasob = x;
}
unsigned int Field::getnumb()
{
	return fnumber;
}
unsigned int Field::getzasob()
{
	return zasob;
}
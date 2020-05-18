#include "FieldClass.h"
unsigned int Field::getnumb()
{
	return fnumber;
}
unsigned int Field::getzasob()
{
	return zasob;
}
void Field::zlodzust()
{
	zlodzej = true;
}
void Field::zlodzusu()
{
	zlodzej = false;
}
bool Field::checkzlod()
{
	return zlodzej;
}
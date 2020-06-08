#include "FieldClass.h"

void Field::setnumb(unsigned int fnumber_)
{
	fnumber = fnumber_;
}

void Field::setzasob(unsigned int zasob_) {
	zasob = zasob_;//1=Clay,2=Desert,3=Farm,4=Field,5=Forest,6=Mountain
}

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
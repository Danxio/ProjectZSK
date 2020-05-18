#pragma once
class Field
{
	unsigned int fnumber{ 0 };
	unsigned int zasob{ 0 };
	bool zlodzej = false;

public:
	unsigned int getnumb();
	unsigned int getzasob();
	void zlodzust();
	void zlodzusu();
	bool checkzlod();
};
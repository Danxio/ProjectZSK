#pragma once
#include "SFML/Graphics.hpp"
using namespace sf;
class Obiekty {
	Vector2f origin;
	float rotation{ 0 };
	Vector2f scale;
	Vector2f position{ 0,0 };
public:
	void setOrigin(Vector2f origin_);
	void setRotation(float rotation_);
	void setScale(Vector2f scale_);
	void setPosition(Vector2f position_);
	Vector2f getOrigin();
	float getRotation();
	Vector2f getScale();
	Vector2f getPosition();
};


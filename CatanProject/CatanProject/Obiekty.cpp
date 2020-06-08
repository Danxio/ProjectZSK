#include "Obiekty.h"
void Obiekty::setOrigin(Vector2f origin_){
	origin = origin_;
}
void Obiekty::setPosition(Vector2f  position_) {
	position = position_;
}
void Obiekty::setRotation(float rotation_) {
	rotation = rotation_;
}
void Obiekty::setScale(Vector2f scale_) {
	scale = scale_;
}
Vector2f Obiekty::getOrigin() {
	return origin;
}
Vector2f Obiekty::getPosition() {
	return position;
}
float Obiekty::getRotation() {
	return rotation;
}
Vector2f Obiekty::getScale() {
	return scale;
}
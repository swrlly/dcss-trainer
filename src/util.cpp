#include "util.h"

const char* const BoolToString(bool b){
	return b ? "true" : "false";
}

float round(float number, unsigned int numPlaces) {
	float temp = (int)(number * (numPlaces * 10) + .5);
	return (float)temp / (numPlaces * 10);
}

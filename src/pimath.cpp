#include "pimath.h"

float lerp(float v0, float v1, float t)
{
    return v0 + (v1 - v0) * t;
}
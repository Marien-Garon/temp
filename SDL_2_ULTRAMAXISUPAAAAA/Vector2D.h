#pragma once
#include <iostream>

struct Vector2D
{
	float x;
	float y;
	

	//Le const indique qu'on ne modifie pas la valeur interne du Vector

	Vector2D operator+(const Vector2D& other) const { return { x + other.x, y + other.y }; }

	Vector2D operator-(const Vector2D& other) const { return { x - other.x, y - other.y }; }
	
	Vector2D operator*(float nbr) const { return { x * nbr, y * nbr }; }
	
	Vector2D operator/(float nbr) const { return { x / nbr, y / nbr }; }


	Vector2D operator+=(const Vector2D& other) { x += other.x; y += other.y; return *this; };

	Vector2D operator-=(const Vector2D& other) { x -= other.x; y -= other.y; return *this; };

	Vector2D operator*=(float nbr) { x *= nbr; y *= nbr; return *this; };

	Vector2D operator/=(float nbr) { x /= nbr; y /= nbr; return *this; };



	//Renvoie la norme du Vecteur
	float Length() const { return std::sqrt(x * x + y * y); };


	//Vector2D Normalize() { return Length() > 0 ? *this / Length() : { 0.0f , 0.0f }; }; ????????????????????????? WHY IT DOESNT WORK ?????

	/*
	Renvoie un vecteur de meme direction mais de norme 1
	Lenny Information :
		En gros c'est pour avoir un deplacement fluide en diagonale :/
	
	*/
	Vector2D Normalize()  
	{ 
		if (Length() > 0)
			return *this / Length();
		return { 0.0f, 0.0f };
	};
	
};
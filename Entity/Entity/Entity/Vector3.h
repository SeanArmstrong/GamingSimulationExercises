#pragma once;

#include <iostream>
class Vector3{
public:
	Vector3(const float x = 0.0f, const float y = 0.0f, const float z = 0.0f);
	Vector3::Vector3(const Vector3& v);
	~Vector3();
	inline float getCoordinateX() const { return coord[0]; }
	inline float getCoordinateY() const { return coord[1]; }
	inline float getCoordinateZ() const { return coord[2]; }

	float getMagnitude() const;

	inline void setCoordinateX(const float new_x) { coord[0] = new_x; }
	inline void setCoordinateY(const float new_y) { coord[1] = new_y; }
	inline void setCoordinateZ(const float new_z) { coord[2] = new_z; }

	Vector3 unitVector();
	Vector3 orthogonalUnitVector(const Vector3& v);

	Vector3 operator+(const Vector3& v);
	Vector3 operator-(const Vector3& v);
	Vector3 operator*(const float scalar);
	Vector3 operator/(const float scalar);
	float		  operator*(const Vector3& v);
	Vector3 operator%(const Vector3& v);

	Vector3& operator+=(const Vector3& v);
	Vector3& operator-=(const Vector3& v);
	Vector3& operator/=(const float scalar);
	Vector3& operator%=(const Vector3& v);

	bool operator==(const Vector3& v) const;
	bool operator!=(const Vector3& v) const;

	Vector3& operator=(const Vector3& v);

private:
	/* Array of Coordinates x,y,z
	* coord[0] = x
	* coord[1] = y
	* coord[2] = z
	*/
	float coord[3];
};

// Prints Vector3 in the form {x,y,z}
std::ostream& operator<< (std::ostream& outStream, Vector3 vector);

Vector3 operator*(const float scalar, Vector3& v);
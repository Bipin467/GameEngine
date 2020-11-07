#pragma once
#include <Core/Vendor/glm/glm.hpp>
#include <Core/Vendor/glm/gtx/transform.hpp>
#include <iostream>
static float RADTODEG = 57.2958f;
static float DEGTORAD = 0.0174533f;
struct Vector3;
struct Vector2;
struct Vector4;
struct Mat4;
struct Vector2 {
public:
	float x, y;
public:
	Vector2();
	Vector2(float x, float y);
	Vector2(const Vector2& value);
	Vector2(const Vector3& value);
	Vector2(const Vector4& value);
	Vector2(const glm::vec2& value);
	Vector2(const glm::vec3& value);
	Vector2(const glm::vec4& value);
	operator glm::vec2();
	operator glm::vec3();
	operator glm::vec4();
	void operator +=(const Vector2&  value);
	void operator -=(const Vector2&  value);
	void operator *=(const Vector2&  value);
	void operator /=(const Vector2&  value);
	bool operator !=(const Vector2& value) const;
	bool operator ==(const Vector2& value) const;
	Vector2 operator +(const Vector2 & value) const;
	Vector2 operator -(const Vector2 & value) const;
	Vector2 operator *(const Vector2 & value) const;
	Vector2 operator /(const Vector2 & value) const;
	Vector2 Add(const Vector2& value) const;
	Vector2 Sub(const Vector2& value) const;
	Vector2 Div(const Vector2& value) const;
	void operator +=(float value);
	void operator -=(float value);
	void operator *=(float value);
	void operator /=(float value);
	Vector2 operator +(float value) const;
	Vector2 operator -(float value) const;
	Vector2 operator *(float value) const;
	Vector2 operator /(float value) const;
	Vector2 Add(float value) const;
	Vector2 Sub(float value) const;
	Vector2 Div(float value) const;
	Vector2 Mul(float value) const;
	float Dot(const Vector2& value) const;
	void Pow(float powerValue);
	Vector2 Normalize() const;
	float Magnitude() const;
	static Vector2 Zero() { return Vector2(.0f, .0f); };
	static Vector2 One() { return Vector2(1.0f, 1.0f); };
	friend std::ostream& operator<<(std::ostream& stream, const Vector2& vector);
};

struct Vector3 {
public:
	float x, y, z;
public:
	Vector3();
	Vector3(float x, float y, float z);
	Vector3(const Vector3& value);
	Vector3(const Vector2& value);
	Vector3(const Vector4& value);
	Vector3(const glm::vec2& value);
	Vector3(const glm::vec3& value);
	Vector3(const glm::vec4& value);
	operator glm::vec2();
	operator glm::vec3();
	operator glm::vec4();
	bool operator !=(const Vector3& value) const;
	bool operator ==(const Vector3& value) const;
	void operator +=(const Vector3&  value);
	void operator -=(const Vector3&  value);
	void operator *=(const Vector3&  value);
	void operator /=(const Vector3&  value);
	Vector3 operator +(const Vector3 & value) const;
	Vector3 operator -(const Vector3 & value) const;
	Vector3 operator *(const Vector3 & value) const;
	Vector3 operator /(const Vector3 & value) const;
	Vector3 Add(const Vector3& value) const;
	Vector3 Sub(const Vector3& value) const;
	Vector3 Div(const Vector3& value) const;
	void operator +=(float value);
	void operator -=(float value);
	void operator *=(float value);
	void operator /=(float value);
	Vector3 operator +(float value) const;
	Vector3 operator -(float value) const;
	Vector3 operator *(float value) const;
	Vector3 operator /(float value) const;
	Vector3 Add(float value) const;
	Vector3 Sub(float value) const;
	Vector3 Div(float value) const;
	Vector3 Mul(float value) const;
	float Dot(const Vector3& value) const;
	void Pow(float powerValue);
	Vector3 Cross(const Vector3& value) const;
	Vector3 Normalize() const;
	float Magnitude() const;
	static Vector3 Zero() { return Vector3(.0f, .0f, .0f); };
	static Vector3 One() { return Vector3(1.0f, 1.0f, 1.0f); };
	friend std::ostream& operator <<(std::ostream & stream, const Vector3& vector);
};

struct Vector4 {
public:
	float x, y, z, w;
public:
	Vector4();
	Vector4(float x, float y, float z, float w);
	Vector4(const Vector4& value);
	Vector4(const Vector3& value);
	Vector4(const Vector2& value);
	Vector4(const glm::vec2& value);
	Vector4(const glm::vec3& value);
	Vector4(const glm::vec4& value);
	operator glm::vec2();
	operator glm::vec3();
	operator glm::vec4();
	bool operator !=(const Vector4& value) const;
	bool operator ==(const Vector4& value) const;
	void operator +=(const Vector4&  value);
	void operator -=(const Vector4&  value);
	void operator *=(const Vector4&  value);
	void operator /=(const Vector4&  value);
	Vector4 operator +(const Vector4 & value) const;
	Vector4 operator -(const Vector4 & value) const;
	Vector4 operator *(const Vector4 & value) const;
	Vector4 operator /(const Vector4 & value) const;
	Vector4 Add(const Vector4& value) const;
	Vector4 Sub(const Vector4& value) const;
	Vector4 Div(const Vector4& value) const;
	void operator +=(float value);
	void operator -=(float value);
	void operator *=(float value);
	void operator /=(float value);
	Vector4 operator +(float value) const;
	Vector4 operator -(float value) const;
	Vector4 operator *(float value) const;
	Vector4 operator /(float value) const;
	Vector4 Add(float value) const;
	Vector4 Sub(float value) const;
	Vector4 Div(float value) const;
	Vector4 Mul(float value) const;
	float Dot(const Vector4& value) const;
	void Pow(float value);
	Vector4 Normalize() const;
	float Magnitude() const;
	static Vector4 Zero() { return Vector4(.0f, .0f, .0f, .0f); };
	static Vector4 One() { return Vector4(1.0f, 1.0f, 1.0f, 1.0f); };
	friend std::ostream& operator <<(std::ostream& stream, const Vector4& vector);

};

struct Mat4 {
public:
	float elements[4*4];
public:
	Mat4();
	Mat4(float diagonal);
	Mat4(glm::mat4 value);
	operator glm::mat4();
	Mat4& Mul(const Mat4& other);
	Mat4& Mul(const glm::mat4 & other);
	friend Mat4 operator * (Mat4 left,const Mat4& other);
	Mat4& operator *= (const Mat4& other);
	glm::mat4 & ToGlmMat();
	static Mat4 Identity();
	static Mat4 Orthographic(float left, float right, float bottom, float top, float near, float far);
	static Mat4 Perspective(float fov, float aspetRatio, float near, float far);
	static Mat4 Translation(const Vector3& translation);
	static Mat4 Rotation( const Vector3& axis);
	static Mat4 Scale(const Vector3& scale);
	static Mat4 SingleRotation(float angle, const Vector3& axis);
private:
};
#include "Public/Maths.h"
#include <math.h>
Vector2::Vector2()
{
}

Vector2::Vector2(float x, float y)
{
	this->x = x;
	this->y = y;
}

Vector2::Vector2(const Vector2 & value)
	: x(value.x), y(value.y)
{
}

Vector2::Vector2(const Vector3 & value)
	: x(value.x), y(value.y)
{
}

Vector2::Vector2(const Vector4 & value)
	: x(value.x), y(value.y)
{
}

Vector2::Vector2(const glm::vec2 & value)
	: x(value.x), y(value.y)
{
}

Vector2::Vector2(const glm::vec3 & value)
	:x(value.x),y(value.y)
{
}

Vector2::Vector2(const glm::vec4 & value)
	:x(value.x),y(value.y)
{
}

Vector2::operator glm::vec2()
{
	return glm::vec2(x, y);
}

Vector2::operator glm::vec3()
{
	return glm::vec3(x, y, 0);
}

Vector2::operator glm::vec4()
{
	return glm::vec4(x, y, 0, 0);
}



void Vector2::operator+=(const Vector2& value)
{
	*this = Add(value);
}

void Vector2::operator-=(const Vector2& value)
{
	*this = Sub(value);
}

void Vector2::operator*=(const Vector2& value)
{
	*this = (*this) * value;
}

void Vector2::operator/=(const Vector2& value)
{
	*this = Div(value);
}

bool Vector2::operator!=(const Vector2 & value) const
{
	return x != value.x && y != value.y;
}

bool Vector2::operator==(const Vector2 & value) const
{
	return x == value.x && y == value.y;
}

Vector2 Vector2::operator+(const Vector2& value) const
{
	return Add(value);
}

Vector2 Vector2::operator-(const Vector2& value) const
{
	return Sub(value);
}

Vector2 Vector2::operator*(const Vector2& value) const
{
	return Vector2(value.x*x, value.y*y);
}

Vector2 Vector2::operator/(const Vector2& value) const
{
	return Div(value);
}

Vector2 Vector2::Add(const Vector2& value) const
{
	return Vector2(x + value.x, y + value.y);
}

Vector2 Vector2::Sub(const Vector2& value) const
{
	return Vector2(x - value.x, y - value.y);
}

Vector2 Vector2::Div(const Vector2& value) const
{
	return Vector2(x / value.x, y / value.y);
}

void Vector2::operator+=(float value)
{
	*this = Add(value);
}

void Vector2::operator-=(float value)
{
	*this = Sub(value);
}

void Vector2::operator*=(float value)
{
	*this = Mul(value);
}

void Vector2::operator/=(float value)
{
	*this = Div(value);
}

Vector2 Vector2::operator+(float value) const
{
	return Add(value);
}

Vector2 Vector2::operator-(float value) const
{
	return Sub(value);
}

Vector2 Vector2::operator*(float value) const
{
	return Mul(value);
}

Vector2 Vector2::operator/(float value) const
{
	return Div(value);
}

Vector2 Vector2::Add(float value) const
{
	return Vector2(x + value, y + value);
}

Vector2 Vector2::Sub(float value) const
{
	return Vector2(x - value, y - value);
}

Vector2 Vector2::Div(float value) const
{
	return Vector2(x / value, y / value);
}

Vector2 Vector2::Mul(float value) const
{
	return Vector2(x*value, y*value);
}

float Vector2::Dot(const Vector2& value) const
{
	return x * value.x + y * value.y;
}

void Vector2::Pow(float powerValue)
{
	x = pow(x, powerValue);
	y = pow(y, powerValue);
}


Vector2 Vector2::Normalize() const
{
	float mag = Magnitude();
	return Vector2(x / mag, y / mag);
}

float Vector2::Magnitude() const
{
	Vector2 val = *this;
	val.Pow(2);
	float res = val.x + val.y;
	return pow(res, 0.5);
}


Vector3::Vector3()
{
}

Vector3::Vector3(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3::Vector3(const Vector3 & value)
	:x(value.x), y(value.y), z(value.z)
{

}

Vector3::Vector3(const Vector2 & value)
	: x(value.x), y(value.y), z(0)
{
}

Vector3::Vector3(const Vector4 & value)
	: x(value.x), y(value.y), z(value.z)
{
}

Vector3::Vector3(const glm::vec2 & value)
	:x(value.x),y(value.y),z(0)
{
}

Vector3::Vector3(const glm::vec3 & value)
	:x(value.x), y(value.y), z(value.z)
{
}

Vector3::Vector3(const glm::vec4 & value)
	:x(value.x),y(value.y),z(value.z)
{
}



bool Vector3::operator!=(const Vector3 & value) const
{
	return value.x != x && value.y != y && value.z != z;
}

bool Vector3::operator==(const Vector3 & value) const
{
	return value.x == x && value.y == y && value.z == z;
}



void Vector3::operator+=(const Vector3& value)
{
	*this = Add(value);
}

void Vector3::operator-=(const Vector3& value)
{
	*this = Sub(value);
}

void Vector3::operator*=(const Vector3& value)
{
	*this = (*this)*value;
}

void Vector3::operator/=(const Vector3& value)
{
	*this = Div(value);
}

Vector3 Vector3::operator+(const Vector3& value) const
{
	return Add(value);
}

Vector3 Vector3::operator-(const Vector3& value) const
{
	return Sub(value);
}

Vector3 Vector3::operator*(const Vector3& value) const
{
	return Vector3(x*value.x, y*value.y, z*value.z);
}

Vector3 Vector3::operator/(const Vector3& value) const
{
	return Div(value);
}

Vector3 Vector3::Add(const Vector3& value) const
{
	return Vector3(x + value.x, y + value.y, z + value.z);
}

Vector3 Vector3::Sub(const Vector3& value) const
{
	return Vector3(x - value.x, y - value.y, z - value.z);
}

Vector3 Vector3::Div(const Vector3& value) const
{
	return Vector3(x / value.x, y / value.y, z / value.z);
}

void Vector3::operator+=(float value)
{
	*this = Add(value);
}

void Vector3::operator-=(float value)
{
	*this = Sub(value);
}

void Vector3::operator*=(float value)
{
	*this = Mul(value);
}

void Vector3::operator/=(float value)
{
	*this = Div(value);
}

Vector3 Vector3::operator+(float value) const
{
	return Add(value);
}

Vector3 Vector3::operator-(float value) const
{
	return Sub(value);
}

Vector3 Vector3::operator*(float value) const
{
	return Mul(value);
}

Vector3 Vector3::operator/(float value) const
{
	return Div(value);
}

Vector3 Vector3::Add(float value) const
{
	return Vector3(x + value, y + value, z + value);
}

Vector3 Vector3::Sub(float value) const
{
	return Vector3(x - value, y - value, z - value);
}

Vector3 Vector3::Div(float value) const
{
	value = 1.0f / value;
	return Vector3(x*value, y*value, z*value);
}

Vector3 Vector3::Mul(float value) const
{
	return Vector3(x*value, y*value, z*value);
}

float Vector3::Dot(const Vector3& value) const
{
	return x * value.x + y * value.y + z * value.z;
}

void Vector3::Pow(float powerValue)
{
	x = pow(x, powerValue);
	y = pow(y, powerValue);
	z = pow(z, powerValue);
}

Vector3 Vector3::Cross(const Vector3& value) const
{
	return Vector3(y*value.z - z * value.y, z*value.x - x * value.z, x*value.y - y * value.x);
}

Vector3 Vector3::Normalize() const
{
	float mag = Magnitude();
	return Vector3(x / mag, y / mag, z / mag);
}

float Vector3::Magnitude() const
{
	Vector3 value = *this;
	value.Pow(2);
	float res = value.x + value.y + value.z;
	return pow(res, 0.5f);
}

Vector4::Vector4()
	:x(0),y(0),z(0),w(0)
{
}

Vector4::Vector4(float x, float y, float z, float w)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

Vector4::Vector4(const Vector4 & value)
	:x(value.x), y(value.y), z(value.z), w(value.w)
{
}

Vector4::Vector4(const Vector3 & value)
	: x(value.x), y(value.y), z(value.z), w(0)
{
}

Vector4::Vector4(const Vector2 & value)
	: x(value.x), y(value.y), z(0), w(0)
{
}

Vector4::Vector4(const glm::vec2 & value)
	:x(value.x), y(value.y),z(0)
{
}

Vector4::Vector4(const glm::vec3 & value)
	:x(value.x),y(value.y),z(value.z),w(0)
{
}

Vector4::Vector4(const glm::vec4 & value)
	:x(value.x),y(value.y),z(value.z),w(value.w)
{
}

bool Vector4::operator!=(const Vector4 & value) const
{
	return !((*this) == value);
}

bool Vector4::operator==(const Vector4 & value) const
{
	return value.x == x && value.y == y && value.z == z && value.w == w;
}

void Vector4::operator+=(const Vector4 & value)
{
	*this = this->Add(value);
}

void Vector4::operator-=(const Vector4 & value)
{
	*this = this->Sub(value);
}

void Vector4::operator*=(const Vector4 & value)
{
	*this = (*this)*value;
}

void Vector4::operator/=(const Vector4 & value)
{
	*this = this->Div(value);
}

Vector4 Vector4::operator+(const Vector4 & value) const
{
	return Add(value);
}

Vector4 Vector4::operator-(const Vector4 & value) const
{
	return Sub(value);
}

Vector4 Vector4::operator*(const Vector4 & value) const
{
	return Vector4(x*value.x, y*value.y, z*value.z, w*value.w);
}

Vector4 Vector4::operator/(const Vector4 & value) const
{
	return Div(value);
}

Vector4 Vector4::Add(const Vector4 & value) const
{
	return Vector4(value.x + x, value.y + y, value.z + z, value.w + w);
}

Vector4 Vector4::Sub(const Vector4 & value) const
{
	return Vector4(x - value.x, y - value.y, z - value.z, w - value.w);
}

Vector4 Vector4::Div(const Vector4 & value) const
{
	return Vector4(x / value.x, y / value.y, z / value.z, w / value.w);
}

void Vector4::operator+=(float value)
{
	*this = (*this) + value;
}

void Vector4::operator-=(float value)
{
	*this = (*this) - value;
}

void Vector4::operator*=(float value)
{
	*this = (*this)*value;
}

void Vector4::operator/=(float value)
{
	*this = (*this) / value;
}

Vector4 Vector4::operator+(float value) const
{
	return Add(value);
}

Vector4 Vector4::operator-(float value) const
{
	return Sub(value);
}

Vector4 Vector4::operator*(float value) const
{
	return Mul(value);
}

Vector4 Vector4::operator/(float value) const
{
	return Div(value);
}

Vector4 Vector4::Add(float value) const
{
	return Vector4(x + value, y + value, z + value, w + value);
}

Vector4 Vector4::Sub(float value) const
{
	return Vector4(x - value, y - value, z - value, w - value);;
}

Vector4 Vector4::Div(float value) const
{
	return Vector4(x / value, y / value, z / value, w / value);
}

Vector4 Vector4::Mul(float value) const
{
	return Vector4(x*value, y*value, z*value, w*value);
}

float Vector4::Dot(const Vector4 & value) const
{
	return x * value.x + y * value.y + z * value.z + w + value.w;
}

void Vector4::Pow(float value)
{
	x = pow(x, value);
	y = pow(y, value);
	z = pow(z, value);
	w = pow(w, value);
}

Vector4 Vector4::Normalize() const
{
	float mag = Magnitude();
	return Vector4(x / mag, y / mag, z / mag, w / mag);
}

float Vector4::Magnitude() const
{
	Vector4 val = *this;
	val.Pow(2.0f);
	float res = val.x + val.y + val.z + val.w;
	return pow(res, 0.5f);
}

std::ostream & operator<<(std::ostream & stream, const Vector2 & vector)
{
	return stream << "Vector2: (" << vector.x << ", " << vector.y << ")";
}

std::ostream & operator<<(std::ostream & stream, const Vector3& vector)
{
	return stream << "Vector3: (" << vector.x << ", " << vector.y << ", " << vector.z << ")";
}

std::ostream & operator<<(std::ostream & stream, const Vector4& vector)
{
	return stream << "Vector4: (" << vector.x << ", " << vector.y << ", " << vector.z << ", "<< vector.w << ")";
}

Mat4 operator*(Mat4 left, const Mat4 & other)
{
	Mat4 result = left;
	result = result.Mul(other);
	return result;
}

Mat4::Mat4()
{
	for (int i = 0; i < 16; i++) {
		elements[i] = 0.0f;
	}
}

Mat4::Mat4(float diagonal)
{
	for (int i = 0; i < 16; i++) {
		elements[i] = 0.0f;
	}
	elements[0 + 0 * 4] = diagonal;
	elements[1 + 1 * 4] = diagonal;
	elements[2 + 2 * 4] = diagonal;
	elements[3 + 3 * 4] = diagonal;
}

Mat4::Mat4(glm::mat4 value)
{
	float* initReference = &value[0][0];
	for (int i = 0; i < 16; i++) {
		elements[i] = *(initReference + i);
	}
}

Mat4::operator glm::mat4()
{
	glm::mat4 result;
	for (int i = 0; i < 16; i++) {
		*(&result[0][0] + i) = elements[i];
	}
	return result;
}


Mat4 & Mat4::Mul(const Mat4 & other)
{
	float data[16];
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			float sum = 0.0f;
			for (int e = 0; e < 4; e++) {
				sum += elements[e + y * 4] * other.elements[x + e * 4];
			}
			data[x + y * 4] = sum;
		}
	}
	memcpy(elements, data, 4 * 4 * sizeof(float));
	return *this;
}

Mat4 & Mat4::Mul(const glm::mat4 & other) {
	float data[16];
	const float* otherdata = &other[0][0];
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			float sum = 0.0f;
			for (int e = 0; e < 4; e++) {
				sum += elements[e + y * 4] * otherdata[x + e * 4];
			}
			data[x + y * 4] = sum;
		}
	}
	memcpy(elements, data, 4 * 4 * sizeof(float));
	return *this;
}

glm::mat4 & Mat4::ToGlmMat() {
	glm::mat4 data;
	float* matData = &data[0][0];
	for (int i = 0; i < 16; i++) {
		*(matData + i) = elements[i];
	}
	return data;
}

Mat4 & Mat4::operator*=(const Mat4 & other)
{
	return Mul(other);
}

Mat4 Mat4::Identity()
{
	return Mat4(1.0f);
}

Mat4 Mat4::Orthographic(float left, float right, float bottom, float top, float near, float far)
{
	Mat4 result(1.0f);
	result.elements[0 + 0 * 4] = 2.0f / (right - left);
	result.elements[1 + 1 * 4] = 2.0f / (top - bottom);
	result.elements[2 + 2 * 4] = 2.0f / (near - far);
	result.elements[3 + 0 * 4] = (left + right) / (left - right);
	result.elements[3 + 1 * 4] = (bottom + top) / (bottom - top);
	result.elements[3 + 2 * 4] = (far + near) / (far - near);
	return result;
}

Mat4 Mat4::Perspective(float fov, float aspetRatio, float near, float far)
{
	Mat4 result(1.0f);
	float q = 1.0f / tan(0.5f*fov*DEGTORAD);
	float a = q / aspetRatio;
	float b = (near + far) / (near - far);
	float c = (2.0f*near*far) / (near - far);
	result.elements[0 + 0 * 4] = a;
	result.elements[1 + 1 * 4] = q;
	result.elements[2 + 2 * 4] = b;
	result.elements[3 + 2 * 4] = -1.0f;
	result.elements[2 + 3 * 4] = c;
	return result;
}

Mat4 Mat4::Translation(const Vector3 & translation)
{
	Mat4 result(1.0f);
	result.elements[0 + 3 * 4] = translation.x;
	result.elements[1 + 3 * 4] = translation.y;
	result.elements[2 + 3 * 4] = translation.z;
	return result;
}

Mat4 Mat4::Rotation( const Vector3 & axis)
{
	glm::mat4 result(1.f);
	result = glm::rotate(result, axis.x, glm::vec3(1, 0, 0));
	result = glm::rotate(result, axis.y, glm::vec3(0, 1, 0));
	result = glm::rotate(result, axis.z, glm::vec3(0, 0, 1));
	return result;
}

Mat4 Mat4::Scale(const Vector3 & scale)
{
	Mat4 result(1.0f);
	result.elements[0 + 0 * 4] = scale.x;
	result.elements[1 + 1 * 4] = scale.y;
	result.elements[2 + 2 * 4] = scale.z;
	return result;
}

Mat4 Mat4::SingleRotation(float angle, const Vector3 & axis)
{
	Mat4 result(1.0f);

	float r = angle*DEGTORAD;
	float c = cos(r);
	float s = sin(r);
	float omc = 1.0f - c;

	float x = axis.x;
	float y = axis.y;
	float z = axis.z;

	result.elements[0 + 0 * 4] = x * x * omc + c;
	result.elements[0 + 1 * 4] = y * x * omc + z * s;
	result.elements[0 + 2 * 4] = x * z * omc - y * s;

	result.elements[1 + 0 * 4] = x * y * omc - z * s;
	result.elements[1 + 1 * 4] = y * y * omc + c;
	result.elements[1 + 2 * 4] = y * z * omc + x * s;

	result.elements[2 + 0 * 4] = x * z * omc + y * s;
	result.elements[2 + 1 * 4] = y * z * omc - x * s;
	result.elements[2 + 2 * 4] = z * z * omc + c;

	return result;
	
}

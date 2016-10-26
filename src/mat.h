#ifndef GLMATH_MAT_H
#define GLMATH_MAT_H

#include "vec.h"
#include <GL/glew.h>
#include <iostream>

#define M_PI 3.14159265358979323846

GLfloat DegreesToRadians = (GLfloat) (M_PI / 180.0);

class mat2 {

    vec2 _m[2];

public:
    mat2 (GLfloat d = GLfloat(1.0)) {
        _m[0].x = d;
        _m[1].y = d;
    }

    mat2 (const vec2 &a, const vec2 &b) {
        _m[0] = a;
        _m[1] = b;
    }

    mat2 (GLfloat m00, GLfloat m01,
          GLfloat m10, GLfloat m11) {

        _m[0] = vec2(m00, m01);
        _m[1] = vec2(m10, m11);
    }

    mat2 (const mat2 &m) {
        if (*this != m) {
            _m[0] = m._m[0];
            _m[1] = m._m[1];
        }
    }

    vec2 &operator[] (int i) {
        return _m[i];
    }

    const vec2 &operator[] (int i) const {
        return _m[i];
    }

    mat2 operator+ (const mat2 &m) const {
        return mat2(_m[0] + m[0], _m[1] + m[1]);
    }

    mat2 operator- (const mat2 &m) const {
        return mat2(_m[0] - m[0], _m[1] - m[1]);
    }

    mat2 operator* (const GLfloat s) const {
        return mat2(_m[0] * s, _m[1] * s);
    }

    friend mat2 operator* (const GLfloat s, const mat2 &m)  {
        return m * s;
    }

    mat2 operator* (const mat2 &m) const {

        mat2 a(0.0);

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    a[i][j] += _m[i][k] * m[k][j];
                }
            }
        }

        return a;
    }

    mat2 operator/ (const GLfloat s) const {
        return mat2(_m[0] / s, _m[1] / s);
    }

    mat2 &operator+= (const mat2 &m) {
        _m[0] += m[0];
        _m[1] += m[1];
        return *this;
    }

    mat2 &operator-= (const mat2 &m) {
        _m[0] -= m[0];
        _m[1] -= m[1];
        return *this;
    }

    mat2 &operator*= (const GLfloat s) {
        _m[0] *= s;
        _m[1] *= s;
        return *this;
    }

    mat2 &operator/= (const GLfloat s) {
        _m[0] /= s;
        _m[1] /= s;
        return *this;
    }

    vec2 operator* (const vec2 &v) const {
        return vec2(_m[0][0] * v.x + _m[0][1] * v.y, _m[1][0] * v.x + _m[1][1] * v.y);
    }

    friend std::ostream &operator<< (std::ostream &os, const mat2 &m) {
        return os << std::endl << m[0] << std::endl << m[1] << std::endl;
    }

    friend std::istream &operator>> (std::istream &is, mat2 &m) {
        return is >> m._m[0] >> m._m[1];
    }

    operator const GLfloat *() const {
        return static_cast<const GLfloat *>(&_m[0].x);
    }

    operator GLfloat *() {
        return static_cast<GLfloat *>(&_m[0].x);
    }

};

inline mat2 matrixCompMult (const mat2 &a, const mat2 &b) {
    return mat2(a[0][0] * b[0][0], a[0][1] * b[0][1],
                a[1][0] * b[1][0], a[1][1] * b[1][1]);
}

inline mat2 transpose (const mat2 &m) {
    return mat2(m[0].x, m[1].x, m[0].y, m[1].y);
}

class mat3 {

    vec3 _m[3];

public:
    mat3 (const GLfloat s = GLfloat(1.0)) {
        _m[0].x = s;
        _m[1].y = s;
        _m[2].z = s;
    }

    mat3 (const vec3 &a, const vec3 &b, const vec3 &c) {
        _m[0] = a;
        _m[1] = b;
        _m[2] = c;
    }

    mat3 (GLfloat m00, GLfloat m10, GLfloat m20,
          GLfloat m01, GLfloat m11, GLfloat m21,
          GLfloat m02, GLfloat m12, GLfloat m22) {

        _m[0] = vec3(m00, m10, m20);
        _m[1] = vec3(m01, m11, m21);
        _m[2] = vec3(m02, m12, m22);
    }

    mat3 (const mat3 &m) {
        if (*this != m) {
            _m[0] = m[0];
            _m[1] = m[1];
            _m[2] = m[2];
        }
    }

    vec3 &operator[] (int i) {
        return _m[i];
    }

    const vec3 &operator[] (int i) const {
        return _m[i];
    }

    mat3 operator+ (const mat3 &m) const {
        return mat3(_m[0] + m[0], _m[1] + m[1], _m[2] + m[2]);
    }

    mat3 operator- (const mat3 &m) const {
        return mat3(_m[0] - m[0], _m[1] - m[1], _m[2] - m[2]);
    }

    mat3 operator* (const GLfloat s) const {
        return mat3(_m[0] * s, _m[1] * s, _m[2] * s);
    }

    friend mat3 operator* (const GLfloat s, const mat3 &m) {
        return mat3(s * m[0], s * m[1], s * m[2]);
    }

    mat3 operator* (const mat3 &m) const {
        mat3 a(0.0);

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    a[i][j] += _m[i][k] * m[k][j];
                }
            }
        }
        return a;
    }

    mat3 operator/ (const GLfloat s) const {
        return mat3(_m[0] / s, _m[1] / s, _m[2] / s);
    }

    mat3 &operator+= (const mat3 &m) {
        _m[0] += m[0];
        _m[1] += m[1];
        _m[2] += m[2];
        return *this;
    }

    mat3 &operator-= (const mat3 &m) {
        _m[0] -= m[0];
        _m[1] -= m[1];
        _m[2] -= m[2];
        return *this;
    }

    mat3 operator*= (const GLfloat s) {
        _m[0] *= s;
        _m[1] *= s;
        _m[2] *= s;
        return *this;
    }

    mat3 operator/= (const GLfloat s) {
        _m[0] /= s;
        _m[1] /= s;
        _m[2] /= s;
        return *this;
    }

    vec3 operator* (const vec3 &v) const {
        return vec3(_m[0][0] * v.x + _m[0][1] * v.y + _m[0][2] * v.z,
                    _m[1][0] * v.x + _m[1][1] * v.y + _m[1][2] * v.z,
                    _m[2][0] * v.x + _m[2][1] * v.y + _m[2][2] * v.z);
    }

    friend std::ostream &operator<< (std::ostream &os, const mat3 &m) {
        return os << std::endl << m[0] << std::endl << m[1] << std::endl << m[2] << std::endl;
    }

    friend std::istream &operator>> (std::istream &is, mat3 &m) {
        return is >> m._m[0] >> m._m[1] >> m._m[2];
    }

    operator const GLfloat *() const {
        return static_cast<const GLfloat *>(&_m[0].x);
    }

    operator GLfloat *() {
        return static_cast<GLfloat *>(&_m[0].x);
    }
};

inline mat3 transpose (const mat3 &a) {
    return mat3(a[0][0], a[1][0], a[2][0],
                a[0][1], a[1][1], a[2][1],
                a[0][2], a[1][2], a[2][2]);
}

inline mat3 matrixCompMult (const mat3 &a, const mat3 &b) {
    return mat3(a[0][0] * b[0][0], a[0][1] * b[0][1], a[0][2] * b[0][2],
                a[1][0] * b[1][0], a[1][1] * b[1][1], a[1][2] * b[1][2],
                a[2][0] * b[2][0], a[2][1] * b[2][1], a[2][2] * b[2][2]);
}

class mat4 {

    vec4 _m[4];

public:
    mat4 (const GLfloat s = GLfloat(1.0)) {
        _m[0].x = s;
        _m[1].y = s;
        _m[2].z = s;
        _m[3].w = s;
    }

    mat4 (const vec4 &a, const vec4 &b, const vec4 &c, const vec4 &d) {
        _m[0] = a;
        _m[1] = b;
        _m[2] = c;
        _m[3] = d;
    }

    mat4 (GLfloat m00, GLfloat m10, GLfloat m20, GLfloat m30,
          GLfloat m01, GLfloat m11, GLfloat m21, GLfloat m31,
          GLfloat m02, GLfloat m12, GLfloat m22, GLfloat m32,
          GLfloat m03, GLfloat m13, GLfloat m23, GLfloat m33) {

        _m[0] = vec4(m00, m10, m20, m30);
        _m[1] = vec4(m01, m11, m21, m31);
        _m[2] = vec4(m02, m12, m22, m32);
        _m[3] = vec4(m03, m13, m23, m33);
    }

    mat4 (const mat4 &m) {
        if (*this != m) {
            _m[0] = m._m[0];
            _m[1] = m._m[1];
            _m[2] = m._m[2];
            _m[3] = m._m[3];
        }
    }

    vec4 &operator[] (int i) {
        return _m[i];
    }

    const vec4 &operator[] (int i) const {
        return _m[i];
    }

    mat4 operator+ (const mat4 &m) const {
        return mat4(_m[0] + m[0], _m[1] + m[1], _m[2] + m[2], _m[3] + m[3]);
    }

    mat4 operator- (const mat4 &m) const {
        return mat4(_m[0] - m[0], _m[1] - m[1], _m[2] - m[2], _m[3] - m[3]);
    }

    mat4 operator* (const GLfloat s) const {
        return mat4(_m[0] * s, _m[1] * s, _m[2] * s, _m[3] * s);
    }

    friend mat4 operator* (const GLfloat s, const mat4 &m) {
        return mat4(m[0] * s, m[1] * s, m[2] * s, m[3] * s);
    }

    mat4 operator* (const mat4 &m) const {
        mat4 a(0.0);

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    a[i][j] += _m[i][k] * m[k][j];
                }
            }
        }

        return a;
    }

    mat4 operator/ (const GLfloat s) const {
        return mat4(_m[0] / s, _m[1] / s, _m[2] / s, _m[3] / s);
    }

    mat4 &operator+= (const mat4 &m) {
        _m[0] += m[0];
        _m[1] += m[1];
        _m[2] += m[2];
        _m[3] += m[3];
        return *this;
    }

    mat4 &operator-= (const mat4 &m) {
        _m[0] -= m[0];
        _m[1] -= m[1];
        _m[2] -= m[2];
        _m[3] -= m[3];
        return *this;
    }

    mat4 &operator*= (const GLfloat s) {
        _m[0] *= s;
        _m[1] *= s;
        _m[2] *= s;
        _m[3] *= s;
        return *this;
    }

    mat4 &operator/= (const GLfloat s) {
        _m[0] /= s;
        _m[1] /= s;
        _m[2] /= s;
        _m[3] /= s;
        return *this;
    }

    vec4 operator* (const vec4 &v) const {
        return vec4(dot(_m[0], v), dot(_m[1], v), dot(_m[2], v), dot(_m[3], v));
    }

    friend std::ostream &operator<< (std::ostream &os, const mat4 &m) {
        return os << std::endl << m[0] << std::endl << m[1] << std::endl << m[2] << std::endl << m[3] << std::endl;
    }

    friend std::istream &operator>> (std::istream &is, mat4 &m) {
        return is >> m._m[0] >> m._m[1] >> m._m[2] >> m._m[3];
    }

    operator const GLfloat *() const {
        return static_cast<const GLfloat *>(&_m[0].x);
    }

    operator GLfloat *() {
        return static_cast<GLfloat *>(&_m[0].x);
    }
};

mat4 matrixCompMult(const mat4 &a, const mat4 &b) {
    return mat4(a[0][0] * b[0][0], a[0][1] * b[0][1], a[0][2] * b[0][2], a[0][3] * b[0][3],
                a[1][0] * b[1][0], a[1][1] * b[1][1], a[1][2] * b[1][2], a[1][3] * b[1][3],
                a[2][0] * b[2][0], a[2][1] * b[2][1], a[2][2] * b[2][2], a[2][3] * b[2][3],
                a[3][0] * b[3][0], a[3][1] * b[3][1], a[3][2] * b[3][2], a[3][3] * b[3][3]);
}

mat4 transpose(const mat4 &a) {
    return mat4(a[0][0], a[1][0], a[2][0], a[3][0],
                a[0][1], a[1][1], a[2][1], a[3][1],
                a[0][2], a[1][2], a[2][2], a[3][2],
                a[0][3], a[1][3], a[2][3], a[3][3]);
}

inline mat4 RotateX (const GLfloat theta) {
    GLfloat angle = DegreesToRadians * theta;

    mat4 c;
    c[2][2] = c[1][1] = (GLfloat) cos(angle);
    c[2][1] = (GLfloat) sin(angle);
    c[1][2] = -c[2][1];

    return c;
}

inline mat4 RotateY (const GLfloat theta) {
    GLfloat angle = DegreesToRadians * theta;

    mat4 c;
    c[2][2] = c[0][0] = (GLfloat) cos(angle);
    c[0][2] = (GLfloat) sin(angle);
    c[2][0] = -c[0][2];
    return c;
}

inline mat4 RotateZ (const GLfloat theta) {
    GLfloat angle = DegreesToRadians * theta;

    mat4 c;
    c[0][0] = c[1][1] = (GLfloat) cos(angle);
    c[1][0] = (GLfloat) sin(angle);
    c[0][1] = -c[1][0];
    return c;
}

inline mat4 Scale (const GLfloat x, const GLfloat y, const GLfloat z) {
    mat4 c;
    c[0][0] = x;
    c[1][1] = y;
    c[2][2] = z;

    return c;
}

inline mat4 Scale (vec3 &v) {
    return Scale(v.x, v.y, v.z);
}

inline mat4 Translate (const GLfloat x, const GLfloat y, const GLfloat z) {
    mat4 c;
    c[0][3] = x;
    c[1][3] = y;
    c[2][3] = z;
    return c;
}

inline mat4 Translate (const vec3 &v) {
    return Translate(v.x, v.y, v.z);
}

inline mat4 Translate (const vec4 &v) {
    return Translate(v.x, v.y, v.z);
}

inline mat4 Perspective (const GLfloat fovy, const GLfloat aspect, const GLfloat zNear, const GLfloat zFar) {
    mat4 c;
    GLfloat top = (GLfloat) (tan(fovy * DegreesToRadians / 2.0f) * zNear);
    GLfloat right = top * aspect;

    c[0][0] = zNear / right;
    c[1][1] = zNear / top;
    c[2][2] = -(zFar + zNear) / (zFar - zNear);
    c[2][3] = -2.0f * zFar * zNear / (zFar - zNear);
    c[3][2] = -1.0f;
    c[3][3] = 0.0f;

    return c;
}

inline mat4 LookAt (const vec4 &eye, const vec4 &at, const vec4 &up) {

    vec4 n = normalize(eye - at);
    vec4 u = normalize(cross(up, n));
    vec4 v = normalize(cross(n, u));
    vec4 t = vec4(0.0f, 0.0f, 0.0f, 1.0f);
    mat4 c = mat4(u, v, n, t);

    return c * Translate(-eye);
}


inline mat4 Ortho (const GLfloat left, const GLfloat right, const GLfloat bottom, const GLfloat top, const GLfloat zNear, const GLfloat zFar) {
    mat4 c;
    c[0][0] = 2.0f / (right - left);
    c[1][1] = 2.0f / (top - bottom);
    c[2][2] = -2.0f / (zFar - zNear);
    c[3][3] = 1.0f;
    c[0][3] = -(right + left) / (right - left);
    c[1][3] = -(top + bottom) / (top - bottom);
    c[2][3] = -(zFar + zNear) / (zFar - zNear);

    return c;
}

inline mat4 Ortho2D (const GLfloat left, const GLfloat right, const GLfloat bottom, const GLfloat top) {
    return Ortho(left, right, bottom, top, -1.0f, 1.0f);
}


#endif //GLMATH_MAT_H

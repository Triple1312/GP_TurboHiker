//
// Created by Phili on 14/11/2020.
//

#ifndef GP_VECTOR3_H
#define GP_VECTOR3_H

namespace ppp {



template <typename T>
class Vector3 {
public:
    Vector3() = default;

    Vector3(T x, T y, T z);


    Vector3<T> operator -(const Vector3<T>& right);

    Vector3<T> operator +(const Vector3<T>& right);

    Vector3<T> operator /(const T right);

    T x, y, z;
};

//template <typename T>
//bool collision_vec(Vector3<T> &left, Vector3<T> &right) {
//
//    return
//} ///todo make collision



template<typename T>
Vector3<T>::Vector3(T x, T y, T z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

template<typename T>
Vector3<T> operator-(const Vector3<T> &right) {
    return Vector3<T>(-right.x, -right.y, -right.z);
}

template<typename T>
Vector3<T> operator+(const Vector3<T> &right) {
    return Vector3<T>(+right.x, +right.y, +right.z);
}

    template<typename T>
    Vector3<T> Vector3<T>::operator/(const T right) {
        return Vector3<T>(this->x/right, this->y/right, this->z/right);
    }

//    template<typename T>
//    Vector3<T> &Vector3<T>::operator/=(T right) {
//        this->x = this->x /right;
//        this->y
//    }

    template<typename T>
inline Vector3<T> & operator/=(Vector3<T> &left, T right) {
    left.x /= right;
    left.y /= right;
    left.z /= right;

    return left;
}




typedef Vector3<float> Vec3F;
typedef Vector3<int> Vec3I;
typedef Vector3<std::uint8_t> Vec3U8;
typedef Vector3<std::uint64_t> Vec3UI;













}

#endif //GP_VECTOR3_H

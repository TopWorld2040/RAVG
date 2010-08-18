#ifndef __RVGVECTORS_H
#define __RVGVECTORS_H 1

/*
------------------------------------
Forward declarations
------------------------------------*/

class Vec3;
class Vec4;
class Matrix4x4;

/*
=============================================
2, 3, and 4-dimensional vectors
=============================================*/

class Vec2
{
public:

  Float x, y;
  
  Vec2 yx () const;

  Vec3 xy (Float z) const;
  Vec4 xy (Float z, Float w) const;
  
  Vec2 ();
  Vec2 (Float xy);
  Vec2 (Float x0, Float y0);
  Vec2& set (Float x0, Float y0);
  Vec2& operator= (const Vec2 &v);
  bool operator== (const Vec2 &v) const;
  bool operator!= (const Vec2 &v) const;
  
  Vec2& operator+= (const Vec2 &v);
  Vec2& operator-= (const Vec2 &v);
  Vec2& operator*= (Float k);
  Vec2& operator/= (Float k);
  
  Vec2 operator+ (const Vec2 &v) const;
  Vec2 operator- (const Vec2 &v) const;
  Vec2 operator* (const Vec2 &v) const;
  Vec2 operator/ (const Vec2 &v) const;
  Vec2 operator* (Float k) const;
  Vec2 operator/ (Float k) const;
  
  Float norm () const;
  Float normSq () const;
  Vec2& normalize ();
  
  Vec2& offset (Float ox, Float oy);
  Vec2& offsetV (const Vec2 &v, Float d);
  Vec2& offsetVN (const Vec2 &v, Float d);
  Vec2 reverse () const;
};

class Vec3
{
public:

  Float x, y, z;
  
  Vec2 xy () const;
  Vec4 xyz (Float w) const;
  
  Vec3 ();
  Vec3 (Float xyz);
  Vec3 (Float x0, Float y0, Float z0);
  Vec3& set (Float x0, Float y0, Float z0);
  Vec3& operator= (const Vec3 &v);
  bool operator== (const Vec3 &v) const;
  bool operator!= (const Vec3 &v) const;
  
  Vec3& operator+= (const Vec3 &v);
  Vec3& operator-= (const Vec3 &v);
  Vec3& operator*= (Float k);
  Vec3& operator/= (Float k);
  
  Vec3 operator+ (const Vec3 &v) const;
  Vec3 operator- (const Vec3 &v) const;
  Vec3 operator* (const Vec3 &v) const;
  Vec3 operator/ (const Vec3 &v) const;
  Vec3 operator* (Float k) const;
  Vec3 operator/ (Float k) const;
  
  Float norm () const;
  Float normSq () const;
  Vec3& normalize ();
  
  Vec3& offset (Float ox, Float oy, Float oz);
  Vec3& offsetV (const Vec3 &v, Float d);
  Vec3& offsetVN (const Vec3 &v, Float d);
  Vec3 reverse () const;
};

class Vec4
{
public:

  Float x, y, z, w;
  
  Vec2 xy () const;
  Vec3 xyz () const;
  
  Vec4 ();
  Vec4 (Float xyzw);
  Vec4 (Float x0, Float y0, Float z0, Float w0);
  Vec4& set (Float x0, Float y0, Float z0, Float w0);
  
  Vec4& operator= (const Vec4 &v);
  bool operator== (const Vec4 &v) const;
  bool operator!= (const Vec4 &v) const;
  
  Vec4& operator+= (const Vec4 &v);
  Vec4& operator-= (const Vec4 &v);
  Vec4& operator*= (Float k);
  Vec4& operator/= (Float k);

  Vec4 operator+ (const Vec4 &v) const;
  Vec4 operator- (const Vec4 &v) const;
  Vec4 operator* (const Vec4 &v) const;
  Vec4 operator/ (const Vec4 &v) const;
  Vec4 operator* (Float k) const;
  Vec4 operator/ (Float k) const;
  
  Float norm () const;
  Float normSq () const;
  Vec4& normalize ();
  
  Vec4& offset (Float ox, Float oy, Float ow, Float oz);
  Vec4& offsetV (const Vec4 &v, Float d);
  Vec4& offsetVN (const Vec4 &v, Float d);
  Vec4 reverse () const;
};

class Vec
{
public:

  static Vec2 Floor (const Vec2 &v);
  static Vec3 Floor (const Vec3 &v);
  static Vec4 Floor (const Vec4 &v);

  static Vec2 Ceil (const Vec2 &v);
  static Vec3 Ceil (const Vec3 &v);
  static Vec4 Ceil (const Vec4 &v);

  static Vec2 Fract (const Vec2 &v);
  static Vec3 Fract (const Vec3 &v);
  static Vec4 Fract (const Vec4 &v);

  static Vec2 Min (const Vec2 &v1, const Vec2 &v2);
  static Vec3 Min (const Vec3 &v1, const Vec3 &v2);
  static Vec4 Min (const Vec4 &v1, const Vec4 &v2);

  static Vec2 Max (const Vec2 &v1, const Vec2 &v2);
  static Vec3 Max (const Vec3 &v1, const Vec3 &v2);
  static Vec4 Max (const Vec4 &v1, const Vec4 &v2);
  
  static Float Dot (const Vec2 &v1, const Vec2 &v2);
  static Float Dot (const Vec3 &v1, const Vec3 &v2);
  static Float Dot (const Vec4 &v1, const Vec4 &v2);
  
  static Float Angle (const Vec2 &v1, const Vec2 &v2);
  static Float Angle (const Vec3 &v1, const Vec3 &v2);
  static Float Angle (const Vec4 &v1, const Vec4 &v2);
  
  static Float AngleN (const Vec2 &v1, const Vec2 &v2);
  static Float AngleN (const Vec3 &v1, const Vec3 &v2);
  static Float AngleN (const Vec4 &v1, const Vec4 &v2);
  
  static Float Cross (const Vec2 &v1, const Vec2 &v2);
  static Vec3 Cross (const Vec3 &v1, const Vec3 &v2);

  template <class V> static V Lerp (const V &v1, const V &v2, Float t);
  
  static Float RotationOnPlane2 (const Vec2 &v);
  static Float RotationOnPlane2N (const Vec2 &v);
  static Float RotationOnPlane3 (const Vec3 &v, const Vec3 &ux, const Vec3 &uy);
  static Float RotationOnPlane3N (const Vec3 &v, const Vec3 &ux, const Vec3 &uy);
  
  static Float AreaSign2 (const Vec2 &p1, const Vec2 &p2, const Vec2 &p3);
  static Float AreaSign3 (const Vec3 &p1, const Vec3 &p2, const Vec3 &p3);
  static Float Area2 (const Vec2 &p1, const Vec2 &p2, const Vec2 &p3);
  static Float Area2V (const Vec2 &v1, const Vec2 &v2);
  static Float Area3 (const Vec3 &p1, const Vec3 &p2, const Vec3 &p3);
  static Float Area3V (const Vec3 &v1, const Vec3 &v2);
  static bool InsideTriangle (const Vec2 &p, const Vec2 &p1, const Vec2 &p2,
                              const Vec2 &p3, Float maxerror=0.0001);
};

/*
=============================================
Quaternion
=============================================*/

class Quat
{
public:

  Float x,y,z,w;

  Quat ();
  Quat (Float x, Float y, Float z, Float w);
  void set (Float x, Float y, Float z, Float w);

  Float norm () const;
  Float normSq () const;
  Quat& normalize ();

  void setIdentity ();
  void fromAxisAngle (Float x, Float y, Float z, Float radang);
  void fromAxisAngle (const Vec3 &axis, Float radang);
  void fromMatrix (const Matrix4x4 &m);
  Matrix4x4 toMatrix ();
  
  static Quat Slerp (const Quat &q1, const Quat &q2, Float t);
  static Quat Nlerp (const Quat &q1, const Quat &q2, Float t);
  inline static Float Dot (const Quat &q1, const Quat &q2);

  bool operator== (const Quat &q) const;
  bool operator!= (const Quat &q) const;
};

Quat operator* (const Quat &q1, const Quat &q2);

/*
=============================================
Vec inline functions
=============================================*/

//Swizzle
inline Vec2 Vec2::yx () const
  { return Vec2 (y,x); }


//Conversions
inline Vec3 Vec2::xy (Float z) const
  { return Vec3 (x,y,z); }

inline Vec4 Vec2::xy (Float z, Float w) const
  { return Vec4 (x,y,z,w); }


inline Vec2 Vec3::xy () const
  { return Vec2 (x,y); }

inline Vec4 Vec3::xyz (Float w) const
  { return Vec4 (x,y,z,w); }


inline Vec2 Vec4::xy () const
  { return Vec2 (x,y); }

inline Vec3 Vec4::xyz () const
  { return Vec3(x,y,z); }


//Default constructor
inline Vec2::Vec2 ()
  { x=0.0f; y=0.0f; }

inline Vec3::Vec3 ()
  { x=0.0f; y=0.0f; z=0.0f; }

inline Vec4::Vec4 ()
  { x=0.0f; y=0.0f; z=0.0f; w=0.0f; }


//All-members constructor
inline Vec2::Vec2 (Float xy)
  { x=xy; y=xy; }

inline Vec3::Vec3 (Float xyz)
  { x=xyz; y=xyz; z=xyz; }

inline Vec4::Vec4 (Float xyzw)
  { x=xyzw; y=xyzw; z=xyzw; w=xyzw; }


//Separate members contructor
inline Vec2::Vec2 (Float x0, Float y0)
  { x=x0; y=y0; }

inline Vec3::Vec3 (Float x0, Float y0, Float z0)
  { x=x0; y=y0; z=z0; }

inline Vec4::Vec4 (Float x0, Float y0, Float z0, Float w0)
  { x=x0; y=y0; z=z0; w=w0; }


//Separate members assignment
inline Vec2& Vec2::set (Float x0, Float y0)
  { x=x0; y=y0; return *this; }

inline Vec3& Vec3::set (Float x0, Float y0, Float z0)
  { x=x0; y=y0; z=z0; return *this; }

inline Vec4& Vec4::set (Float x0, Float y0, Float z0, Float w0)
  { x=x0; y=y0; z=z0; w=w0; return *this; }


inline Vec2& Vec2::operator= (const Vec2 &v)
  { x=v.x; y=v.y; return *this; }

inline Vec3& Vec3::operator= (const Vec3 &v)
  { x=v.x; y=v.y; z=v.z; return *this; }

inline Vec4& Vec4::operator= (const Vec4 &v)
  { x=v.x; y=v.y; z=v.z; w=v.w; return *this; }


inline bool Vec2::operator== (const Vec2 &v) const
  { return x==v.x && y==v.y; }

inline bool Vec3::operator== (const Vec3 &v) const
  { return x==v.x && y==v.y && z==v.z; }

inline bool Vec4::operator== (const Vec4 &v) const
  { return x==v.x && y==v.y && z==v.z && w==v.w; }


inline bool Vec2::operator!= (const Vec2 &v) const
  { return x!=v.x || y!=v.y; }

inline bool Vec3::operator!= (const Vec3 &v) const
  { return x!=v.x || y!=v.y || z!=v.z; }

inline bool Vec4::operator!= (const Vec4 &v) const
  { return x!=v.x || y!=v.y || z!=v.z || w!=v.w; }


inline Vec2& Vec2::operator+= (const Vec2 &v)
  { x+=v.x; y+=v.y; return *this; }

inline Vec3& Vec3::operator+= (const Vec3 &v)
  { x+=v.x; y+=v.y; z+=v.z; return *this; }

inline Vec4& Vec4::operator+= (const Vec4 &v)
  { x+=v.x; y+=v.y; z+=v.z; w+=v.w; return *this; }


inline Vec2& Vec2::operator-= (const Vec2 &v)
  { x-=v.x; y-=v.y; return *this; }

inline Vec3& Vec3::operator-= (const Vec3 &v)
  { x-=v.x; y-=v.y; z-=v.z; return *this; }

inline Vec4& Vec4::operator-= (const Vec4 &v)
  { x-=v.x; y-=v.y; z-=v.z; w-=v.w; return *this; }


inline Vec2& Vec2::operator*= (Float k)
  { x*=k; y*=k; return *this; }

inline Vec3& Vec3::operator*= (Float k)
  { x*=k; y*=k; z*=k; return *this; }

inline Vec4& Vec4::operator*= (Float k)
  { x*=k; y*=k; z*=k; w*=k; return *this; }


inline Vec2& Vec2::operator/= (Float k)
  { x/=k; y/=k; return *this; }

inline Vec3& Vec3::operator/= (Float k)
  { x/=k; y/=k; z/=k; return *this; }

inline Vec4& Vec4::operator/= (Float k)
  { x/=k; y/=k; z/=k; w/=k; return *this; }


inline Vec2 Vec2::operator+ (const Vec2 &v) const
  { return Vec2 (x+v.x, y+v.y); }

inline Vec3 Vec3::operator+ (const Vec3 &v) const
  { return Vec3 (x+v.x, y+v.y, z+v.z); }

inline Vec4 Vec4::operator+ (const Vec4 &v) const
  { return Vec4 (x+v.x, y+v.y, z+v.z, w+v.w); }


inline Vec2 Vec2::operator- (const Vec2 &v) const
  { return Vec2 (x-v.x, y-v.y); }

inline Vec3 Vec3::operator- (const Vec3 &v) const
  { return Vec3 (x-v.x, y-v.y, z-v.z); }

inline Vec4 Vec4::operator- (const Vec4 &v) const
  { return Vec4 (x-v.x, y-v.y, z-v.z, w-v.w); }


inline Vec2 Vec2::operator* (const Vec2 &v) const
  { return Vec2 (x*v.x, y*v.y); }

inline Vec3 Vec3::operator* (const Vec3 &v) const
  { return Vec3 (x*v.x, y*v.y, z*v.z); }

inline Vec4 Vec4::operator* (const Vec4 &v) const
  { return Vec4 (x*v.x, y*v.y, z*v.z, w*v.w); }


inline Vec2 Vec2::operator/ (const Vec2 &v) const
  { return Vec2 (x/v.x, y/v.y); }

inline Vec3 Vec3::operator/ (const Vec3 &v) const
  { return Vec3 (x/v.x, y/v.y, z/v.z); }

inline Vec4 Vec4::operator/ (const Vec4 &v) const
  { return Vec4 (x/v.x, y/v.y, z/v.z, w/v.w); }


inline Vec2 Vec2::operator* (Float k) const
  { return Vec2 (x*k, y*k); }

inline Vec3 Vec3::operator* (Float k) const
  { return Vec3 (x*k, y*k, z*k); }

inline Vec4 Vec4::operator* (Float k) const
  { return Vec4 (x*k, y*k, z*k, w*k); }


inline Vec2 Vec2::operator/ (Float k) const
  { return Vec2 (x/k, y/k); }

inline Vec3 Vec3::operator/ (Float k) const
  { return Vec3 (x/k, y/k, z/k); }

inline Vec4 Vec4::operator/ (Float k) const
  { return Vec4 (x/k, y/k, z/k, w/k); }


inline Float Vec2::norm () const
  { return SQRT (x*x + y*y); }

inline Float Vec3::norm () const
  { return SQRT (x*x + y*y + z*z); }

inline Float Vec4::norm () const
  { return SQRT (x*x + y*y + z*z + w*w); }


inline Float Vec2::normSq () const
  { return x*x + y*y; }

inline Float Vec3::normSq () const
  { return x*x + y*y + z*z; }

inline Float Vec4::normSq () const
  { return x*x + y*y + z*z + w*w; }


inline Vec2& Vec2::normalize ()
  { Float k=1.0f/norm(); x = k*x; y = k*y; return *this; }

inline Vec3& Vec3::normalize ()
  { Float k=1.0f/norm(); x = k*x; y = k*y; z = k*z; return *this; }

inline Vec4& Vec4::normalize ()
  { Float k=1.0f/norm(); x = k*x; y = k*y; z = k*z; w = k*w; return *this; }


inline Vec2& Vec2::offset (Float ox, Float oy)
  { x+=ox; y+=oy; return *this; }

inline Vec3& Vec3::offset (Float ox, Float oy, Float oz)
  { x+=ox; y+=oy; z+=oz; return *this; }

inline Vec4& Vec4::offset (Float ox, Float oy, Float oz, Float ow)
  { x+=ox; y+=oy; z+=oz; w+=ow; return *this; }


inline Vec2& Vec2::offsetV (const Vec2 &v, Float d)
  { Float K = d/v.norm(); x += v.x*K; y += v.y*K; return *this; }

inline Vec3& Vec3::offsetV (const Vec3 &v, Float d)
  { Float K = d/v.norm(); x += v.x*K; y += v.y*K; z += v.z*K; return *this; }

inline Vec4& Vec4::offsetV (const Vec4 &v, Float d)
  { Float K = d/v.norm(); x += v.x*K; y += v.y*K; z += v.z*K; w += v.w*K; return *this; }


inline Vec2& Vec2::offsetVN (const Vec2 &v, Float d)
  { x += v.x*d; y += v.y*d; return *this; }

inline Vec3& Vec3::offsetVN (const Vec3 &v, Float d)
  { x += v.x*d; y += v.y*d; z += v.z*d; return *this; }

inline Vec4& Vec4::offsetVN (const Vec4 &v, Float d)
  { x += v.x*d; y += v.y*d; z += v.z*d; w += v.w*d; return *this; }


inline Vec2 Vec2::reverse () const
  { return Vec2 (-x, -y); }

inline Vec3 Vec3::reverse () const
  { return Vec3 (-x, -y, -z); }

inline Vec4 Vec4::reverse () const
  { return Vec4 (-x, -y, -z, -w); }


inline Float Vec::Dot (const Vec2 &v1, const Vec2 &v2)
  { return v1.x*v2.x + v1.y*v2.y; }

inline Float Vec::Dot (const Vec3 &v1, const Vec3 &v2)
  { return v1.x*v2.x + v1.y*v2.y + v1.z*v2.z; }

inline Float Vec::Dot (const Vec4 &v1, const Vec4 &v2)
  { return v1.x*v2.x + v1.y*v2.y + v1.z*v2.z + v1.w*v2.w; }


inline Float Vec::Angle (const Vec2 &v1, const Vec2 &v2)
  { return ACOS (Vec::Dot (v1,v2) / (v1.norm() * v2.norm())); }

inline Float Vec::Angle (const Vec3 &v1, const Vec3 &v2)
  { return ACOS (Vec::Dot (v1,v2) / (v1.norm() * v2.norm())); }

inline Float Vec::Angle (const Vec4 &v1, const Vec4 &v2)
  { return ACOS (Vec::Dot (v1,v2) / (v1.norm() * v2.norm())); }


inline Float Vec::AngleN (const Vec2 &v1, const Vec2 &v2)
  { return ACOS (Vec::Dot (v1,v2)); }

inline Float Vec::AngleN (const Vec3 &v1, const Vec3 &v2)
  { return ACOS (Vec::Dot (v1,v2)); }

inline Float Vec::AngleN (const Vec4 &v1, const Vec4 &v2)
  { return ACOS (Vec::Dot (v1,v2)); }


inline Float Vec::Cross (const Vec2 &v1, const Vec2 &v2) {
  return v1.x*v2.y - v2.x*v1.y;
}

inline Vec3 Vec::Cross (const Vec3 &v1, const Vec3 &v2) {
  return Vec3 (v1.y*v2.z - v2.y*v1.z,
                  v2.x*v1.z - v1.x*v2.z,
                  v1.x*v2.y - v2.x*v1.y);
}

template <class V> inline V Vec::Lerp (const V &v1, const V &v2, Float t) {
  return v1 * (1.0f - t) + v2 * t;
}


inline Vec2 Vec::Floor (const Vec2 &v) {
  return Vec2( FLOOR(v.x), FLOOR(v.y) );
}

inline Vec3 Vec::Floor (const Vec3 &v) {
  return Vec3( FLOOR(v.x), FLOOR(v.y), FLOOR(v.z) );
}

inline Vec4 Vec::Floor (const Vec4 &v) {
  return Vec4( FLOOR(v.x), FLOOR(v.y), FLOOR(v.z), FLOOR(v.w) );
}


inline Vec2 Vec::Ceil (const Vec2 &v) {
  return Vec2( CEIL(v.x), CEIL(v.y) );
}

inline Vec3 Vec::Ceil (const Vec3 &v) {
  return Vec3( CEIL(v.x), CEIL(v.y), CEIL(v.z) );
}

inline Vec4 Vec::Ceil (const Vec4 &v) {
  return Vec4( CEIL(v.x), CEIL(v.y), CEIL(v.z), CEIL(v.w) );
}


inline Vec2 Vec::Fract (const Vec2 &v) {
  return Vec2( v.x - FLOOR(v.x), v.y - FLOOR(v.y) );
}

inline Vec3 Vec::Fract (const Vec3 &v) {
  return Vec3( v.x - FLOOR(v.x), v.y - FLOOR(v.y), v.z - FLOOR(v.z) );
}

inline Vec4 Vec::Fract (const Vec4 &v) {
  return Vec4( v.x - FLOOR(v.x), v.y - FLOOR(v.y), v.z - FLOOR(v.z), v.w - FLOOR(v.w) );
}


inline Vec2 Vec::Min (const Vec2 &v1, const Vec2 &v2) {
  return Vec2(
    v1.x < v2.x ? v1.x : v2.x,
    v1.y < v2.y ? v1.y : v2.y );
}

inline Vec3 Vec::Min (const Vec3 &v1, const Vec3 &v2) {
  return Vec3(
    v1.x < v2.x ? v1.x : v2.x,
    v1.y < v2.y ? v1.y : v2.y,
    v1.z < v2.z ? v1.z : v2.z );
}

inline Vec4 Vec::Min (const Vec4 &v1, const Vec4 &v2) {
  return Vec4(
    v1.x < v2.x ? v1.x : v2.x,
    v1.y < v2.y ? v1.y : v2.y,
    v1.z < v2.z ? v1.z : v2.z,
    v1.w < v2.w ? v1.w : v2.w );
}


inline Vec2 Vec::Max (const Vec2 &v1, const Vec2 &v2) {
  return Vec2(
    v1.x > v2.x ? v1.x : v2.x,
    v1.y > v2.y ? v1.y : v2.y );
}

inline Vec3 Vec::Max (const Vec3 &v1, const Vec3 &v2) {
  return Vec3(
    v1.x > v2.x ? v1.x : v2.x,
    v1.y > v2.y ? v1.y : v2.y,
    v1.z > v2.z ? v1.z : v2.z );
}

inline Vec4 Vec::Max (const Vec4 &v1, const Vec4 &v2) {
  return Vec4(
    v1.x > v2.x ? v1.x : v2.x,
    v1.y > v2.y ? v1.y : v2.y,
    v1.z > v2.z ? v1.z : v2.z,
    v1.w > v2.w ? v1.w : v2.w );
}

/*
=============================================
Quat inline functions
=============================================*/

inline Quat::Quat ()
  { x=0.0f; y=0.0f; z=0.0f; w=1.0f; }

inline Quat::Quat (Float xx, Float yy, Float zz, Float ww)
  { x=xx; y=yy; z=zz; w=ww; }

inline void Quat::set (Float xx, Float yy, Float zz, Float ww)
  { x=xx; y=yy; z=zz; w=ww; }

inline void Quat::setIdentity ()
  { x=0.0f; y=0.0f; z=0.0f; w=1.0f; }

inline Float Quat::norm () const
  { return SQRT (x*x + y*y + z*z + w*w); }

inline Float Quat::normSq () const
  { return x*x + y*y + z*z + w*w; }

inline Quat& Quat::normalize ()
  { Float n=norm(); x/=n; y/=n; z/=n; w/=n; return *this; }

inline Float Quat::Dot (const Quat &q1, const Quat &q2)
  { return q1.x*q2.x + q1.y*q2.y + q1.z*q2.z + q1.w*q2.w; }

inline bool Quat::operator== (const Quat &q) const
  { return x==q.x && y==q.y && z==q.z && w==q.w; }

inline bool Quat::operator!= (const Quat &q) const
  { return x!=q.x || y!=q.y || z!=q.z || w!=q.w; }

#endif//__RVGVECTORS_H

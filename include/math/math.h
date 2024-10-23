#pragma once

#include <util.h>

#pragma region vecs

typedef union _uvec2_ {
    double data[2];
    PP_ANON_STRUCT(
        PP_ANON_UNION(double x, r, s, u;);
        PP_ANON_UNION(double y, g, t, v;);
    );
} packed vec2;

typedef union _uvec3_ {
    double data[3];
    PP_ANON_STRUCT(
        PP_ANON_UNION(double x, r, s, u;);
        PP_ANON_UNION(double y, g, t, v;);
        PP_ANON_UNION(double z, b, p, q;);
    );
} packed vec3;

typedef union _uvec4_ {
    double data[4];
    PP_ANON_STRUCT(
        PP_ANON_UNION(double x, r, s, u;);
        PP_ANON_UNION(double y, g, t, v;);
        PP_ANON_UNION(double z, b, p, q;);
        PP_ANON_UNION(double w, a, o, n;);
    );
} packed vec4;

#define vec2_new(...) PP_OVERLOAD(___vec2_new_, __VA_ARGS__)

#define ___vec2_new_0()  (vec2){0.0f, 0.0f}
#define ___vec2_new_1(x) (vec2){x, 0.0f}
#define ___vec2_new_2(x, y) (vec2){x, y}

#define vec2_up()   vec2_new( 0, 1 )
#define vec2_down() vec2_new( 0,-1 )
#define vec2_left() vec2_new(-1, 0 )
#define vec2_right()vec2_new( 1, 0 )
#define vec2_mul_scalar(vec, scalar) (vec2){vec.x * scalar, vec.y * scalar};

#define vec2_add(x, y)  vec2_new( x.data[0] + y.data[0], x.data[1] + y.data[1] )
#define vec2_sub(x, y)  vec2_new( x.data[0] - y.data[0], x.data[1] - y.data[1] )
#define vec2_mul(x, y)  vec2_new( x.data[0] * y.data[0], x.data[1] * y.data[1] )
#define vec2_div(x, y)  vec2_new( x.data[0] / y.data[0], x.data[1] / y.data[1] )
  
#define vec3_new(...) PP_OVERLOAD(___vec3_new_, __VA_ARGS__)

#define ___vec3_new_0()  (vec3){0.0f, 0.0f, 0.0f}
#define ___vec3_new_1(x) (vec3){x, 0.0f, 0.0f}
#define ___vec3_new_2(x, y) (vec3){x, y, 0.0f}
#define ___vec3_new_3(x, y, z) (vec3){x, y, z}

#define vec3_up()   vec3_new( 0.0f, 1.0f, 0.0f)
#define vec3_down() vec3_new( 0.0f,-1.0f, 0.0f)
#define vec3_left() vec3_new(-1.0f, 0.0f, 0.0f)
#define vec3_right()vec3_new( 1.0f, 0.0f, 0.0f)
#define vec3_mul_scalar(vec, scalar) (vec3){vec.x * scalar, vec.y * scalar, vec.z * scalar};

#define vec3_add(x, y) vec3_new(x.data[0] + y.data[0], x.data[1] + y.data[1], x.data[2] + y.data[2])
#define vec3_mul(x, y) vec3_new(x.data[0] * y.data[0], x.data[1] * y.data[1], x.data[2] * y.data[2])
#define vec3_div(x, y) vec3_new(x.data[0] / y.data[0], x.data[1] / y.data[1], x.data[2] / y.data[2])

#define vec4_new(...) PP_OVERLOAD(___vec4_new_, __VA_ARGS__)

#define ___vec4_new_0()             (vec4){0.0f, 0.0f, 0.0f, 0.0f}
#define ___vec4_new_1(x)            (vec4){x, 0.0f, 0.0f, 0.0f}
#define ___vec4_new_2(x, y)         (vec4){x, y, 0.0f, 0.0f}
#define ___vec4_new_3(x, y, z)      (vec4){x, y, z, 0.0f}
#define ___vec4_new_4(x, y, z, w)   (vec4){x, y, z, w}

#define vec4_up()    vec4_new( 0.0f, 1.0f)
#define vec4_down()  vec4_new( 0.0f,-1.0f)
#define vec4_left()  vec4_new(-1.0f, 0.0f)
#define vec4_right() vec4_new( 1.0f, 0.0f)
#define vec4_mul_scalar(vec, scalar) vec4_new(vec.x * scalar, vec.y * scalar, vec.z * scalar, vec.w * scalar);

#define vec4_add(x, y) vec4_new(x.data[0] + y.data[0], x.data[1] + y.data[1], x.data[2] + y.data[2], x.data[3] + y.data[3])
#define vec4_sub(x, y) vec4_new(x.data[0] - y.data[0], x.data[1] - y.data[1], x.data[2] - y.data[2], x.data[3] - y.data[3])
#define vec4_mul(x, y) vec4_new(x.data[0] * y.data[0], x.data[1] * y.data[1], x.data[2] * y.data[2], x.data[3] * y.data[3])
#define vec4_div(x, y) vec4_new(x.data[0] / y.data[0], x.data[1] / y.data[1], x.data[2] / y.data[2], x.data[3] / y.data[3])

#pragma endregion vecs

#pragma region mats

#define CREATE_MAT(dim) typedef union _umat##dim##_ {\
    double data[dim*dim]; \
} mat##dim;

CREATE_MAT(2);
CREATE_MAT(3);
CREATE_MAT(4);

#undef CREATE_MAT

#define mat2_new(...) PP_OVERLOAD(___mat2_new_, __VA_ARGS__)
#define ___mat2_new_0(...) (mat2){0.0f}
#define ___mat2_new_2(val1, val2) (mat2){{val1, val2, val1, val2}}
#define ___mat2_new_4(val1, val2, val3, val4) (mat2){{val1, val2, val3, val4}}

#define mat2_add(_matrix_1_, _matrix_2_) (mat2){\
    {\
    _matrix_1_.data[0] + _matrix_2_.data[0],\
    _matrix_1_.data[1] + _matrix_2_.data[1],\
    _matrix_1_.data[2] + _matrix_2_.data[2],\
    _matrix_1_.data[3] + _matrix_2_.data[3] \
    }\
}

#define mat2_add(_matrix_1_, _matrix_2_) (mat2){\
    {\
    _matrix_1_.data[0] - _matrix_2_.data[0],\
    _matrix_1_.data[1] - _matrix_2_.data[1],\
    _matrix_1_.data[2] - _matrix_2_.data[2],\
    _matrix_1_.data[3] - _matrix_2_.data[3] \
    }\
}

#define mat2_mul(_matrix_1_, _matrix_2_) (mat2) {\
    {\
    _matrix_1_.data[0]    
    }\
}
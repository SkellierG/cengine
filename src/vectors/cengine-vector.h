#ifndef CENGINE_VECTORS_H
#define CENGINE_VECTORS_H

#include "cengine-ivec.h"
#include "cengine-vec2.h"
#include "cengine-vec3.h"
#include "cengine-vec4.h"

//cengine-vector.h
GObject* cengine_vector_new_from_array(const gdouble *values, guint size);
void cengine_vector_print(GObject *vector);

//cengine-vec2.h
CengineVec2* cengine_vec2_new(gdouble x, gdouble y);

gdouble cengine_vec2_get_x(CengineVec2 *self);
void cengine_vec2_set_x(CengineVec2 *self, gdouble value);
gdouble cengine_vec2_get_y(CengineVec2 *self);
void cengine_vec2_set_y(CengineVec2 *self, gdouble value);

void cengine_vec2_reset(CengineVec2 *self);
void cengine_vec2_swap(CengineVec2 *self);

GArray* cengine_vec2_get_values(CengineVec2 *self);
CengineVec2* cengine_vec2_to_vec2(CengineVec2 *self);
CengineVec3* cengine_vec2_to_vec3(CengineVec2 *self);
CengineVec4* cengine_vec2_to_vec4(CengineVec2 *self);

//cengine-vec3.h
CengineVec3* cengine_vec3_new(gdouble x, gdouble y, gdouble z);

gdouble cengine_vec3_get_x(CengineVec3 *self);
void cengine_vec3_set_x(CengineVec3 *self, gdouble value);
gdouble cengine_vec3_get_y(CengineVec3 *self);
void cengine_vec3_set_y(CengineVec3 *self, gdouble value);
gdouble cengine_vec3_get_z(CengineVec3 *self);
void cengine_vec3_set_z(CengineVec3 *self, gdouble value);

void cengine_vec3_reset(CengineVec3 *self);
void cengine_vec3_swap(CengineVec3 *self);

GArray* cengine_vec3_get_values(CengineVec3 *self);
CengineVec2* cengine_vec3_to_vec2(CengineVec3 *self);
CengineVec3* cengine_vec3_to_vec3(CengineVec3 *self);
CengineVec4* cengine_vec3_to_vec4(CengineVec3 *self);

//cengine-vec4.h
CengineVec4* cengine_vec4_new(gdouble x, gdouble y, gdouble z, gdouble w);

gdouble cengine_vec4_get_x(CengineVec4 *self);
void cengine_vec4_set_x(CengineVec4 *self, gdouble value);
gdouble cengine_vec4_get_y(CengineVec4 *self);
void cengine_vec4_set_y(CengineVec4 *self, gdouble value);
gdouble cengine_vec4_get_z(CengineVec4 *self);
void cengine_vec4_set_z(CengineVec4 *self, gdouble value);
gdouble cengine_vec4_get_w(CengineVec4 *self);
void cengine_vec4_set_w(CengineVec4 *self, gdouble value);

void cengine_vec4_reset(CengineVec4 *self);
void cengine_vec4_swap(CengineVec4 *self);

GArray* cengine_vec4_get_values(CengineVec4 *self);
CengineVec2* cengine_vec4_to_vec2(CengineVec4 *self);
CengineVec3* cengine_vec4_to_vec3(CengineVec4 *self);
CengineVec4* cengine_vec4_to_vec4(CengineVec4 *self);

#endif

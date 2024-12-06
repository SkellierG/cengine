#ifndef CENGINE_VEC4_H
#define CENGINE_VEC4_H

#include "cengine-ivec.h"

#define CENGINE_TYPE_VEC4 (cengine_vec4_get_type())
G_DECLARE_FINAL_TYPE(CengineVec4, cengine_vec4, CENGINE, VEC4, GObject)

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


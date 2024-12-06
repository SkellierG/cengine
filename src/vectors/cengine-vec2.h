#ifndef CENGINE_VEC2_H
#define CENGINE_VEC2_H

#include "cengine-ivec.h"

#define CENGINE_TYPE_VEC2 (cengine_vec2_get_type())
G_DECLARE_FINAL_TYPE(CengineVec2, cengine_vec2, CENGINE, VEC2, GObject)

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

#endif


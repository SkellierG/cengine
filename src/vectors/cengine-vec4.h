#ifndef CENGINE_VEC4_H
#define CENGINE_VEC4_H

#include <glib-object.h>
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

#endif

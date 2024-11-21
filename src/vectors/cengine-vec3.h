#ifndef CENGINE_VEC3_H
#define CENGINE_VEC3_H

#include <glib-object.h>
#include "cengine-ivec.h"

#define CENGINE_TYPE_VEC3 (cengine_vec3_get_type())
G_DECLARE_FINAL_TYPE(CengineVec3, cengine_vec3, CENGINE, VEC3, GObject)

CengineVec3* cengine_vec3_new(gdouble x, gdouble y, gdouble z);
gdouble cengine_vec3_get_x(CengineVec3 *self);
void cengine_vec3_set_x(CengineVec3 *self, gdouble value);
gdouble cengine_vec3_get_y(CengineVec3 *self);
void cengine_vec3_set_y(CengineVec3 *self, gdouble value);
gdouble cengine_vec3_get_z(CengineVec3 *self);
void cengine_vec3_set_z(CengineVec3 *self, gdouble value);

#endif

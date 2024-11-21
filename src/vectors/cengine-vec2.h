#ifndef CENGINE_VEC2_H
#define CENGINE_VEC2_H

#include <glib-object.h>
#include "cengine-ivec.h"

#define CENGINE_TYPE_VEC2 (cengine_vec2_get_type())
G_DECLARE_FINAL_TYPE(CengineVec2, cengine_vec2, CENGINE, VEC2, GObject)

CengineVec2* cengine_vec2_new(gdouble x, gdouble y);
gdouble cengine_vec2_get_x(CengineVec2 *self);
void cengine_vec2_set_x(CengineVec2 *self, gdouble value);
gdouble cengine_vec2_get_y(CengineVec2 *self);
void cengine_vec2_set_y(CengineVec2 *self, gdouble value);

#endif


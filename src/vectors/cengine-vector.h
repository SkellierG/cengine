#ifndef CENGINE_VECTORS_H
#define CENGINE_VECTORS_H

#include <glib-2.0/glib-object.h>

#include "cengine-ivec.h"
#include "cengine-vec2.h"
#include "cengine-vec3.h"
#include "cengine-vec4.h"

GObject* cengine_vector_new_from_array(const gdouble *values, guint size);
void cengine_vector_print(GObject *vector);

#endif

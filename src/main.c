#include <glib-2.0/glib.h>
#include <gtk/gtk.h>
#include "vectors/cengine-vector.h"

int main(int argc, char *argv[]) {
    GtkWidget *window;

    gtk_init(&argc, &argv);
    
    gdouble x = 0.5;
    gdouble y = 8.1;
    gdouble z = 1.1;
    gdouble w = 1.2;
    
    CengineVec4 *vector4_test = cengine_vec4_new(x,y,z,w);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "GTK3 Test");
    gtk_window_set_default_size(GTK_WINDOW(window), 200, 200);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    
    cengine_vector_print((GObject *)vector4_test);

    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}


#include <gtk/gtk.h>

static void display() {
	g_print("Login Screen\n");
}

static void display(GtkApplication *a, gpointer u_dat) {
	GtkWidget *window;
	GtkWidget *button;
	GtkWidget *button_box;
	
	window = gtk_application_window_new(a);
	gtk_window_set_title (GTK_WINDOW(window), "Login Screen\n");
	gtk_window_set_default_size (GTK_WINDOW(window), 400, 400);
	
	button_box = gtk_button_box_new (GTK_ORIENTATION_HORIZONTAL);
    gtk_container_add (GTK_CONTAINER (window), button_box);
    
    button = gtk_button_new_with_label ("Login Screen\n");
    g_signal_connect (button, "clicked", G_CALLBACK (display), NULL);
    g_signal_connect_swapped (button, "clicked", G_CALLBACK (gtk_widget_destroy), window);
    gtk_container_add (GTK_CONTAINER (button_box), button);
    
    gtk_widget_show_all (window);
}

int main(int argc, char **argv) {
	GtkApplication *a;
	int retval;
	a = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);
    g_signal_connect (a, "activate", G_CALLBACK (display), NULL);
    retval = g_application_run (G_APPLICATION (a), argc, argv);
    g_object_unref (a);
	return 0;
}

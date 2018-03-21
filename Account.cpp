#include <gtk/gtk.h>

static void disp() {
	//g_print("Login Screen?\n");
}

static void on_click_login(GtkButton *button,gpointer dat) {
	
}

static void display(GtkApplication *a, gpointer u_dat) {
	GtkWidget *window;
	GtkWidget *button;
	GtkWidget *button_box;
	GtkWidget *logbox;
	GtkWidget *newbox;
	
	window = gtk_application_window_new(a);
	gtk_window_set_title (GTK_WINDOW(window), "Login Screen\n");
	gtk_window_set_default_size (GTK_WINDOW(window), 400, 400);
	
	button_box = gtk_button_box_new (GTK_ORIENTATION_HORIZONTAL);
    gtk_container_add (GTK_CONTAINER (window), button_box);
    
    newbox=gtk_box_new(GTK_ORIENTATION_HORIZONTAL,5);
    gtk_container_add(GTK_CONTAINER(window),newbox);

    logbox=gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(newbox),logbox,TRUE,TRUE,5);
    
    button = gtk_button_new_with_label ("Enter Username\n");
    g_signal_connect (button, "clicked", G_CALLBACK (on_click_logic), logbox);
    //g_signal_connect_(button, "clicked", G_CALLBACK (gtk_widget_destroy), window);
    //on_click_login(button, u_dat);
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

#include "widgets.h"

void initializeWidgets(){
	
	
	GtkBuilder* builder = gtk_builder_new();
	
	GError* buildError = NULL;
	if(!gtk_builder_add_from_file(builder, "vista.glade", &buildError)){
		g_printerr("Error loading glade file %s\n", buildError->message);
		g_error_free(buildError);
		return;
		
	}
	
	GtkWidget *window = GTK_WIDGET(gtk_builder_get_object(builder, "vistaPrincipal"));
		GtkWidget *box_v1 = GTK_WIDGET(gtk_builder_get_object(builder, "box_v1"));
				GtkWidget *label_v1 = GTK_WIDGET(gtk_builder_get_object(builder, "label_v1"));
				GtkWidget *file_v1 = GTK_WIDGET(gtk_builder_get_object(builder, "filechooser_v1"));
				GtkWidget *button_v1 = GTK_WIDGET(gtk_builder_get_object(builder, "button_v1"));

	GtkWidget *window2 = GTK_WIDGET(gtk_builder_get_object(builder, "vistaSecundaria"));
		GtkWidget *box_v2 = GTK_WIDGET(gtk_builder_get_object(builder, "box_v2"));
				GtkWidget *label_v2 = GTK_WIDGET(gtk_builder_get_object(builder, "label_v2"));
				GtkWidget *button_v2 = GTK_WIDGET(gtk_builder_get_object(builder, "button_v2"));

}
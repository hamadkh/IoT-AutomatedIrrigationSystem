#include <gtk/gtk.h>
#include <stdlib.h>

GtkWidget *g_lbl_hello;
GtkWidget *btn_START;
GtkWidget *btn_STOP;

int ran = 0;

int main(int argc, char *argv[])
{
    GtkBuilder      *builder; 
    GtkWidget       *window;


    gtk_init(&argc, &argv);

    builder = gtk_builder_new();
    
 
    
    gtk_builder_add_from_file (builder, "glade/window_main.glade", NULL);

    window = GTK_WIDGET(gtk_builder_get_object(builder, "window_main"));
    gtk_builder_connect_signals(builder, NULL);
    
    g_lbl_hello = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_hello"));

    g_object_unref(builder);

    gtk_widget_show(window);                
    gtk_main();

    return 0;
}

void on_btn_START_clicked()
{	
	
	gtk_label_set_text(GTK_LABEL(g_lbl_hello), "ON");
	if(ran == 0)
	{
		//ran = system("./myprog");
		//printf("%d\n", ran);
		//ran = 1;
		//printf("%d\n", ran);
	}
	
}

void on_btn_STOP_clicked()
{
    gtk_label_set_text(GTK_LABEL(g_lbl_hello), "OFF");
    //ran = 0;
}

// called when window is closed
void on_window_main_destroy()
{
    gtk_main_quit();
}
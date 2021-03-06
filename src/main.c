/* sudo apt-get install build-essential libgtk2.0-dev */

#include <gtk/gtk.h>

//Different Newline for Windows
#if defined(_WIN32)
#define LINEBREAK "\r\n"
#else
#define LINEBREAK "\n"
#endif

int main(int argc, char *argv[])
{
	printf("Starting FreeNote with %d parameters."LINEBREAK, argc);

    GtkBuilder      *builder; 
    GtkWidget       *window;

    gtk_init(&argc, &argv);

    builder = gtk_builder_new_from_file("glade/FreeNote.glade");

    window = GTK_WIDGET(gtk_builder_get_object(builder, "MainWindow"));
    gtk_builder_connect_signals(builder, NULL);

    g_object_unref(builder);

    gtk_widget_show(window);
    gtk_main();

    return 0;
}

// called when window is closed
G_MODULE_EXPORT 
void on_MainWindow_destroy()
{
	printf("User requested to exit program."LINEBREAK);
    gtk_main_quit();
}
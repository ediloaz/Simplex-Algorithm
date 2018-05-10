#ifndef INTERFAZ_H
#define INTERFAZ_H

#include <string.h>
#include <gtk/gtk.h>
#include <stdbool.h>



GtkBuilder  *builder; 
GtkWidget   *window;

GtkWidget   *entry_nombre_problema;
GtkWidget   *entry_nombre_variables;
GtkWidget   *entry_funcion_objetivo;
GtkWidget   *radiobutton_max;

GtkWidget   *entry_rest1;
GtkWidget   *entry_rest2;
GtkWidget   *entry_rest3;
GtkWidget   *entry_rest4;
GtkWidget   *entry_rest5;
GtkWidget   *entry_rest6;
GtkWidget   *entry_rest7;
GtkWidget   *entry_rest8;
GtkWidget   *entry_rest9;
GtkWidget   *entry_rest10;
GtkWidget   *entry_eq1;
GtkWidget   *entry_eq2;
GtkWidget   *entry_eq3;
GtkWidget   *entry_eq4;
GtkWidget   *entry_eq5;
GtkWidget   *entry_eq6;
GtkWidget   *entry_eq7;
GtkWidget   *entry_eq8;
GtkWidget   *entry_eq9;
GtkWidget   *entry_eq10;
GtkWidget   *combobox1;
GtkWidget   *combobox2;
GtkWidget   *combobox3;
GtkWidget   *combobox4;
GtkWidget   *combobox5;
GtkWidget   *combobox6;
GtkWidget   *combobox7;
GtkWidget   *combobox8;
GtkWidget   *combobox9;
GtkWidget   *combobox10;

GtkWidget   *switch_tablas_intermedias;
GtkWidget   *button_ejecutar;

int IniciarInterfaz(int argc, char *argv[])
{
    gtk_init(&argc, &argv);
    builder = gtk_builder_new();

    if( gtk_builder_add_from_file (builder,"interface.glade" , NULL) == 0){
         printf("No se pudo cargar el archivo GLADE\n");
         return(0);
    } 
    
    // Traigo los objetos/widgets de la interfaz Glade
    window = GTK_WIDGET(gtk_builder_get_object(builder, "interface"));
    entry_nombre_problema  = GTK_WIDGET(gtk_builder_get_object(builder, "entry_nombre_problema"));
    entry_nombre_variables = GTK_WIDGET(gtk_builder_get_object(builder, "entry_nombre_variables"));
    entry_funcion_objetivo = GTK_WIDGET(gtk_builder_get_object(builder, "entry_funcion_objetivo"));
    entry_rest1 = GTK_WIDGET(gtk_builder_get_object(builder, "entry_rest1"));
    entry_rest2 = GTK_WIDGET(gtk_builder_get_object(builder, "entry_rest2"));
    entry_rest3 = GTK_WIDGET(gtk_builder_get_object(builder, "entry_rest3"));
    entry_rest4 = GTK_WIDGET(gtk_builder_get_object(builder, "entry_rest4"));
    entry_rest5 = GTK_WIDGET(gtk_builder_get_object(builder, "entry_rest5"));
    entry_rest6 = GTK_WIDGET(gtk_builder_get_object(builder, "entry_rest6"));
    entry_rest7 = GTK_WIDGET(gtk_builder_get_object(builder, "entry_rest7"));
    entry_rest8 = GTK_WIDGET(gtk_builder_get_object(builder, "entry_rest8"));
    entry_rest9 = GTK_WIDGET(gtk_builder_get_object(builder, "entry_rest9"));
    entry_rest10= GTK_WIDGET(gtk_builder_get_object(builder, "entry_rest10"));
    entry_eq1 = GTK_WIDGET(gtk_builder_get_object(builder, "entry_eq1"));
    entry_eq2 = GTK_WIDGET(gtk_builder_get_object(builder, "entry_eq2"));
    entry_eq3 = GTK_WIDGET(gtk_builder_get_object(builder, "entry_eq3"));
    entry_eq4 = GTK_WIDGET(gtk_builder_get_object(builder, "entry_eq4"));
    entry_eq5 = GTK_WIDGET(gtk_builder_get_object(builder, "entry_eq5"));
    entry_eq6 = GTK_WIDGET(gtk_builder_get_object(builder, "entry_eq6"));
    entry_eq7 = GTK_WIDGET(gtk_builder_get_object(builder, "entry_eq7"));
    entry_eq8 = GTK_WIDGET(gtk_builder_get_object(builder, "entry_eq8"));
    entry_eq9 = GTK_WIDGET(gtk_builder_get_object(builder, "entry_eq9"));
    entry_eq10= GTK_WIDGET(gtk_builder_get_object(builder, "entry_eq10"));
    gtk_builder_connect_signals(builder, NULL);
 
    g_object_unref(builder);
 
    gtk_widget_show(window);                
    gtk_main();
 
    return 0;   
}
 

void on_window_main_destroy(){
    gtk_main_quit();
}


bool FormatoCorrectoNombrePrograma(char *texto){
    printf("Nombre del programa: \"%s\" \n", texto);
    return true;
}

bool FormatoCorrectoNombreVariables(char *texto){
    printf("Nombres de las variables: \"%s\"  \n", texto);
    return true;
}
bool FormatoCorrectoFuncionObjetivo(char *texto){
    printf("Función objetivo: \"%s\" \n", texto);
    return true;
}

bool FormatoCorrectoRestriccion(char *texto_resticcion, char *texto_equal){
    printf("Restriccion: \"%s\" | Comparada a: \"%s\" \n", texto_resticcion ,texto_equal);
    return true;
}




void AccionEjecutar(){
    printf("Se presionó el botón de ejecutar \n");

    // Inicializar todas las variables
    const gchar *g_texto_nombre_problema;
    const gchar *g_texto_nombre_variables;
    const gchar *g_texto_funcion_objetivo;
    int id_radiobutton;
    const gchar *g_texto_rest1;
    const gchar *g_texto_rest2;
    const gchar *g_texto_rest3;
    const gchar *g_texto_rest4;
    const gchar *g_texto_rest5;
    const gchar *g_texto_rest6;
    const gchar *g_texto_rest7;
    const gchar *g_texto_rest8;
    const gchar *g_texto_rest9;
    const gchar *g_texto_rest10;
    const gchar *g_texto_eq1;
    const gchar *g_texto_eq2;
    const gchar *g_texto_eq3;
    const gchar *g_texto_eq4;
    const gchar *g_texto_eq5;
    const gchar *g_texto_eq6;
    const gchar *g_texto_eq7;
    const gchar *g_texto_eq8;
    const gchar *g_texto_eq9;
    const gchar *g_texto_eq10;
    char texto_nombre_problema[100];
    char texto_nombre_variables[100];
    char texto_funcion_objetivo[100];
    char texto_rest1[100];
    char texto_rest2[100];
    char texto_rest3[100];
    char texto_rest4[100];
    char texto_rest5[100];
    char texto_rest6[100];
    char texto_rest7[100];
    char texto_rest8[100];
    char texto_rest9[100];
    char texto_rest10[100];
    char texto_eq1[100];
    char texto_eq2[100];
    char texto_eq3[100];
    char texto_eq4[100];
    char texto_eq5[100];
    char texto_eq6[100];
    char texto_eq7[100];
    char texto_eq8[100];
    char texto_eq9[100];
    char texto_eq10[100];

    // Coger todos los datos de la interfaz y convertirlo a un formato manejable propio de C (ej.: gchar -> char)
    g_texto_nombre_problema = gtk_entry_get_text(GTK_ENTRY(entry_nombre_problema));
    g_texto_nombre_variables = gtk_entry_get_text(GTK_ENTRY(entry_nombre_variables));
    g_texto_funcion_objetivo = gtk_entry_get_text(GTK_ENTRY(entry_funcion_objetivo));
    g_texto_rest1 = gtk_entry_get_text(GTK_ENTRY(entry_rest1));
    g_texto_rest2 = gtk_entry_get_text(GTK_ENTRY(entry_rest2));
    g_texto_rest3 = gtk_entry_get_text(GTK_ENTRY(entry_rest3));
    g_texto_rest4 = gtk_entry_get_text(GTK_ENTRY(entry_rest4));
    g_texto_rest5 = gtk_entry_get_text(GTK_ENTRY(entry_rest5));
    g_texto_rest6 = gtk_entry_get_text(GTK_ENTRY(entry_rest6));
    g_texto_rest7 = gtk_entry_get_text(GTK_ENTRY(entry_rest7));
    g_texto_rest8 = gtk_entry_get_text(GTK_ENTRY(entry_rest8));
    g_texto_rest9 = gtk_entry_get_text(GTK_ENTRY(entry_rest9));
    g_texto_rest10 = gtk_entry_get_text(GTK_ENTRY(entry_rest10));
    g_texto_eq1 = gtk_entry_get_text(GTK_ENTRY(entry_eq1));
    g_texto_eq2 = gtk_entry_get_text(GTK_ENTRY(entry_eq2));
    g_texto_eq3 = gtk_entry_get_text(GTK_ENTRY(entry_eq3));
    g_texto_eq4 = gtk_entry_get_text(GTK_ENTRY(entry_eq4));
    g_texto_eq5 = gtk_entry_get_text(GTK_ENTRY(entry_eq5));
    g_texto_eq6 = gtk_entry_get_text(GTK_ENTRY(entry_eq6));
    g_texto_eq7 = gtk_entry_get_text(GTK_ENTRY(entry_eq7));
    g_texto_eq8 = gtk_entry_get_text(GTK_ENTRY(entry_eq8));
    g_texto_eq9 = gtk_entry_get_text(GTK_ENTRY(entry_eq9));
    g_texto_eq10 = gtk_entry_get_text(GTK_ENTRY(entry_eq10));
    sprintf(texto_nombre_problema,  "%8s\n", g_texto_nombre_problema);
    sprintf(texto_nombre_variables, "%8s\n", g_texto_nombre_variables);
    sprintf(texto_funcion_objetivo, "%8s\n", g_texto_funcion_objetivo);
    sprintf(texto_rest1, "%8s\n", g_texto_rest1);
    sprintf(texto_rest2, "%8s\n", g_texto_rest2);
    sprintf(texto_rest3, "%8s\n", g_texto_rest3);
    sprintf(texto_rest4, "%8s\n", g_texto_rest4);
    sprintf(texto_rest5, "%8s\n", g_texto_rest5);
    sprintf(texto_rest6, "%8s\n", g_texto_rest6);
    sprintf(texto_rest7, "%8s\n", g_texto_rest7);
    sprintf(texto_rest8, "%8s\n", g_texto_rest8);
    sprintf(texto_rest9, "%8s\n", g_texto_rest9);
    sprintf(texto_rest10,"%8s\n", g_texto_rest10);
    sprintf(texto_eq1, "%8s\n", g_texto_eq1);
    sprintf(texto_eq2, "%8s\n", g_texto_eq2);
    sprintf(texto_eq3, "%8s\n", g_texto_eq3);
    sprintf(texto_eq4, "%8s\n", g_texto_eq4);
    sprintf(texto_eq5, "%8s\n", g_texto_eq5);
    sprintf(texto_eq6, "%8s\n", g_texto_eq6);
    sprintf(texto_eq7, "%8s\n", g_texto_eq7);
    sprintf(texto_eq8, "%8s\n", g_texto_eq8);
    sprintf(texto_eq9, "%8s\n", g_texto_eq9);
    sprintf(texto_eq10,"%8s\n", g_texto_eq10);
 
    // Revisar formato de las variables
    FormatoCorrectoNombrePrograma(texto_nombre_problema);
    FormatoCorrectoNombreVariables(texto_nombre_variables);
    FormatoCorrectoFuncionObjetivo(texto_funcion_objetivo);
    FormatoCorrectoRestriccion(texto_rest1, texto_eq1);
    FormatoCorrectoRestriccion(texto_rest2, texto_eq2);
    FormatoCorrectoRestriccion(texto_rest3, texto_eq3);
    FormatoCorrectoRestriccion(texto_rest4, texto_eq4);
    FormatoCorrectoRestriccion(texto_rest5, texto_eq5);
    FormatoCorrectoRestriccion(texto_rest6, texto_eq6);
    FormatoCorrectoRestriccion(texto_rest7, texto_eq7);
    FormatoCorrectoRestriccion(texto_rest8, texto_eq8);
    FormatoCorrectoRestriccion(texto_rest9, texto_eq9);

    // Convertir al formato adecuado para el ALGORITMO SIMPLEX

    // Llamar la función del ALGORITMO SIMPLEX

}


#endif /* INTERFAZ_H */


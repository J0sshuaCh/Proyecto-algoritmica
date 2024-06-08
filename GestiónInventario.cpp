#include <iostream>
#include <fstream>
#include <iomanip>
#include <conio.h>
#include <cstring>
#include <string.h>
#include <cstdlib>
#include <locale.h>
using namespace std;

struct inventario {
    char nombre[30];
    bool remanente = false;
    float cantidad, precio, precioFinal;
};

void guardarDatos (inventario objetos[],int dimension, int ultimoArticulo, int cantidadArt){
    ofstream archivo ("datos_inventario.txt");
    if (archivo.is_open()){
        archivo << cantidadArt << " "<< ultimoArticulo<<endl;
        for (int i = 0; i<dimension; ++i){
            archivo<<objetos[i].nombre<< " "<<objetos[i].cantidad<<" "<<objetos[i].precio<<" "<<objetos[i].precioFinal<<endl;
        }
        archivo.close();
    }else{
        cout<<"No se pudo abrir el archivo para guardar los datos."<<endl;
    }
}
void eliminarArticulo (inventario objetos[], int& dimension, int& ultimoArticulo){
    system ("cls");
    cin.ignore();
    int aux;
    char nombreBuscar[30];
    bool encontrado = false;

    cout<<"Ingrese el nombre del artículo que desea eliminar :";
    cin.getline(nombreBuscar, 30, '\n');

    for (int i = 0; i <dimension; ++i){
        if(strcmp(objetos[i].nombre, nombreBuscar) == 0){
            aux = i;
            encontrado = true;
            break;
        }
    }

    if (encontrado = true){
        for (int i = aux; i<dimension; ++i){
            strcpy(objetos[i].nombre, objetos[i+1].nombre);
            objetos[i].precio = objetos[i+1].precio;
            objetos[i].cantidad = objetos[i+1].cantidad;
        }
        ultimoArticulo = ultimoArticulo - 1;
        dimension = dimension - 1;
        cout<<"Objeto : "<<nombreBuscar<<" eliminado correctamente";
    }else{
        cout<<"Objeto : "<<nombreBuscar<<" no se encontró dentro del inventario.";
    }
    getch();
}

void modificarArticulo(inventario objetos[], int dimension) {
    system("cls");
    cin.ignore();
    char nombreBuscar[30];
    bool encontrado = false;

    cout << "Ingrese el nombre del artículo que desea modificar: ";
    cin.getline(nombreBuscar, 30, '\n');

    for (int i = 0; i < dimension; ++i) {
        if (strcmp(objetos[i].nombre, nombreBuscar) == 0) {
            cout << "Artículo encontrado. Ingrese los nuevos datos:\n";
            cout << "Nuevo nombre: ";
            cin.getline(objetos[i].nombre, 30, '\n');
            cout << "Nueva cantidad: ";
            cin >> objetos[i].cantidad;
            cout << "Nuevo precio unitario: ";
            cin >> objetos[i].precio;
            objetos[i].precioFinal = objetos[i].cantidad * objetos[i].precio;
            cin.ignore();
            encontrado = true;
            break;
        }
    }
}

void modificarCant(inventario objeto[], int cantidaadArt){
    system("cls");
    cin.ignore();
    char busqueda[30];
    double cantidad;
    bool encontrado = false;

    cout<<"Ingrese el nombre del artículo que desea modificar: ";
    cin.getline(busqueda,30, '\n');

    for (int i = 0; i<cantidaadArt; ++i){
        if(strcmp(objeto[i].nombre, busqueda) == 0){
            cout<<"Articulo encontrado!"<<endl<<"Ingrese la cantidad usada: ";
            cin>>cantidad;
            objeto[i].cantidad = objeto[i].cantidad - cantidad;
            cin.ignore();
            encontrado = true;
            break;
        }
    }
    if (encontrado = false){
        cout<<"No se encontró ningún articulo";
    }
}
void agregarArticulo(inventario objeto1[], int& cantidadArt, int& ultimoArticulo){
system("cls");
cin.ignore();
char remanente;
char terminar = 'Y';
while(terminar == 'Y' || terminar == 'y'){
    cout<<"Ingrese el nombre del objeto "<<ultimoArticulo+1<<endl;
    cin.getline(objeto1[ultimoArticulo].nombre,30,'\n');
    cout<<endl<<"Ingrese la cantidad del objeto "<<"\""<<objeto1[ultimoArticulo].nombre<<"\" :";
    cin>>objeto1[ultimoArticulo].cantidad;
/*    do{
        cout<<endl<<"¿El objeto puede dejar residuo? Y/N"<<endl;
        cin>>remanente;
        if (remanente == 'y' || remanente == 'Y'){
            objeto1[ultimoArticulo].remanente = true;
        }else if(remanente == 'n' || remanente == 'N'){
            objeto1[ultimoArticulo].remanente = false;
        }else{
            cout<<"Ingrese una de las dos opciones";
        }
*/
    }while(remanente!= 'Y' && remanente !='y' && remanente!='n' && remanente!= 'N');
    cout<<endl<<"Ingrese el precio unitario del objeto "<<"\""<<objeto1[ultimoArticulo].nombre<<"\" :";
    cin>>objeto1[ultimoArticulo].precio;
    objeto1[ultimoArticulo].precioFinal = objeto1[ultimoArticulo].precio*objeto1[ultimoArticulo].cantidad;
    cantidadArt = cantidadArt + 1;
    ultimoArticulo = ultimoArticulo+1;
    cin.ignore();
    cout<<"Pasar al siguiente articulo Y/N"<<endl;
    cin>>terminar;
    cin.ignore();
}
return;
}
void mostrarInventario (inventario objetos[], int dimension ){
    cout << left << setw(30) << "Nombre"
        << setw(10) << "Cantidad"
        << setw(10) << "Precio"
        << setw(15) << "Precio Final" << endl;

    for (int i = 0; i < dimension; ++i) {
        cout << left << setw(30) << objetos[i].nombre
            << setw(10) << objetos[i].cantidad
            << setw(10) << objetos[i].precio
            << setw(15) << objetos[i].precio * objetos[i].cantidad << endl;
    }
    getch();

}

void cargarDatos (inventario datos[], int& dimension, int& ultimoArticulo, int& cantidadArt){
    ifstream archivo("datos_inventario.txt");
    if (archivo.is_open()){
        archivo>> cantidadArt >> ultimoArticulo;
        dimension = 50;
        for (int i = 0; i<dimension; ++i){
            archivo>> datos[i].nombre >> datos[i].cantidad>> datos[i].precio >> datos[i].precioFinal;
        }
        archivo.close();
    }else {
    cout<<"No se pudo abrir el archivo para cargar los datos. Se iniciaran con los valores predeterminados"<<endl;
    dimension = 50;
    ultimoArticulo = 0;
    cantidadArt = 0;
    }
}
int main(){
    setlocale(LC_ALL, "spanish");
    inventario objetos[50];
    int cantidadArt = 0;
    int ultimoArticulo = 0;
    int dimension = 50;
    int menu;
    cargarDatos(objetos,dimension,ultimoArticulo,cantidadArt);
    while (true){
        guardarDatos(objetos,dimension,ultimoArticulo,cantidadArt);
        cout<<"Bienvenido al inventario!"<<endl<<"Escoja su opción"<<endl;
        cout<<"1. Agregar articulos"<<endl<<"2. Mostrar inventario"<<endl<<"3. Modificar Articulo"<<endl<<"4. Eliminar articulo"<<endl<<"5. Modificar cantidad de articulo"<<endl<<"6. Gestionar remantentes"<<endl<<"0. Volver al menú principal"<<endl;
        cin>>menu;
        switch (menu){
            case 1: agregarArticulo(objetos,cantidadArt, ultimoArticulo);
                    break;
            case 2: mostrarInventario(objetos, cantidadArt);
                    break;
            case 3: modificarArticulo(objetos,cantidadArt);
                    break;
            case 4: eliminarArticulo(objetos, cantidadArt, ultimoArticulo);
                    break;
            case 5: modificarCant(objetos,cantidadArt);
                    break;
            case 6: break;
        }

    }

    getch();
    return 0;
}







void gestionRemantentes (){


}




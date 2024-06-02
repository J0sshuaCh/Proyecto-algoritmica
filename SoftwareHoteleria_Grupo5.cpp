#include <iostream>
#include <fstream>
#include <iomanip>
#include <conio.h>
#include <cstring>
#include <string>
#include <vector>
#include <string.h>
#include <cstdlib>
#include <iomanip>
#include <locale.h>
using namespace std;

struct inventario {
    char nombre[30];
    bool remanente;
    float cantidad, precio, precioFinal;
};
/*void eliminarObjeto(inventario objetos[], int& cantidadArt) {
    system("cls");
    cin.ignore();
    char nombreBuscar[30];
    bool encontrado = false;
    cout << "Ingrese el nombre del artículo que desea eliminar: ";
    cin.getline(nombreBuscar, 30, '\n');
    for (int i = 0; i < cantidadArt; ++i) {
        if (strcmp(objetos[i].nombre, nombreBuscar) == 0) {
            for (int j = i; j < cantidadArt - 1; ++j) {
                strcpy(objetos[j].nombre, objetos[j + 1].nombre);
                objetos[j].cantidad = objetos[j + 1].cantidad;
                objetos[j].precio = objetos[j + 1].precio;
                objetos[j].precioFinal = objetos[j + 1].precioFinal;
            }
            cantidadArt--;
            encontrado = true;
            break;
        }
    }

    if (encontrado == true) {
        cout << "Artículo eliminado correctamente.\n";
    } else {
        cout << "No se encontró el artículo en el inventario.\n";
    }
    getch();
}
*/
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
void agregarArticulo(inventario objeto1[], int& cantidadArt, int& ultimoArticulo){
system("cls");
cin.ignore();
char terminar = 'Y';
while(terminar == 'Y' || terminar == 'y'){
    cout<<"Ingrese el nombre del objeto "<<ultimoArticulo+1<<endl;
    cin.getline(objeto1[ultimoArticulo].nombre,30,'\n');
    cout<<endl<<"Ingrese la cantidad del objeto "<<"\""<<objeto1[ultimoArticulo].nombre<<"\" :";
    cin>>objeto1[ultimoArticulo].cantidad;
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
    system("cls");
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

void menuInventario(){
    inventario objetos[50];
    int cantidadArt = 0;
    int ultimoArticulo = 0;
    int dimension = 50;
    int menu = 1;
    cargarDatos(objetos,dimension,ultimoArticulo,cantidadArt);
    while (menu != 0){
        system("cls");
        guardarDatos(objetos,dimension,ultimoArticulo,cantidadArt);
        cout<<"Bienvenido al inventario!"<<endl<<"Escoja su opción"<<endl;
        cout<<"1. Agregar articulos"<<endl<<"2. Mostrar inventario"<<endl<<"3. Modificar Articulo"<<endl<<"4.Elminar Articulo"<<endl<<"5. Gestionar remanente"<<endl<<"0. Volver al menú principal"<<endl;
        cin>>menu;
        switch (menu){
            case 1: agregarArticulo(objetos,cantidadArt, ultimoArticulo);
                    break;
            case 2: mostrarInventario(objetos, cantidadArt);
                    break;
            case 3: modificarArticulo(objetos,cantidadArt);
                    break;
            case 0: break;
        }

    }
}
// Definimos la clase Habitación
class Habitacion {
private:
    int numero;
    bool ocupada;
    double tarifa;
    string clienteNombre;
    string clienteDocumento;

public:
    Habitacion(int num, double tarifa) : numero(num), ocupada(false), tarifa(tarifa) {}

    int getNumero() const { return numero; }
    bool estaOcupada() const { return ocupada; }
    double getTarifa() const { return tarifa; }
    const string& getClienteNombre() const { return clienteNombre; }
    const string& getClienteDocumento() const { return clienteDocumento; }

    void reservar(const string& nombre, const string& documento) {
        ocupada = true;
        clienteNombre = nombre;
        clienteDocumento = documento;
    }

    void liberar() {
        ocupada = false;
        clienteNombre = "";
        clienteDocumento = "";
    }
};

// Función para mostrar el menú
int mostrarMenu() {
    cout << "\n----- Menú -----\n";
    cout << "1. Mostrar habitaciones disponibles\n";
    cout << "2. Reservar una habitacion\n";
    cout << "3. Mostrar habitaciones ocupadas\n";
    cout << "4. Desocupar una habitacion\n";
    cout << "5. Salir\n";
    cout << "Seleccione una opcion: ";

    int opcion;
    cin >> opcion;
    return opcion;
}

// Función para encontrar la primera habitación disponible
Habitacion* encontrarPrimeraDisponible(vector<Habitacion>& habitaciones) {
    for (int i = 0; i < habitaciones.size(); ++i) {
        if (!habitaciones[i].estaOcupada()) {
            return &habitaciones[i];
        }
    }
    return NULL;
}

// Función para encontrar una habitación ocupada por número de habitación
Habitacion* encontrarHabitacionOcupada(vector<Habitacion>& habitaciones, int numero) {
    for (int i = 0; i < habitaciones.size(); ++i) {
        if (habitaciones[i].estaOcupada() && habitaciones[i].getNumero() == numero) {
            return &habitaciones[i];
        }
    }
    return NULL;
}

// Función para mostrar todas las habitaciones ocupadas
void mostrarHabitacionesOcupadas(const vector<Habitacion>& habitaciones) {
    cout << "\nHabitaciones Ocupadas:\n";
    bool encontrada = false;
    for (int i = 0; i < habitaciones.size(); ++i) {
        if (habitaciones[i].estaOcupada()) {
            cout << "Habitacion #" << habitaciones[i].getNumero() << " - Cliente: "
                 << habitaciones[i].getClienteNombre() << " (Documento: "
                 << habitaciones[i].getClienteDocumento() << ")\n";
            encontrada = true;
        }
    }
    if (!encontrada) {
        cout << "No hay habitaciones ocupadas.\n";
    }
}
void menuHabitacion() {
    vector<Habitacion> habitaciones;

    // Registrar habitaciones disponibles
    for (int i = 0; i < 5; ++i) {
        int num = 101 + i;
        double tarifa = 100.0 ;
        habitaciones.push_back(Habitacion(num, tarifa));
    }

    int opcion;
    do {
        opcion = mostrarMenu();

        switch (opcion) {
            case 1:
                cout << "\nHabitaciones Disponibles:\n";
                for (int i = 0; i < habitaciones.size(); ++i) {
                    if (!habitaciones[i].estaOcupada()) {
                        cout << "Habitacion #" << habitaciones[i].getNumero() << " (Tarifa: S/. "
                             << habitaciones[i].getTarifa() << ")\n";
                    }
                }
                break;
            case 2: {
                Habitacion* habitacionDisponible = encontrarPrimeraDisponible(habitaciones);
                if (habitacionDisponible) {
                    string nombre, documento;
                    cout << "Ingrese el nombre del cliente: ";
                    cin >> nombre;
                    cout << "Ingrese el documento del cliente: ";
                    cin >> documento;
                    habitacionDisponible->reservar(nombre, documento);
                    cout << "Habitacion #" << habitacionDisponible->getNumero()
                         << " reservada con exito para " << nombre << "!\n";
                } else {
                    cout << "No hay habitaciones disponibles para reservar.\n";
                }
                break;
            }
            case 3:
                mostrarHabitacionesOcupadas(habitaciones);
                break;
            case 4: {
                int numero;
                cout << "Ingrese el numero de la habitacion a desocupar: ";
                cin >> numero;
                Habitacion* habitacionOcupada = encontrarHabitacionOcupada(habitaciones, numero);
                if (habitacionOcupada) {
                    habitacionOcupada->liberar();
                    cout << "Habitacion #" << habitacionOcupada->getNumero() << " desocupada correctamente.\n";
                } else {
                    cout << "No se encontro una habitacion ocupada con el numero especificado.\n";
                }
                break;
            }
            case 5:
                cout << "Saliendo del programa.\n";
                break;
            default:
                cout << "Opcion invalida. Intente nuevamente.\n";
                break;
        }

    } while (opcion != 5);
}
int main (){
    setlocale(LC_ALL, "spanish");
    int menu;
    while (true){
        system("cls");
        cout<<"------------------Bienvenido a InnovaHotel---------------------"<<endl;
        cout<<"1. Gestionar habitaciones"<<endl<<"2. Gestionar inventario"<<endl<<"3. Gestionar empleados"<<endl<<"4.Finanzas"<<endl<<"0. Salir del programa"<<endl;
        cout<<"Digite su opción :";
        cin>>menu;
        system("cls");
        switch(menu){
            case 1: menuHabitacion();
                    break;
            case 2: menuInventario();
                    break;
            case 0: cout<<"Adios!";
                    return 0;
        }

    }


	getch();
	return 0;
}

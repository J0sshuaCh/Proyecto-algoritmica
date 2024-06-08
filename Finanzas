#include <iostream>
#include <fstream>
#include <iomanip>
#include <conio.h>
#include <cstring>
#include <string>
#include <vector>
#include <cstdlib>
#include <locale.h>

using namespace std;

struct inventario {
    char nombre[30];
    bool remanente;
    float cantidad, precio, precioFinal;
};

struct Habitacion {
    int numero;
    bool ocupada;
    double tarifa;
    string clienteNombre;
    string clienteDocumento;

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

struct empleados {
    char nombre[30];
    char apellido[30];
    long DNI;
    char puesto[30];
    float sueldo;
};

void guardarDatos(inventario objetos[], int cantidadArt) {
    ofstream archivo("datos_inventario.txt");
    if (archivo.is_open()) {
        archivo << cantidadArt << endl;
        for (int i = 0; i < cantidadArt; ++i) {
            archivo << objetos[i].nombre << " " << objetos[i].cantidad << " " << objetos[i].precio << " " << objetos[i].precioFinal << endl;
        }
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo para guardar los datos." << endl;
    }
}

void cargarDatos(inventario datos[], int& cantidadArt) {
    ifstream archivo("datos_inventario.txt");
    if (archivo.is_open()) {
        archivo >> cantidadArt;
        for (int i = 0; i < cantidadArt; ++i) {
            archivo >> datos[i].nombre >> datos[i].cantidad >> datos[i].precio >> datos[i].precioFinal;
        }
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo para cargar los datos. Se iniciarán con los valores predeterminados" << endl;
        cantidadArt = 0;
    }
}

void guardarEmpleados(empleados empleadosHotel[], int cantidadEmpleados) {
    ofstream archivo("datos_empleados.txt");
    if (archivo.is_open()) {
        archivo << cantidadEmpleados << endl;
        for (int i = 0; i < cantidadEmpleados; ++i) {
            archivo << empleadosHotel[i].nombre << " "
                    << empleadosHotel[i].apellido << " "
                    << empleadosHotel[i].DNI << " "
                    << empleadosHotel[i].puesto << " "
                    << empleadosHotel[i].sueldo << endl;
        }
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo para guardar los datos." << endl;
    }
}

void cargarEmpleados(empleados empleadosHotel[], int& cantidadEmpleados) {
    ifstream archivo("datos_empleados.txt");
    if (archivo.is_open()) {
        archivo >> cantidadEmpleados;
        for (int i = 0; i < cantidadEmpleados; ++i) {
            archivo >> empleadosHotel[i].nombre
                    >> empleadosHotel[i].apellido
                    >> empleadosHotel[i].DNI
                    >> empleadosHotel[i].puesto
                    >> empleadosHotel[i].sueldo;
        }
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo para cargar los datos. Se iniciarán con los valores predeterminados." << endl;
        cantidadEmpleados = 0;
    }
}

float calcularCostoTotalInventario(const inventario objetos[], int cantidadArt) {
    float costoTotal = 0.0;
    for (int i = 0; i < cantidadArt; ++i) {
        costoTotal += objetos[i].precioFinal;
    }
    return costoTotal;
}

double calcularCostoTotalHabitacionesOcupadas(const vector<Habitacion>& habitaciones) {
    double costoTotal = 0.0;
    for (const auto& habitacion : habitaciones) {
        if (habitacion.estaOcupada()) {
            costoTotal += habitacion.getTarifa();
        }
    }
    return costoTotal;
}

double calcularCostoTotalPersonal(const empleados empleadosHotel[], int cantidadEmpleados) {
    double totalSueldos = 0.0;
    for (int i = 0; i < cantidadEmpleados; ++i) {
        totalSueldos += empleadosHotel[i].sueldo;
    }
    return totalSueldos;
}

void menuFinanzas(const inventario objetos[], int cantidadArt, const vector<Habitacion>& habitaciones, const empleados empleadosHotel[], int cantidadEmpleados) {
    system("cls");
    float costoTotalInventario = calcularCostoTotalInventario(objetos, cantidadArt);
    double ventasHabitacion = calcularCostoTotalHabitacionesOcupadas(habitaciones);
    double costoTotalPersonal = calcularCostoTotalPersonal(empleadosHotel, cantidadEmpleados);
    double ganancias = ventasHabitacion - costoTotalInventario - costoTotalPersonal;

    cout << "------ BALANCE DEL HOTEL ------\n";
    cout << left << setw(30) << "Ventas habitacion: S/." 
         << setw(30) << "Costo inventario: S/." 
         << setw(30) << "Costo personal: S/."
         << "Ganancias: S/." << endl;
    cout << left << setw(30) << fixed << setprecision(2) << ventasHabitacion 
         << setw(30) << fixed << setprecision(2) << costoTotalInventario 
         << setw(30) << fixed << setprecision(2) << costoTotalPersonal
         << fixed << setprecision(2) << ganancias << endl;
    getch();
}

void eliminarArticulo(inventario objetos[], int& dimension, int& ultimoArticulo) {
    system("cls");
    cin.ignore();
    int aux;
    char nombreBuscar[30];
    bool encontrado = false;

    cout << "Ingrese el nombre del artículo que desea eliminar: ";
    cin.getline(nombreBuscar, 30, '\n');

    for (int i = 0; i <= dimension; ++i) {
        if (strcmp(objetos[i].nombre, nombreBuscar) == 0) {
            aux = i;
            encontrado = true;
            break;
        }
    }

    if (encontrado) {
        for (int i = aux; i <= dimension; ++i) {
            strcpy(objetos[i].nombre, objetos[i + 1].nombre);
            objetos[i].precio = objetos[i + 1].precio;
            objetos[i].cantidad = objetos[i + 1].cantidad;
        }
        ultimoArticulo--;
        dimension--;
        cout << "Objeto: " << nombreBuscar << " eliminado correctamente";
    } else {
        cout << "Objeto: " << nombreBuscar << " no se encontró dentro del inventario.";
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

    for (int i = 0; i <= dimension; ++i) {
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

void modificarCant(inventario objeto[], int cantidadArt) {
    system("cls");
    cin.ignore();
    char busqueda[30];
    double cantidad;
    bool encontrado = false;

    cout << "Ingrese el nombre del artículo que desea modificar: ";
    cin.getline(busqueda, 30, '\n');

    for (int i = 0; i < cantidadArt; ++i) {
        if (strcmp(objeto[i].nombre, busqueda) == 0) {
            cout << "Artículo encontrado!\nIngrese la cantidad usada: ";
            cin >> cantidad;
            objeto[i].cantidad -= cantidad;
            cin.ignore();
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        cout << "No se encontró ningún artículo";
    }
}

void agregarArticulo(inventario objeto1[], int& cantidadArt, int& ultimoArticulo) {
    system("cls");
    cin.ignore();
    char remanente;
    char terminar = 'Y';
    while (terminar == 'Y' || terminar == 'y') {
        cout << "Ingrese el nombre del objeto " << ultimoArticulo + 1 << endl;
        cin.getline(objeto1[ultimoArticulo].nombre, 30, '\n');
        cout << endl << "Ingrese la cantidad del objeto \"" << objeto1[ultimoArticulo].nombre << "\" :";
        cin >> objeto1[ultimoArticulo].cantidad;
        cout << endl << "Ingrese el precio unitario del objeto \"" << objeto1[ultimoArticulo].nombre << "\" :";
        cin >> objeto1[ultimoArticulo].precio;
        objeto1[ultimoArticulo].precioFinal = objeto1[ultimoArticulo].precio * objeto1[ultimoArticulo].cantidad;
        cantidadArt++;
        ultimoArticulo++;
        cin.ignore();
        cout << "Pasar al siguiente artículo Y/N" << endl;
        cin >> terminar;
        cin.ignore();
    }
}

void mostrarInventario(inventario objetos[], int dimension) {
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

void cargarDatos(inventario datos[], int& dimension, int& ultimoArticulo, int& cantidadArt) {
    ifstream archivo("datos_inventario.txt");
    if (archivo.is_open()) {
        archivo >> cantidadArt >> ultimoArticulo;
        dimension = 50;
        for (int i = 0; i < dimension; ++i) {
            archivo >> datos[i].nombre >> datos[i].cantidad >> datos[i].precio >> datos[i].precioFinal;
        }
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo para cargar los datos. Se iniciarán con los valores predeterminados" << endl;
        dimension = 50;
        ultimoArticulo = 0;
        cantidadArt = 0;
    }
}

void menuInventario() {
    setlocale(LC_ALL, "spanish");
    inventario objetos[50];
    int cantidadArt = 0;
    int ultimoArticulo = 0;
    int dimension = 50;
    int menu;
    cargarDatos(objetos, dimension, ultimoArticulo, cantidadArt);
    while (menu != 0) {
        guardarDatos(objetos, cantidadArt);
        cout << "Bienvenido al inventario!" << endl << "Escoja su opción" << endl;
        cout << "1. Agregar artículos" << endl
             << "2. Mostrar inventario" << endl
             << "3. Modificar Artículo" << endl
             << "4. Eliminar artículo" << endl
             << "5. Modificar cantidad de artículo" << endl
             << "0. Volver al menú principal" << endl;
        cin >> menu;
        switch (menu) {
            case 1:
                agregarArticulo(objetos, cantidadArt, ultimoArticulo);
                break;
            case 2:
                mostrarInventario(objetos, cantidadArt);
                break;
            case 3:
                modificarArticulo(objetos, cantidadArt);
                break;
            case 4:
                eliminarArticulo(objetos, cantidadArt, ultimoArticulo);
                break;
            case 5:
                modificarCant(objetos, cantidadArt);
                break;
            case 0:
                break;
        }
    }
    getch();
    return;
}

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

Habitacion* encontrarPrimeraDisponible(vector<Habitacion>& habitaciones) {
    for (int i = 0; i < habitaciones.size(); ++i) {
        if (!habitaciones[i].estaOcupada()) {
            return &habitaciones[i];
        }
    }
    return NULL;
}

Habitacion* encontrarHabitacionOcupada(vector<Habitacion>& habitaciones, int numero) {
    for (int i = 0; i < habitaciones.size(); ++i) {
        if (habitaciones[i].estaOcupada() && habitaciones[i].getNumero() == numero) {
            return &habitaciones[i];
        }
    }
    return NULL;
}

void menuHabitacion() {
    vector<Habitacion> habitaciones;

    for (int i = 0; i < 5; ++i) {
        int num = 101 + i;
        double tarifa = 100.0;
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

void crearNuevoEmpleado(empleados empleadosHotel[], int& cantidadEmpleados) {
    if (cantidadEmpleados >= 50) {
        cout << "No se pueden agregar más empleados. Capacidad máxima alcanzada." << endl;
        return;
    }

    vector<string> puestos;
    puestos.push_back("Recepcionista");
    puestos.push_back("Limpieza");
    puestos.push_back("Cocina");
    puestos.push_back("Mantenimiento");
    puestos.push_back("Gerente");

    bool agregarOtro = false;
    do {
        system("cls");
        cin.ignore();

        empleados nuevoEmpleado;

        cout << "Ingrese el nombre del empleado: ";
        cin.getline(nuevoEmpleado.nombre, 30, '\n');
        cout << "Ingrese el apellido del empleado: ";
        cin.getline(nuevoEmpleado.apellido, 30, '\n');
        cout << "Ingrese el DNI del empleado: ";
        cin >> nuevoEmpleado.DNI;
        cin.ignore();

        cout << "Seleccione el puesto del empleado: " << endl;
        for (int i = 0; i < puestos.size(); ++i) {
            cout << i + 1 << ". " << puestos[i] << endl;
        }
        int puestoSeleccionado;
        cin >> puestoSeleccionado;
        cin.ignore();

        strcpy(nuevoEmpleado.puesto, puestos[puestoSeleccionado - 1].c_str());

        cout << "Ingrese el sueldo del empleado: ";
        cin >> nuevoEmpleado.sueldo;
        cin.ignore();

        empleadosHotel[cantidadEmpleados] = nuevoEmpleado;
        cantidadEmpleados++;

        guardarEmpleados(empleadosHotel, cantidadEmpleados);

        cout << "Empleado agregado exitosamente!" << endl;

        cout << "¿Desea agregar otro empleado? (s/n): ";
        char respuesta;
        cin >> respuesta;
        agregarOtro = (respuesta == 's' || respuesta == 'S');
    } while (agregarOtro && cantidadEmpleados < 50);
}

void mostrarEmpleados() {
    ifstream archivo("datos_empleados.txt");
    if (archivo.is_open()) {
        int cantidadEmpleados;
        archivo >> cantidadEmpleados;
        empleados empleadosHotel[50];
        for (int i = 0; i < cantidadEmpleados; ++i) {
            archivo >> empleadosHotel[i].nombre
                >> empleadosHotel[i].apellido
                >> empleadosHotel[i].DNI
                >> empleadosHotel[i].puesto
                >> empleadosHotel[i].sueldo;
        }
        archivo.close();

        system("cls");
        cout << left << setw(30) << "Nombre"
            << setw(30) << "Apellido"
            << setw(15) << "DNI"
            << setw(20) << "Puesto"
            << setw(10) << "Sueldo" << endl;

        for (int i = 0; i < cantidadEmpleados; ++i) {
            cout << left << setw(30) << empleadosHotel[i].nombre
                << setw(30) << empleadosHotel[i].apellido
                << setw(15) << empleadosHotel[i].DNI
                << setw(20) << empleadosHotel[i].puesto
                << setw(10) << fixed << setprecision(2) << empleadosHotel[i].sueldo << endl;
        }
        system("pause");
    } else {
        cout << "No se pudo abrir el archivo para cargar los datos." << endl;
    }
}

void eliminarempleado(empleados empleado[], int& cantidadEmpleados) {
    system("cls");
    cin.ignore();
    int aux;
    char nombreBuscar[30];
    char apellidoBuscar[30];
    bool encontrado = false;
    cout << "Ingrese el nombre del empleado que desea eliminar: ";
    cin.getline(nombreBuscar, 30, '\n');
    cout << endl << "Ingrese el apellido del empleado que desea eliminar: ";
    cin.getline(apellidoBuscar, 30, '\n');

    for (int i = 0; i <= cantidadEmpleados; ++i) {
        if (strcmp(empleado[i].nombre, nombreBuscar) == 0 && strcmp(empleado[i].apellido, apellidoBuscar) == 0) {
            aux = i;
            encontrado = true;
            break;
        }
    }

    if (encontrado) {
        for (int i = aux; i <= cantidadEmpleados; ++i) {
            strcpy(empleado[i].nombre, empleado[i + 1].apellido);
            strcpy(empleado[i].apellido, empleado[i + 1].apellido);
            empleado[i].DNI = empleado[i + 1].DNI;
            empleado[i].sueldo = empleado[i + 1].sueldo;
            strcpy(empleado[i].puesto, empleado[i + 1].puesto);
        }
        cantidadEmpleados--;
        cout << "Empleado: " << nombreBuscar << " " << apellidoBuscar << " eliminado correctamente";
    } else {
        cout << "Empleado: " << nombreBuscar << " " << apellidoBuscar << " no se encontró en la base de datos.";
    }
    getch();
}

void modificarEmpleado(empleados empleado[], int cantidadEmpleados) {
    system("cls");
    cin.ignore();
    char nombreBuscar[30];
    char apellidoBuscar[30];
    bool encontrado = false;
    int puesto;
    cout << "Ingrese el nombre del empleado a modificar: ";
    cin.getline(nombreBuscar, 30, '\n');
    cout << endl << "Ingrese el apellido del empleado a modificar: ";
    cin.getline(apellidoBuscar, 30, '\n');
    for (int i = 0; i <= cantidadEmpleados; ++i) {
        if (strcmp(empleado[i].nombre, nombreBuscar) == 0 && strcmp(empleado[i].apellido, apellidoBuscar) == 0) {
            cout << "Empleado encontrado. Ingrese los nuevos datos:\n";
            cout << "Nuevo nombre: ";
            cin.getline(empleado[i].nombre, 30, '\n');
            cout << "Nuevo apellido: ";
            cin.getline(empleado[i].apellido, 30, '\n');
            cout << "Nuevo DNI: ";
            cin >> empleado[i].DNI;
            cout << "Nuevo puesto:\n";
            do {
                cout << "1. Recepcionista\n";
                cout << "2. Limpieza\n";
                cout << "3. Cocina\n";
                cout << "4. Mantenimiento\n";
                cout << "5. Gerente\n";
                cin >> puesto;
                if (puesto != 1 && puesto != 2 && puesto != 3 && puesto != 4 && puesto != 5) {
                    cout << "Ingrese una opción válida!";
                }
            } while (puesto != 1 && puesto != 2 && puesto != 3 && puesto != 4 && puesto != 5);
            cout << "Nuevo sueldo: ";
            cin >> empleado[i].sueldo;
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        cout << "Empleado no encontrado en la base de datos!";
    }
    getch();
}

void menuEmpleados() {
    empleados empleadosHotel[50];
    int cantidadEmpleados = 0;
    cargarEmpleados(empleadosHotel, cantidadEmpleados);

    int opcion;
    do {
        guardarEmpleados(empleadosHotel, cantidadEmpleados);
        system("cls");
        cout << "----- Gestión de Empleados -----" << endl;
        cout << "1. Crear nuevo empleado" << endl;
        cout << "2. Mostrar empleado" << endl;
        cout << "3. Eliminar empleado" << endl;
        cout << "4. Modificar empleado" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                crearNuevoEmpleado(empleadosHotel, cantidadEmpleados);
                break;
            case 2:
                mostrarEmpleados();
                break;
            case 3:
                eliminarempleado(empleadosHotel, cantidadEmpleados);
                break;
            case 4:
                modificarEmpleado(empleadosHotel, cantidadEmpleados);
                break;
            default:
                cout << "Opción inválida. Intente nuevamente." << endl;
                break;
        }
    } while (opcion != 0);
}

int main() {
    setlocale(LC_ALL, "spanish");
    vector<Habitacion> habitaciones;
    for (int i = 101; i <= 110; ++i) {
        habitaciones.push_back(Habitacion(i, 100.0));
    }

    inventario objetos[50];
    int cantidadArt = 0;
    cargarDatos(objetos, cantidadArt);

    empleados empleadosHotel[50];
    int cantidadEmpleados = 0;
    cargarEmpleados(empleadosHotel, cantidadEmpleados);

    int menu;
    do {
        system("cls");
        cout << "------------------Bienvenido a InnovaHotel---------------------" << endl;
        cout << "1. Gestionar habitaciones" << endl
             << "2. Gestionar inventario" << endl
             << "3. Gestionar empleados" << endl
             << "4. Finanzas" << endl
             << "0. Salir del programa" << endl;
        cout << "Digite su opción: ";
        cin >> menu;
        cin.ignore();  // Limpiar el buffer de entrada

        switch (menu) {
            case 1:
                menuHabitacion();
                break;
            case 2:
                menuInventario();
                break;
            case 3:
                menuEmpleados();
                break;
            case 4:
                menuFinanzas(objetos, cantidadArt, habitaciones, empleadosHotel, cantidadEmpleados);
                break;
            case 0:
                cout << "Adios!";
                return 0;
        }
    } while (menu != 0);

    getch();
    return 0;
}


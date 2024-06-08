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

struct empleados {
    char nombre[30];
    char apellido[30];
    long DNI;
    char puesto[30];
    float sueldo;
};

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

        int puestoSeleccionado;
        bool seleccionValida = false;
        do {
            cout << "Seleccione el puesto del empleado: " << endl;
            for (int i = 0; i < puestos.size(); ++i) {
                cout << i + 1 << ". " << puestos[i] << endl;
            }
            cin >> puestoSeleccionado;
            cin.ignore();

            if (puestoSeleccionado >= 1 && puestoSeleccionado <= puestos.size()) {
                seleccionValida = true;
            } else {
                cout << "Opción inválida. Intente nuevamente." << endl;
            }
        } while (!seleccionValida);

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
    }
    else {
        cout << "No se pudo abrir el archivo para cargar los datos." << endl;
    }
}
void eliminarempleado(empleados empleado[], int& cantidadEmpleados){
    system("cls");
    cin.ignore();
    int aux;
    char nombreBuscar[30];
    char apellidoBuscar[30];
    bool encontrado = false;
    cout<<"Ingrese el nombre del empleado que desea eliminar :";
    cin.getline(nombreBuscar, 30, '\n');
    cout<<endl<<"Ingrese el apellido del empleado que desea eliminar :";
    cin.getline(apellidoBuscar, 30, '\n');

    for (int i = 0; i<= cantidadEmpleados;++i){
        if(strcmp(empleado[i].nombre, nombreBuscar) == 0 && strcmp(empleado[i].apellido, apellidoBuscar) == 0){
            aux = i;
            encontrado = true;
            break;
        }
    }

    if (encontrado == true){
        for (int i = aux; i<= cantidadEmpleados; ++i){
            strcpy(empleado[i].nombre, empleado[i+1].apellido);
            strcpy(empleado[i].apellido, empleado[i+1].apellido);
            empleado[i].DNI = empleado[i+1].DNI;
            empleado[i].sueldo = empleado[i+1].sueldo;
            strcpy(empleado[i].puesto, empleado[i+1].puesto);
        }
        cantidadEmpleados = cantidadEmpleados -1;
        cout<<"Empleado : "<<nombreBuscar<< " "<<apellidoBuscar << " eliminado correctamente";
    }else{
        cout<<"Emleado : "<<nombreBuscar <<" "<<apellidoBuscar << " no se encontró en la base de datos.";
    }
getch();
}
void modificarEmpleado(empleados empleado[], int cantidadEmpleados){
    system("cls");
    cin.ignore();
    char nombreBuscar[30];
    char apellidoBuscar[30];
    bool encontrado = false;
    int puesto;
    cout<<"Ingrese el nombre del empleado a modificar: ";
    cin.getline(nombreBuscar, 30, '\n');
    cout<<endl<<"Ingrese el apellido del empleado a modificar: ";
    cin.getline(apellidoBuscar, 30, '\n');
    for (int i = 0; i<= cantidadEmpleados; ++i){
        if (strcmp(empleado[i].nombre, nombreBuscar)==0 && strcmp(empleado[i].apellido, apellidoBuscar) == 0){
            cout<<"Empleado encontrado. Ingrese los nuevos datos : \n";
            cout<<"Nuevo nombre: ";
            cin.getline(empleado[i].nombre,30, '\n');
            cout<<"Nuevo apellido: ";
            cin.getline(empleado[i].apellido, 30,'\n');
            cout<<"Nuevo DNI: ";
            cin>>empleado[i].DNI;
            cout<<"Nuevo puesto: "<<endl;;
            do{
                cout<<"1. Recepcionista"<<endl;
                cout<<"2. Limpieza"<<endl;
                cout<<"3. Cocina"<<endl;
                cout<<"4. Mantenimiento"<<endl;
                cout<<"5. Gerente"<<endl;
                cin>>puesto;
                if (puesto != 1 && puesto !=2 && puesto != 3 && puesto!= 4 && puesto != 5){
                    cout<<"Ingrese una opcion valida!";
                }
            }while(puesto != 1 && puesto !=2 && puesto != 3 && puesto!= 4 && puesto != 5);
            cout<<"Nuevo sueldo: ";
            cin>>empleado[i].sueldo;
            encontrado = true;
            break;
        }
    }
    if (encontrado == false ){
        cout<<"Empleado no encontrado en la base de datos!";
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
        cout<<cantidadEmpleados<<endl;
        cout << "----- Gestión de Empleados -----" << endl;
        cout << "1. Crear nuevo empleado" << endl;
        cout << "2. Mostrar empleado"<<endl;
        cout << "3. Eliminar empleado"<<endl;
        cout << "4. Modificar empleado"<<endl;
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

    menuEmpleados();

    getch();
    return 0;
}



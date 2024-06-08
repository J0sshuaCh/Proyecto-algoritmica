#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

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


int mostrarMenu() {
    cout << "\n----- Menú -----\n";
    cout << "1. Mostrar habitaciones disponibles\n";
    cout << "2. Reservar una habitación\n";
    cout << "3. Mostrar habitaciones ocupadas\n";
    cout << "4. Liberar una habitación\n";
    cout << "5. Salir\n";
    cout << "Seleccione una opción: ";

    int opcion;
    cin >> opcion;
    return opcion;
}


Habitacion* encontrarPrimeraDisponible(vector<Habitacion>& habitaciones) {
    for (size_t i = 0; i < habitaciones.size(); ++i) {
        if (!habitaciones[i].estaOcupada()) {
            return &habitaciones[i];
        }
    }
    return NULL;
}

void mostrarHabitacionesOcupadas(const vector<Habitacion>& habitaciones) {
    cout << "\nHabitaciones Ocupadas:\n";
    bool encontrada = false;
    for (size_t i = 0; i < habitaciones.size(); ++i) {
        if (habitaciones[i].estaOcupada()) {
            cout << "Habitación #" << habitaciones[i].getNumero() << " - Cliente: "
                 << habitaciones[i].getClienteNombre() << " (Documento: "
                 << habitaciones[i].getClienteDocumento() << ")\n";
            encontrada = true;
        }
    }
    if (!encontrada) {
        cout << "No hay habitaciones ocupadas.\n";
    }
}

void guardarHabitaciones(const vector<Habitacion>& habitaciones) {
    ofstream archivo("habitaciones_reservadas.txt");
    if (archivo.is_open()) {
        for (size_t i = 0; i < habitaciones.size(); ++i) {
            archivo << habitaciones[i].getNumero() << " "
                    << habitaciones[i].estaOcupada() << " "
                    << habitaciones[i].getTarifa() << " "
                    << habitaciones[i].getClienteNombre() << " "
                    << habitaciones[i].getClienteDocumento() << endl;
        }
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo para guardar los datos.\n";
    }
}

void cargarHabitaciones(vector<Habitacion>& habitaciones) {
    ifstream archivo("habitaciones_reservadas.txt");
    if (archivo.is_open()) {
        int numero;
        bool ocupada;
        double tarifa;
        string clienteNombre;
        string clienteDocumento;

        habitaciones.clear();
        while (archivo >> numero >> ocupada >> tarifa) {
            archivo.ignore();
            getline(archivo, clienteNombre, ' ');
            getline(archivo, clienteDocumento);

            Habitacion habitacion(numero, tarifa);
            if (ocupada) {
                habitacion.reservar(clienteNombre, clienteDocumento);
            }
            habitaciones.push_back(habitacion);
        }
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo para cargar los datos. Se iniciarán con los valores predeterminados.\n";
    }
}

void liberarHabitacion(vector<Habitacion>& habitaciones) {
    int numero;
    cout << "Ingrese el número de la habitación a liberar: ";
    cin >> numero;
    for (size_t i = 0; i < habitaciones.size(); ++i) {
        if (habitaciones[i].getNumero() == numero && habitaciones[i].estaOcupada()) {
            habitaciones[i].liberar();
            cout << "Habitación #" << numero << " liberada con éxito.\n";
            guardarHabitaciones(habitaciones);
            return;
        }
    }
    cout << "No se encontró una habitación ocupada con ese número.\n";
}

int main() {
	setlocale(LC_ALL, "spanish");
    vector<Habitacion> habitaciones;

    cargarHabitaciones(habitaciones);

    if (habitaciones.empty()) {
        for (int i = 0; i < 5; ++i) {
            int num = 101 + i;
            double tarifa = 100.0;
            habitaciones.push_back(Habitacion(num, tarifa));
        }
    }

    int opcion;
    do {
        opcion = mostrarMenu();

        switch (opcion) {
            case 1:
                cout << "\nHabitaciones Disponibles:\n";
                for (size_t i = 0; i < habitaciones.size(); ++i) {
                    if (!habitaciones[i].estaOcupada()) {
                        cout << "Habitación #" << habitaciones[i].getNumero() << " (Tarifa: S/. "
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
                    cout << "Habitación #" << habitacionDisponible->getNumero()
                         << " reservada con éxito para " << nombre << "!\n";
                    guardarHabitaciones(habitaciones);
                } else {
                    cout << "No hay habitaciones disponibles para reservar.\n";
                }
                break;
            }
            case 3:
                mostrarHabitacionesOcupadas(habitaciones);
                break;
            case 4:
                liberarHabitacion(habitaciones);
                break;
            case 5:
                cout << "Saliendo del programa.\n";
                break;
            default:
                cout << "Opción inválida. Intente nuevamente.\n";
                break;
        }

    } while (opcion != 5);

    return 0;
}


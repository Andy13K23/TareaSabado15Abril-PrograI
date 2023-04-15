#include <iostream>
#include <fstream>
#include <filesystem>
#include <windows.h>

using namespace std;

namespace fs = std::filesystem;

int main() {
    string ruta;
    string nombre_archivo;
    cout << "Ingrese la ruta donde desea crear el archivo: ";
    cin >> ruta;
    cout << "Ingrese el nombre del archivo: ";
    cin >> nombre_archivo;

    nombre_archivo += ".txt";

    fs::path ruta_archivo = ruta + "\\" + nombre_archivo;

    if (fs::exists(ruta_archivo)) {
        cout << "El archivo ya existe." <<endl;
    } else {
        // Creamos el archivo
        ofstream archivo(ruta_archivo);
        if (archivo.is_open()) {
            archivo << "¡Hola mundo, si pueden leer esto fui creado correctamente!" <<endl;
            archivo.close();
            cout << "El archivo de texto se creó correctamente en la ruta especificada." <<endl;
        } else {
            cout << "No se pudo crear el archivo." <<endl;
            return 1;
        }
    }
    
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_INTENSITY);

    std::cout << "Archivo de texto creado en la ruta: " << fs::absolute(ruta_archivo).string() << std::endl;

    return 0;
}
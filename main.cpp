#include <iostream>
#include "Biblioteca.h"

using namespace std;

int main() {
    Biblioteca biblioteca;

    // Agregar libros a la biblioteca
    biblioteca.agregarLibro(Libro("Libro 1", "Autor 1", "Acción"));
    // Agregar más libros...

    // Agregar usuarios a la biblioteca
    biblioteca.agregarUsuario(Usuario("Usuario 1", "Apellido 1", "DNI 1"));
    // Agregar más usuarios...

    // Realizar operaciones
    Usuario &usuario = biblioteca.usuarios[0];
    Libro &libro = biblioteca.libros[0];
    string DNI;
    Usuario* usuariopointer;
    Usuario* usuario_devolucion;

    int opcion;
    while (true) {
        cout << "Menú de la Biblioteca" << endl;
        cout << "1. Comprobar disponibilidad de libros" << endl;
        cout << "2. Ver historial de un usuario" << endl;
        cout << "3. Sacar un libro" << endl;
        cout << "4. Devolver un libro" << endl;
        cout << "5. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                biblioteca.comprobarDisponibilidad();
                break;
            case 2:
                cout << "Ingrese el DNI del usuario: ";
                cin >> DNI;
                for (Usuario &usuario: biblioteca.usuarios) {
                    if (usuario.DNI == DNI) {
                        biblioteca.verHistorialUsuario(usuario);
                        break;
                    } else {
                        cout << "Usuario no registrado" << endl;
                        break;
                    }
                }
                break;
            case 3:
                cout << "Ingrese el DNI del usuario: ";
                cin >> DNI;
                usuariopointer = nullptr;
                for (Usuario& u : biblioteca.usuarios) {
                    if (u.DNI == DNI) {
                        usuariopointer = &u;
                        break;
                    }
                }
                if (usuariopointer == nullptr) {
                    cout << "Usuario no encontrado." << endl;
                } else {
                    cout << "Ingrese el título del libro que desea sacar: ";
                    string titulo;
                    cin.ignore();
                    getline(cin, titulo);
                    for (Libro& libro : biblioteca.libros) {
                        if (libro.titulo == titulo && libro.disponible) {
                            biblioteca.sacarLibro(*usuariopointer, libro);
                            cout << "Libro asignado al usuario." << endl;
                            break;
                        }
                    }
                }
                break;
            case 4:
                cout << "Ingrese el DNI del usuario: ";
                cin >> DNI;
                usuario_devolucion = nullptr;
                for (Usuario& u : biblioteca.usuarios) {
                    if (u.DNI == DNI) {
                        usuario_devolucion = &u;
                        break;
                    }
                }
                if (usuario_devolucion == nullptr) {
                    std::cout << "Usuario no encontrado." << std::endl;
                } else {
                    biblioteca.devolverLibro(*usuario_devolucion);
                    std::cout << "Libro devuelto correctamente." << std::endl;
                }
                break;
            case 5:
                std::cout << "Saliendo del programa." << std::endl;
                return 0;
            default:
                std::cout << "Opción no válida. Por favor, seleccione una opción válida." << std::endl;


        }
    }

    return 0;
}
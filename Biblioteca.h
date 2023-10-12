//
// Created by juanm on 12/10/2023.
//

#ifndef BIBLIOTECA_BIBLIOTECA_H
#define BIBLIOTECA_BIBLIOTECA_H
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Libro {
public:
    string titulo;
    string autor;
    string categoria;
    bool disponible;

    Libro(const string& titulo, const string& autor, const string& categoria)
            : titulo(titulo), autor(autor), categoria(categoria), disponible(true) {}
};

class Usuario {
public:
    string nombre;
    string apellidos;
    string DNI;
    Libro* libroActual;
    vector<Libro*> historial;

    Usuario(const string& nombre, const string& apellidos, const string& DNI)
            : nombre(nombre), apellidos(apellidos), DNI(DNI), libroActual(nullptr) {}

    void agregarLibroAlHistorial(Libro* libro) {
        historial.push_back(libro);
    }
};

class Biblioteca {
public:
    vector<Libro> libros;
    vector<Usuario> usuarios;

    void agregarLibro(const Libro& libro) {
        libros.push_back(libro);
    }

    void agregarUsuario(const Usuario& usuario) {
        usuarios.push_back(usuario);
    }

    void comprobarDisponibilidad() {
        for (const Libro& libro : libros) {
            if (libro.disponible) {
                cout << "Libro disponible: " << libro.titulo << " (" << libro.categoria << ")" << endl;
            }
        }
    }

    void verHistorialUsuario(const Usuario& usuario) {
        for (const Libro* libro : usuario.historial) {
            std::cout << "Libro en historial: " << libro->titulo << " (" << libro->categoria << ")" << std::endl;
        }
    }

    bool usuarioTieneLibro(const Usuario& usuario) {
        return usuario.libroActual != nullptr;
    }

    void sacarLibro(Usuario& usuario, Libro& libro) {
        if (libro.disponible) {
            usuario.libroActual = &libro;
            libro.disponible = false;
        }
    }

    void devolverLibro(Usuario& usuario) {
        if (usuarioTieneLibro(usuario)) {
            Libro& libro = *(usuario.libroActual);
            libro.disponible = true;
            usuario.agregarLibroAlHistorial(&libro);
            usuario.libroActual = nullptr;
        }
    }
};



#endif //BIBLIOTECA_BIBLIOTECA_H

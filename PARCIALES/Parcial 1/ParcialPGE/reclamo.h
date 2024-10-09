// reclamo.h
#ifndef RECLAMO_H
#define RECLAMO_H

#include "usuario.h"

class reclamo : public usuario {
public:
    std::string tipo;
    std::string descripcion;
    std::string fecha;
    std::string codigo;
    usuario destinatario;
    int anexado;    // Código de otro reclamo relacionado
    int recepcion;  // 0: No recibido, 1: Recibido
    int archivado;  // 0: No archivado, 1: Archivado
    int anulado;    // 0: No anulado, 1: Anulado

    reclamo(const usuario& u, const std::string& t, const std::string& d, const std::string& f, const usuario& dest,
        const std::string& c = "", int a = 0, int r = 0, int ar = 0, int an = 0)
        : usuario(u), tipo(t), descripcion(d), fecha(f), destinatario(dest), codigo(c),
        anexado(a), recepcion(r), archivado(ar), anulado(an) {}
};

#endif // RECLAMO_H

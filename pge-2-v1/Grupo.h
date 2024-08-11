#ifndef GRUPO_H
#define GRUPO_H

#include "Estudiante.h"
#include <vector>
using namespace std;

class Grupo {
public:
    void agregarEstudiante(const Estudiante& estudiante);
    float calcularPromedioNotas() const;

private:
    vector<Estudiante> estudiantes;
};

#endif // GRUPO_H
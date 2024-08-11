#include "Grupo.h"

void Grupo::agregarEstudiante(const Estudiante& estudiante) {
    estudiantes.push_back(estudiante);
}

float Grupo::calcularPromedioNotas() const {
    if (estudiantes.empty()) {
        return 0.0f;
    }

    float sumaNotas = 0.0f;
    for (const auto& estudiante : estudiantes) {
        sumaNotas += estudiante.getNota();
    }

    return sumaNotas / estudiantes.size();
}

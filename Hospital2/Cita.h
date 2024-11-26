#ifndef CITA_H
#define CITA_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <memory>
#include <vector>

class Paciente; // Declaraci�n anticipada
class Medico;   // Declaraci�n anticipada

class Cita {
public:
    Cita(std::unique_ptr<Paciente> paciente, std::unique_ptr<Medico> medico, const std::string& fecha, int urgencia);

    static void crearCitasCSV();
    static int obtenerMaxIdCitas();
    static bool guardarCitaEnCSV(const Cita& cita);
    static bool buscarPacienteEnCSV(const std::string& nombreBuscado);
    static bool buscarMedicoEnCSV(const std::string& nombreBuscado);
    static void agregarCita(const std::string& nombrePaciente, const std::string& nombreMedico, const std::string& fecha, int urgencia);

private:
    std::unique_ptr<Paciente> paciente;
    std::unique_ptr<Medico> medico;
    std::string fecha;
    int urgencia;
    static std::vector<std::unique_ptr<Cita>> citas; // Almacena las citas
};

#endif // CITA_H
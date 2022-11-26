#pragma once

#include <vector>
#include "Fecha.h"
#include <string>
#include <unordered_map>
#include <map>
using Medico = std::string;
using Paciente = std::string;

class Consultorio
{
public:
	void nuevoMedico(Medico const& medico);
	void pideConsulta(Paciente const& paciente, Medico const& medico, Fecha const& fecha);
	Paciente siguientePaciente(Medico const& medico);
	void atiendeConsulta(Medico const& medico);
	std::vector<std::pair<Fecha, Paciente>> listaPacientes(Medico const& medico, Fecha const& fecha);
private:
	std::unordered_map<Medico, std::map<Fecha, Paciente>> consultorio;
};


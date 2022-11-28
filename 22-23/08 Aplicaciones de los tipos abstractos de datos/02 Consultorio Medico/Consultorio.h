#pragma once

#include <vector>
#include "Fecha.h"
#include <string>
#include <unordered_map>
#include <map>
#include <stdexcept>
using Medico = std::string;
using Paciente = std::string;

class Consultorio
{
public:
	void nuevoMedico(Medico const& medico) {
		if (consultorio.count(medico) == 0) {
			consultorio.insert({ medico,{} });
		}
	}

	void pideConsulta(Paciente const& paciente, Medico const& medico, Fecha const& fecha) {
		if (consultorio.count(medico) == 0) {
			throw std::domain_error("Medico no existente");
		}
		if (consultorio[medico].count(fecha) > 0) {
			throw std::domain_error("Hueco ocupado");
		}

		consultorio[medico].insert({ fecha,paciente });
	}

	Paciente siguientePaciente(Medico const& medico) {
		if (consultorio.count(medico) == 0) {
			throw std::domain_error("Medico no existente");
		}
		auto it = consultorio[medico].begin();
		if (it == consultorio[medico].end()) {
			throw std::domain_error("No hay paciente");
		}

		return it->second;
	}
	void atiendeConsulta(Medico const& medico) {

		if (consultorio.count(medico) == 0) {
			throw std::domain_error("Medico no existente");
		}
		auto it = consultorio[medico].begin();
		if (it == consultorio[medico].end()) {
			throw std::domain_error("No hay paciente");
		}
		consultorio[medico].erase(it);
	}
	std::vector<std::pair<Fecha, Paciente>> listaPacientes(Medico const& medico, Fecha const& fecha) {
		if (consultorio.count(medico) == 0) {
			throw std::domain_error("Medico no existente");
		}
		std::map<Fecha, Paciente> citas = consultorio[medico];
		std::vector < std::pair<Fecha, Paciente>> lista;

		for (auto const& i : citas) {
			if (i.first.getDia() == fecha.getDia())
				lista.push_back({ i.first,i.second });
		}

		return lista;
	}
private:
	std::unordered_map<Medico, std::map<Fecha, Paciente>> consultorio;
};


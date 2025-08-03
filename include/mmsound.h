#ifndef MMSOUND_H
#define MMSOUND_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include <stdio.h>

#define ERROR_EXIT(...) fprintf(stderr, __VA_ARGS__); exit(1)
#define ERROR_RETURN(R, ...) fprintf(stderr, __VA_ARGS__); return R

extern unsigned int g_default_long;

namespace mmsound {
	class Nota {
		private:
			char nombre;
			unsigned int octava;
			unsigned int duracion;
			char alteracion;

		public:
			// Constructor
			Nota(char n = 'c', unsigned int o = 4, unsigned int d = 1, char a = '\0'):
				nombre(n),
				octava(o),
				duracion(d),
				alteracion(a) {}

			// Getters
			char getNombre() const { return nombre; }
			unsigned int getOctava() const { return octava; }
			unsigned int getDuracion() const { return duracion; }
			char getAlteracion() const { return alteracion; }

			// Setters
			void setNombre(char n) { nombre = n; }
			void setOctava(unsigned int  o) { octava = o; }
			void setDuracion(unsigned int d) { duracion = d; }
			void setAlteracion(char a) { alteracion = a; }

			// void prolongar(float factor) { duracion *= factor; }
			
                        std::string toString() const {
                                return std::string(1, nombre) + " A:" +
                                       std::string(1, alteracion) + " O:" +
                                       std::to_string(octava) + " D(" +
                                       std::to_string(duracion) + ")";
                        }
        };
	
	class Secuencia {
		private:

	};
	
	class Reproductor {
		private:
	};
} // namespace mmsound

void	parser_mmline(std::string &line);

#endif

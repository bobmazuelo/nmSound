#include "mmsound.h"
#include <cmath>
#include <cctype>

using namespace mmsound;

static double note_to_freq(const Nota& nota)
{
        int base;
        switch (std::tolower(nota.getNombre()))
        {
                case 'c': base = 0; break;
                case 'd': base = 2; break;
                case 'e': base = 4; break;
                case 'f': base = 5; break;
                case 'g': base = 7; break;
                case 'a': base = 9; break;
                case 'b': base = 11; break;
                default: base = 0; break;
        }

        int alt = 0;
        if (nota.getAlteracion() == '#')
                alt = 1;
        else if (nota.getAlteracion() == 'b')
                alt = -1;

        int midi = 12 * (nota.getOctava() + 1) + base + alt;
        return 440.0 * std::pow(2.0, (midi - 69) / 12.0);
}

void    generate_csound(const std::vector<Nota>& notes,
        const std::string &filename)
{
        std::ofstream file(filename);
        if (!file.is_open())
        {
                std::cerr << "[ERROR]: unable to open " << filename << "\n";
                exit(1);
        }

        file << "<CsoundSynthesizer>\n"
                "<CsInstruments>\n"
                "instr 1\n"
                "aout oscili p4, p5\n"
                "outs aout, aout\n"
                "endin\n"
                "</CsInstruments>\n"
                "<CsScore>\n";

        double start = 0.0;
        for (const auto& n : notes)
        {
                double dur = static_cast<double>(n.getDuracion());
                double freq = note_to_freq(n);
                file << "i1 " << start << ' ' << dur << " 0.5 " << freq << "\n";
                start += dur;
        }

        file << "e\n"
                "</CsScore>\n"
                "</CsoundSynthesizer>\n";

        file.close();
}

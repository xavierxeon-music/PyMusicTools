#include <pybind11/pybind11.h>

// Abstract
void init_AbstractOscilator(pybind11::module_& module);
void init_AbstractEffect(pybind11::module_& module);
void init_AbstractSoundSource(pybind11::module_& module);

// Blocks
void init_PolyRamp(pybind11::module_& module);
void init_Trapezoid(pybind11::module_& module);

// Effect
void init_Revoice(pybind11::module_& module);

// Midi
void init_MidiCommon(pybind11::module_& module);

// Music
void init_Note(pybind11::module_& module);
void init_Tempo(pybind11::module_& module);
void init_TimeCode(pybind11::module_& module);

// Sound
void init_Sample(pybind11::module_& module);
void init_Morpher(pybind11::module_& module);
void init_Spectrum(pybind11::module_& module);
void init_WaveTable(pybind11::module_& module);

// Tools
void init_FastRandom(pybind11::module_& module);
void init_Range(pybind11::module_& module);
void init_SevenBit(pybind11::module_& module);

PYBIND11_MODULE(musictools, module)
{
   // Abstract
   init_AbstractOscilator(module);
   init_AbstractEffect(module);
   init_AbstractSoundSource(module);

   // Blocks
   init_PolyRamp(module);
   init_Trapezoid(module);

   // Effect
   init_Revoice(module);

   // Midi
   init_MidiCommon(module);

   // Music
   init_Note(module);
   init_Tempo(module);
   init_Spectrum(module);
   init_TimeCode(module);

   // Sound
   init_Sample(module);
   init_Morpher(module);
   init_WaveTable(module);

   // Tools
   init_FastRandom(module);
   init_Range(module);
   init_SevenBit(module);
}

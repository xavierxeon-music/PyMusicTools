#include <pybind11/pybind11.h>

#ifndef MusicToolsH
#define MusicToolsH
#include "py_MusicTools.h"
#endif // NOT MusicToolsH

PYBIND11_MODULE(musictools, module)
{
   init_AbstractEffect(module);
   init_AbstractOscilator(module);
   init_AbstractSoundSource(module);
   init_Counter(module);
   init_FastRandom(module);
   init_MidiCommon(module);
   init_MidiFile(module);
   init_Note(module);
   init_PolyRamp(module);
   init_Revoice(module);
   init_Sample(module);
   init_SampleOscilator(module);
   init_Sequencer(module);
   init_SevenBit(module);
   init_SoundMesh(module);
   init_Spectrum(module);
   init_Tempo(module);
   init_TimeCode(module);
   init_TrackerLane(module);
   init_TrackerProject(module);
   init_Trapezoid(module);
   init_WaveTable(module);
}


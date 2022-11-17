#include <pybind11/pybind11.h>

#ifndef MusicToolsH
#define MusicToolsH
#include "py_MusicTools.h"
#endif // NOT MusicToolsH

PYBIND11_MODULE(musictools, module)
{
   init_AbstractSegmentCrawler(module);
   init_Contour(module);
   init_Counter(module);
   init_FastRandom(module);
   init_Grooves(module);
   init_MidiCommon(module);
   init_MidiFile(module);
   init_Note(module);
   init_Sample(module);
   init_SampleOscilator(module);
   init_Sequencer(module);
   init_SevenBit(module);
   init_SoundMesh(module);
   init_Spectrum(module);
   init_Tempo(module);
   init_TimeCode(module);
}


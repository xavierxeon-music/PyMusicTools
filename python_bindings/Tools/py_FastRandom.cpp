#include <pybind11/pybind11.h>

#include <Tools/FastRandom.h>

void init_FastRandom(pybind11::module_& module)
{
   pybind11::class_<FastRandom> fastrandom(module, "FastRandom");
   fastrandom.def(pybind11::init<>());
   

   // autogen start
   // autogen end
}


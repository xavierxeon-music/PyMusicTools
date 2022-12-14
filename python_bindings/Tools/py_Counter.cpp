#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <Tools/Counter.h>

void init_Counter(pybind11::module_& module)
{
   pybind11::class_<Counter> counter(module, "Counter");
   counter.def(pybind11::init<const uint64_t&>());
   

   // autogen start
   counter.def("reset", &Counter::reset);
   counter.def("setMaxValue", &Counter::setMaxValue);
   counter.def("valueAndNext", &Counter::valueAndNext);
   counter.def("getCurrentValue", &Counter::getCurrentValue);
   counter.def("nextAndIsMaxValue", &Counter::nextAndIsMaxValue);
   counter.def("getMaxValue", &Counter::getMaxValue);
   // autogen end
}


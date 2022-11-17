#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <Blocks/Contour.h>

void init_Contour(pybind11::module_& module)
{
   pybind11::class_<Contour> contour(module, "Contour");
   contour.def(pybind11::init<>());
   
   pybind11::class_<Contour::Poly> contour_poly(module, "ContourPoly");
   contour_poly.def(pybind11::init<>());
   

   // autogen start
   contour.def("setup", &Contour::setup);
   contour.def("resize", &Contour::resize);
   contour.def("getName", &Contour::getName);
   contour.def("setName", &Contour::setName);
   contour.def("getSegmentValue", &Contour::getSegmentValue);
   contour.def("resetSegment", &Contour::resetSegment);
   contour.def("getSegmentStartValue", &Contour::getSegmentStartValue);
   contour.def("hasSegmentStartValue", &Contour::hasSegmentStartValue);
   contour.def("setSegmentStartValue", &Contour::setSegmentStartValue);
   contour.def("getSegmentEndValue", &Contour::getSegmentEndValue);
   contour.def("hasSegmentEndValue", &Contour::hasSegmentEndValue);
   contour.def("setSegmentEndValue", &Contour::setSegmentEndValue);
   contour.def("hasSegmentValues", &Contour::hasSegmentValues);
   contour.def("isSegmentSteady", &Contour::isSegmentSteady);
   contour.def("setSegmentSteady", &Contour::setSegmentSteady);
   contour_poly.def("clear", &Contour::Poly::clear);
   contour_poly.def("update", &Contour::Poly::update);
   contour_poly.def("getContourCount", &Contour::Poly::getContourCount);
   contour_poly.def("getContour", &Contour::Poly::getContour);
   // autogen end
}


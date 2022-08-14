#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <Sound/SoundMesh.h>

void init_SoundMesh(pybind11::module_& module)
{
   pybind11::class_<SoundMesh::Point> soundmesh_point(module, "Point");
   soundmesh_point.def(pybind11::init<>());
   
   pybind11::class_<SoundMesh::Grid> soundmesh_grid(module, "Grid");
   soundmesh_grid.def(pybind11::init<const uint16_t&>());
   
   pybind11::class_<SoundMesh::Grid::PointF> soundmesh_grid_pointf(soundmesh_grid, "PointF");
   soundmesh_grid_pointf.def(pybind11::init<>());
   
   pybind11::class_<SoundMesh::Table> soundmesh_table(module, "Table");
   soundmesh_table.def(pybind11::init<const uint64_t&>());
   

   // autogen start
   soundmesh_point.def_readwrite("xIndex", &SoundMesh::Point::xIndex);
   soundmesh_point.def_readwrite("yIndex", &SoundMesh::Point::yIndex);
   
   soundmesh_grid.def("getSize", &SoundMesh::Grid::getSize);
   soundmesh_grid.def("get", &SoundMesh::Grid::get);
   soundmesh_grid.def("set", &SoundMesh::Grid::set);
   soundmesh_table.def("update", &SoundMesh::Table::update);
   soundmesh_table.def("valueByAngle", &SoundMesh::Table::valueByAngle);
   // autogen end
}


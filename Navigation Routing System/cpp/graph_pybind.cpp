#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "graph.h"

namespace py = pybind11;

PYBIND11_MODULE(graph_module, m) {
    py::class_<Graph>(m, "Graph")
        .def(py::init<>()) // Constructor
        .def("addEdge", &Graph::addEdge)
        .def("addNodeCoordinates", &Graph::addNodeCoordinates)
        .def("aStarPathPy", &Graph::aStarPathPy)
        .def("getAdjacencyListPy", &Graph::getAdjacencyListPy);
}

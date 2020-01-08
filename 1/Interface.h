#ifndef INTERFACE_H
#define INTERFACE_H


#include <iostream>
#include <vector>

#include "Class_Graph.h"

void add_graph(std::vector<Graph> &g, int org);
void set_graph_or(int choose, std::vector<Graph> &g);
void set_graph(int choose, std::vector<Graph> &g);
void set_graph_list(std::vector<Graph> &g);
void set_graph_list_or(std::vector<Graph> &g);
void set_all_matrix(int already, Graph &g);
void set_all_matrix_or(int already, Graph &g);
int which_graph(std::vector<Graph> &g);
int which_ver(std::vector<Graph> &g, int gr);
void choose_two_graph(std::vector<Graph> &g, int &gr1, int &gr2);
void source_and_sink(Graph &gor, std::vector<int> &source, std::vector<int> &sink);
void Save_ad(Graph &g);
void Save_in(Graph &g);
void Save_la(Graph &g);

#endif // INTERFACE_H

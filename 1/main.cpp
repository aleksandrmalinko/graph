#include <iostream>
#include <vector>
#include <Windows.h>
#include "Class_Graph.h"
#include "Interface.h"

#define INT_MAX 2147483647
int menu() 
{
	int choose = 0;
	std::cout 
		<< "\n-------------------------------------------\n"
		<< "You can:\n"
		<< "1) Add new graph\n"
		<< "2) List of existing graphs\n"
		<< "3) Show number of vertices\n"
		<< "4) Show count of graph edges\n"
		<< "5) Show degree of vertices of a graph\n"
		<< "6) Show degree sequence of graph\n"
		<< "7) Show matrix_adjacency of graph\n"
		<< "8) Show matrix_incidence of graph\n"
		<< "9) Show list_adjacency of graph\n"
		<< "10) Show source and sink\n"
		<< "11) Show hanging vertices\n"
		<< "12) Show isolated vertices\n"
		<< "13) Show distance between two vertices\n"
		<< "14) Show eccentricity of vertice\n"
		<< "15) Show D\n"
		<< "16) Show rad\n"
		<< "17) Show peri\n"
		<< "18) Show O\n"
		<< "19) Add V\n"
		<< "20) Del V\n"
		<< "21) Add E\n"
		<< "22) Del E\n"
		<< "23) Complement graph\n"
		<< "24) Subdivision of the graph edge\n"
		<< "25) Tightening the graph\n"
		<< "26) Vertex identification\n"
		<< "27) Duplication V\n"
		<< "28) Breeding V\n"
		<< "29) Union\n"
		<< "30) Compound\n"
		<< "31) multiplication\n"
		<< "32) Save matrix_adjacency\n"
		<< "33) Save matrix_incidence\n"
		<< "34) Save list_adjacency\n"
		<< "-------------------------------------------\n";
	std::cin >> choose;
	return choose;
}
int main()
{
	std::vector<Graph> g;
	while (1) 
	{
		int choose = menu();
		switch (choose) {
			case(1): 
			{
				int choose = 0;
				std::cout << "Or?:\n"
					<< "1) Y\n"
					<< "2) N\n";
				int org = -1;
				std::cin >> org;
				std::cout << "How?:\n"
					<< "1) matrix_adjacency\n"
					<< "2) matrix_incidence\n"
					<< "3) list_adjacency\n";
				std::cin >> choose;
				if (org == 2)
				{
					add_graph(g, org);
					switch (choose) {
					case(1):
					{
						set_graph(choose, g);
						break;
					}
					case(2):
					{
						set_graph(choose, g);
						break;
					}
					case(3):
					{
						set_graph_list(g);
						break;
					}
					default:
					{
						std::cout << "Incorrect\n";
						break;
					}
					}
				}
				if (org == 1)
				{
					add_graph(g, org);
					switch (choose) {
					case(1):
					{
						set_graph_or(choose, g);
						break;
					}
					case(2):
					{
						set_graph_or(choose, g);
						break;
					}
					case(3):
					{
						set_graph_list_or(g);
						break;
					}
					default:
					{
						std::cout << "Incorrect\n";
						break;
					}
					}
				}
			
				break;
			}
			case(2): //List of existing graphs"
			{
				std::cout << "Not or: ";
				for (int i = 0; i < g.size(); i++)
				{
					if (g[i].Isor() == 0)
						std::cout << "G" << i + 1 << " ";
				}
				std::cout << "\n";
				std::cout << "Or: ";
				for (int i = 0; i < g.size(); i++)
				{
					if (g[i].Isor() == 1)
						std::cout << "G" << i + 1 << " ";
				}
				std::cout << "\n";
				break;
			}
			case(3): //Show number of vertices 
			{
				int gr = which_graph(g);
				int ver = g[gr].Get_vertices();
				std::cout << ver << "\n";
				break;
			}
			case(4): //Show count of graph edges
			{
				int gr = which_graph(g);
				int edg = g[gr].Get_edges();
				std::cout << edg << "\n";
				break;
			}
			case(5): //Show degree of vertices of a graph
			{
				int gr = which_graph(g);
				int org = g[gr].Isor();
				if (org == 0)
				{
					int ver = which_ver(g, gr);
					int edg = g[gr].Deegree_vert(ver);
					std::cout << edg << "\n";
				}
				if (org == 1)
				{
					int ver = which_ver(g, gr);
					int s1 = 0;
					int s2 = 0;
					g[gr].Deegree_vert_or(ver, s1, s2);
					std::cout << s1 << " " << s2 << "\n";
				}
				break;
			}
			case(6): //Show degree sequence of graph
			{
				int gr = which_graph(g);
				int org = g[gr].Isor();
				if (org == 0)
				{
					std::vector<int> degree;
					g[gr].Deegree_sequence(degree);
					for (int i = 0; i < degree.size(); i++)
					{
						std::cout << degree[i] << " ";
					}
					std::cout << "\n";
				}
				if (org == 1)
				{
					std::vector<int> degree1;
					std::vector<int> degree2;
					g[gr].Deegree_sequence_or(degree1, degree2);
					std::cout << "ish: ";
					for (int i = 0; i < degree1.size(); i++)
					{
						std::cout << degree1[i] << " ";
					}
					std::cout << "\n";
					std::cout << "zah: ";
					for (int i = 0; i < degree2.size(); i++)
					{
						std::cout << degree2[i] << " ";
					}
					std::cout << "\n";
				}
				break;
			}
			case(7): //Show matrix_adjacency of graph
			{
				int gr = which_graph(g);
				g[gr].Get_matrix(1);
				break;
			}
			case(8): //Show matrix_incidence of graph
			{
				int gr = which_graph(g);
				g[gr].Get_matrix(2);
				break;
			}
			case(9): //Show list_adjacency of graph
			{
				int gr = which_graph(g); 
				g[gr].Get_list_adjacency();
				break;
			} 
			case(10): // Show source and sink
			{
				std::cout << "\n";
				std::cout << "Or: ";
				for (int i = 0; i < g.size(); i++)
				{
					if (g[i].Isor() == 1)
						std::cout << "G" << i + 1 << " ";
				}
				std::cout << "\nChoose graph: ";
				int gr = -1;
				std::cin >> gr;
				gr--;
				std::vector<int> source;
				std::vector<int> sink;
				source_and_sink(g[gr], source, sink);
				std::cout << "source: ";
				for (int i = 0; i < source.size(); i++)
				{
					std::cout << source[i] << " ";
				}
				std::cout << "\n";
				std::cout << "sink: ";
				for (int i = 0; i < sink.size(); i++)
				{
					std::cout << sink[i] << " ";
				}
				std::cout << "\n";
				break;
			}
			case(11): //Show  hanging vertices
			{
				int gr = which_graph(g);
				std::vector<int> ver;
				g[gr].Get_hanging_vertices(ver);
				if (ver.size() == 0)
				{
					std::cout << "Noone";
				}
				else
				{
					for (int i = 0; i < ver.size(); i++)
					{
						std::cout << ver[i] << " ";
					}
				}
				std::cout << "\n";
				break;
			}
			case(12): //Show  isolated vertices
			{
				int gr = which_graph(g);
				std::vector<int> ver;
				g[gr].Get_isolated_vertices(ver);
				if (ver.size() == 0)
				{
					std::cout << "Noone";
				}
				else
				{
					for (int i = 0; i < ver.size(); i++)
					{
						std::cout << ver[i] << " ";
					}
				}
				std::cout << "\n";
				break;
			}
			case(13): //Show  distance between two vertices
			{
				std::cout << "\n";
				std::cout << "Not or: ";
				for (int i = 0; i < g.size(); i++)
				{
					if (g[i].Isor() == 0)
						std::cout << "G" << i + 1 << " ";
				}
				std::cout << "\nChoose graph: ";
				int gr = -1;
				std::cin >> gr;
				gr--;

				int v1, v2;
				std::cout << "v1:";
				std::cin >> v1;
				std::cout << "\nv2:";
				std::cin >> v2;
				int dist  = g[gr].Show_distance(v1, v2);
				std::cout << "\n" << dist;
				break;
			}
			case(14): //Show  eccentricity of vertice
			{
				std::cout << "\n";
				std::cout << "Not or: ";
				for (int i = 0; i < g.size(); i++)
				{
					if (g[i].Isor() == 0)
						std::cout << "G" << i + 1 << " ";
				}
				std::cout << "\nChoose graph: ";
				int gr = -1;
				std::cin >> gr;
				gr--;

				int v;
				std::cout << "v:";
				std::cin >> v;
				int ecc = 0;
				int dist = 0;
				for (int i = 0; i < g[gr].Get_vertices(); i++)
				{
					dist = g[gr].Show_distance(v, i+1);
					if ((dist > ecc)&&(dist!= INT_MAX)&&(i != v)) 
						ecc = dist;
				}
				std::cout << "\n" << ecc;
				break;
			}
			case(15): //Show  D
			{
				std::vector<int> diameter;
				std::cout << "\n";
				std::cout << "Not or: ";
				for (int i = 0; i < g.size(); i++)
				{
					if (g[i].Isor() == 0)
						std::cout << "G" << i + 1 << " ";
				}
				std::cout << "\nChoose graph: ";
				int gr = -1;
				std::cin >> gr;
				gr--;

				int comp_num = 0;
				std::vector <std::vector <int> > adjm = g[gr].Get_matrix_adjacency();
				std::vector<int>component(adjm.size(), -1);
				for (int i = 0; i < adjm.size(); i++)
				{
					if (component[i] != -1)
						continue;
					component[i] = comp_num;
					for (int j = 0; j < adjm.size(); j++)
					{
						if (i == j)
							continue;
						if (g[gr].Show_distance(i + 1, j + 1) != INT_MAX)
							component[j] = component[i];
					}
					comp_num++;
				}
				std::vector < std::vector < int>> all_ecc(comp_num, std::vector<int>(adjm.size(), -1));
				for (int co = 0; co < comp_num; co++) {
					for (int v = 0; v < adjm.size(); v++) {
						if (component[v] != co)
							continue;
						int eccent = 0;
						for (int i = 0; i < adjm.size(); i++) {
							//if (component[co] != i) 
							//continue; 
							if ((g[gr].Show_distance(v + 1, i + 1) > eccent) && (g[gr].Show_distance(v + 1, i + 1) != INT_MAX) && (i != v))
								eccent = g[gr].Show_distance(v + 1, i + 1);
						}
						all_ecc[co][v] = eccent;
					}
				}
				std::vector<int> diam_t(comp_num, 0);
				for (int co = 0; co < comp_num; co++) {
					for (int i = 0; i < adjm.size(); i++) {
						if (component[i] != co)
							continue;
						if ((all_ecc[co][i] > diam_t[co]) && (all_ecc[co][i] != INT_MAX))
							diam_t[co] = all_ecc[co][i];
					}
				}
				diameter = diam_t;
				for (int i = 0; i < diameter.size(); i++)
				{
					std::cout << "Comp " << i << " d= " << diameter[i] << "\n";
				}
				break;
			}
			case(16): //Show  rad
			{
				std::vector<int> diameter;
				std::cout << "\n";
				std::cout << "Not or: ";
				for (int i = 0; i < g.size(); i++)
				{
					if (g[i].Isor() == 0)
						std::cout << "G" << i + 1 << " ";
				}
				std::cout << "\nChoose graph: ";
				int gr = -1;
				std::cin >> gr;
				gr--;

				int comp_num = 0;
				std::vector <std::vector <int> > adjm = g[gr].Get_matrix_adjacency();
				std::vector<int>component(adjm.size(), -1);
				for (int i = 0; i < adjm.size(); i++)
				{
					if (component[i] != -1)
						continue;
					component[i] = comp_num;
					for (int j = 0; j < adjm.size(); j++)
					{
						if (i == j)
							continue;
						if (g[gr].Show_distance(i + 1, j + 1) != INT_MAX)
							component[j] = component[i];
					}
					comp_num++;
				}
				std::vector < std::vector < int>> all_ecc(comp_num, std::vector<int>(adjm.size(), -1));
				for (int co = 0; co < comp_num; co++) {
					for (int v = 0; v < adjm.size(); v++) {
						if (component[v] != co)
							continue;
						int eccent = 0;
						for (int i = 0; i < adjm.size(); i++) {
							//if (component[co] != i) 
							//continue; 
							if ((g[gr].Show_distance(v + 1, i + 1) > eccent) && (g[gr].Show_distance(v + 1, i + 1) != INT_MAX) && (i != v))
								eccent = g[gr].Show_distance(v + 1, i + 1);
						}
						all_ecc[co][v] = eccent;
					}
				}
				std::vector<int> rad_t(comp_num, INT_MAX);
				for (int co = 0; co < comp_num; co++) {
					for (int i = 0; i < adjm.size(); i++) {
						if (component[i] != co)
							continue;
						if ((all_ecc[co][i] < rad_t[co]) && (all_ecc[co][i] != 0))
							rad_t[co] = all_ecc[co][i];
					}
				}
				diameter = rad_t;
				for (int i = 0; i < diameter.size(); i++)
				{
					std::cout << "Comp " << i << " d= " << diameter[i] << "\n";
				}
				break;
			}
			case(17): //Show  peri
			{
				std::vector<int> diameter;
				std::vector <std::vector<int>> vtemp;
				std::cout << "\n";
				std::cout << "Not or: ";
				for (int i = 0; i < g.size(); i++)
				{
					if (g[i].Isor() == 0)
						std::cout << "G" << i + 1 << " ";
				}
				std::cout << "\nChoose graph: ";
				int gr = -1;
				std::cin >> gr;
				gr--;

				int comp_num = 0;
				std::vector <std::vector <int> > adjm = g[gr].Get_matrix_adjacency();
				std::vector<int>component(adjm.size(), -1);
				for (int i = 0; i < adjm.size(); i++)
				{
					if (component[i] != -1)
						continue;
					component[i] = comp_num;
					for (int j = 0; j < adjm.size(); j++)
					{
						if (i == j)
							continue;
						if (g[gr].Show_distance(i + 1, j + 1) != INT_MAX)
							component[j] = component[i];
					}
					comp_num++;
				}
				std::vector < std::vector < int>> all_ecc(comp_num, std::vector<int>(adjm.size(), -1));
				for (int co = 0; co < comp_num; co++) {
					for (int v = 0; v < adjm.size(); v++) {
						if (component[v] != co)
							continue;
						int eccent = 0;
						for (int i = 0; i < adjm.size(); i++) {
							//if (component[co] != i) 
							//continue; 
							if ((g[gr].Show_distance(v + 1, i + 1) > eccent) && (g[gr].Show_distance(v + 1, i + 1) != INT_MAX) && (i != v))
								eccent = g[gr].Show_distance(v + 1, i + 1);
						}
						all_ecc[co][v] = eccent;
					}
				}
				std::vector<int> diam_t(comp_num, 0);
				for (int co = 0; co < comp_num; co++) {
					for (int i = 0; i < adjm.size(); i++) {
						if (component[i] != co)
							continue;
						if ((all_ecc[co][i] > diam_t[co]) && (all_ecc[co][i] != INT_MAX))
							diam_t[co] = all_ecc[co][i];
					}
				}

				for (int i = 0; i < comp_num; i++)
					vtemp.push_back(std::vector<int>());
				for (int co = 0; co < comp_num; co++) {
					for (int i = 0; i < adjm.size(); i++) {
						if (component[i] != co)
							continue;
						if (all_ecc[co][i] == diam_t[co])
							vtemp[co].push_back(i);
					}
				}

				for (int i = 0; i < vtemp.size(); i++)
				{
					std::cout << "Comp " << i << ": ";
					for (int j = 0; j < vtemp.size(); j++)
					{
						std::cout << vtemp[i][j] << " ";
					}
					std::cout << "\n";
				}
				break;
			}
			case(18): //Show  O
			{
				std::vector<int> diameter;
				std::vector <std::vector<int>> vtemp;
				std::cout << "\n";
				std::cout << "Not or: ";
				for (int i = 0; i < g.size(); i++)
				{
					if (g[i].Isor() == 0)
						std::cout << "G" << i + 1 << " ";
				}
				std::cout << "\nChoose graph: ";
				int gr = -1;
				std::cin >> gr;
				gr--;

				int comp_num = 0;
				std::vector <std::vector <int> > adjm = g[gr].Get_matrix_adjacency();
				std::vector<int>component(adjm.size(), -1);
				for (int i = 0; i < adjm.size(); i++)
				{
					if (component[i] != -1)
						continue;
					component[i] = comp_num;
					for (int j = 0; j < adjm.size(); j++)
					{
						if (i == j)
							continue;
						if (g[gr].Show_distance(i + 1, j + 1) != INT_MAX)
							component[j] = component[i];
					}
					comp_num++;
				}
				std::vector < std::vector < int>> all_ecc(comp_num, std::vector<int>(adjm.size(), -1));
				for (int co = 0; co < comp_num; co++) {
					for (int v = 0; v < adjm.size(); v++) {
						if (component[v] != co)
							continue;
						int eccent = 0;
						for (int i = 0; i < adjm.size(); i++) {
							//if (component[co] != i) 
							//continue; 
							if ((g[gr].Show_distance(v + 1, i + 1) > eccent) && (g[gr].Show_distance(v + 1, i + 1) != INT_MAX) && (i != v))
								eccent = g[gr].Show_distance(v + 1, i + 1);
						}
						all_ecc[co][v] = eccent;
					}
				}
				std::vector<int> rad_t(comp_num, INT_MAX);
				for (int co = 0; co < comp_num; co++) {
					for (int i = 0; i < adjm.size(); i++) {
						if (component[i] != co)
							continue;
						if ((all_ecc[co][i] < rad_t[co]) && (all_ecc[co][i] != 0))
							rad_t[co] = all_ecc[co][i];
					}
				}
				for (int i = 0; i < comp_num; i++)
					vtemp.push_back(std::vector<int>());
				for (int co = 0; co < comp_num; co++) {
					for (int i = 0; i < adjm.size(); i++) {
						if (component[i] != co)
							continue;
						if (all_ecc[co][i] == rad_t[co])
							vtemp[co].push_back(i);
					}
				}
				for (int i = 0; i < vtemp.size(); i++)
				{
					std::cout << "Comp " << i << ": ";
					for (int j = 0; j < vtemp.size(); j++)
					{
						 std::cout << vtemp[i][j] << " ";
					}
					std::cout << "\n";
				}
				break;
			}
			case(19): // Add v
			{
				int gr = which_graph(g);
				int org = g[gr].Isor();
				if (org == 0)
				{
					int gr = which_graph(g);
					std::vector <std::vector <int>> matrix;
					matrix = g[gr].Get_matrix_adjacency();
					int size = matrix.size();
					for (int i = 0; i < size; i++)
					{
						matrix[i].push_back(0);
					}
					matrix.push_back(std::vector <int>(size + 1, 0));
					g[gr].Set_matrix(1, matrix);
					set_all_matrix(1, g[gr]);
					std::cout << "New v: V" << size + 1 << "\n";
				}
				if (org == 1)
				{
					int gr = which_graph(g);
					std::vector <std::vector <int>> matrix;
					matrix = g[gr].Get_matrix_adjacency();
					int size = matrix.size();
					for (int i = 0; i < size; i++)
					{
						matrix[i].push_back(0);
					}
					matrix.push_back(std::vector <int>(size + 1, 0));
					g[gr].Set_matrix(1, matrix);
					set_all_matrix_or(1, g[gr]);
					std::cout << "New v: V" << size + 1 << "\n";
				}
				break;
			}
			case(20): // Delete v
			{
				int gr = which_graph(g);
				int org = g[gr].Isor();
				if (org == 0)
				{
					int gr = which_graph(g);
					int v;
					std::cout << "v:";
					std::cin >> v;
					std::vector <std::vector <int>> temp_matrix;
					temp_matrix = g[gr].Get_matrix_adjacency();
					int size = temp_matrix.size();
					temp_matrix.erase(temp_matrix.begin() + v - 1);
					for (int i = 0; i < size - 1; i++)
					{
						temp_matrix[i].erase(temp_matrix[i].begin() + v - 1);
					}
					g[gr].Set_matrix(1, temp_matrix);
					set_all_matrix(1, g[gr]);
					std::cout << "Deleted v: V" << v << "\n";
				}
				if (org == 1)
				{
					int gr = which_graph(g);
					int v;
					std::cout << "v:";
					std::cin >> v;
					std::vector <std::vector <int>> temp_matrix;
					temp_matrix = g[gr].Get_matrix_adjacency();
					int size = temp_matrix.size();
					temp_matrix.erase(temp_matrix.begin() + v - 1);
					for (int i = 0; i < size - 1; i++)
					{
						temp_matrix[i].erase(temp_matrix[i].begin() + v - 1);
					}
					g[gr].Set_matrix(1, temp_matrix);
					set_all_matrix_or(1, g[gr]);
					std::cout << "Deleted v: V" << v << "\n";
				}
				break;
			}
			case(21): // Add e
			{
				int gr = which_graph(g);
				int org = g[gr].Isor();
				if (org == 0)
				{
					int gr = which_graph(g);
					std::vector <std::vector <int>> matrix;
					matrix = g[gr].Get_matrix_incidence();
					int v = g[gr].Get_vertices();
					int e = g[gr].Get_edges();

					int v1, v2;
					std::cout << "v1:";
					std::cin >> v1;
					std::cout << "v2:";
					std::cin >> v2;

					if (v1 != v2)
					{
						for (int i = 0; i < v; i++)
						{
							if (((i != (v1 - 1)) && (i != (v2 - 1))))
								matrix[i].push_back(0);
							else
								matrix[i].push_back(1);
						}
					}
					else
					{
						for (int i = 0; i < v; i++)
						{
							if (((i != (v1 - 1)) && (i != (v2 - 1))))
								matrix[i].push_back(0);
							else
								matrix[i].push_back(2);
						}
					}

					g[gr].Set_matrix(2, matrix);
					set_all_matrix(2, g[gr]);
					std::cout << "New e: E" << e + 1 << "\n";
				}
				if (org == 1)
				{
					int gr = which_graph(g);
					std::vector <std::vector <int>> matrix;
					matrix = g[gr].Get_matrix_incidence();
					int v = g[gr].Get_vertices();
					int e = g[gr].Get_edges();

					int v1, v2;
					std::cout << "v1:";
					std::cin >> v1;
					std::cout << "v2:";
					std::cin >> v2;

					if (v1 != v2)
					{
						for (int i = 0; i < v; i++)
						{
							if (((i != (v1 - 1)) && (i != (v2 - 1))))
								matrix[i].push_back(0);
							else
								if (i == (v1-1))
									matrix[i].push_back(1);
								else 
									matrix[i].push_back(-1);
						}
					}
					else
					{
						for (int i = 0; i < v; i++)
						{
							if (i != (v1 - 1)) 
								matrix[i].push_back(0);
							else
								matrix[i].push_back(2);
						}
					}

					g[gr].Set_matrix(2, matrix);
					set_all_matrix_or(2, g[gr]);
					std::cout << "New e: E" << e + 1 << "\n";
				}
				break;
			}
			case(22): // Dell e
			{
				int gr = which_graph(g);
				int org = g[gr].Isor();
				if (org == 0)
				{
					int gr = which_graph(g);
					std::vector <std::vector <int>> matrix;
					matrix = g[gr].Get_matrix_incidence();
					g[gr].Get_matrix(2);


					int e;
					std::cout << "e:";
					std::cin >> e;

					for (int i = 0; i < matrix.size(); i++)
					{
						matrix[i].erase(matrix[i].begin() + e - 1);
					}

					g[gr].Set_matrix(2, matrix);
					set_all_matrix(2, g[gr]);
					std::cout << "Deleted\n";
				}
				if (org == 1)
				{
					int gr = which_graph(g);
					std::vector <std::vector <int>> matrix;
					matrix = g[gr].Get_matrix_incidence();
					g[gr].Get_matrix(2);


					int e;
					std::cout << "e:";
					std::cin >> e;

					for (int i = 0; i < matrix.size(); i++)
					{
						matrix[i].erase(matrix[i].begin() + e - 1);
					}

					g[gr].Set_matrix(2, matrix);
					set_all_matrix(2, g[gr]);
					std::cout << "Deleted\n";
				}
				break;
			}
			case(23): // complement graph
			{
				int gr = which_graph(g);
				add_graph(g, 0);

				std::vector <std::vector <int>> matrix;
				matrix = g[gr].Get_matrix_adjacency();
				
				for (int i = 0; i < matrix.size(); i++)
				{
					for (int j = 0; j < matrix.size(); j++)
					{
						if (i == j) matrix[i][j] = 0;
						else if (matrix[i][j] == 0) matrix[i][j] = 1;
						else if (matrix[i][j] == 1) matrix[i][j] = 0;
					}
				}
				
				g[g.size()-1].Set_matrix(1, matrix);
				set_all_matrix(1, g[g.size() - 1]);
				std::cout << "New graph added: G" << g.size()  << "\n";
				g[g.size() - 1].Get_matrix(1);

				break;
			}
			case(24): // subdivision of the graph edge
			{
				int gr = which_graph(g);
				
				std::vector <std::vector <int>> matrix;
				matrix = g[gr].Get_matrix_incidence();
				
				int v = g[gr].Get_vertices();
				int e = g[gr].Get_edges();

				g[gr].Get_matrix(2);
				int edge;
				std::cout << "e:";
				std::cin >> edge;

				for (int i = 0; i < v; i++)
				{
						matrix[i].push_back(0);
						matrix[i].push_back(0);
				}
				matrix.push_back(std::vector <int>(e + 2, 0));

				int flag = 0;
				for (int i = 0; i < v; i++)
				{
					if (matrix[i][edge-1] == 1) 
					{
						if (flag == 0) {
							matrix[i][e] = 1;
							matrix[v][e] = 1;
							flag = 1;
						}
						else
						{
							matrix[i][e+1] = 1;
							matrix[v][e+1] = 1;
						}
					}
				}

				for (int i = 0; i < matrix.size(); i++)
				{
					matrix[i].erase(matrix[i].begin() + edge - 1);
				}
				g[gr].Set_matrix(2, matrix);
				set_all_matrix(2, g[gr]);
				break;
			}
			case(25): // tightening the graph
			{
				int gr = which_graph(g);

				std::vector <std::vector <int>> matrix_a;
				matrix_a = g[gr].Get_matrix_adjacency();

				std::vector <std::vector <int>> matrix_i;
				matrix_i = g[gr].Get_matrix_incidence();

				int v = g[gr].Get_vertices();
				int e = g[gr].Get_edges();

				g[gr].Get_matrix(2);
				int edge;
				std::cout << "e:";
				std::cin >> edge;

				for (int i = 0; i < v; i++)
				{
					matrix_a[i].push_back(0);
				}
				matrix_a.push_back(std::vector <int>(v + 1, 0));
				v += 1;// Добавили вершину - увеличили их количество
				int first = -1;
				int second = -1;
				for (int i = 0; i < e; i++) //v
				{
					if (matrix_i[i][edge - 1] == 1)
					{
						if (first == -1)
							first = i;
						else
							second = i;
					}

				}
				if (first == 2) break;
				for (int i = 0; i < v; i++)
				{
					if ((matrix_a[first][i] == 1) && (i != second))
					{
						matrix_a[v - 1][i] = 1;
						matrix_a[i][v - 1] = 1;
					}
					else if ((matrix_a[second][i] == 1) && (i != first))
					{
						matrix_a[v - 1][i] = 1;
						matrix_a[i][v - 1] = 1;
					}
					else
					{
						matrix_a[v - 1][i] = 0;
						matrix_a[i][v - 1] = 0;
					}
				}

				matrix_a.erase(matrix_a.begin() + first);
				for (int i = 0; i < v - 1; i++)
				{
					matrix_a[i].erase(matrix_a[i].begin() + first);
				}

				matrix_a.erase(matrix_a.begin() + second-1);
				for (int i = 0; i < v - 2; i++)
				{
					matrix_a[i].erase(matrix_a[i].begin() + second-1);
				}

				g[gr].Set_matrix(1, matrix_a);
				set_all_matrix(1, g[gr]);
				break;
			}
			case(26): // vertex identification
			{
				int gr = which_graph(g);

				std::vector <std::vector <int>> matrix_a;
				matrix_a = g[gr].Get_matrix_adjacency();

				std::vector <std::vector <int>> matrix_i;
				matrix_i = g[gr].Get_matrix_incidence();

				int v = g[gr].Get_vertices();
				int e = g[gr].Get_edges();

				g[gr].Get_matrix(1);
				int first, second;
				std::cout << "v1:";
				std::cin >> first;
				std::cout << "v2:";
				std::cin >> second;
				
				first--;
				second--;
				for (int i = 0; i < v; i++)
				{
					matrix_a[i].push_back(0);
				}
				matrix_a.push_back(std::vector <int>(v + 1, 0));

				v += 1;
				for (int i = 0; i < v; i++)
				{
					if ((matrix_a[first][i] == 1) && (i != second))
					{
						matrix_a[v - 1][i] = 1;
						matrix_a[i][v - 1] = 1;
					}
					else if ((matrix_a[second][i] == 1) && (i != first))
					{
						matrix_a[v - 1][i] = 1;
						matrix_a[i][v - 1] = 1;
					}
					else
					{
						matrix_a[v - 1][i] = 0;
						matrix_a[i][v - 1] = 0;
					}
				}

				matrix_a.erase(matrix_a.begin() + first);
				for (int i = 0; i < v - 1; i++)
				{
					matrix_a[i].erase(matrix_a[i].begin() + first);
				}

				matrix_a.erase(matrix_a.begin() + second - 1);
				for (int i = 0; i < v - 2; i++)
				{
					matrix_a[i].erase(matrix_a[i].begin() + second - 1);
				}

				g[gr].Set_matrix(1, matrix_a);
				set_all_matrix(1, g[gr]);
				break;
			}
			case(27): // Дубль
			{
				int gr = which_graph(g);
				std::vector <std::vector <int>> matrix;
				matrix = g[gr].Get_matrix_adjacency();

				g[gr].Get_matrix(1);
				int v;
				std::cout << "v:";
				std::cin >> v;

				v--;
				for (int i = 0; i < matrix.size(); i++)
				{
					matrix[i].push_back(0);
				}
				matrix.push_back(std::vector <int>(matrix.size() + 1, 0));

				for (int i = 0; i < matrix.size(); i++)
				{
					if (matrix[v][i] == 1)
					{
						matrix[matrix.size()-1][i] = 1;
						matrix[i][matrix.size() - 1] = 1;
					}
				}

				g[gr].Set_matrix(1, matrix);
				set_all_matrix(1, g[gr]);
				std::cout << "Added\n";
				break;
			}
			case(28): // Размножение
			{
				int gr = which_graph(g);
				std::vector <std::vector <int>> matrix;
				matrix = g[gr].Get_matrix_adjacency();

				g[gr].Get_matrix(1);
				int v;
				std::cout << "v:";
				std::cin >> v;

				v--;
				for (int i = 0; i < matrix.size(); i++)
				{
					matrix[i].push_back(0);
				}
				matrix.push_back(std::vector <int>(matrix.size() + 1, 0));

				for (int i = 0; i < matrix.size(); i++)
				{
					if (matrix[v][i] == 1)
					{
						matrix[matrix.size() - 1][i] = 1;
						matrix[i][matrix.size() - 1] = 1;
					}
				}
				matrix[matrix.size() - 1][v] = 1;
				matrix[v][matrix.size() - 1] = 1;

				g[gr].Set_matrix(1, matrix);
				set_all_matrix(1, g[gr]);
				std::cout << "Added\n";
				break;
			}
			case(29): // Объединение
			{
				int gr1, gr2;
				choose_two_graph(g,gr1,gr2);
				add_graph(g,0);
				std::vector <std::vector <int>> matrix_1;
				std::vector <std::vector <int>> matrix_2;
				
				matrix_1 = g[gr1].Get_matrix_adjacency();
				matrix_2 = g[gr2].Get_matrix_adjacency();

				int size1 = matrix_1.size();
				int size2 = matrix_2.size();
				std::vector <std::vector <int>> matrix(size1 + size2);

				for (int i = 0; i < size1 + size2; i++) {
					for (int j = 0; j < size1 + size2; j++) {
						matrix[i].push_back(0);
					}
				}

				for (int i = 0; i < size1 + size2; i++)
				{
					for (int j = 0; j < size1 + size2; j++)
					{
						if (i < size1)
						{
							if (j < size1)
							{
								matrix[i][j] = matrix_1[i][j];
							}
							else
							{
								matrix[i][j] = 0;
							}
						}
						else if (i >= size1)
						{
							if (j < size1)
							{
								matrix[i][j] = 0;
							}
							else
							{
								matrix[i][j] = matrix_2[i- size1][j- size1];
							}
						}
					}
				}
				
				g[g.size()-1].Set_matrix(1, matrix);
				set_all_matrix(1, g[g.size() - 1]);
				std::cout << "Added\n";
				break;
			}
			case(30): // Соединение
			{
				int gr1, gr2;
				choose_two_graph(g, gr1, gr2);
				add_graph(g,0);
				std::vector <std::vector <int>> matrix_1;
				std::vector <std::vector <int>> matrix_2;

				matrix_1 = g[gr1].Get_matrix_adjacency();
				matrix_2 = g[gr2].Get_matrix_adjacency();

				int size1 = matrix_1.size();
				int size2 = matrix_2.size();
				std::vector <std::vector <int>> matrix(size1 + size2);

				for (int i = 0; i < size1 + size2; i++) {
					for (int j = 0; j < size1 + size2; j++) {
						matrix[i].push_back(0);
					}
				}

				for (int i = 0; i < size1 + size2; i++)
				{
					for (int j = 0; j < size1 + size2; j++)
					{
						if (i < size1)
						{
							if (j < size1)
							{
								matrix[i][j] = matrix_1[i][j];
							}
							else
							{
								matrix[i][j] = 1;
							}
						}
						else if (i >= size1)
						{
							if (j < size1)
							{
								matrix[i][j] = 1;
							}
							else
							{
								matrix[i][j] = matrix_2[i - size1][j - size1];
							}
						}
					}
				}

				g[g.size() - 1].Set_matrix(1, matrix);
				set_all_matrix(1, g[g.size() - 1]);
				std::cout << "Added\n";
				break;
			}
			case(31): //  Умножение
			{
				int gr1, gr2;
				choose_two_graph(g, gr1, gr2);
				add_graph(g,0);
				std::vector <std::vector <int>> matrix_1;
				std::vector <std::vector <int>> matrix_2;

				matrix_1 = g[gr1].Get_matrix_adjacency();
				matrix_2 = g[gr2].Get_matrix_adjacency();

				int s1 = matrix_1.size();
				int s2 = matrix_2.size();
				int s3 = s1 * s2;
				int i1str = 0, i2str = 0, i1col = 0, i2col = 0;
				std::vector < std::vector < int >> vec3((s3), std::vector<int>((s3), 0));
				for (int i = 0; i < s3; i++) {
					i1str = i / s2;
					i2str = i % s2;
					for (int j = 0; j < s3; j++) {
						i1col = j / s2;
						i2col = j % s2;
						if (i1str == i1col)
						{
							if (matrix_2[i2str][i2col] == 1)
							{
								vec3[i][j] = 1;
							}
						}
						else if (i2str == i2col)
						{
							if (matrix_1[i1str][i1col] == 1)
							{
								vec3[i][j] = 1;
							}
						}
						else
						{
							vec3[i][j] = 0;
						}
					}
				}
				g[g.size() - 1].Set_matrix(1, vec3);
				set_all_matrix(1, g[g.size() - 1]);
				std::cout << "Added\n";
				break;
			}
			case (32):
			{
				int gr = which_graph(g);
				Save_ad(g[gr]);
				break;
			}
			case (33):
			{
				int gr = which_graph(g);
				Save_in(g[gr]);
				break;
			}
			case (34):
			{
				int gr = which_graph(g);
				Save_la(g[gr]);
				break;
			}
			default:
				break;
		}
	}
}
#include "Interface.h"
#include "Class_Graph.h"

#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <limits>

#include <algorithm>
#include <iomanip>

#define INT_MAX 2147483647
void add_graph(std::vector<Graph> &g, int org)
{
	g.push_back(Graph(org%2)); // 1- орграф, 0- не ор

}

void set_graph(int choose, std::vector<Graph> &g)
{
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::cout << "Path: ";
	std::string path;
	std::getline(std::cin, path);
	std::ifstream in(path);
	
	std::vector<std::vector<int>> matrix;
	std::string line;
	int num;
	for (int i = 0; getline(in, line); i++) {
		std::stringstream ss(line);
		matrix.push_back(std::vector<int>()); // добавляем новую строку
		while (ss >> num) {
			matrix[i].push_back(num); // в данную строку добавляем элементы.
		}
	}

	g[g.size() - 1].Set_matrix(choose, matrix);
	g[g.size() - 1].Get_matrix(choose);
	set_all_matrix(choose, g[g.size() - 1]);
	
}

void set_graph_or(int choose, std::vector<Graph> &g)
{
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::cout << "Path: ";
	std::string path;
	std::getline(std::cin, path);
	std::ifstream in(path);

	std::vector<std::vector<int>> matrix;
	std::string line;
	int num;
	for (int i = 0; getline(in, line); i++) {
		std::stringstream ss(line);
		matrix.push_back(std::vector<int>()); // добавляем новую строку
		while (ss >> num) {
			matrix[i].push_back(num); // в данную строку добавляем элементы.
		}
	}

	g[g.size() - 1].Set_matrix(choose, matrix);
	g[g.size() - 1].Get_matrix(choose);
	set_all_matrix_or(choose, g[g.size() - 1]);

}

void set_graph_list(std::vector<Graph> &g)
{
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::cout << "Path: ";
	std::string path;
	std::getline(std::cin, path);
	std::ifstream in(path);

	std::vector<std::vector<int>> matrix;
	std::string line;
	int num;
	getline(in, line);//считываем всю строку 
	int linesize = line.size();
	for (unsigned int i = 0, j = 0; linesize!=0; i++, j++)
	{
		std::string line1 = line;

		int begin = line1.find("{");
		line1.erase(0, begin+1);

		int end = line1.find("}");
		line1.erase(end, line1.size()-end);

		std::stringstream ss(line1);
		matrix.push_back(std::vector<int>());
		while (ss >> num) {
			matrix[j].push_back(num); // в данную строку добавляем элементы. 
		}
		i += end;
		line.erase(0, begin + end + 2);
		linesize = line.size();
	}

	g[g.size() - 1].Set_list_adjacency(matrix);
	g[g.size() - 1].Get_list_adjacency();
	set_all_matrix(3, g[g.size() - 1]);
}

void set_graph_list_or(std::vector<Graph> &g)
{
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::cout << "Path: ";
	std::string path;
	std::getline(std::cin, path);
	std::ifstream in(path);

	std::vector<std::vector<int>> matrix;
	std::string line;
	int num;
	getline(in, line);//считываем всю строку 
	int linesize = line.size();
	for (unsigned int i = 0, j = 0; i < linesize; i++, j++)
	{
		int begin = line.find("{");
		int end = line.find("}");
		std::string line1 = line;
		line1.erase(begin, begin + 1);
		line1.erase(end, line1.size());
		line1.erase(line1.size());
		std::stringstream ss(line1);
		matrix.push_back(std::vector<int>());
		while (ss >> num) {
			matrix[j].push_back(num); // в данную строку добавляем элементы. 
		}
		i += end;
		line.erase(begin, end + 1);
	}

	g[g.size() - 1].Set_list_adjacency(matrix);
	g[g.size() - 1].Get_list_adjacency();
	set_all_matrix_or(3, g[g.size() - 1]);
}

void set_all_matrix(int already, Graph &g) {
	switch (already)
	{
	case(1): // Матрица смежности уже есть
	{
		std::vector<std::vector<int>> matrix_adjacency;
		
		int size_m_a;
		int edges = 0;
		int sdvig = 0;
		matrix_adjacency = g.Get_matrix_adjacency();
		size_m_a = matrix_adjacency.size();
		for (int i = 0; i < size_m_a; i++) // Считываем количество ребер
		{
			for (int j = sdvig; j < size_m_a; j++) 
			{
				int a = 0;
				if (i == j)
				{
					a = matrix_adjacency[i][j];
					a = a / 2;
				}
				else 
					a = matrix_adjacency[i][j];
				if (a != 0)
					edges += a;
			}
			sdvig++;
		}

		sdvig = 0;
		std::vector<std::vector<int>> matrix_incidence(size_m_a); //Создаем нулевую матрицу инцидентности
		for (int i = 0; i < size_m_a; i++) {
			for (int j = 0; j < edges; j++) {
				matrix_incidence[i].push_back(0);
			}
		}

		int shet_reb = 0;
		for (int i = 0; i < size_m_a; i++) // Считываем количество ребер
		{
			for (int j = sdvig; j < size_m_a; j++)
			{
				int a = matrix_adjacency[i][j];
				if (a != 0) 
				{
					if (i != j) 
					{
						for (int r = 0; r < a; r++) {
							matrix_incidence[i][shet_reb] = 1;
							matrix_incidence[j][shet_reb] = 1;
							shet_reb++;
						}
					}
					else
					{
						a = a / 2;
						for (int r = 0; r < a; r++) {
							matrix_incidence[i][shet_reb] = 2;
							shet_reb++;
						}
					}
					
				}
					
			}
			sdvig++;
		}
		

		std::vector<std::vector<int>> list_adjacency(size_m_a);

		for (int i = 0; i < size_m_a; i++) // Считываем количество ребер
		{
			list_adjacency[i].push_back(i + 1);
			for (int j = 0; j < size_m_a; j++)
			{
				int a = 0;
				if (i != j)
				{
					a = matrix_adjacency[i][j];
					if (a != 0)
					{
						for (int r = 0; r < a; r++)
							list_adjacency[i].push_back(j + 1);
					}
				}
				else
				{
					a = matrix_adjacency[i][j];
					a = a / 2;
					if (a != 0)
					{
						for (int r = 0; r < a; r++)
							list_adjacency[i].push_back(j + 1);
					}
				}
			}
		}

		g.Set_matrix(2, matrix_incidence);
		g.Set_list_adjacency(list_adjacency);
		break;
	}
	case(2): // Матрица инцидентности уже есть
	{
		std::vector<std::vector<int>> matrix_incidence;
		int size_m_i = 0;
		matrix_incidence = g.Get_matrix_incidence();
		size_m_i = matrix_incidence.size();

		std::vector<std::vector<int>> matrix_adjacency(size_m_i);
		for (int i = 0; i < size_m_i; i++) {
			for (int j = 0; j < size_m_i; j++) {
				matrix_adjacency[i].push_back(0);
			}
		}

		float v_v = 0.5;
		for (unsigned int i = 0; i < matrix_incidence[0].size(); i++)
		{
			for (int j = 0; j < size_m_i; j++)
			{
				if (matrix_incidence[j][i] == 2)//petlya
				{
					matrix_adjacency[j][j] += 2;
				}
				else if (matrix_incidence[j][i] != 0)
				{
					if (v_v == 0.5)
					{
						v_v = (float)j;
					}
					else
					{
						if (matrix_incidence[(int)v_v][i] > 0)
							matrix_adjacency[(int)v_v][j] += 1;// matrix_incidence[(int)v_v][i];
						if (matrix_incidence[j][i] > 0)
							matrix_adjacency[j][(int)v_v] += 1;// matrix_incidence[j][i];
					}
				}
			}
			v_v = 0.5;
		}

		std::vector<std::vector<int>> list_adjacency(size_m_i);

		for (int i = 0; i < size_m_i; i++) // Считываем количество ребер
		{
			list_adjacency[i].push_back(i + 1);
			for (int j = 0; j < size_m_i; j++)
			{
				int a = 0;
				if (i != j)
				{
					a = matrix_adjacency[i][j];
					if (a != 0)
					{
						for (int r = 0; r < a; r++)
							list_adjacency[i].push_back(j + 1);
					}
				}
				else
				{
					a = matrix_adjacency[i][j];
					a = a / 2;
					if (a != 0)
					{
						for (int r = 0; r < a; r++)
							list_adjacency[i].push_back(j + 1);
					}
				}
			}
		}

		g.Set_matrix(1, matrix_adjacency);
		g.Set_list_adjacency(list_adjacency);
		break;
	}
	case(3): // Лист смежности уже есть
	{
		std::vector<std::vector<int>> list_adjacency;
		int size_l_a = 0;
		list_adjacency = g.Get_list_ad();
		size_l_a = list_adjacency.size();

		std::vector<std::vector<int>> matrix_adjacency(size_l_a);
		for (int i = 0; i < size_l_a; i++) {
			//transf.push_back(std::vector<int>(matrix_t.size()));
			for (int j = 0; j < size_l_a; j++) {
				matrix_adjacency[i].push_back(0);
			}
		}
		
		for (int i = 0; i < size_l_a; i++) {
			int first = 0;
			for (int j = 0; j < list_adjacency[i].size(); j++) {
				if (first == 0) first = list_adjacency[i][j];
				else
				{
					int second = list_adjacency[i][j];
					if (first!=second)
						matrix_adjacency[first-1][second -1 ] += 1;
					else 
						matrix_adjacency[first - 1][second - 1] += 2;
				}
				
			}
		}

		int sdvig = 0;
		int edges = 0;
		int size_m_a = matrix_adjacency.size();
		for (int i = 0; i < size_m_a; i++) // Считываем количество ребер
		{
			for (int j = sdvig; j < size_m_a; j++)
			{
				int a = 0;
				if (i == j)
				{
					a = matrix_adjacency[i][j];
					a = a / 2;
				}
				else
					a = matrix_adjacency[i][j];
				if (a != 0)
					edges += a;
			}
			sdvig++;
		}

		sdvig = 0;
		std::vector<std::vector<int>> matrix_incidence(size_l_a); //Создаем нулевую матрицу инцидентности
		for (int i = 0; i < size_l_a; i++) {
			for (int j = 0; j < edges; j++) {
				matrix_incidence[i].push_back(0);
			}
		}

		int shet_reb = 0;
		for (int i = 0; i < size_m_a; i++) {

			for (int j = sdvig; j < size_m_a; j++)
			{
				int a = matrix_adjacency[i][j];
				if (a != 0)
				{
					if (i != j)
					{
						for (int r = 0; r < a; r++) {
							matrix_incidence[i][shet_reb] += 1;
							matrix_incidence[j][shet_reb] += 1;
							shet_reb++;
						}
					}
					else
					{
						a = a / 2;
						for (int r = 0; r < a; r++) {
							matrix_incidence[i][shet_reb] += 2;
							shet_reb++;
						}
					}
				}
			}

			sdvig++;
		}

		g.Set_matrix(1, matrix_adjacency);
		g.Set_matrix(2, matrix_incidence);
		break;
	}
	default:
		break;
	}
}

void set_all_matrix_or(int already, Graph &g) {
	switch (already)
	{
	case(1): // Матрица смежности уже есть
	{
		std::vector<std::vector<int>> matrix_adjacency;

		int size_m_a;
		int edges = 0;
		int sdvig = 0;
		matrix_adjacency = g.Get_matrix_adjacency();
		size_m_a = matrix_adjacency.size();
		for (int i = 0; i < size_m_a; i++) // Считываем количество ребер
		{
			for (int j = 0; j < size_m_a; j++)
			{
				int a = 0;
				if (i!=j)
					a = matrix_adjacency[i][j];
				else
				{
					a = matrix_adjacency[i][j];
					a = a / 2;
				}
				if (a != 0)
					edges += a;
			}
		}

		sdvig = 0;
		std::vector<std::vector<int>> matrix_incidence(size_m_a); //Создаем нулевую матрицу инцидентности
		for (int i = 0; i < size_m_a; i++) {
			for (int j = 0; j < edges; j++) {
				matrix_incidence[i].push_back(0);
			}
		}

		int shet_reb = 0;
		for (int i = 0; i < size_m_a; i++) // Считываем количество ребер
		{
			for (int j = 0; j < size_m_a; j++)
			{
				int a = matrix_adjacency[i][j];
				if (a != 0)
				{
					if (i != j)
					{
						for (int r = 0; r < a; r++) {
							matrix_incidence[i][shet_reb] = 1;
							matrix_incidence[j][shet_reb] = -1;
							shet_reb++;
						}
					}
					else
					{
						for (int r = 0; r < a; r++) {
							a = a / 2;
							matrix_incidence[i][shet_reb] = 2;
							shet_reb++;
						}
					}
					
				}

			}
			sdvig++;
		}


		std::vector<std::vector<int>> list_adjacency(size_m_a);

		for (int i = 0; i < size_m_a; i++) // Считываем количество ребер
		{
			list_adjacency[i].push_back(i + 1);
			for (int j = 0; j < size_m_a; j++)
			{
				int a = 0;
				if (i != j)
				{
					a = matrix_adjacency[i][j];
					if (a != 0)
					{
						for (int r = 0; r < a; r++)
							list_adjacency[i].push_back(j + 1);
					}
				}
				else
				{
					a = matrix_adjacency[i][j];
					a = a / 2;
					if (a != 0)
					{
						for (int r = 0; r < a; r++)
							list_adjacency[i].push_back(j + 1);
					}
				}

			}
		}

		g.Set_matrix(2, matrix_incidence);
		g.Set_list_adjacency(list_adjacency);
		break;
	}
	case(2): // Матрица инцидентности уже есть
	{
		std::vector<std::vector<int>> matrix_incidence;
		int size_m_i = 0;
		matrix_incidence = g.Get_matrix_incidence();
		size_m_i = matrix_incidence.size();

		std::vector<std::vector<int>> matrix_adjacency(size_m_i);
		for (int i = 0; i < size_m_i; i++) {
			//transf.push_back(std::vector<int>(matrix_t.size()));
			for (int j = 0; j < size_m_i; j++) {
				matrix_adjacency[i].push_back(0);
			}
		}

		float v_v = 0.5;
		for (unsigned int i = 0; i < matrix_incidence[0].size(); i++)
		{
			for (int j = 0; j < size_m_i; j++)
			{
				if (matrix_incidence[j][i] == 2)//petlya
				{
					matrix_adjacency[j][j] += 2;
				}
				else if (matrix_incidence[j][i] != 0)
				{
					if (v_v == 0.5)
					{
						v_v = (float)j;
					}
					else
					{
						if (matrix_incidence[(int)v_v][i] > 0)
							matrix_adjacency[(int)v_v][j] += 1;// matrix_incidence[(int)v_v][i];
						if (matrix_incidence[j][i] > 0)
							matrix_adjacency[j][(int)v_v] += 1;// matrix_incidence[j][i];
					}
				}
			}
			v_v = 0.5;
		}

		std::vector<std::vector<int>> list_adjacency(size_m_i);

		for (int i = 0; i < size_m_i; i++) // Считываем количество ребер
		{
			list_adjacency[i].push_back(i + 1);
			for (int j = 0; j < size_m_i; j++)
			{
				int a = 0;
				if (i != j)
				{
					a = matrix_adjacency[i][j];
					if (a != 0)
					{
						for (int r = 0; r < a; r++)
							list_adjacency[i].push_back(j + 1);
					}
				}
				else
				{
					a = matrix_adjacency[i][j];
					a = a / 2;
					if (a != 0)
					{
						for (int r = 0; r < a; r++)
							list_adjacency[i].push_back(j + 1);
					}
				}
			}
		}

		g.Set_matrix(1, matrix_adjacency);
		g.Set_list_adjacency(list_adjacency);
		break;
	}
	case(3): // Лист смежности уже есть
	{
		std::vector<std::vector<int>> list_adjacency;
		int size_l_a = 0;
		list_adjacency = g.Get_list_ad();
		size_l_a = list_adjacency.size();

		std::vector<std::vector<int>> matrix_adjacency(size_l_a);
		for (int i = 0; i < size_l_a; i++) {
			//transf.push_back(std::vector<int>(matrix_t.size()));
			for (int j = 0; j < size_l_a; j++) {
				matrix_adjacency[i].push_back(0);
			}
		}

		for (int i = 0; i < size_l_a; i++) {
			int first = 0;
			for (int j = 0; j < list_adjacency[i].size(); j++) {
				if (first == 0) first = list_adjacency[i][j];
				else
				{
					int second = list_adjacency[i][j];
					if (first != second)
						matrix_adjacency[first - 1][second - 1] += 1;
					else
						matrix_adjacency[first - 1][second - 1] += 2;
				}

			}
		}

		int sdvig = 0;
		int edges = 0;
		for (int i = 0; i < size_l_a; i++) // Считываем количество ребер
		{
			for (int j = 0; j < size_l_a; j++)
			{
				int a = 0;
				if (i == j)
				{
					a = matrix_adjacency[i][j];
					a = a / 2;
				}
				else
					a = matrix_adjacency[i][j];
				if (a != 0)
					edges += a;
			}
		}

		sdvig = 0;
		std::vector<std::vector<int>> matrix_incidence(size_l_a); //Создаем нулевую матрицу инцидентности
		for (int i = 0; i < size_l_a; i++) {
			for (int j = 0; j < edges; j++) {
				matrix_incidence[i].push_back(0);
			}
		}

		int shet_reb = 0;
		for (int i = 0; i < size_l_a; i++)
		{
			for (int j = 0; j < size_l_a; j++)
			{
				int a = matrix_adjacency[i][j];
				if (a != 0)
				{
					if (i != j)
					{
						for (int r = 0; r < a; r++) {
							matrix_incidence[i][shet_reb] = 1;
							matrix_incidence[j][shet_reb] = -1;
							shet_reb++;
						}
					}
					else
					{
						a = a / 2;
						for (int r = 0; r < a; r++) {
							matrix_incidence[i][shet_reb] = 2;
							shet_reb++;
						}
					}
				}
			}
		}

		g.Set_matrix(1, matrix_adjacency);
		g.Set_matrix(2, matrix_incidence);
		break;
	}
	default:
		break;
	}
}

int which_graph(std::vector<Graph> &g)
{
	int gr = 0;
	if (g.size() != 1) {
		for (int i = 0; i < g.size(); i++)
		{
			std::cout << "G" << i + 1 << " ";
		}
		std::cout << "\nWhich graph?\n";
		std::cin >> gr;
		gr--;
	}
	return gr;
}

void choose_two_graph(std::vector<Graph> &g, int &gr1, int &gr2)
{
	if (g.size() >= 2) {
		for (int i = 0; i < g.size(); i++)
		{
			std::cout << "G" << i + 1 << " ";
		}
		std::cout << "\nG1? \n";
		std::cin >> gr1;
		gr1--;
		std::cout << "\nG2? \n";
		std::cin >> gr2;
		gr2--;
	}
	else
	{
		gr1 = -1;
		gr2 = -2;
	}
}

int which_ver(std::vector<Graph> &g, int gr)
{
	int ver;
	g[gr].Get_matrix(1);
	std::cout << "\nWhich vertices?\n";
	std::cin >> ver;
	return ver-1;
}

void source_and_sink(Graph &g, std::vector<int> &source, std::vector<int> &sink) 
{
	std::vector<std::vector<int>> matrix_adjacency;
	matrix_adjacency = g.Get_matrix_adjacency();
	for (int i = 0; i < matrix_adjacency.size(); i++)
	{
		int min = 0;
		for (int j = 0; j < matrix_adjacency.size(); j++)
		{
			if (matrix_adjacency[i][j] != 0)
			{
				min++;
				break;
			}
		}
		if (min == 0) 
			sink.push_back(i + 1);
	}

	for (int i = 0; i < matrix_adjacency.size(); i++)
	{
		int min = 0;
		for (int j = 0; j < matrix_adjacency.size(); j++)
		{
			if (matrix_adjacency[j][i] != 0)
			{
				min++;
				break;
			}
		}
		if (min == 0) source.push_back(i + 1);
	}
}

void Save_ad(Graph &g)
{
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::cout << "Path: ";
	std::string path;
	std::getline(std::cin, path);
	std::ofstream out(path);

	std::vector<std::vector<int>> matrix;
	matrix = g.Get_matrix_adjacency();
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix.size(); j++) {
			out << matrix[i][j] << " ";
		}
		out << "\n";
	}
}

void Save_in(Graph &g)
{
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::cout << "Path: ";
	std::string path;
	std::getline(std::cin, path);
	std::ofstream out(path);

	std::vector<std::vector<int>> matrix;
	matrix = g.Get_matrix_incidence();
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[0].size(); j++) {
			out << matrix[i][j] << " ";
		}
		out << "\n";
	}
}

void Save_la(Graph &g)
{
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::cout << "Path: ";
	std::string path;
	std::getline(std::cin, path);
	std::ofstream out(path);

	std::vector<std::vector<int>> matrix;
	matrix = g.Get_list_ad();
	for (int i = 0; i < matrix.size(); i++) {
		out << "{";
		for (int j = 0; j < matrix[i].size(); j++) {
			out << matrix[i][j] << " ";
		}
		out << "}";
	}
}
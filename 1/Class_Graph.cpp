#include "Class_Graph.h"
#define INT_MAX 2147483647
Graph::Graph(int org):
	orgraf(org)
{

}

void Graph::Get_matrix(int mat)
{
	std::cout << "\n";
	switch (mat)
	{
	case(1): {
		std::cout << std::left << std::setw(3) << "";
		for (int i = 0; i < matrix_adjacency_.size(); i++) {
			std::cout << std::left << std::setw(3) << i+1;
		}
		std::cout << "\n";
		for (int i = 0; i < (matrix_adjacency_.size()+1)*3; i++) {
			std::cout << "-";
		}
		std::cout << "\n";
		for (int i = 0; i < matrix_adjacency_.size(); i++) {
				std::cout << std::left << std::setw(2) << i + 1 << "|";
			for (int j = 0; j < matrix_adjacency_.size(); j++) {
				std::cout << std::left << std::setw(3) << matrix_adjacency_[i][j];
			}
			std::cout << "\n";
		}
		std::cout << "\n";
		break;
	}
	case(2): {
		std::cout << std::left << std::setw(3) << "";
		for (int i = 0; i < matrix_incidence_[0].size(); i++) {
			std::cout << std::left << std::setw(3) << i + 1;
		}
		std::cout << "\n";
		for (int i = 0; i < matrix_incidence_.size(); i++) {
			std::cout << std::left << std::setw(3) << i + 1;
			for (int j = 0; j < matrix_incidence_[0].size(); j++) {
				std::cout << std::left << std::setw(3) << matrix_incidence_[i][j];
			}
			std::cout << "\n";
		}
		std::cout << "\n";
		break;
	}
	default:
		break;
	}
	
}

void Graph::Set_matrix(int mat, std::vector<std::vector<int>> &matrix) 
{
	switch (mat) {
	case(1): {
		matrix_adjacency_ = matrix;
		vertices_ = matrix_adjacency_.size();
		break;
	}
	case(2): {
		matrix_incidence_ = matrix;
		edges_ = matrix_incidence_[0].size();
		break;
	}
	default:
		break;
	}
}

void Graph::Set_list_adjacency(std::vector<std::vector<int>> &matrix) 
{
	list_adjacency_ = matrix;
}

void Graph::Get_list_adjacency()
{
	std::cout << "\n";
	std::for_each(list_adjacency_.begin(), list_adjacency_.end(), [](std::vector<int>& ivec)
	{
		std::cout << "{ ";
		std::for_each(ivec.begin(), ivec.end(), [](int i)
		{
			std::cout << i << " ";
		});
		std::cout << "} ";
	});
	std::cout << "\n";
}

std::vector<std::vector<int>> Graph::Get_matrix_adjacency()
{
	return matrix_adjacency_;
}

std::vector<std::vector<int>> Graph::Get_matrix_incidence()
{
	return matrix_incidence_;
}

std::vector<std::vector<int>> Graph::Get_list_ad()
{
	return list_adjacency_;
}

int Graph::Get_vertices()
{
	return vertices_;
}

int Graph::Get_edges()
{
	return edges_;
}

int Graph::Deegree_vert(int vert)
{
	degree_[0] = 0;
	for (int i = 0; i < matrix_adjacency_.size(); i++) {
		if (matrix_adjacency_[vert][i] != 0)
		{
			if (vert!=i)
				degree_[0] += matrix_adjacency_[vert][i];
			else 
				degree_[0] += matrix_adjacency_[vert][i] / 2;
		}
	}
	return degree_[0];
}

void Graph::Deegree_vert_or(int vert, int &s1, int &s2)
{
	for (int i = 0; i < matrix_adjacency_.size(); i++) {
		if (matrix_adjacency_[vert][i] != 0)
			if (i!=vert)
				s1 += matrix_adjacency_[vert][i];
			else
			{
				s1 += (matrix_adjacency_[vert][i] / 2);
			}
	}
	for (int i = 0; i < matrix_adjacency_.size(); i++) {
		if (matrix_adjacency_[i][vert] != 0)
			if (i != vert)
				s2 += matrix_adjacency_[i][vert];
			else
			{
				s2 += (matrix_adjacency_[i][vert] / 2);
			}
	}
	return;
}

void Graph::Deegree_sequence(std::vector<int > &degree)
{
	for (int i = 0; i < matrix_adjacency_.size(); i++)
	{
		int deg = 0;
		for (int j = 0; j < matrix_adjacency_.size(); j++)
		{
			deg += matrix_adjacency_[i][j];
		}
		degree.push_back(deg);
	}
}

void Graph::Deegree_sequence_or(std::vector<int > &degree1, std::vector<int > &degree2)
{
	for (int i = 0; i < matrix_adjacency_.size(); i++)
	{
		int deg = 0;
		for (int j = 0; j < matrix_adjacency_.size(); j++)
		{
			if (i!=j)
				deg += matrix_adjacency_[i][j];
			else
				deg += ( matrix_adjacency_[i][j] / 2);
		}
		degree1.push_back(deg);
	}

	for (int i = 0; i < matrix_adjacency_.size(); i++)
	{
		int deg = 0;
		for (int j = 0; j < matrix_adjacency_.size(); j++)
		{
			if (i != j)
				deg += matrix_adjacency_[j][i];
			else
				deg += (matrix_adjacency_[j][i] / 2);
		}
		degree2.push_back(deg);
	}
}

void Graph::Get_hanging_vertices(std::vector<int> &ver)
{
	if (orgraf == 0) {
		for (int i = 0; i < matrix_adjacency_.size(); i++)
		{
			int deg = 0;
			for (int j = 0; j < matrix_adjacency_.size(); j++)
			{
				deg += matrix_adjacency_[i][j];
			}
			if (deg == 1) ver.push_back(i + 1);
		}
	}
	else
	{
		for (int i = 0; i < matrix_adjacency_.size(); i++)
		{
			int deg1 = 0;
			int deg2 = 0;
			for (int j = 0; j < matrix_adjacency_.size(); j++)
			{
				deg1 += matrix_adjacency_[i][j];
				deg2 += matrix_adjacency_[j][i];
			}
			if (((deg1 == 1)&&(deg2==0))||((deg1 == 0) && (deg2 == 1))) ver.push_back(i + 1);
		}
	}
}

void Graph::Get_isolated_vertices(std::vector<int> &ver)
{
	if (orgraf == 0) {
		for (int i = 0; i < matrix_adjacency_.size(); i++)
		{
			int deg = 0;
			for (int j = 0; j < matrix_adjacency_.size(); j++)
			{
				deg += matrix_adjacency_[i][j];
			}
			if (deg == 0) ver.push_back(i + 1);
		}
	}
	else
	{
		for (int i = 0; i < matrix_adjacency_.size(); i++)
		{
			int deg1 = 0;
			int deg2 = 0;
			for (int j = 0; j < matrix_adjacency_.size(); j++)
			{
				deg1 += matrix_adjacency_[i][j];
				deg2 += matrix_adjacency_[j][i];
			}
			if (((deg1 == 0) && (deg2 == 0))) ver.push_back(i + 1);
		}
	}
}

int Graph::Show_distance(int v1, int v2)
{
	std::vector <int> distance(vertices_);
	std::vector <int> visited(vertices_);
	std::vector <std::vector <int>> matrix_adjacency_s = matrix_adjacency_;
	//делаем простой
	for (int i = 0; i < matrix_adjacency_s.size(); i++)
	{
		for (int j = 0; j < matrix_adjacency_s.size(); j++)
		{
			if (i == j) matrix_adjacency_s[i][j] = 0;
			if (matrix_adjacency_s[i][j] != 0)
				matrix_adjacency_s[i][j] = 1;
		}
	}
	for (int i = 0; i < vertices_; i++) {
		distance[i] = INT_MAX;
	}
	distance[v1 - 1] = 0;
	int index;
	for (int p = 0; p < vertices_ - 1; p++) {
		int min = INT_MAX;
		for (int i = 0; i < vertices_; i++) {
			if (!visited[i] && distance[i] < min) {
				min = distance[i]; index = i;
			}
		}
		visited[index] = true;
		for (int i = 0; i < vertices_; i++) {
			if (!visited[i] && matrix_adjacency_s[index][i] > 0 && distance[index] != INT_MAX && distance[index] + matrix_adjacency_s[index][i] < distance[i]) {
				distance[i] = distance[index] + matrix_adjacency_s[index][i];
			}
		}
	}
	return distance[v2 - 1];
}

int Graph::Isor() const
{
	return orgraf;
}
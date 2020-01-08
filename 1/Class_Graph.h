#ifndef CLASS_GRAPH_H
#define CLASS_GRAPH_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

class Graph{
public:
	Graph(int org);
	void Get_matrix(int mat) ;
	void Set_matrix(int mat, std::vector<std::vector<int>> &matrix);
	void Set_list_adjacency(std::vector<std::vector<int>> &matrix);
	void Get_list_adjacency();
	int Get_vertices();
	int Get_edges();
	void Deegree_vert_or(int vert, int &s1, int &s2);
	int Deegree_vert(int vert);
	void Deegree_sequence(std::vector<int > &degree);
	void Deegree_sequence_or(std::vector<int > &degree1, std::vector<int > &degree2);
	void Get_hanging_vertices(std::vector<int> &ver);
	void Get_isolated_vertices(std::vector<int> &ver);
	int Show_distance(int v1, int v2);
	std::vector<std::vector<int>> Get_matrix_adjacency();
	std::vector<std::vector<int>> Get_matrix_incidence();
	std::vector<std::vector<int>> Get_list_ad();
	int Isor() const;

private:
	bool orgraf;
	int vertices_; //Вершины
	int edges_; //Ребра
	int degree_[2]; //Степень вершины

	std::vector<int> degree_sequence_; //Степенная последовательность
	std::vector<std::vector<int>> matrix_adjacency_; //Матрица смежности
	std::vector<std::vector<int>> matrix_incidence_; //Матрица инцидентности
	std::vector<std::vector<int>> list_adjacency_;
	std::vector<int> hanging_vertices_;
	std::vector<int> isolated_vertices_;
	std::vector<int> source_;
	std::vector<int> drain_;
	int distance_;
	int eccentricity_;
	int d_;
	int r_;
	std::vector<int> o_;
	std::vector<int> peripheral_;

};

#endif // CLASS_GRAPH_H
// Quick_SortTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
//#include "GameNode.h"
using namespace std;



struct Node
{


	double GetRating();
	string GetName();
	string GetGenre();


	double rating;
	string name;
	string genre;

	Node() {
		rating = 0.0;
		name = "";
		genre = "";
	}
	Node(double rating, string name, string genre) {
		this->rating = rating;
		this->name = name;
		this->genre = genre;
	}

};






void QuickSort(vector<Node*>& GameList, int low, int high);
int Partition(vector<Node*>& GameList, int low, int high);

int main()
{
	//number of inputs
	int numIn;
	cin >> numIn;

	//strings for input
	string ratingVal;
	string name;
	string genre;

	//vector of nodes
	vector<Node*> nodes;

	for (int i = 0; i < numIn; i++){
	
		cin >> ratingVal;
		cin >> name;
		cin >> genre;

		/*
		Example Input:
		5
		7 AC_Odyssey RPG
		5 BO3 Shooter
		9 HaloCE Shooter
		10 EldenRing RPG
		3 Anthem RPG

		*/
		double rating = stod(ratingVal);

		Node* node = new Node(rating, name, genre);		

		//cout << node->GetRating() << " " << node->GetName() << " " << node->GetGenre() << "\n";	

		nodes.push_back(node);

	}

	//choose middle value as pviot
	swap(nodes[0], nodes[(int)nodes.size() / 2]);
	
	//low and high values for quicksort
	int low = 0;
	int high = nodes.size() - 1;
	QuickSort(nodes, low, high);

	cout << "\n";
	for (int i = 0; i < nodes.size(); i++) {	
		cout << nodes[i]->rating << " " << nodes[i]->name << " " << nodes[i]->genre << "\n";	
	}
}


/***************************************************************************************
*    Title: <Quick Sort Code>
*    Author: <Professor Amanpreet Kapoor>
*    Date: <Oct 25, 2022>
*    Code version: <N/A>
*    Availability: <UF Canvas Module 6 DSA (COP 3530)>
*
***************************************************************************************/

//Quick-Sort Implementation
void QuickSort(vector<Node*>& GameList, int low, int high) {
	//make a quick sort
	if (low < high) {
		int pivot = Partition(GameList, low, high);
		QuickSort(GameList, low, pivot - 1);
		QuickSort(GameList, pivot + 1, high);

	}

}
int Partition(vector<Node*>& GameList, int low, int high) {

	double pivot = GameList[low]->rating;
	int up = low;
	int down = high;

	while (up < down) {
		for (int i = up; i < high; i++) {
			if (GameList[up]->rating > pivot)
				break;
			up++;
		}
		for (int i = high; i > low; i--) {

			if (GameList[down]->rating < pivot)
				break;
			down--;
		}
		if (up < down) {

		
			swap(GameList[up], GameList[down]);
			
		}
	}
	swap(GameList[low], GameList[down]);
	return down;

}


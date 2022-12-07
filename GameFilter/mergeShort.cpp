#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

struct game
{
	string name, genre, developer;
	double rating;

	game()
	{
		name, genre, developer = "";
		rating = 0.0;
	}


	game(string name, string genre, string developer, double rating)
	{
		this->name = name;
		this->genre = genre;
		this->developer = developer;
		this->rating = rating;
	}

};

void merge(vector<game*>& gameArchive, int start, int mid, int end)
{
	vector<game*> leftVec(mid - start + 1);
	vector<game*> rightVec(end - mid);

	// Fill in left vector
	for (int i = 0; i < leftVec.size(); ++i)
		leftVec[i] = gameArchive[start + i];

	// Fill in right vector
	for (int i = 0; i < rightVec.size(); ++i)
		rightVec[i] = gameArchive[mid + 1 + i];

	int leftInd = 0, rightInd = 0;
	int curr = start; 
	int leftSize = leftVec.size();
	int rightSize = rightVec.size();

	// Compare each index of the subarrays, adding the highest value to curr
	while (leftInd < leftSize && rightInd < rightSize)
	{
		if (leftVec[leftInd]->rating <= rightVec[rightInd]->rating)
		{
			gameArchive[curr] = rightVec[rightInd];
			rightInd++;
		}

		else
		{
			gameArchive[curr] = leftVec[leftInd];
			leftInd++;
		}

		curr++;
	}

	// Add remaining values on the right subarray
	while (rightInd < rightSize)
		gameArchive[curr++] = rightVec[rightInd++];
	// Add remaining vlaues in the left subarray
	while (leftInd < leftSize)
		gameArchive[curr++] = leftVec[leftInd++];
	

}

void mergeSort(vector<game*>& gameArchive, int left, int right)
{
	// Base case is if start = end and sorting array of 1
	if (right > left)
	{
		// Mid is the index where the vector is divided into 2 vectors
		int mid = (left + right) / 2;

		mergeSort(gameArchive, left, mid); // Sort left side
		mergeSort(gameArchive, mid + 1, right); // Sort right side

		merge(gameArchive, left, mid, right); // Merge sorted halves
		
	}
	
}



	


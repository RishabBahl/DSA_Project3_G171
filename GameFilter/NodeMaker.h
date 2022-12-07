#pragma once

#include <iostream>

#include <istream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

class Game {
public:
    string title;
    int year;
    double rating;
    vector<string> genres;
    vector<string> platforms;
    string esrb;
    int udg=0;
    int udp = 0;
    int gennum() {
        
        return (int)genres.size();
    }
    int platnum() {
       
        return (int)platforms.size();
    }

};
class DataSaver {
public:
    int select = 0;
    
    vector <Game*> yearsNA;
    vector <Game*> years60to79;
    vector <Game*> years80to99;
    vector <Game*> years00to19;
    vector <Game*> years20toNow;
    vector <Game*> cont=years00to19;

    DataSaver() {
        //cout << "Hello, World!" << std::endl;
        ifstream file("game_info (1).csv");
        string bob;
        getline(file, bob);
        getline(file, bob);
        for (int i = 0; i < 1; i *= 1) {
            if ((bob == ",,,,,")||(bob=="")||(bob==" ")) {
                break;
            }
            Game* trashy = new Game();
            

            int comma = 0;
            int extra = 0;
            string year;
            string rating;
            string genre;
            string platform;
            string esrb;
            //cout << "bob" << ": " << bob.size() << endl;
            for (int j = 0; j < bob.size(); j++) {
                if (bob[j] == ',') {
                    extra++;
                }
            }
            extra -= 5;
            for (int j = 0; j < bob.size(); j++) {
                //cout << j << endl;

                if ((comma == 0) && (bob[j] != ',')) {
                    trashy->title = trashy->title + bob[j];
                }
                if ((comma == 1) && (bob[j] != ',')) {
                    year = year + bob[j];
                }
                if ((comma == 2) && (bob[j] != ',')) {
                    rating = rating + bob[j];
                }
                if ((comma == 3) && (bob[j] != ',')) {
                    if ((bob[j] == '|') && (platform != "")) {
                        trashy->platforms.push_back(platform);
                        platform = "";
                    }
                    else if (bob[j] != '|') {
                        platform = platform + bob[j];
                    }

                }
                if ((comma == 4) && (bob[j] != ',')) {
                    if ((bob[j] == '|') && (genre != "")) {
                        trashy->genres.push_back(genre);
                        genre = "";
                    }
                    else if (bob[j] != '|') {
                        genre = genre + bob[j];
                    }

                }
                if ((comma == 5) && (bob[j] != ',')) {
                    //cout << "oops" << endl;
                    trashy->esrb = trashy->esrb + bob[j];
                }
                if ((bob[j] == ',') && (extra == 0)) {
                    if (comma == 3) {
                        trashy->platforms.push_back(platform);
                    }
                    if (comma == 4) {
                        trashy->genres.push_back(genre);
                    }
                    comma++;
                }
                else if ((bob[j] == ',') && (extra != 0)) {
                    trashy->title = trashy->title + bob[j];
                    extra--;
                }

            }
            if (year.size() <= 1) {
                trashy->year = 0;
            }
            else {
                //cout << trashy->title << endl;
                //cout << year << endl;
                year = year.substr(year.size() - 4);
                trashy->year = stoi(year);
            }
            trashy->rating = stod(rating);
            if (trashy->year == 0) {
                yearsNA.push_back(trashy);
            }
            else if (trashy->year <= 1979) {
                years60to79.push_back(trashy);
            }
            else if (trashy->year <= 1999) {
                years80to99.push_back(trashy);
            }
            else if (trashy->year <= 2019) {
                years00to19.push_back(trashy);
            }
            else {
                years20toNow.push_back(trashy);
            }

            getline(file, bob);
            //cout << bob << endl;
        }

        //cout << bob << endl;
    }
    
    int ys60to79;
    int ys80to99;
    int ys00to19;
    int ys20toNow;

    void setter() {
        ys60to79 = years60to79.size();
        ys80to99 = years80to99.size();
        ys00to19 = years00to19.size();
        ys20toNow = years20toNow.size();
      
    }
    void QuickSort(vector<Game*>& GameList, double low, double high) {
        //make a quick sort
        if (low < high) {
            int pivot = Partition(GameList, low, high);
            QuickSort(GameList, low, pivot - 1);
            QuickSort(GameList, pivot + 1, high);

        }

    }
    double Partition(vector<Game*>& GameList, double low, double high) {

        double pivot = GameList[low]->rating;
        if (pivot == 5) {
            pivot--;
        }
        double up = low;
        double down = high;

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

    //MERGESORT

    void merge(vector<Game*>& GameArchive, int start, int mid, int end)
    {
        vector<Game*> leftVec(mid - start + 1);
        vector<Game*> rightVec(end - mid);

        // Fill in left vector
        for (int i = 0; i < leftVec.size(); ++i)
            leftVec[i] = GameArchive[start + i];

        // Fill in right vector
        for (int i = 0; i < rightVec.size(); ++i)
            rightVec[i] = GameArchive[mid + 1 + i];

        int leftInd = 0, rightInd = 0;
        int curr = start;
        int leftSize = leftVec.size();
        int rightSize = rightVec.size();

        // Compare each index of the subarrays, adding the highest value to curr
        while (leftInd < leftSize && rightInd < rightSize)
        {
            if (leftVec[leftInd]->rating <= rightVec[rightInd]->rating)
            {
                GameArchive[curr] = rightVec[rightInd];
                rightInd++;
            }

            else
            {
                GameArchive[curr] = leftVec[leftInd];
                leftInd++;
            }

            curr++;
        }

        // Add remaining values on the right subarray
        while (rightInd < rightSize)
            GameArchive[curr++] = rightVec[rightInd++];
        // Add remaining vlaues in the left subarray
        while (leftInd < leftSize)
            GameArchive[curr++] = leftVec[leftInd++];


    }

    void mergeSort(vector<Game*>& GameArchive, int left, int right)
    {
        // Base case is if start = end and sorting array of 1
        if (right > left)
        {
            // Mid is the index where the vector is divided into 2 vectors
            int mid = (left + right) / 2;

            mergeSort(GameArchive, left, mid); // Sort left side
            mergeSort(GameArchive, mid + 1, right); // Sort right side

            merge(GameArchive, left, mid, right); // Merge sorted halves

        }

    }
};
DataSaver idiot;


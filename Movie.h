#pragma once
#include <iostream>
#include <string>
using namespace std;

class Movie {
private:
	//private members
	string MovieName;
	int MovieID, PubYear, numReviews;
	int Ratings[5];
	float averageRating;
	
public:
	//constructor prototype
	Movie(int id, string name, int year);

	//accessor prototypes
	int getMovieID();
	string getMovieName();
	int getPubYear();
	int getRating(int num);
	int getNumReviews();
	float getAverageRating();

	//mutator prototypes
	void setRating(int num);
	void setNumReviews(int num);

	//functions
	void incrementReviews();
	void calculatetAverageRating();
	void displayInformation();

};//end Movie class
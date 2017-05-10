#pragma once
#include <iostream>
#include <string>
using namespace std;

class Review {
private:
	//private members
	int MovieID, UserID, Rating, numRating;
	string ReviewDate;

public:
	//constructor prototype
	Review(int mid, int uid, int rating);

	//accessor prototypes
	int getMovieID();
	int getUserID();
	int getRating();
	int getNumRating();
	string getReviewDate();

	//mutator prototypes
	void setNumRating(int num);

	//function
	void incrementNumReviews();

};//end Review class

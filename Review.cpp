#include "Review.h"

//constructor
Review::Review(int mid, int uid, int rating) {
	MovieID = mid;
	UserID = uid;
	Rating = rating;
	numRating = 0;
}

/*
Review::Review(int uid, int rating) {
	UserID = uid;
	numRating = rating;
}
*/

//accessors
int Review::getMovieID() { return MovieID; }
int Review::getUserID() { return UserID; }
int Review::getRating() { return Rating; }
int Review::getNumRating() { return numRating; }

//mutators
void Review::setNumRating(int num) {
	numRating = num;
}

//functions
void Review::incrementNumReviews() {
	numRating++;
}
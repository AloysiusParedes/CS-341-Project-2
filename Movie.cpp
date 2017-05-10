#include "Movie.h"

//constructor
Movie::Movie(int id, string name, int pub) {
	MovieID = id;
	MovieName = name;
	PubYear = pub;
	for (int i = 0; i < 5; i++)
		Ratings[i] = 0;
	numReviews = 0;
	averageRating = 0;
}

//accessors
int Movie::getMovieID() { return MovieID; }
string Movie::getMovieName() { return MovieName; }
int Movie::getPubYear() { return PubYear;}
int Movie::getRating(int num) { return Ratings[num - 1]; }
int Movie::getNumReviews() { return numReviews; }
float Movie::getAverageRating() { return averageRating; }

//mutators
void Movie::setRating(int num) { Ratings[num - 1]++; }
void Movie::setNumReviews(int num){ numReviews = num; }

//functions
void Movie::calculatetAverageRating() {
	float average = 0;

	for (int i = 0; i < 5; i++) 
		average += ((i + 1) * Ratings[i]);

	averageRating = average / getNumReviews();
}

void Movie::incrementReviews() { numReviews++; }

void Movie::displayInformation() {
	cout << "Movie:\t\t" << "\"" << MovieName << "\"" << "\nYear:\t\t" << PubYear << "\nAvgRating:\t" << averageRating << "\nNumReviews:\t" << getNumReviews() << endl;

	for (int i = 0; i < 5; i++)
		cout << "Num " << i + 1 << "'s:\t" << Ratings[i] << endl;
}



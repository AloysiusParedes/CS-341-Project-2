/*
Name:		Aloysius Paredes
Program:	CS 341 Fall 2016 Homework 2
Descr:		Netflix Movie Reviews - Analyze Netflix moview reviews. There are 2 text files, one containing moview reviews, and one containing the names of the movies.
*/

#include <iostream>
#include <fstream>	//used for istream
#include <string>	//used for C++ string
#include <vector>	//used for vectors
#include <sstream>	//used to help parse CSV (comma-separated values)
#include <algorithm>//used for sorts

#include "Movie.h"
#include "Review.h"
using namespace std;

int main() {
	//header
	cout << "** Netflix Movie Review Analysis **" << endl << endl;
	
	//vector declarations
	vector<Movie> movies;
	vector<Review> reviews;
	vector<Review> reviewers;

	//comma separate strings for files
	string line, movieID, movieName, pubYear, userID, rating, reviewDate;

	//values to hold number of crimes and number of crime codes
	int numMovies = 0, numReviews = 0;

	//read in movies
	ifstream moviesFile("movies.csv");

	//check if file can be open and read
	if (!moviesFile.good()) {
		cout << "\nCANNOT OPEN movies.csv!\n\n";
		return -1;
	}

	//skip header
	getline(moviesFile, line);

	//read until the end of the movies file
	while (getline(moviesFile, line)) {
		//hold the entire line
		stringstream ss(line);

		//parse line
		getline(ss, movieID, ',');
		getline(ss, movieName, ',');
		getline(ss, pubYear);

		//create object
		Movie m(stoi(movieID), movieName, stoi(pubYear));

		//insert object at the end of vector
		movies.push_back(m);
	}

	//update number of movies
	numMovies = movies.size();
	
	//output number of movies
	cout << ">> Reading movies...\t" << numMovies << endl;

	//close the file
	moviesFile.close();

	//sort movies by ID number
	sort(movies.begin(), movies.end(), 
		[&](Movie s1, Movie s2) {
		if (s1.getMovieID() < s2.getMovieID())
			return true;
		else
			return false;
		});

	//read in reviews
	ifstream reviewsFile("reviews.csv");

	//check if file can be open and read
	if (!reviewsFile.good()) {
		cout << "\nCANNOT OPEN reviews.csv!\n\n";
		return -1;
	}

	//skip header
	getline(reviewsFile, line);

	//read until the end of the reviews file
	while (getline(reviewsFile, line)) {
		int flag = 0;
		//hold the entire line
		stringstream ss(line);

		//parse line
		getline(ss, movieID, ',');
		getline(ss, userID, ',');
		getline(ss, rating, ',');
		getline(ss, reviewDate);

		//create object
		Review r(stoi(movieID), stoi(userID), stoi(rating));

		int index = stoi(movieID) - 1;
		int ratingVal = stoi(rating);

		//insert object at the end of vector
		reviews.push_back(r);

		//update number of reviews for a specific movie ID
		movies.at(index).incrementReviews();

		//update rating value
		movies.at(index).setRating(ratingVal);
	}

	//update number of movies
	numReviews = reviews.size();
	
	//calculate the averages for all the movies
	for (int i = 0; i < numMovies; i++)
		movies.at(i).calculatetAverageRating();

	//output number of reviews
	cout << ">> Reading reviews...\t" << numReviews << endl << endl;

	//close the file
	reviewsFile.close();

	//sort movies by rating number
	sort(movies.begin(), movies.end(),
		[&](Movie s1, Movie s2) {
		if (s1.getAverageRating() > s2.getAverageRating())
			return true;
		else if (s1.getAverageRating() < s2.getAverageRating())
			return false;
		else{
			if (s1.getMovieName() < s2.getMovieName())
				return true;
			else
				return false;
		}
	});

	//output the top 10 movies based on average rating, then by movie name
	cout << ">> Top-10 Movies <<" << endl;
	cout << "Rank\tID\tReviews\tAvg\tName" << endl;
	for (int i = 0; i < 10; i++) 
		cout << i + 1 << ".\t" << movies.at(i).getMovieID() << "\t" << movies.at(i).getNumReviews() << "\t" << movies.at(i).getAverageRating() << "\t" << "\"" << movies.at(i).getMovieName() << "\""<< endl;
	
	//sort reviews by userID
	sort(reviews.begin(), reviews.end(),
		[&](Review r1, Review r2) {
		if (r1.getUserID() < r2.getUserID())
			return true;
		else
			return false;
	});

	//count the number of reviews each user has made
	int count = 0;
	for (int i = 0; i < numReviews - 1; i++) {
		if (reviews.at(i).getUserID() == reviews.at(i + 1).getUserID()) {
			count++;
			continue;
		}
		else {
			Review r = reviews.at(i);
			r.setNumRating(count + 1);
			reviewers.push_back(r);
			count = 0;
		}
	}

	//sort reviewers by number of ratings
	sort(reviewers.begin(), reviewers.end(),
		[&](Review r1, Review r2) {
		if (r1.getNumRating() > r2.getNumRating())
			return true;
		else if (r1.getNumRating() < r2.getNumRating())
			return false;
		else{ //sort by userID if number of ratings are the same
			if (r1.getUserID() < r2.getUserID())
				return true;
			else
				return false;
		}
	});
	
	//output the top 10 users based on # of reviews submitted, then by user id
	cout << "\n>> Top-10 Users <<" << endl;
	cout << "Rank\tID\t\tReviews" << endl;
	for (int i = 0; i < 10; i++)
		cout << i + 1 << ".\t" << reviewers.at(i).getUserID() << "\t\t" << reviewers.at(i).getNumRating() << endl;

	//sort movies by ID number
	sort(movies.begin(), movies.end(),
		[&](Movie s1, Movie s2) {
		if (s1.getMovieID() < s2.getMovieID())
			return true;
		return false;
	});

	//user interactive loop
	cout << "\n>> Movie Information <<" << endl;
	int userInput = numMovies + 1;
	while (userInput != 0) {
		cout << "Please enter a movie ID [1..." << numMovies << "], 0 to stop: ";
		cin >> userInput;

		if(userInput > 0 && userInput <= numMovies)
			movies.at(userInput - 1).displayInformation();
		else if (userInput == 0) {
			cout << "\n\n** DONE **" << endl << endl;
			break;
		}
		else
			cout << "** Invalid movie ID, please try again..." << endl << endl;
	}

	return 0;
}//end main()
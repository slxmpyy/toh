// mixtapre.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Caden Johnson
// 9.8.2026
// Review Music
//

#include <iostream>
#include <string>
#include <vector>

void eachTrack(int totalTracks, std::vector<std::string>& tracks, std::vector<double>& trackRatings, std::vector<std::string>& trackNotes);
int main()
{
	std::vector<std::string> tracks;
	std::vector<std::string> trackNotes;
	std::vector<double> trackRatings;
	std::string title;
	std::string favorite;
	std::string weakest;
	int totalTracks;
	double overallAvg;
	double sum = 0;																						//should be initialize bc adding things to it

	std::cout << "What's the title of the piece you're reviewing?\n";
	std::getline(std::cin, title);
	std::cout << "and how many tracks?\n";
	std::cin >> totalTracks;
	std::cin.ignore();																					//cin leaving lefotver newline therefore,
																										//.ignore in the function before getline
	eachTrack(totalTracks, tracks, trackRatings, trackNotes);

	std::cout << "\nReviewing: " << title << "\n\n";
	for (int i = 0; i < totalTracks; ++i) {
		std::cout << tracks[i] << '\n';
		std::cout << trackRatings[i] << "/10\n";
		std::cout << "Track Notes: " << trackNotes[i] << "\n\n";
	}

	if (totalTracks > 1) {
		double greatest = 0;
		double least = 10;																				//initialize greatest to 0 because regardless the block
		int i = 0;																						//will always execute even if they enter a 0
		for (double rating : trackRatings) {
			sum += rating;
			if (rating > greatest) {
				greatest = rating;
				favorite = tracks[i];
			}
			if (rating < least) {
				least = rating;
				weakest = tracks[i];
			}
			++i;
		}
		overallAvg = sum / totalTracks;

		std::cout << "Overall, your average rating was " << overallAvg << '\n';
		std::cout << "Favorite: " << favorite << '\n';
		std::cout << "Weakest: " << weakest;
	}

	return 0;
}
void eachTrack(int totalTracks, std::vector<std::string>& tracks, std::vector<double>& trackRatings, std::vector<std::string>& trackNotes) {
	std::string currentTrackTitle;
	double currentTrackRating;
	std::string currentTrackNote;

	for (int i = 0; i < totalTracks; ++i) {
		std::cout << "\nTrack " << i + 1 << " title: ";
		std::getline(std::cin, currentTrackTitle);
		tracks.push_back(currentTrackTitle);
		
		std::cout << "Rating out of 10: ";
		std::cin >> currentTrackRating;
		std::cin.ignore();																					//newline still sitting in buffer after cin so
		trackRatings.push_back(currentTrackRating);															//.ignore so getline doesnt grab it and give empty

		std::cout << "Notes: ";
		std::getline(std::cin, currentTrackNote);
		trackNotes.push_back(currentTrackNote);
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

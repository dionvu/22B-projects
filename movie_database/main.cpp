#include <cctype>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

struct Movie {
  string title;
  double grossTotal;
  string director;
  string releaseDate;
  int runTime;
};

int numberOfLines(ifstream &file) {
  string temp;
  int count = 0;
  while (getline(file, temp))
    count++;
  file.clear();
  file.seekg(0);
  return count;
}

void populateMovieFromFile(ifstream &file, Movie &movie) {
  string temp;
  getline(file, movie.title, ',');

  getline(file, temp, ',');
  movie.grossTotal = stod(temp);

  getline(file, temp, ',');
  movie.director = temp.substr(1, temp.length() - 1);

  getline(file, temp, ',');
  movie.releaseDate = temp.substr(1, temp.length() - 1);

  getline(file, temp);
  movie.runTime = stoi(temp);
}

void displayMovie(const Movie &movie) {
  cout << movie.title << ", " << movie.grossTotal << ", " << movie.director
       << ", " << movie.releaseDate << ", " << movie.runTime << '\n';
}

Movie *createDatabase(int &numMovies) {
  string fileName;
  Movie *movies;
  ifstream file;

  do {
    file.close();

    cout << "Enter the input file name: ";
    cin >> fileName;
    fileName += ".txt";

    file.open(fileName);

    if (!file)
      cout << "Enter a valid file name.\n";
  } while (!file);

  numMovies = numberOfLines(file);

  movies = new Movie[numMovies];

  for (int i = 0; i < numMovies; i++)
    populateMovieFromFile(file, movies[i]);

  return movies;
}

bool caseInsenitiveCmp(string str1, string str2) {
  string result;
  for (char c : str1)
    result += tolower(c);
  str1 = result;
  result.clear();

  for (char c : str2)
    result += tolower(c);
  str2 = result;

  return str1 == str2;
}

int main() {
  int numMovies;
  Movie *movies;

  movies = createDatabase(numMovies);

  for (int i = 0; i < numMovies; i++) {
    cout << "Movie " << i + 1 << endl;
    displayMovie(movies[i]);
  }

  cout << caseInsenitiveCmp("youjJjJ cum", "YouJJJJ kum");

  delete[] movies;
}

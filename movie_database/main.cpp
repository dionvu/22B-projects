/**
 * @brief A program to manage a movie database, including searching for movies,
 * displaying them, and saving favorites to a file.
 *
 * @date 2024 Jan 30
 */

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

/**
 * @struct Movie
 * @brief Represents a movie with its title, gross total, director, release
 * date, and run time.
 */
struct Movie {
  string title;
  double grossTotal;
  string director;
  string releaseDate;
  int runTime;
};

// Prototypes
int numberOfLines(std::ifstream &file);
void populateMovieFromFile(std::ifstream &file, Movie &movie);
void displayMovie(const Movie &movie);
Movie *createDatabase(int &numMovies);
bool caseInsensitiveCmp(std::string str1, std::string str2);
void saveToFile(const Movie &movie);
void findMovie(Movie *movies, int numMovies);
bool promptToContinue();
void displayFavorites();

int main() {
  int numMovies;
  Movie *movies;
  char input;

  movies = createDatabase(numMovies);

  do
    findMovie(movies, numMovies);
  while (promptToContinue());

  displayFavorites();

  delete[] movies;
}

/**
 * @brief Counts the number of lines in a file.
 * @param file The input file stream.
 * @return The number of lines in the file.
 */
int numberOfLines(ifstream &file) {
  string temp;
  int count = 0;
  while (getline(file, temp))
    count++;
  file.clear();
  file.seekg(0);
  return count;
}

/**
 * @brief Populates a Movie struct from a file.
 * @param file The input file stream.
 * @param movie The Movie struct to populate.
 */
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

/**
 * @brief Displays details of a movie.
 * @param movie The Movie struct to display.
 */
void displayMovie(const Movie &movie) {
  cout << '\n';
  cout << "Title: " << movie.title << '\n';
  cout << "Gross total: " << movie.grossTotal << '\n';
  cout << "Director: " << movie.director << '\n';
  cout << "Release date: " << movie.releaseDate << '\n';
  cout << "Runtime: " << movie.runTime << '\n';
  cout << '\n';
}

/**
 * @brief Creates a movie database from a file.
 * @param numMovies Reference to the number of movies in the database.
 * @return Pointer to the array of Movie structs.
 */
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

/**
 * @brief Performs a case-insensitive comparison of two strings.
 * @param str1 The first string.
 * @param str2 The second string.
 * @return True if the strings are equal, ignoring case; otherwise, false.
 */
bool caseInsenitiveCmp(string str1, string str2) {
  if (str1.length() != str2.length())
    return false;

  for (int i = 0; i < str1.length(); i++)
    if (tolower(str1[i]) != tolower(str2[i]))
      return false;

  return true;
}

/**
 * @brief Saves a movie to a file.
 * @param movie The Movie struct to save.
 */
void saveToFile(const Movie &movie) {
  static bool opened = false;
  ofstream favorites;

  if (!opened) {
    favorites.open("favorites.txt");
    favorites << movie.title << ", " << movie.grossTotal << ", "
              << movie.director << ", " << movie.releaseDate << ", "
              << movie.runTime << '\n';
    opened = true;
  } else {
    favorites.open("favorites.txt", ios::app);
    favorites << movie.title << ", " << movie.grossTotal << ", "
              << movie.director << ", " << movie.releaseDate << ", "
              << movie.runTime << '\n';
  }
  favorites.close();
}

/**
 * @brief Finds and displays a movie by its title.
 * @param movies Pointer to the array of Movie structs.
 * @param numMovies The number of movies in the database.
 */
void findMovie(Movie *movies, int numMovies) {
  string searchTitle;
  string choice;
  bool found = false;

  cout << "Enter a movie title to be searched for: ";
  cin.ignore();
  getline(cin, searchTitle);

  for (int i = 0; i < numMovies; i++) {
    if (caseInsenitiveCmp(movies[i].title, searchTitle)) {
      found = true;
      displayMovie(movies[i]);
      cout << "Would you like to save the movie " << movies[i].title
           << "? ('Y' or 'N')\n";
      cin >> choice;

      if (choice == "Y" || choice == "y") {
        cout << "Saving movie to favorites.\n";
        saveToFile(movies[i]);
      }
    }
  }

  if (!found)
    cout << "Error: movie not found...\n";
}

/**
 * @brief Prompts the user to continue or exit.
 * @return True if the user wants to continue; otherwise, false.
 */
bool promptToContinue() {
  string choice;
  do {
    cout << "Press 'Y' to continue or 'N' to exit: ";
    cin >> choice;
    if (choice == "Y" || choice == "y")
      return true;
    else if (choice == "N" || choice == "n")
      return false;
    else
      cout << "Invalid input. Please enter 'Y' to continue or 'N' to exit."
           << '\n';
  } while (true);
}

/**
 * @brief Displays favorite movies from the favorites file.
 */
void displayFavorites() {
  ifstream favorites("favorites.txt");
  string title, grossTotal, director, releaseDate, runTime;

  cout << '\n';

  if (!favorites) {
    cout << "Favorites file not opened properly.\n";
    return;
  }

  cout << "Your favorites:\n";
  while (getline(favorites, title, ',')) {
    getline(favorites, grossTotal, ',');
    getline(favorites, director, ',');
    getline(favorites, releaseDate, ',');
    getline(favorites, runTime);

    cout << '\n'
         << "Title: " << title << '\n'
         << "Gross total:" << grossTotal << '\n'
         << "Director:" << director << '\n'
         << "Release date:" << releaseDate << '\n'
         << "Runtime:" << runTime << '\n'
         << '\n';
  }
}

/* Sample Run
 *
 * Enter the input file name: movies
 * Enter a movie title to be searched for: skyFALL
 *
 * Title: Skyfall
 * Gross total: 1.109
 * Director: Sam Mendes
 * Release date: 11/9/12
 * Runtime: 143
 *
 * Would you like to save the movie Skyfall? ('Y' or 'N')
 * y
 * Saving movie to favorites.
 * Press 'Y' to continue or 'N' to exit: y
 * Enter a movie title to be searched for: toy StORY 3
 *
 * Title: Toy Story 3
 * Gross total: 1.067
 * Director: Lee Unkrich
 * Release date: 7/18/10
 * Runtime: 103
 *
 * Would you like to save the movie Toy Story 3? ('Y' or 'N')
 * y
 * Saving movie to favorites.
 * Press 'Y' to continue or 'N' to exit: y
 * Enter a movie title to be searched for: avAtar
 *
 * Title: Avatar
 * Gross total: 2.788
 * Director: James Cameron
 * Release date: 12/18/09
 * Runtime: 161
 *
 * Would you like to save the movie Avatar? ('Y' or 'N')
 * n
 * Press 'Y' to continue or 'N' to exit: n
 *
 * Your favorites:
 *
 * Title: Skyfall
 * Gross total: 1.109
 * Director: Sam Mendes
 * Release date: 11/9/12
 * Runtime: 143
 *
 * Title: Toy Story 3
 * Gross total: 1.067
 * Director: Lee Unkrich
 * Release date: 7/18/10
 * Runtime: 103
 */

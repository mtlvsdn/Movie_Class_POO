#include <iostream>
#include <string>

class Movie {
private:
	const int id = 1;
	std::string name = "Home Alone 2";
	std::string description = "A very good Christmas movie.";
	int actorsCount = 5;
	std::string* actors = nullptr;
	int year = 1992;
	bool published = false;
	char character = '9';

public:
	//Setters
	void setName(std::string newName) {
		this->name = newName;
	}
	void setDescription(std::string newDescription) {
		this->description = newDescription;
	}
	void setActorsCount(int newActorsCount) {
		this->actorsCount = newActorsCount;
	}
	void setActors(std::string* newActors) {
		if (this->actors != 0) {
			delete[] this->actors;
		}
		this->actors = new std::string[this->actorsCount];
		for (int i = 0; i < this->actorsCount; i++) {
			this->actors[i] = newActors[i];
		}
	}
	void setYear(int newYear) {
		this->year = newYear;
	}
	void isPublished(bool newPublished) {
		this->published = newPublished;
	}
	//Getters
	int getId() {
		return this->id;
	}
	std::string getName() {
		return this->name;
	}
	std::string getDescription() {
		return this->description;
	}
	int getActorsCount() {
		return this->actorsCount;
	}
	std::string* getActors() {
		std::string* newArray = new std::string[this->actorsCount];
		for (int i = 0; i < this->actorsCount; i++) {
			newArray[i] = this->actors[i];
		}
		return newArray;
	}
	int getYear() {
		return this->year;
	}
	int getPublished() {
		return this->published;
	}

	//Default Constructor
	Movie():id(1) {
		setName("Home Alone 2");
		setDescription("A very good Christmas movie.");
		setActorsCount(5);
		std::string newArray[] = {"John", "Mell", "Laura", "Greg", "Ben"};
		setActors(newArray);
		setYear(1992);
		isPublished(true);
	}
	//Constructor with parameters
	Movie(int newId, std::string newName, std::string newDescription, int newActorsCount, 
		std::string* newActors, int newYear, bool newPublished):id(newId) {
		setName(newName);
		setDescription(newDescription);
		setActorsCount(newActorsCount);
		setActors(newActors);
		setYear(newYear);
		isPublished(newPublished);
	}
	//Copy Constructor
	Movie(const Movie& source) {
		setName(source.name);
		setDescription(source.description);
		setActorsCount(source.actorsCount);
		setActors(source.actors);
		setYear(source.year);
		isPublished(source.published);
	}
	//Destructor
	~Movie() {
		delete[] this->actors;
	}
	//overloading =
	Movie operator=(const Movie& newMovie) {
		this->name = newMovie.name;
		this->description = newMovie.description;
		this->actorsCount = newMovie.actorsCount;

		if (this->actors != nullptr) {
			delete[] this->actors;
		}
		this->actors = new std::string[this->actorsCount];
		for (int i = 0; i < this->actorsCount; i++) {
			this->actors[i] = newMovie.actors[i];
		}

		this->year = newMovie.year;
		this->published = newMovie.published;
		return *this;
	}
	//overloading[]
	std::string operator[](int index) {
		if (index < 0 || index > this->actorsCount) {
			throw std::exception("The provided index for the array is invalid");
		}
		return this->actors[index];
	}
	//overloading !
	bool operator!() {
		return !this->published;
	}
	//overloading <<
	friend std::ostream& operator<<(std::ostream& console, const Movie& newMovie);
	//overloading >>
	friend std::istream& operator>>(std::istream& console, Movie& newMovie);
	// overloading cast int to string
	operator int() const {
		int number = static_cast<int>(this->character);
		return number;
	}
	//overloading cast string to int
	operator std::string() const {
		return std::to_string(this->actorsCount);
	}
	//overloading ==
	bool operator==(const Movie& source) {
		if (this->name == source.name) {
			return true;
		}
		else {
			return false;
		}
	}
	//overloading >=
	bool operator>=(const Movie& source) {
		if (this->actorsCount >= source.actorsCount) {
			return true;
		}
		else {
			return false;
		}
	}
	//overloading ++
	void operator++() {
		this->actorsCount++;
	}
	void operator--() {
		this->actorsCount--;
	}
	int operator+(const Movie& source) {
		return this->actorsCount + source.actorsCount;
	}
	int operator-(const Movie& source) {
		return this->id - source.id;
	}
	int operator*(const Movie& source) {
		return this->actorsCount * source.actorsCount;
	}
	float operator/(const Movie& source) {
		return this->actorsCount / source.actorsCount;
	}
};

//overloading <<
std::ostream& operator<<(std::ostream& console, const Movie& source) {
	console << std::endl << "ID: " << source.id;
	console << std::endl << "Name: " << source.name;
	console << std::endl << "Description: " << source.description;
	console << std::endl << "Actors Count: " << source.actorsCount;
	console << std::endl << "Actor name: ";
	for (int i = 0; i < source.actorsCount; i++) {
		console << ", " << source.actors[i];
	}
	console << std::endl << "Year: " << source.year;
	console << std::endl << "Is the movie published?: " << source.published;
	return console;
}
//overloading >>
std::istream& operator>>(std::istream& console, Movie& source) {
	console >> source.name;
	console >> source.description;
	console >> source.actorsCount;
	if (source.actors != nullptr) {
		delete[] source.actors;
	}
	source.actors = new std::string[source.actorsCount];
	for (int i = 0; i < source.actorsCount; i++) {
		console >> source.actors[i];
	}
	console >> source.year;
	console >> source.published;
	return console;
}

int main() {
	std::string newArray[] = { "John", "Vlad", "Bob", "Mary", "Mihai" };
	Movie movie1(1, "Terminator", "Interesting movie", 5, newArray, 2000, true);
	std::cout << movie1;

	/*Movie movie2 = movie1;
	Movie movie3;
	movie3 = movie1;
	std::cout << movie2;
	std::cout << movie3;*/
	
	Movie movie4;
	std::cout << movie4;
	std::cout << std::endl << std::endl;
	std::cin >> movie4;
	std::cout << movie4;
}
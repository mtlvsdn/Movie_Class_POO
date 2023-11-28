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
		std::string newArray[] = {"John", "Mell" "Laura", "Greg", "Ben"};
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
		this->actors = newMovie.actors;
		this->year = newMovie.year;
		this->published = newMovie.published;
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

	}
	//overloading cast string to int
	operator std::string() const {

	}
	//overloading ==
	bool operator==(const Movie& source) {

	}
	//overloading >=
	bool operator>=(const Movie& source) {

	}
	//overloading ++
	void operator++() {

	}
	void operator--() {

	}
	int operator+(const Movie& source) {

	}
	int operator-(const Movie& source) {

	}
	int operator*(const Movie& source) {

	}
	float operator/(const Movie& source) {

	}
};

//overloading <<
std::ostream& operator<<(std::ostream& console, const Movie& source) {

}
//overloading >>
std::istream& operator>>(std::istream& console, Movie& source) {

}

int main() {

}
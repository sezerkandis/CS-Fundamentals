// https://www.hackerrank.com/challenges/30-inheritance/
   
#include <iostream>
#include <vector>

using namespace std;

class Person{
	protected:
		string firstName;
		string lastName;
		int id;
	public:
		Person(string firstName, string lastName, int identification){
			this->firstName = firstName;
			this->lastName = lastName;
			this->id = identification;
		}
		void printPerson(){
			cout<< "Name: "<< lastName << ", "<< firstName <<"\nID: "<< id << "\n"; 
		}
	
};

// Enter your code here.
// --------------------------------------------------------- // 
#include <functional>
#include <numeric>
// --------------------------------------------------------- // 

class Student :  public Person{
	private:
		vector<int> testScores;  
	public:

// Enter your code here.
// --------------------------------------------------------- // 
        Student(string name, string surname, int ident, std::vector<int> scores) : Person(name, surname, ident){
            testScores.assign(scores.begin(), scores.end());
        }

        char calculate() {
            if (testScores.size() == 0) {
                return 'T';    
            }
                        
            int average = std::accumulate(testScores.begin(), testScores.end(), 0) / testScores.size();
            return average < 40 ? 'T' :
                   average >= 40 && average < 55 ? 'D' :
                   average >= 55 && average < 70 ? 'P' :
                   average >= 70 && average < 80 ? 'A' :
                   average >= 80 && average < 90 ? 'E' :
                   average >= 90 && average <= 100 ? 'O' : '-';
        }
// --------------------------------------------------------- // 
};

int main() {
	string firstName;
  	string lastName;
	int id;
  	int numScores;
	cin >> firstName >> lastName >> id >> numScores;
  	vector<int> scores;
  	for(int i = 0; i < numScores; i++){
	  	int tmpScore;
	  	cin >> tmpScore;
		scores.push_back(tmpScore);
	}
	Student* s = new Student(firstName, lastName, id, scores);
	s->printPerson();
	cout << "Grade: " << s->calculate() << "\n";
	return 0;
}
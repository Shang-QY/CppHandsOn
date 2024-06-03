#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void printStateBit(const istream& iss) {
    cout << "State Bit : ";
    cout << (iss.good() ? "G" : "-");
    cout << (iss.fail() ? "F" : "-");
    cout << (iss.eof() ? "E" : "-");
    cout << (iss.bad() ? "B" : "-");
    cout << endl;
}

int stringToInteger(const string& str) {
    int result = 0;
    istringstream iss(str);
    // printStateBit(iss);

    // iss >> result;
    // printStateBit(iss);
    // if (iss.fail()) throw std::domain_error("no value int at the beginning!");
    if (!(iss >> result))
        throw std::domain_error("no value int at the beginning!");

    char remain;
    iss >> remain;
    if (!iss.fail()) throw std::domain_error("more than a single value int!");

    return result;
}

void testStringToInteger() {
    while (true) {
        cout << "Please input a line: ";
        string s;
        getline(cin, s);
        cout << "You typed in: " << s << endl;
        int i = stringToInteger(s);
        cout << "As an integer, it is " << i << endl;
    }
}

void bufferedExperiment(ostream& oss) {
    oss << "CS";

    oss << "106";

    oss << "L";

    oss << endl;
}

int endlAtEveryLine() {
    auto startMove = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < 100; i++) {
        cout << i << endl;
    }

    auto stopMove = std::chrono::high_resolution_clock::now();
    auto moveDuration = chrono::duration_cast<std::chrono::microseconds>(stopMove - startMove);
    return moveDuration.count();
}

int endlAtEnd() {
    auto startMove = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < 100; i++) {
        cout << i << '\n';
    }
    cout << endl;

    auto stopMove = std::chrono::high_resolution_clock::now();
    auto moveDuration = chrono::duration_cast<std::chrono::microseconds>(stopMove - startMove);
    return moveDuration.count();
}

void printEndTime(const string& input) {
    istringstream iss(input);
    int h, m, h_d, m_d;
    string day;
    string remain;
    char c;
    iss >> h >> c >> m >> day >> h_d >> remain >> m_d >> remain;

    int next_h = (h + h_d + (m + m_d) / 60) % 24;
    if (next_h > 12) {
        next_h -= 12;
        day = day == "PM" ? "AM" : "PM";
    }
    cout << next_h << ":" << (m + m_d) % 60 << " " << day << endl;
}

int getInteger(const string& prompt) {
    while (true) {
        cout << prompt;
        string line;
        int result;
        char trash;
        if (!getline(cin, line)) throw domain_error("no input");
        istringstream iss(line);
        if (iss >> result && !(iss >> trash)) return result;
    }
}

int main() {
    ostringstream oss("hello qingyu");
    cout << oss.str() << endl;
    oss << "Bye";
    cout << oss.str() << endl;


    istringstream iss("16.9 hello qingyu");
    int k;
    iss >> k;
    string s;
    iss >> s;
    cout << k << " " << s << endl;


    // testStringToInteger();


    bufferedExperiment(cout);


    int a = endlAtEveryLine();
    int b = endlAtEnd();
    cout << "EndAt each line: " << a << endl;
    cout << "EndAt end: " << b << endl;


    // cout << "please give a start time and a duration: ";
    // string time_duration;
    // getline(cin, time_duration);
    // printEndTime(time_duration);


    istringstream iss2("16.9\n hello qingyu");
    double value;
    string line;
    iss2 >> value;
    // iss2.ignore();
    getline(iss2, line);
    cout << value << "line: " << line << endl;
}

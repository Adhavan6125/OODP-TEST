#include <iostream>
#include <string>

class Doctor {
private:
    std::string name;
    int id;
    std::string specialization;
    int patientsAttended;
    double consultingFee;
    std::string dateOfJoining;
    
public:
    Doctor(std::string n, int i, std::string spec, int patients, double fee, std::string date)
        : name(n), id(i), specialization(spec), patientsAttended(patients), consultingFee(fee), dateOfJoining(date) {}
    double calculateEarnings() const {
        return patientsAttended * consultingFee;
    }
    bool earningsExceedThreshold(double threshold) const {
        return calculateEarnings() > threshold;
    }
     void displayDetails() const {
        std::cout << "Doctor Name: " << name << std::endl;
        std::cout << "ID: " << id << std::endl;
        std::cout << "Specialization: " << specialization << std::endl;
        std::cout << "Patients Attended: " << patientsAttended << std::endl;
        std::cout << "Consulting Fee per Patient: " << consultingFee << std::endl;
        std::cout << "Date of Joining: " << dateOfJoining << std::endl;
        std::cout << "Total Earnings: " << calculateEarnings() << std::endl;
    }
};

int main() {
    Doctor doctor1("Dr. John Smith", 101, "Cardiology", 120, 500, "2020-01-15");
    doctor1.displayDetails();

    return 0;
}








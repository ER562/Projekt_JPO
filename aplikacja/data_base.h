#ifndef DATA_BASE_H
#define DATA_BASE_H

#endif // DATA_BASE_H

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using std::string, std::vector, std::getline, std::stoi, std::to_string, std::stringstream;

struct person {
    //imi�
    string name;
    string surname;
    //data urodzenia
    int day_of_birth;
    int month_of_birth;
    int year_of_birth;
    //miejsce zamieszkania

    string street;
    int street_number;
    string city;
    string country;
    //contact details
    int phone_number;
    string email;
};

class data_center {
private:
    vector<person> base;
public:

    void put_record(person x) {
        base.push_back(x);
    };

    int get_record(int x, person& y) {
        if (base.size() <= x) {
            return 1;
        }
        else {
            y = base[x];
            return 0;
        }
    };

    void delete_record(int x){
        base.erase(base.begin() + x);
    };

    vector<int> find_record(person x,int name_i, int surname_i, int day_of_birth_i,
                            int month_of_birth_i, int year_of_birth_i, int street_i, int street_number_i,
                            int city_i, int country_i, int phone_number_i, int email_i){
        vector<int> y(base.size(), 1);
        int iterator{ 0 };
        for (person z : base) {
            //name
            if (name_i) {
                if (z.name != x.name) {
                    y[iterator] = 0;
                }
            }
            //surname
            if (surname_i) {
                if (z.surname != x.surname) {
                    y[iterator] = 0;
                }
            }
            //day of birth
            if (day_of_birth_i) {
                if (z.day_of_birth != x.day_of_birth) {
                    y[iterator] = 0;
                }
            }
            //month of birth
            if (month_of_birth_i) {
                if (z.month_of_birth != x.month_of_birth) {
                    y[iterator] = 0;
                }
            }
            //year of birth
            if (year_of_birth_i) {
                if (z.year_of_birth != x.year_of_birth) {
                    y[iterator] = 0;
                }
            }
            //street
            if (street_i) {
                if (z.street != x.street) {
                    y[iterator] = 0;
                }
            }
            //street number
            if (street_number_i) {
                if (z.street_number != x.street_number) {
                    y[iterator] = 0;
                }
            }
            //city
            if (city_i) {
                if (z.city != x.city) {
                    y[iterator] = 0;
                }
            }
            //country
            if (country_i) {
                if (z.country != x.country) {
                    y[iterator] = 0;
                }
            }
            //phone number
            if (phone_number_i) {
                if (z.phone_number != x.phone_number) {
                    y[iterator] = 0;
                }
            }
            //email
            if (email_i) {
                if (z.email != x.email) {
                    y[iterator] = 0;
                }
            }
            iterator++;
        }
        vector<int> resoult;
        for (int i{ 0 }; i < y.size(); i++) {
            if (y[i] == 1) {
                resoult.push_back(i);
            }
        }
        return resoult;
    };

    int size(void){
        return base.size();
    };

    string save_record( int number){
        number--;
        string resoult;
        resoult += base[number].name + "," + base[number].surname + "," + to_string(base[number].day_of_birth) + "," + to_string(base[number].month_of_birth) + "," + to_string(base[number].year_of_birth) + ","
                   + base[number].street + "," + to_string(base[number].street_number) + "," + base[number].city + "," + base[number].country + "," + to_string(base[number].phone_number) + ","
                   + base[number].email;
        return resoult;
    };

    person load_record(string x){
        person y;
        stringstream z (x);
        string temp;
        getline(z, y.name, ',');
        getline(z, y.surname, ',');
        getline(z, temp, ',');
        y.day_of_birth = stoi(temp);
        getline(z, temp, ',');
        y.month_of_birth = stoi(temp);
        getline(z, temp, ',');
        y.year_of_birth = stoi(temp);
        getline(z, y.street, ',');
        getline(z, temp, ',');
        y.street_number = stoi(temp);
        getline(z, y.city, ',');
        getline(z, y.country, ',');
        getline(z, temp, ',');
        y.phone_number = stoi(temp);
        getline(z, y.email, ',');
        return y;
    };
};

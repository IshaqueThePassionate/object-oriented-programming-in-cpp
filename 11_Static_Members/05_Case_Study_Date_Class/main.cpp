#ifndef DATE_H
#define DATE_H

class Date {
private:
    // --- TOPIC: DATA MEMBERS ---
    // These are normal instance variables.
    // Every object (d1, d2) has its own copy of day, month, and year.
    int day;
    int month;
    int year;

    // --- TOPIC: STATIC DATA MEMBER ---
    // This variable is SHARED by all objects. 
    // There is only ONE copy of 'defaultDate' in the entire program.
    // We use it to store a fallback date (e.g., 7/3/2005).
    static Date defaultDate;

public:
    // --- TOPIC: CONSTRUCTOR WITH DEFAULT ARGUMENTS ---
    // Note: Default values (= 0) are written ONLY in the header.
    // This allows us to create objects like Date() or Date(10,12,2024).
    Date(int aDay = 0, int aMonth = 0, int aYear = 0);

    // --- TOPIC: DESTRUCTOR ---
    // Clean-up function called automatically when an object dies.
    ~Date();

    // --- TOPIC: GETTERS (ACCESSORS) ---
    // 'const' is used because these functions strictly READ data (no changes).
    int getDay() const;
    int getMonth() const;
    int getYear() const;

    // --- TOPIC: SETTERS (MUTATORS) ---
    // Used to validate and WRITE data to private members.
    void setDay(int aDay);
    void setMonth(int aMonth);
    void setYear(int aYear);

    // --- TOPIC: MEMBER FUNCTIONS ---
    // Normal functions that perform actions on the object.
    void addDay(int x);
    void addMonth(int x);
    void addYear(int x);

    // --- TOPIC: STATIC MEMBER FUNCTION ---
    // This function belongs to the CLASS, not an object.
    // It is used to change the 'defaultDate' (static variable).
    static void setDefaultDate(int aDay, int aMonth, int aYear);
};

#endif

// #include "Date.h"

// --- TOPIC: STATIC VARIABLE INITIALIZATION ---
// CRITICAL RULE: Static variables must be initialized OUTSIDE the class.
// Here, we set the shared default date to March 7th, 2005.
Date Date::defaultDate(7, 3, 2005);

// --- TOPIC: CONSTRUCTOR LOGIC ---
// This logic runs every time a new Date object is created.
Date::Date(int aDay, int aMonth, int aYear) {
    // If the user provided a day (e.g., 10), use it.
    // If the user provided 0 (default), copy the value from the STATIC variable.
    if (aDay == 0)
        day = defaultDate.day;
    else
        setDay(aDay); // Use setter to ensure validation

    if (aMonth == 0)
        month = defaultDate.month;
    else
        setMonth(aMonth);

    if (aYear == 0)
        year = defaultDate.year;
    else
        setYear(aYear);
}

// Destructor (Empty here, but present for completeness)
Date::~Date() {
}

// --- TOPIC: GETTERS IMPLEMENTATION ---
// Simple functions to return private values.
int Date::getDay() const {
    return day;
}
int Date::getMonth() const {
    return month;
}
int Date::getYear() const {
    return year;
}

// --- TOPIC: SETTERS WITH VALIDATION ---
// This ensures no object ever has an invalid date (like Month 14).
void Date::setDay(int aDay) {
    if (aDay > 0 && aDay <= 31)
        day = aDay;
}
void Date::setMonth(int aMonth) {
    if (aMonth > 0 && aMonth <= 12)
        month = aMonth;
}
void Date::setYear(int aYear) {
    year = aYear;
}

// --- TOPIC: MEMBER FUNCTIONS ---
void Date::addDay(int x) {
    day += x;
}
void Date::addMonth(int x) {
    month += x;
}
void Date::addYear(int x) {
    year += x;
}

// --- TOPIC: STATIC FUNCTION IMPLEMENTATION ---
// Notice: It modifies 'defaultDate', not 'day' or 'month'.
// Because it is static, it can only touch static variables.
void Date::setDefaultDate(int aDay, int aMonth, int aYear) {
    defaultDate.day = aDay;
    defaultDate.month = aMonth;
    defaultDate.year = aYear;
}

#include <iostream>
using namespace std;

int main() {
    // --- TOPIC: OBJECT CREATION (INSTANTIATION) ---
    
    // CASE 1: Using Defaults
    // No arguments passed. The Constructor sees 0,0,0.
    // It copies the Static defaultDate (7/3/2005).
    Date d1;  

    // CASE 2: Custom Values
    // Arguments passed. The Constructor uses 10, 12, 2024.
    Date d2(10, 12, 2024);

    // --- TOPIC: USING GETTERS ---
    cout << "d1: " << d1.getDay() << "/" << d1.getMonth() << "/" << d1.getYear() << endl;
    cout << "d2: " << d2.getDay() << "/" << d2.getMonth() << "/" << d2.getYear() << endl;

    // --- TOPIC: CALLING MEMBER FUNCTIONS ---
    d2.addYear(1); // Changes d2 year to 2025
    cout << "d2 after addYear: " << d2.getDay() << "/" << d2.getMonth() << "/" << d2.getYear() << endl;

    // --- TOPIC: CALLING STATIC MEMBER FUNCTION ---
    // We call this using the CLASS NAME (Date::), not an object.
    // This updates the shared 'defaultDate' for everyone created in the future.
    Date::setDefaultDate(1, 1, 2030);

    // CASE 3: New Defaults
    // d3 is created AFTER we changed the static default.
    // So d3 will be 1/1/2030.
    Date d3;

    cout << "d3: " << d3.getDay() << "/" << d3.getMonth() << "/" << d3.getYear() << endl;

    return 0;
}

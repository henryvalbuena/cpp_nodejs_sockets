// this class transform c strings into c strings JSON format
// Example:
// Input message: "Hello World!"
// Output message: {"message": "Hello World!"}
// Additionally, the class has methods to add properties to the JSON object
// and values to those methods before outputting the final message.

#ifndef SICT_JSONformat
#define SICT_JSONformat
#include <string>
#include <cstring>
#include <iostream>

// Error codes
#define OK 1
#define JSON_FORMAT -1
#define OUT_OB -2
namespace sict {
    class JSONformat {
        // Property of the JSON obj
        std::string* property;
        // Value of the JSON obj
        std::string* value;
        // Current size of the array
        size_t size;
        // Maximum size of the array
        size_t max;
        // JSON return cstring
        char* JSON;
        // Status of current object
        bool isEmpty;
        // Validate a c string passed if empty or null
        bool strVal(const char* cstring_);
        // Holds the error code
        int err;
    public:
        JSONformat() : property(nullptr), value(nullptr), size(0), 
            max(0), JSON(nullptr), isEmpty(true) {};
        // Construct a JSON object passing a string as argument that
        // have the format {"property":"value"[,"property":"value"]}
        JSONformat(const std::string JSON_String);
        ~JSONformat();
        // Add property and value, return 1 if ok else fails
        int addPropertyAndValue(const char* property_, const char* value_);
        // Modify property, suppling property position in the array, return 1 if ok else fails
        int updateProperty(const char* property_, size_t position_);
        // Modify value, supplying property position in the array, return 1 if ok else fails
        int updateValue(const char* value_, size_t position_);
        // Remove property and value, supplying position in the array, return 1 if ok else fails
        int removePropertyAndValue(size_t position_);
        // Returns std::string property and value at given position
        // formatted as {"property":"value"}
        const std::string& getPropertyAndValue(size_t position_) const;
        // Return std::string value at given position
        const std::string& getValue(size_t position_) const;
        // Display current JSON object
        void display() const;
        // Returns cstring reference of JSON format
        const char* getJSONString();
        // Returns true if current object is empty
        bool empty() const;
        // Returns the current object error state
        int errorState() const;
    };
}
#endif // SICT_JSONformat
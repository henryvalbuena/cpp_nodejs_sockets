// this class transform c strings into c strings JSON format
// Example:
// Input message: "Hello World!"
// Output message: '{"message": "Hello World!"}'
// Additionally, the class has methods to add properties to the JSON object
// and values to those methods before outputting the final message.

#ifndef SICT_JSONformat
#define SICT_JSONformat
#include <string>
#include <cstring>
#include <iostream>
namespace sict {
    class JSONformat {
        // Property of the JSON obj
        std::string* property;
        // Value of the JSON obj
        std::string* value;
        // size of the array
        size_t size;
        // JSON return cstring
        char* JSON;
        // Validate a c string passed if empty or null
        bool strVal(const char* cstring_);
    public:
        JSONformat() : property(nullptr), value(nullptr), size(0), JSON(nullptr) {};
        ~JSONformat();
    // Add property and value, return 1 if ok else fails
        int addPropertyAndValue(const char* property_, const char* value_);
    // Modify property, suppling property position in the array, return 1 if ok else fails
        int updateProperty(const char* property_, size_t position_);
    // Modify value, supplying property position in the array, return 1 if ok else fails
        int updateValue(const char* value_, size_t position_);
    // Remove property and value, supplying position in the array, return 1 if ok else fails
        int removePropertyAndValue(size_t position_);
    // Display current JSON object
        void display() const;
    // Returns cstring reference of JSON format
        char*& getJSONString();
    };
}
#endif // SICT_JSONformat
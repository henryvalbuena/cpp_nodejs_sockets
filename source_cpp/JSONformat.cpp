#include "JSONformat.h"

namespace sict {

    JSONformat::~JSONformat() {
        delete [] property;
        delete [] value;
        delete [] JSON;
        property = nullptr;
        value = nullptr;
        JSON = nullptr;
    }

    int JSONformat::addPropertyAndValue(const char* prop, const char* val) {
        if (strVal(prop) && size == 0) {
            property = new std::string[std::strlen(prop)];
            property[size] = prop;
            value = new std::string[std::strlen(val)];
            value[size] = val;
            size++;
            return 1;
        } else if (strVal(prop) && size > 0) {
            property[size] = prop;
            value[size] = val;
            size++;
            return 1;
        }
        return -1;
    }

    int JSONformat::updateProperty(const char* prop, size_t pos) {
        if (strVal(prop) && pos < size) {
            property[pos] = prop;
            return 1;
        }
        return -1;
    }

    int JSONformat::updateValue(const char* val, size_t pos) {
        if (strVal(val) && pos < size) {
            value[pos] = val;
            return 1;
        }
        return -1;
    }

    int JSONformat::removePropertyAndValue(size_t pos) {
        std::cout << "TO BE IMPLEMENTED\n"; 
    }

    void JSONformat::display() const {
        std::cout << "'{\n";
         if (size > 0) {
            for (int i = 0; i < size; i++) {
                std::cout << "\"" << property[i] << "\"" << ": " << "\"" << value[i] << "\"";
                if (i >= 0 && (i + 1) < size) std::cout << ",\n";
                else std::cout << "\n";
            }
		}
        std::cout << "}'\n";
    }

    char*& JSONformat::getJSONString() {
        // '{"property":"value"}'
        // add the value and the format to the string
        std::string tempStr = "'{";
        for (int i = 0; i < size; i++) {
            tempStr += "\"" + property[i] + "\":\"" + value[i] + "\"";
            if (i >= 0 && (i + 1) < size) tempStr += ",";
        }
        tempStr += "}'";
        // return a c string
        JSON = new char[tempStr.size()];
        std::strcpy(JSON, tempStr.c_str());
        return JSON;
    }

    bool JSONformat::strVal(const char* str) {
        if (str == nullptr || str[0] == '\0')
            return false;
        return true;
    }
}
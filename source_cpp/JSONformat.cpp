#include "JSONformat.h"

namespace sict {
	JSONformat::JSONformat(const std::string str) {
		JSON = nullptr;
		max = size = 0;
		isEmpty = true;
		property = nullptr;
		value = nullptr;
		//check if its an array
		// ******** TO BE IMPLEMENTED ********

		// check if the string has the format {}

		if (str.size() > 0 && str.at(0) == '{' && str.at((str.size() - 1)) == '}') {
			size_t cnt = 1, k = 0;
			do
			{
				k = str.find(',', (k + 1u));
				if (k != std::string::npos) {
					cnt++;
				}
			} while (k != std::string::npos);
			k = 0;
			property = new std::string[cnt];
			value = new std::string[cnt];
			max = cnt;
			isEmpty = false;
			if (cnt > 1) {
				std::string temp = str;
				temp = temp.erase(0, 1);
				temp = temp.erase(temp.size() - 1, 1);
			
				for (size_t i = 0; i < cnt; i++) {
					std::string s = temp.substr(0, temp.find(','));
					size_t pos = s.find(':');
					addPropertyAndValue(
						s.substr(1, pos - 2).c_str(),
						s.substr(pos + 2, s.size() - (pos + 3)).c_str()
					);
					temp.erase(0, temp.find(',') + 1);
				}
			}
			else {
				size_t pos = str.find(':');
					addPropertyAndValue(
						str.substr(2, pos - 3).c_str(),
						str.substr(pos + 2, str.size() - (pos + 4)).c_str()
					);
			}
		}
	}
	JSONformat::~JSONformat() {
		delete[] property;
		delete[] value;
		delete[] JSON;
		property = nullptr;
		value = nullptr;
		JSON = nullptr;
	}
	int JSONformat::addPropertyAndValue(const char* prop, const char* val) {
		if (strVal(prop) && strVal(val)) { 
			if (!isEmpty && size < max) {
				property[size] = prop;
				value[size] = val;
				size++;
				return 1;
			}
			else if(!isEmpty && size >= max) {
				max++;
				std::string* tempProp = new std::string[max];
				std::string* tempVal = new std::string[max];
				for (size_t i = 0; i < size; i++) {
					tempProp[i] = property[i];
					tempVal[i] = value[i];
				}
				tempProp[size] = prop;
				tempVal[size] = val;
				size++;
				delete [] property;
				delete [] value;
				property = tempProp;
				value = tempVal;
				return 1;
			}
			else {
				max++;
				property = new std::string[max];
				value = new std::string[max];
				property[size] = prop;
				value[size] = val;
				size++;
				isEmpty = false;
				return 1;
			}
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
		return 0;
	}
	void JSONformat::display() const {
		if (!isEmpty) {
			std::cout << "{\n";
			if (size > 0) {
				for (size_t i = 0; i < size; i++) {
					std::cout << "\"" << property[i] << "\"" << ": " << "\"" << value[i] << "\"";
					if (i >= 0 && (i + 1) < size) std::cout << ",\n";
					else std::cout << "\n";
				}
			}
			std::cout << "}\n";
		}
		else std::cout << "Undefined\n";
	}
	const char* JSONformat::getJSONString() {
		if (!isEmpty) {
			std::string tempStr = "{";
			for (size_t i = 0; i < size; i++) {
				tempStr += "\"" + property[i] + "\":\"" + value[i] + "\"";
				if (i >= 0 && (i + 1) < size) tempStr += ",";
			}
			tempStr += "}";
			JSON = new char[tempStr.size()];
			std::strcpy(JSON, tempStr.c_str());
		}
		return JSON;
	}
	bool JSONformat::strVal(const char* str) {
		if (str == nullptr || str[0] == '\0')
			return false;
		return true;
	}
	bool JSONformat::empty() const {
		return isEmpty;
	}
}
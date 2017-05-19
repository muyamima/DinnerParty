#include "StringConditioner.h"

std::string StringConditioner::LTrim(std::string String, char Trimmer) {
	for (size_t i = 0; i < String.size(); ++i) {
		if (String[i] == Trimmer) {
			String.erase(String.begin()+i);
			--i;
		}
		else {
			break;
		}
	}
	return String;
}
std::string StringConditioner::RTrim(std::string String, char Trimmer) {
	if (!String.empty()) {
		for (size_t i = String.size() - 1; i >= 0; --i) {
			if (String[i] == Trimmer) {
				String.erase(String.begin() + i);
			}
			else {
				break;
			}
		}
	}
	return String;
}
std::string StringConditioner::Trim(std::string String, char Trimmer) {
	return LTrim(RTrim(String, Trimmer), Trimmer);
}

std::string StringConditioner::ToLower(std::string String) {
	for (size_t i = 0; i < String.size(); ++i) {
		String[i] = tolower(String[i]);
	}
	return String;
}
std::string StringConditioner::ToUpper(std::string String) {
	if (!String.empty()) {
		String[0] = toupper(String[0]);
	}
	return String;
}
std::string StringConditioner::ToUpperAfterSpace(std::string String) {
	for (size_t i = 1; i < String.size(); ++i) {
		if (String[i-1] == ' ') {
			String[i] = toupper(String[i]);
		}
	}
	return String;
}

std::string StringConditioner::Reduce(std::string String, char Trimmer) {
	for (size_t i = 1; i < String.size(); ++i) {
		if (String[i - 1] == Trimmer && String[i] == Trimmer) {
			String.erase(String.begin()+i);
			--i;
		}
	}
	return String;
}

std::string StringConditioner::Unwrap(std::string String, char Wrapper) {
	if (String.size() > 1) {
		if (String[0] == Wrapper && String[String.size() - 1] == Wrapper) {
			String.erase(String.begin());
			String.erase(String.end() - 1);
		}
	}
	return String;
}

std::string StringConditioner::All(std::string String, char Trimmer) {
	return ToUpperAfterSpace(ToUpper(ToLower(Trim(Reduce(String, Trimmer), Trimmer))));
}
std::string StringConditioner::ReduceTrim(std::string String, char Trimmer) {
	return Trim(Reduce(String, Trimmer), Trimmer);
}
std::string StringConditioner::TrimCap(std::string String, char Trimmer) {
	return ToUpper(ToLower(Trim(String, Trimmer)));
}
std::string StringConditioner::TrimCapAS(std::string String, char Trimmer) {
	return ToUpperAfterSpace(ToUpper(ToLower(Trim(String, Trimmer))));
}
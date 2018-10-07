#include <iostream>
#include <regex>
#include <vector>

using namespace std;

void validate(vector<string> inputs, string rawRegex) {
    regex validateRegex(rawRegex);
    for (auto eachInput: inputs) {
        string result = regex_match(eachInput, validateRegex) ? "true" : "false";
        cout << eachInput << ": " << result << endl;
    }
}

bool isEmail(string target) {
    return true;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    vector<string> inputs;
    inputs.emplace_back("abc@gmail.com");
    inputs.emplace_back("c");
    inputs.emplace_back("l");

    string rawEmailRegex = string("[0-9a-zA-Z]([-_.]?[0-9a-zA-Z])*")
                           + "@[0-9a-zA-Z]([-_.]?[0-9a-zA-Z])*.[a-zA-Z]{2,3}";

    validate(inputs, rawEmailRegex);

    string str = "abc@gmail.com";

    regex emailRegex(rawEmailRegex);
    smatch m;

    if(regex_match(str, m, emailRegex)) {
        for (auto& sm: m) {
            cout << sm << endl;
        }
    }

    return 0;
}

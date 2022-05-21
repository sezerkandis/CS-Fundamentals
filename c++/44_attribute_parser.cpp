// https://www.hackerrank.com/challenges/attribute-parser/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;

// Enter your code here.
// --------------------------------------------------------- // 
int main() {
    unsigned int N, Q;
    cin >> N >> Q;

    std::unordered_map<std::string, std::string> tags;

    // reading hrml lines...
    std::string line, tag_str, last_tag;
    std::cin.ignore();
    for (unsigned int i = 0; i < N; i++) {
        std::getline(std::cin, line);

        // checking ending of tags...
        if (line.substr(0,2) == "</" && line[line.size() - 1] == '>') {
            tag_str = tag_str.size() != line.size() - 3 ? tag_str.substr(0, line.size() - 3) : "";
            continue;
        }

        // reading tag name
        std::string tag = line.find(" ") != std::string::npos ? line.substr(1, line.find(" ") - 1) : line.substr(1, line.size() - 2);
        std::string atts = line.find(" ") != std::string::npos ? line.substr(line.find(" ")) : "";
        atts.erase(std::remove(atts.begin(), atts.end(), ' '), atts.end());
        tag_str = tag_str == "" ? tag : last_tag != tag
                                  ? tag_str + "." + tag
                                  : tag_str;

        if (last_tag != tag) {
            last_tag = tag;
        }
        while(line != "" && atts != ">") {
            // searching key
            auto equal_index = atts.find("=");
            if (equal_index == std::string::npos) {
                break;
            }
            std::string key = atts.substr(0, equal_index);
            atts = atts.substr(equal_index + 2);

            // searching value
            auto ampersant_index = atts.find('"');
            if (ampersant_index == std::string::npos) {
                break;
            }
            std::string value = atts.substr(0, ampersant_index);
            atts = atts.substr(ampersant_index + 1);

            // assinging to map
            tags[tag_str + "~" + key] = value;
        }
    }

    // printing results
    for (unsigned int i = 0; i < Q; i++) {
        std::string query;
        std::cin >> query;
        std::string result = tags.count(query) == 0 ? "Not Found!" : tags[query];
        std::cout << result << std::endl;
    }

    return 0;
}
// --------------------------------------------------------- // 

class Solution {
public:
    // No more required but keeping it nonetheless
    string fixLastLine(string line, int max_l) {
        string whitespace = " \t";
        string fill = " ";
        // replace sub ranges
        auto beginSpace = line.find_first_of(whitespace);
        while (beginSpace != string::npos)
        {
            const auto endSpace = line.find_first_not_of(whitespace, beginSpace);
            const auto range = endSpace - beginSpace;

            line.replace(beginSpace, range, fill);

            const auto newStart = beginSpace + fill.length();
            beginSpace = line.find_first_of(whitespace, newStart);
        }
        int num_of_spaces = max_l - line.size();
        line.append(num_of_spaces, ' ');
        return line;
    }
    string justify(string line, int max_l) {
        const auto strEnd = line.find_last_not_of(" ");
        line = line.substr(0, strEnd+1);

        int l = line.size();
        if (line.find_first_of(" ") == string::npos) {
            int diff = max_l - line.size();
            line.append(diff, ' ');
        } else {
            int index = 0;
            while (l < max_l) {
                index = line.find(" ", index);
                if (index == string::npos) {
                    index = 0;
                    continue;
                }
                line.insert(index, " ");
                index = line.find_first_not_of(" ", index);
                l++;
            }
        }

        return line;
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int curr_len = 0;
        string curr_line;
        vector<string> result;
        for (string word : words) {
            if (curr_len + word.size() < maxWidth) {
                curr_len += word.size() + 1;
                curr_line += word + " ";
            } else if (curr_len + word.size() == maxWidth) {
                curr_len += word.size();
                curr_line += word;
            } else {
                string just_line = justify(curr_line, maxWidth);
                result.push_back(just_line);
                curr_len = word.size() + 1;
                curr_line = word + " ";
            }
        }
        // trim
        const auto strEnd = curr_line.find_last_not_of(" ");
        curr_line = curr_line.substr(0, strEnd+1);
        // add required spaces
        int diff = maxWidth - curr_line.size();
        if (diff != 0) curr_line.append(diff, ' ');

        result.push_back(curr_line);

        return result;
    }
};

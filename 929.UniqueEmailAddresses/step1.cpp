class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> unique_emails;
        for (auto email : emails) {
            int domain_start_position = email.find('@');
            string modified_email = "";
            for (int i = 0; i < domain_start_position; i++) {
                if (email[i] == '+') {
                    break;
                }
                if (email[i] != '.') {
                    modified_email += email[i];
                }
            }
            modified_email += email.substr(domain_start_position);
            unique_emails.insert(modified_email);
        }
        return unique_emails.size();
    }
};

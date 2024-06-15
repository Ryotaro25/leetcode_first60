class Solution {
private:
    string canonicalize(string email) {
        int domain_start_position = email.rfind('@');
        string canonicalized_email = "";
        for (int i = 0; i < domain_start_position; i++) {
            if (email[i] == '+') {
                break;
            }
            if (email[i] != '.') {
                canonicalized_email += email[i];
            }
        }
        canonicalized_email += email.substr(domain_start_position);
        return canonicalized_email;
    }

public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> unique_emails;

        for (auto email : emails) {
            unique_emails.insert(canonicalize(email));
        }
        return unique_emails.size();
    }
};
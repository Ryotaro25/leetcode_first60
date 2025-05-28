class Solution {
public:
  int numUniqueEmails(vector<string>& emails) {
    if (emails.empty()) {
      return 0;
    }
    set<string> unique_emails;
    for (const auto& email : emails) {
      unique_emails.insert(Canonicalize(email));
    }
    return unique_emails.size();
  }

private:
  string Canonicalize(const string& email) {
    int at_mark_position = email.rfind('@');
    string local = email.substr(0, at_mark_position);

    string canonicalized_email;
    for (char letter : local) {
      if (letter == '.') {
        continue;
      }
      if (letter == '+') {
        break;
      }
      canonicalized_email += letter;
    }
    canonicalized_email += email.substr(at_mark_position, email.size());
    return canonicalized_email;
  }
};

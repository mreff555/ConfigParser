#ifndef SECF_HPP
#define SECF_HPP

#include <string>
#include <vector>
#include <regex>

constexpr std::string_view default_secf_file_path = "../config/secf";

struct Entry {std::string name; std::string value;};
using EntryVector = std::vector<Entry>;

class Secf
{
    public:
    Secf(std::string file = std::string(default_secf_file_path));

    Secf(const Secf *obj) = delete;

    Secf operator*(const Secf *rhs) = delete;

    virtual ~Secf() = default;

    bool reload();

    std::string get(std::string value);

    EntryVector find(std::string expr);

    private:
    std::string secf_file_path;
    EntryVector secf_index;
};

#endif /* SECF_HPP */
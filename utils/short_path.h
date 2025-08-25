#include <string_view>

static inline std::string_view short_base_name(std::string_view file) {
    // size_t pos = file.find_last_of("/\\");

    // if(file.empty()) {
    //     return file;
    // }

    // if(pos == std::string_view::npos) {
    //     return file;
    // }

    // if(pos + 1 == file.size()) {
    //     file.remove_suffix(1);
    //     return short_base_name(file);
    // }

    // return file.substr(pos + 1);

    size_t pos = file.find_last_of("/\\");
    return (pos == std::string_view::npos) ? file : file.substr(pos + 1);
}

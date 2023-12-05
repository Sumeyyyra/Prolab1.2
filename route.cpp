#include "Route.h"

Route::Route(int no, std::vector<std::string> stop_list, std::vector<int> distance_list)
    : route_no(no), stops(stop_list), distances(distance_list) {}

int Route::find_stop_index(const std::string& stop_name) {
    for (size_t i = 0; i < stops.size(); i++) {
        if (stops[i] == stop_name) {
            return i;
        }
    }
    return -1;
}

int Route::calculate_distance(const std::string& start, const std::string& end) {
    int start_index = find_stop_index(start);
    int end_index = find_stop_index(end);

    if (start_index == -1 || end_index == -1 || start_index >= end_index) {
        return -1;
    }

    int total_distance = 0;
    for (int i = start_index; i < end_index; i++) {
        total_distance += distances[i];
    }
    return total_distance;
}

bool Route::has_stop(const std::string& stop_name) {
    for (const auto& stop : stops) {
        if (stop == stop_name) {
            return true;
        }
    }
    return false;
}

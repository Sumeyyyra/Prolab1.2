#ifndef ROUTE_H
#define ROUTE_H

#include <vector>
#include <string>

class Route {
private:
    int route_no;
    std::vector<std::string> stops;
    std::vector<int> distances;

    int find_stop_index(const std::string& stop_name);

public:
    Route(int no, std::vector<std::string> stop_list, std::vector<int> distance_list);
    int calculate_distance(const std::string& start, const std::string& end);
    bool has_stop(const std::string& stop_name);
};

#endif

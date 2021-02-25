struct check_in_out {
    std::string station_name;
    int time;
};

struct time_data {
    int time_sum;
    int num_trips;
};

class UndergroundSystem {
private:
    std::unordered_map<int, check_in_out> check_ins;
    std::unordered_map<std::string, std::unordered_map<std::string, time_data> > travel_time_data;

public:
    UndergroundSystem() {

    }

    void checkIn(int id, std::string stationName, int t) {
        check_ins[id] = check_in_out{stationName, t};
    }

    void checkOut(int id, std::string stationName, int t) {
        check_in_out entry_data = check_ins[id];
        check_ins.erase(id);
        
        int time_taken = t - entry_data.time;
        
        time_data& data_entry = travel_time_data[entry_data.station_name][stationName];
        ++data_entry.num_trips;
        data_entry.time_sum += time_taken;
        
    }

    double getAverageTime(std::string startStation, std::string endStation) {
        time_data& data_entry = travel_time_data[startStation][endStation];
        return (double)data_entry.time_sum / data_entry.num_trips;
    }
};
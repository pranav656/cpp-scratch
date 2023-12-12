#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using Range = tuple<ll, ll, ll>;
using Map = vector<Range>;
using Maps = vector<Map>;


string input;

Map create_maps(string m_s)
{
    //  cout<<m_s<<endl;
    Map m;
    while (getline(cin, input) && input != "")
    {
            // cout<<input<<endl;
            if(input == m_s) continue;
            stringstream ss2(input);
            ll dst, src, range;
            ss2 >> dst >> src >> range;
            m.emplace_back(make_tuple(src, dst, range));
                //cout<<dest << " " << src <<" "<<range << endl;
            
    }
    return m;
}

int main()
{
    Maps all_maps;
    map<ll, ll> seed_soil, soil_fert, fert_water, water_light, light_temp,
    temp_hum, hum_loc;
    bool input_seed = false;
    vector<tuple<ll, ll>> seeds_range;
    while (getline(cin, input))
    {
        stringstream ss(input);
        string dummy;
        ss >> dummy;
        ll seed, range;
        if(!input_seed)
        {
            while(ss >> seed >> range)
            {
                //cout<<seed<<endl;
                seeds_range.push_back(make_tuple(seed, seed+range));        
            }
            input_seed = true;
            continue;
        }
       all_maps.push_back(create_maps("seed-to-soil map:"));
       all_maps.push_back(create_maps("soil-to-fertilizer map:"));
       all_maps.push_back(create_maps("fertilizer-to-water map:"));
       all_maps.push_back(create_maps("water-to-light map:"));
       all_maps.push_back(create_maps("light-to-temperature map:"));
       all_maps.push_back(create_maps("temperature-to-humidity map:"));
       all_maps.push_back(create_maps("humidity-to-location map:"));
    }

    for (auto& m : all_maps)
    {
        vector<tuple<ll, ll>> mapped_ranges;
        while(!seeds_range.empty())
        {
            auto seed_range = seeds_range.back();
            ll start = get<0>(seed_range);
            ll end = get<1>(seed_range);
            seeds_range.pop_back();
            bool match_found = false;
            for(Range& r : m)
            {

                ll overlap_start = max(start, get<0>(r));
                ll overlap_end = min(end, get<0>(r)+get<2>(r));
                // if the new range is within valid interval
                if(overlap_start < overlap_end)
                {
                    mapped_ranges.push_back(make_tuple(overlap_start - get<0>(r) + get<1>(r), overlap_end - get<0>(r) + get<1>(r)));
                    if(overlap_start > start)
                    {
                        seeds_range.push_back(make_tuple(start, overlap_start));
                    }
                    if(end > overlap_end)
                    {
                        seeds_range.push_back(make_tuple(overlap_end, end));
                    }
                    match_found = true;
                    break;
                }
            }
            if(!match_found)
            {
                // if it's not within the given intervals,
                // create a new mapped range for the next iteration
                 mapped_ranges.push_back(make_tuple(start, end));
            }
        }
        seeds_range = mapped_ranges;
    }
    ll ans = LLONG_MAX;
    for(auto& seed_range : seeds_range)
    {
        auto start = get<0>(seed_range);
        auto end = get<1>(seed_range);
        ans = min(ans, start);
    }
    cout<<"ans:"<<ans<<endl;
}

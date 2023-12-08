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
    ll ans = LLONG_MAX;
    Maps all_maps;
    map<ll, ll> seed_soil, soil_fert, fert_water, water_light, light_temp,
    temp_hum, hum_loc;
    bool input_seed = false;
    vector<ll> seeds;
    while (getline(cin, input))
    {
        stringstream ss(input);
        string dummy;
        ss >> dummy;
        ll seed;
        if(!input_seed)
        {
            while(ss >> seed)
            {
                //cout<<seed<<endl;
                seeds.push_back(seed);        
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
    for(auto& s : seeds)
    {
        ll search_val = s;
        for(auto& map : all_maps)
        {
            bool within_range = false;
            for(Range& r : map)
            {
                    if(search_val >= get<0>(r) && search_val < (get<0>(r)+get<2>(r)))
                    {
                        search_val = get<1>(r)+(search_val-get<0>(r));
                        break;
                    }
            }
            //cout<<search_val<<endl;
        }
        ans = min(ans, search_val);
    }
    cout<<"ans:"<<ans<<endl;
}

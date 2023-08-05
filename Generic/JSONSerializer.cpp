
// This is a try of JSON serializer and deserializer mentioned in the book
// The Modern C++ Challenge by Marius Bancilla
// JSON library copied from https:/​/​github.​com/​nlohmann/​json
#include "json.hpp"
#include <fstream>
#include <iostream>

using namespace std;

using json = nlohmann::json;

struct casting_role {
    string actor;
    string role;
    bool operator==(const casting_role& other) const
    {
        return (other.actor == actor && other.role == role);
    }
};

struct movie {
    unsigned int id;
    string title;
    unsigned int year;
    unsigned int length;
    vector<casting_role> cast;
    vector<string> directors;
    vector<string> writers;

    bool operator==(const movie& other) const
    {
        return (other.id == id && other.title == title && other.year == year && other.length == length && other.cast == cast && other.directors == directors && other.writers == writers);
    }
};

using movie_list = vector<movie>;

// Json serializor for the casting_role struct
void to_json(json& j, casting_role const& c)
{
    j = json{ { "star", c.actor }, { "name", c.role } };
}

void to_json(json& j, movie const& m)
{
    j = json::object({ { "id", m.id },
        { "title", m.title },
        { "year", m.year },
        { "length", m.length },
        { "cast", m.cast },
        { "directors", m.directors },
        { "writers", m.writers } });
}

void serialize(movie_list const& movies, string_view file_path)
{
    json jdata{ { "movies", movies } };
    ofstream ofile(file_path.data());
    if (ofile.is_open()) {
        ofile << setw(2) << jdata << endl;
    }
}

movie_list deserialize(string_view file_path)
{
    movie_list movies;
    ifstream ifile(file_path.data());
    if (ifile.is_open()) {
        json jdata;

        try {
            ifile >> jdata;
            if (jdata.is_object()) {
                for (auto& element : jdata.at("movies")) {
                    movie m;
                    m.id = element.at("id").get<unsigned int>();
                    m.title = element.at("title").get<string>();
                    m.year = element.at("year").get<unsigned int>();
                    m.length = element.at("length").get<unsigned int>();
                    for (auto& role : element.at("cast")) {
                        m.cast.push_back(
                            casting_role{ role.at("star").get<string>(),
                                role.at("name").get<string>() });
                    }
                    for (auto& director : element.at("directors")) {
                        m.directors.push_back(director);
                    }

                    for (auto& writer : element.at("writers")) {
                        m.writers.push_back(writer);
                    }

                    movies.push_back(m);
                }
            }
        }
        catch (exception const& ex) {
            cout << ex.what() << endl;
        }
    }

    return movies;
}

int main()
{
    movie_list movies{
        {
            11001, "The Matrix", 1999, 196,
            // cast
            {
                { "Keanu Reeves", "Neo" },
                { "Laurence Fishburne", "Morpheus" },
                { "Carrie-Anne Moss", "Trinity" },
                { "Hugo Weaving", "Agent Smith" } },
            // directors
            { "Lana Wachowski", "Lilly Wachowski" },
            // writers
            { "Lana Wachowski", "Lilly Wachowski" },
        },
        {
            9871, "Forrest Gump", 1994, 202,
            { { "Tom Hanks", "Forrest Gump" },
                { "Sally Field", "Mrs. Gump" },
                { "Robin Wright", "Jenny Curran" },
                { "Mykelti Williamson", "Bubba Blue" } },
            { "Robert Zemeckis" },
            { "Winston Groom", "Eric Roth" },
        }
    };

    serialize(movies, "movies.json");

    auto movies_deserialized = deserialize("movies.json");
    assert(movies_deserialized == movies);
}

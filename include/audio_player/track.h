#pragma once

#include <string>

namespace Devialify
{

/*
 * A Track is a single audio file.
 */
class Track final
{
    public:

        const std::string& title() const;
        const std::string& artist() const;
        const std::string& codec() const;
        int duration() const;
        const std::string id() const;
        std::string toString() const;

        Track() = delete; // No default constructor
        explicit Track(const std::string& title, const std::string& artist, int duration, const std::string& codec);
        Track(const Track& other); // Copy constructor
        Track& operator=(Track&& other); // Move Assignment operator

        friend bool operator==(const Track& l, const Track& r)
        {
            return l.id() == r.id();
        }

    private:
        std::string m_title;
        std::string m_artist;
        std::string m_codec;
        int m_duration; // in seconds
};
}
